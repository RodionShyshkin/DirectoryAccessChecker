cmake_minimum_required(VERSION 3.17)
project(DirectoryAccessChecker)

set(CMAKE_C_FLAGS_DEBUG "-D_DEBUG")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE srcs "src/access_checker/*.cpp" "src/directory_storage/*.cpp")
file(GLOB_RECURSE hdrs "src/access_checker/*.h" "src/directory_storage/*.h")

file(GLOB main "main.cpp")

file(GLOB_RECURSE tests "tests/*.cpp")

######## BOOST ########

set(Boost_USE_STATIC_LIBS       ON)
set(Boost_USE_DEBUG_LIBS        OFF)
set(Boost_USE_RELEASE_LIBS      ON)
set(Boost_USE_MULTITHREADED     ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

find_package(Boost 1.74.0 COMPONENTS filesystem REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

######## PROTOBUF ########

find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

file(GLOB_RECURSE PROTO_SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/proto/*.proto")
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_SOURCES})
message("generated ${PROTO_SRCS} ${PROTO_HDRS}")

SET_SOURCE_FILES_PROPERTIES(${PROTO_SRCS} ${PROTO_HDRS} PROPERTIES GENERATED TRUE)

######## gRPC ########
set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)
set(_REFLECTION gRPC::grpc++_reflection)

find_package(gRPC CONFIG REQUIRED)
message(STATUS "Using gRPC ${gRPC_VERSION}")

set(_GRPC_GRPCPP gRPC::grpc++)
find_program(_GRPC_CPP_PLUGIN_EXECUTABLE grpc_cpp_plugin)

get_filename_component(service_proto "proto/service.proto" ABSOLUTE)
get_filename_component(service_proto_path "${service_proto}" PATH)

set(service_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/service.pb.cc")
set(service_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/service.pb.h")
set(service_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/service.grpc.pb.cc")
set(service_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/service.grpc.pb.h")

add_custom_command(
        OUTPUT "${service_proto_srcs}" "${service_proto_hdrs}"
        "${service_grpc_srcs}" "${service_grpc_hdrs}"
        COMMAND protoc
        ARGS -I "${service_proto_path}"
        --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        ${service_proto}
        DEPENDS ${service_proto})

include_directories("${CMAKE_CURRENT_BINARY_DIR}")

######## GTEST ########

include_directories(src)
include_directories(tests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-instr-generate -fcoverage-mapping")

include(GoogleTest)
find_package(GTest REQUIRED)
include_directories(${GMOCK_INCLUDE_DIR})
enable_testing()

set(GMOCK_L "/usr/local/lib/gmock/")

######## Executables ########

add_executable(Server "${CMAKE_SOURCE_DIR}/src/Server.cpp"
        ${srcs} ${hdrs}
        ${PROTO_SRCS} ${PROTO_HDRS}
        ${service_proto_srcs} ${service_proto_hdrs}
        ${service_grpc_srcs} ${service_grpc_hdrs})

target_link_libraries(Server
        ${Boost_LIBRARIES} ${_REFLECTION}
        ${_GRPC_GRPCPP} ${_PROTOBUF_LIBPROTOBUF})

add_executable(DirectoryAccessChecker "${CMAKE_SOURCE_DIR}/src/Client.cpp"
        ${srcs} ${hdrs}
        ${PROTO_SRCS} ${PROTO_HDRS}
        ${service_proto_srcs} ${service_proto_hdrs}
        ${service_grpc_srcs} ${service_grpc_hdrs})

target_link_libraries(DirectoryAccessChecker
        ${Boost_LIBRARIES} ${_REFLECTION}
        ${_GRPC_GRPCPP} ${_PROTOBUF_LIBPROTOBUF})

add_executable(UnitTests ${tests}
                        ${srcs} ${hdrs}
                        ${PROTO_SRCS} ${PROTO_HDRS}
                        ${service_proto_srcs} ${service_proto_hdrs}
                        ${service_grpc_srcs} ${service_grps_hdrs})

set(GMOCK_L "/usr/local/lib/gmock/")
target_link_libraries(UnitTests GTest::GTest GTest::Main /usr/local/lib/libgmock.a /usr/local/lib/libgmock_main.a)
target_link_libraries(UnitTests ${Boost_LIBRARIES}
        ${Protobuf_LIBRARIES}
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF})

gtest_discover_tests(UnitTests)