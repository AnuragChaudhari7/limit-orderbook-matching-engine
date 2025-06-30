#include "CSVParser.h"

CSVParser::CSVParser(){}

int CSVParser::read_csv(string path_to_csv) {
    ifstream file;
    string line = "";
    file.open(path_to_csv);
    while(getline(file, line)){
        cout << line << endl;
        
    }
    return 0;
}