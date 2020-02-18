#include <iostream>
#include <time.h>
#include <iomanip>
#include <cmath>
using namespace std;

struct Titik
{
    int X;
    int Y;
    int IsConvex;
}; 

int main () {
    int n;

    cout << "Masukkan jumlah titik \n";
    cin >> n;
    
    clock_t tStart = clock();

    Titik TitikInput[n+1];
    Titik ArrayHasil[n+2];
    cout << "Titik hasil random adalah sebagai berikut" << endl;
    for (int i=1; i<=n; i++) 
    {
        /*
        int x, y;
        x= rand() % 10 + 1 ;
        TitikInput[i].X = x;
        y= rand() % 10 + 1;
        TitikInput[i].Y = y;
        */
       cin >> TitikInput[i].X;
       cin >> TitikInput[i].Y;
        //cout <<"("<< x << "," << y  <<")" << endl;
cout <<"("<<TitikInput[i].X << "," << TitikInput[i].Y  <<")" << endl;
        TitikInput[i].IsConvex =0;
        ArrayHasil[i].X=0;
        ArrayHasil[i].Y=0;
        ArrayHasil[i].IsConvex = 0;
    }

    TitikInput[n+2].IsConvex =0;
        ArrayHasil[n+2].X=0;
        ArrayHasil[n+2].Y=0;
        ArrayHasil[n+2].IsConvex = 0;

    int IsConpos =0;
    int IsConneg =0;

    bool found = false;
    int k =1, j=1;
    int t1 = 1, t2 = 1;
    int idxhasil =1;
    int inisialidx=0;
    int titik1, titik2, titik3;
    while (k<=n+1)
    {
        found=false;
        if (k==n-1) {
            TitikInput[inisialidx].IsConvex=0;
        }

        while (j<=n && !found) 
        {
            IsConpos =0;
            IsConneg =0;
            for (int t3=1; t3<=n; t3++) 
            {
                 if (t1!= t2 && t1!=t3 && t2!=t3) {
                      int IsPos = (TitikInput[t2].Y-TitikInput[t1].Y)*TitikInput[t3].X + (TitikInput[t1].X-TitikInput[t2].X)*TitikInput[t3].Y-(TitikInput[t1].X*TitikInput[t2].Y-TitikInput[t1].Y*TitikInput[t2].X);
                      if (IsPos>=0) {
                          IsConpos += 1;
                      }
                      else {
                          IsConneg += 1;
                      }
                      

                       cout << "titiknya1 " << TitikInput[t1].X<<endl;
                                cout << "titik1 Y nya " <<TitikInput[t1].Y <<endl;
                              cout << "titiknya " << TitikInput[t2].X<<endl;
                                cout << "titik Y nya " <<TitikInput[t2].Y <<endl;
                                cout << "Convex y nya " << TitikInput[t2].IsConvex<<endl;
                                cout << "urutan k ke ... " << k <<endl;
                                cout << "titik Y nya " <<TitikInput[t2].Y <<endl;
                                cout << "titik Y nya " <<TitikInput[t2].Y <<endl;
                                cout << "t " << TitikInput[t3].X<<endl;
                                cout << "t Y nya " <<TitikInput[t3].Y <<endl;
                                cout << IsConpos <<"\n"<<endl;
                                cout << IsConneg <<"\n"<<endl;

                                
                 }
            }
            if ((IsConpos == 0 || IsConneg ==0)&& (t1!= t2) && (TitikInput[t2].IsConvex ==0))   {
                TitikInput[t2].IsConvex =1;
                found=true;

                
                //Pengecheckan 3 titik
                if (idxhasil==1) {
                    inisialidx=t2;
                }

                if((idxhasil)%4==0) {
                    titik1=t2;
                }
                else if ((idxhasil)%2 == 0) {
                    titik2=t2;
                }
                else if ((idxhasil)%3 == 0) {
                    titik3 =t2;
                }
                cout << "t1: " <<titik1<<endl;
                
                cout << "t2: " <<titik2<<endl;
                
                cout << "t3: " <<titik3<<endl;
                if (idxhasil>=3) {
                    int Segaris = (TitikInput[titik2].Y-TitikInput[titik1].Y)*TitikInput[titik3].X + (TitikInput[titik1].X-TitikInput[titik2].X)*TitikInput[titik3].Y-(TitikInput[titik1].X*TitikInput[titik2].Y-TitikInput[titik1].Y*TitikInput[titik2].X);
                        if (Segaris==0) {
        
                            if ((sqrt(pow(TitikInput[titik2].Y-TitikInput[titik1].Y,2)-(pow(TitikInput[titik2].X-TitikInput[titik1].X,2))) < (sqrt(pow(TitikInput[titik3].Y-TitikInput[titik1].Y,2)-(pow(TitikInput[titik3].X-TitikInput[titik1].X,2)))))) {
                                idxhasil-=1;
                                ArrayHasil[idxhasil].X = TitikInput[t2].X;
                                ArrayHasil[idxhasil].Y = TitikInput[t2].Y;
                                ArrayHasil[idxhasil].IsConvex = 1;
                            }
                        }
                }
                //Memasukkan ke array hasil
                else {
                    ArrayHasil[idxhasil].X = TitikInput[t2].X;
                    ArrayHasil[idxhasil].Y = TitikInput[t2].Y;
                    ArrayHasil[idxhasil].IsConvex = 1;
                }

                                TitikInput[t2].IsConvex =1;
                                cout << "_______________________________________\n";
                                cout << "titiknya1 " << TitikInput[t2].X<<endl;
                                cout << "titik1 Y nya " <<TitikInput[t2].Y <<endl;
                                 cout << "convex??   " <<TitikInput[t2].IsConvex <<endl;
                                cout << "_______________________________________\n";

                idxhasil ++;
                j=1;

            }
            else {
                t2 = t2%n+1;
                j++;
            }
        }
        if (found==true) 
        {
            t1=t2;
            /*
            cout << "+++++++++++++++++++++++++++++++++++\n";
            cout << "titiknya1 " << TitikInput[t1].X<<endl;
            cout << "titik1 Y nya " <<TitikInput[t1].Y <<endl;
            cout << "+++++++++++++++++++++++++++++++++++\n";
            */
        
        k++; 
        }
        else
        {
            t1 = t1%n+1;
            j=1;
        k++; 
        }
    }
    double waktu= ((double) (clock() - tStart)/CLOCKS_PER_SEC);
   cout << "Maka himpunan titik yang membentuk convex hull dinyatakan sebagai senarai (list) sebagai berikut:" << endl;
   cout <<"[";
   //if (ArrayHasil[1].X == ArrayHasil[idxhasil-1].X && ArrayHasil[1].Y == ArrayHasil[idxhasil-1].Y)
   {
       int i =1;
        while (i<idxhasil-1)
        {
            cout << "(" <<  ArrayHasil[i].X << "," <<ArrayHasil[i].Y <<"),";
            i++;
        }
        cout << "(" <<  ArrayHasil[idxhasil-1].X << "," <<ArrayHasil[idxhasil-1].Y<<")";
   }
   cout <<"]"<<endl;
    cout << fixed << setprecision( 6 ) << "Time taken: " << waktu <<" sekon "<<endl;

    return 0;
}