#include <iostream>

int main(){
//������ �������:
const int n=10;
//��������� ����������:
int i;
//������� �������������� ��������:
double x[n],y[n];
//��������� ������:
double a,b;
//������� ��������:
double Sx=0,Sy=0,Sxy=0,Sxx=0;
//���� �������������� ������:
std::cout << "x = ";
for(i=0; i < n; i++)
 std::cin >> x[i];
std::cout << "y = ";
for(i=0; i < n; i++)
 std::cin >> y[i];
//���������� ���������� ������:
for(i=0; i < n; i++){
 Sx+=x[i];
 Sy+=y[i];
 Sxy+=x[i]*y[i];
 Sxx+=x[i]*x[i];
}
Sx/=n;
Sy/=n;
Sxy/=n;
Sxx/=n;
a=(Sx*Sy-Sxy)/(Sx*Sx-Sxx);
b=(Sxy-a*Sxx)/Sx;
//���������:
std::cout << "a = " << a << "\n";
std::cout << "b = " << b << "\n";
return 0;
}
