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
   std::cout << "vvedi kol-vo uravneniy: ";
         std::cin >> n;
         std::cout << "vvedi chislo neizvestnih: ";
         std::cin >> m;
         m+=1;
    int **matrix = new int *[n];
         for (i=0; i<n; i++)
             matrix[i] = new int [m];
 
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


