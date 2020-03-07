//
// Created by sakakibara on 2020/03/08.
//

#include <string>
#include <map>
#include <sstream>
#include <iostream>
#include <docopt.h>

#define VERSION_STRING "v_0.0.0"

using argmap = std::map<std::string, docopt::value>;

static const char USAGE[] =
        R"([cmd]
variational auto-encoder
Usage:

  variational auto-encoder <input>
  variational auto-encoder (-h | --help)
  variational auto-encoder --version

Options:
  <input>                          input
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
  std::cout << "hello world!" << std::endl;
  return 0;
}

