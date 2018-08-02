#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main()
{
   int i, j, n, m;
//создаем массив
       vector< vector<double> > sarr;
    
    readData("AppleStore.csv", ";", sarr);

    for ( size_t i=0; i<sarr.size(); i++ ) {

        for ( size_t j=0; j<sarr[0].size(); j++ ) {

            std::cout << sarr[i][j] << "\t";
        }

        cout << "\n";
    }
 
//инициализируем
   std::cout << "vvedi element";
    for (i = 0; i<n; i++)
        for (j = 0; j<m; j++)
            std::cin >> matrix[i][j];
//выводим массив
    std::cout << "matrix: ";
      for (i=0; i<n; i++)
       {
          for (j=0; j<m; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
       }
    std::cout << "\n";
 
//Метод Гаусса
 
    float tmp, xx[m];
    int k;
 
    for (i=0; i<n; i++)
     {
       tmp=matrix[i][i];
         for (j=n;j>=i;j--)
             matrix[i][j]/=tmp;
           for (j=i+1;j<n;j++)
          {
             tmp=matrix[j][i];
               for (k=n;k>=i;k--)
             matrix[j][k]-=tmp*matrix[i][k];
          }
      }
  /*обратный ход*/
    xx[n-1] = matrix[n-1][n];
     for (i=n-2; i>=0; i--)
       {
           xx[i] = matrix[i][n];
           for (j=i+1;j<n;j++) xx[i]-=matrix[i][j]*xx[j];
       }
 
       for (i=0; i<n; i++)
           std::cout << xx[i] << " ";
       std::cout << "\n";
 
    delete[] matrix;
 
   return 0;
}


