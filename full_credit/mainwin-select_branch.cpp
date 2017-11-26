#include "mainwin.h"
#include <exception>
#include <stdexcept>

int Mainwin::select_branch()
{
  std::vector<std::string> names;
  for(Mice::Emporium e : _emporiums) names.push_back(e.name());
  return select_from_vector(names, "Branch");
}
