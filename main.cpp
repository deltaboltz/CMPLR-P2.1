/*
 * By: Connor Schultz
 * Date Made: 04/03/2021
 * Files Needed: any file with extension .sp21 & makefile to compile all files
 * Made For: CS-4280 (Program Translation Project) @ UMSL
 * Last Update : 04/12/2021 - Added more commments
 */

 //NOTE : Test4 had an error to try to call

#include <iostream>
#include <string>
#include <fstream>
#include "parser.h"
#include "node.h"

using namespace std;

//main prints out the tree for parsing
int main(int argc, char* argv[])
{
  if(argc == 1)
  {
    node<std::string> root = parser(cin);
    root.preOrder();
  }
  else if(argc == 2) //check to see if the file has the proper extension
  {
    string fext, filename(""), filearg(argv[1]);
    int length = filearg.length();

    if(length > 4)
    {
      fext = filearg.substr(length-5, length);

      if(fext == ".sp21")
      {
        filename = filearg;
      }
    }

    if(filename == "")
    {
      filename = filearg + ".sp21";
    }

    ifstream fs(filename.c_str());

    if(fs)
    {
      node<std::string> root = parser(fs);
      root.preOrder();
    }
    else
    {
      cout << filename << " - CANNOT be opened.";
      return 1;
    }
  }
  else
  {
    cout << "Wrong number of arguments were given";
    return 2;
  }

  cout << "finished processing" << endl;
  return 0;
}
