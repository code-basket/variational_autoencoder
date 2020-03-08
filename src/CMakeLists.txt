
find_package(MNIST PATHS ../3rd-party/mnist)

add_executable(vae main.cpp)
target_link_libraries(vae docopt)
target_include_directories(vae PUBLIC ${MNIST_INCLUDE_DIR} ${DOCOPT_INCLUDE_DIRS})
target_compile_definitions(vae PRIVATE MNIST_DATA_LOCATION="${MNIST_DATA_DIR}")
