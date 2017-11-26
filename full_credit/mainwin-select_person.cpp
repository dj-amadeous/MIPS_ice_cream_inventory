#include "mainwin.h"
#include <exception>
#include <stdexcept>

int Mainwin::select_server() {
  /*this method will return the index of the given server that you selected
   *you can set your variable in your other method equal to this method, you will get hte index
   *number of the server you're looking for
  */
  std::vector<std::string> names;
  for(Mice::Server s : _servers) names.push_back(s.name());
  return select_from_vector(names, "Server");
}
