#include<vector>
#include<iostream>

double dotProduct(std::vector<double> a, std::vector<double> b) {
  if(a.size()!=b.size()) {
    std::cout << "dotProduct vector sizes are not equal";
    throw;
  }
  
 double accum=0;
 for(auto i=0; i<a.size(); i++) {
   accum+=a[i]*b[i];
 }

 return accum;
}