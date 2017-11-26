#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <fstream>

void Mainwin::add_picture()
{
  //GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
  int res;
  Glib::ustring name = "Open File";
  std::string file_name;
  //std::ifstream ifs;

  Gtk::FileChooserDialog dialog(name, Gtk::FILE_CHOOSER_ACTION_OPEN);
  dialog.set_transient_for(*this);

  dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
  dialog.add_button("Select", 1);



  res = dialog.run();

  switch(res)
  {
    case(1):
    {
      //ifs.open(dialog.get_filename(), std::ifstream::in});
      //ifs.open(dialog.get_filename());
      file_name = dialog.get_filename();
      std::cout << "Folder selected: " << file_name
        << std::endl;
      break;
    }
    case(Gtk::RESPONSE_CANCEL):
    {
      std::cout << "Cancel clicked." << std::endl;
      break;
    }
    default:
    {
      std::cout << "Unexpected button clicked." << std::endl;
      break;
    }


    if(res == 1)
    {
      auto image = Gdk::Pixbuf::create_from_file(file_name);
    }

  }
}
