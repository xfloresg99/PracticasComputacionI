#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;

 int main()
    {
      char num;
      float suma,resta,mult,div,num1,num2;
      int res;

      cout<<"Intoduce el primer numero"<<endl;
      cin>> num1;
      
      cout<<"Intoduce el segundo numero"<<endl;
      cin>> num2;

      cout<<"Que operacion quiere realizar"<<endl;
      cout<<"+.- Suma"<<endl;
      cout<<"-.- Resta"<<endl;
      cout<<"*.- Multiplicacion"<<endl;
      cout<<"/.- Division"<<endl;
      cout<<"%.- Modulo"<<endl;
      
         cout<<"Introduce Opcion:\n";
         cin>>num;
         
         if (num=='+')  {
         suma=num1+num2;
         cout<<"La suma es: "<<suma;
                      }
        
         else if (num=='-')  {
          resta=num1-num2;
          cout<<"La resta es: "<<resta;
                       }
          else if (num=='*')  {
            mult=num1*num2;
           cout<<"La multiplicacion es: "<<mult;
                       }
        
          else if (num=='/')  {
          div=num1/num2;
          cout<<"La division  es: "<< div;
                       }
            
                   
         else if (num=='%')  {
          	
          res= int (num1) % int(num2);
          cout<<"El residuo es: "<< res;
                       }
            
           
              Return 0;
                   }
            
