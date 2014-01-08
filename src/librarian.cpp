#include <fstream>
#include <ios>
#include <iostream>
using namespace std;

void prepare_koans(istream& is, ostream& os, const string& recipent)
{
  while (is.good()) {
    string line;
    getline( is, line );
    const string startdel = "/*answer=";
    const string enddel = "*/";
    string::size_type startdelpos = line.find(startdel);
    if ( startdelpos!=string::npos ) {
      string::size_type enddelpos = line.find( enddel, startdelpos );
      if ( recipent=="disciple" ) {
        os << line.substr(0,startdelpos);
      } else if ( recipent=="master" ) {
        os << line.substr(0,line.find("__"));
        string::size_type answerstartpos = startdelpos + startdel.length();
        string::size_type answerlength = enddelpos - answerstartpos;
        os << line.substr( answerstartpos, answerlength );
      } else {
        cerr << "Unknown recipent '" << recipent << "'\n"; 
        abort();
      }
      os << line.substr(enddelpos+enddel.length()) << endl;
    } else {
      os << line << endl;
    }
  }
}

int main(int argc, char** argv)
{
  const string recipent(argv[1]);
  const string dstdir(argv[2]);
  for (int i=3; i<argc; ++i) {
    string src_file_name(argv[i]);
    ifstream is(src_file_name);
    if (!is.good()) {
      cerr << "Could not open '" << src_file_name << "' for reading\n";
      abort();
    }

    string::size_type basenamepos = src_file_name.rfind('/') + 1;
    string dst_file_name = dstdir + src_file_name.substr(basenamepos);
    ofstream os( dst_file_name );
    if (!os.good()) {
      cerr << "Could not open '" << dst_file_name << "' for writting\n";
      abort();
    }

    prepare_koans( is, os, recipent );
  } 
  return 0;
}
