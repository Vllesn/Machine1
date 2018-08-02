#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;
using std::cout;

void splitString(const string &fullstr,
                 vector<string> &elements,
                 const string &delimiter) {

    string::size_type lastpos =
        fullstr.find_first_not_of(delimiter, 0);
    string::size_type pos     =
        fullstr.find_first_of(delimiter, lastpos);

    while ( (string::npos != pos) || (string::npos != lastpos) ) {

        elements.push_back(fullstr.substr(lastpos, pos-lastpos));

        lastpos = fullstr.find_first_not_of(delimiter, pos);
        pos = fullstr.find_first_of(delimiter, lastpos);
    }
}

double stringToDouble(const string &str) {

    istringstream stm;
    double val = 0;

    stm.str(str);
    stm >> val;

    return val;
}

void readData(const string &filename,
              const string &csvdelimiter,
              vector< vector<double> > &sarr) {

    ifstream fin(filename.c_str());

    string s;
    vector<string> selements;
    vector<double> delements;

    while ( !fin.eof() ) {

        getline(fin, s);

        if ( !s.empty() ) {

            splitString(s, selements, csvdelimiter);

            for ( size_t i=0; i<selements.size(); i++ ) {

                delements.
                    push_back(stringToDouble(selements[i]));
            }

            sarr.push_back(delements);
            selements.clear();
            delements.clear();
        }
    }

    fin.close();
}

int main(int argc, char** argv) {

    vector< vector<double> > sarr;
    
    readData("AppleStore.csv", ";", sarr);

    for ( size_t i=0; i<sarr.size(); i++ ) {

        for ( size_t j=0; j<sarr[0].size(); j++ ) {

            cout << sarr[i][j] << "\t";
        }

        cout << "\n";
    }

    return 0;
}
