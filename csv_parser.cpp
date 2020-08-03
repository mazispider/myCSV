#include <iostream>
#include <vector>
#include <string>
#include "rapidcsv.h"
//first agument: csv file path. second argument: column name(csv file should have header). third argument: number of last rows to print
int main(int argc, char **argv)
{
  std::string fpath,colName;
  int lNum;
  fpath = std::string(argv[1]);
  colName = std::string(argv[2]);
  lNum = std::stoi(argv[3]);
  
  std::cout << std::string(argv[1]) << std::endl;
  rapidcsv::Document doc(fpath);
 
  std::vector<float> col = doc.GetColumn<float>(colName);
  if(lNum > col.size()){
	  lNum = col.size();
  }
  std::cout << "Read " << col.size() << " values in " << colName << " column."<< std::endl;
  for(int i = col.size() - lNum; i < col.size(); i++){
	  std::cout << i << ": " << col[i] << std::endl;
  }
}
