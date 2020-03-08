//
// Created by sakakibara on 2020/03/08.
//

#include <string>
#include <map>
#include <iostream>
#include <docopt.h>
#include <mnist/mnist_reader.hpp>

#define VERSION_STRING "v_0.0.0"

using argmap = std::map<std::string, docopt::value>;

static const char USAGE[] =
        R"([cmd]
variational auto-encoder
Usage:
  vae
  vae (-h | --help)
  vae --version

Options:
  -h --help                        Show help
  --version                        Show version.
  )";


int main(int argc, char *argv[]) {
  std::map<std::string, docopt::value> args = docopt::docopt(USAGE,
                                                             { argv + 1, argv + argc },
                                                             true,               // show help if requested
                                                             VERSION_STRING );
  #ifndef NDEBUG
  for(auto const& arg : args) {
    std::cout << arg.first <<  arg.second << std::endl;
  }
  #endif

  std::cout << "MNIST data directory: " << MNIST_DATA_LOCATION << std::endl;

  // Load MNIST data
  mnist::MNIST_dataset <std::vector, std::vector<uint8_t>, uint8_t> dataset =
      mnist::read_dataset<std::vector, std::vector, uint8_t, uint8_t>(MNIST_DATA_LOCATION);

  std::cout << "Nbr of training images = " << dataset.training_images.size() << std::endl;
  std::cout << "Nbr of training labels = " << dataset.training_labels.size() << std::endl;
  std::cout << "Nbr of test images = " << dataset.test_images.size() << std::endl;
  std::cout << "Nbr of test labels = " << dataset.test_labels.size() << std::endl;

  return 0;
}

