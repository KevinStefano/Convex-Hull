//NAMA : Kevin Austin Stefano

//Untuk memvisualisasikan data dilakukan dengan memasukkan library graphics.h dilakukan dengan Dev C++
//Hilangkan tanda komentar di beberapa kode jika ingin memvisualisasikan data pada program di bawah ini

#include <iostream>

//Library untuk mengukur waktu eksekusi
#include <chrono>
#include <iomanip>   

//#include <graphics.h>
//#include <sstream> 

using namespace std;

struct Titik
{
    int X;
    int Y;
    int IsConvex;
}; 

int main () {
	
	//initwindow(800,800);
	
    int n;

    cout << "Masukkan jumlah titik \n";
    cin >> n;
    

    Titik TitikInput[n+1];
    Titik ArrayHasil[n+2];
    cout << "Titik hasil random adalah sebagai berikut" << endl;
    for (int i=1; i<=n; i++) 
    {
        int x, y;
        x= rand() % 100 + 1 ;
        TitikInput[i].X = x;
        y= rand() % 100 + 1;
        TitikInput[i].Y = y;
        
        cout <<"("<< x << "," << y  <<")" << endl;

		//circle(400+x*4,400-y*4,5);
		//stringstream ss, sss;
		//string s1,s2;
		//ss << x;
		//ss >> s1;
		//sss << y;
		//sss >> s2; 
		//string s= "(" + s1 + "," + s2 + ")";
	    //int le = s.length(); 
	    //char char_string[le + 1]; 
	    //strcpy(char_string, s.c_str()); 
		//outtextxy(405+x*4,405-y*4, char_string) ;


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

    
    auto start = chrono::high_resolution_clock::now();


    while (k<=n+1)
    {
        found=false;
        if (idxhasil==4 || k ==n) {
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
                                
                 }
            }
            if ((IsConpos == 0 || IsConneg ==0)&& (t1!= t2) && (TitikInput[t2].IsConvex ==0))   {
                TitikInput[t2].IsConvex =1;
                found=true;

                if (idxhasil==1) {
                    inisialidx=t2;
                }
                ArrayHasil[idxhasil].X = TitikInput[t2].X;
                ArrayHasil[idxhasil].Y = TitikInput[t2].Y;
                ArrayHasil[idxhasil].IsConvex = 1;

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
        
        k++; 
        }
        else
        {
            t1 = t1%n+1;
            j=1;
        	k++; 
        }
    }
    
    auto end = chrono::high_resolution_clock::now();
    
    double waktu= chrono::duration_cast<chrono::nanoseconds>(end-start).count();
   cout << "Maka himpunan titik yang membentuk convex hull dinyatakan sebagai senarai (list) sebagai berikut:" << endl;
   cout <<"[";
   if (ArrayHasil[1].X == ArrayHasil[idxhasil-1].X && ArrayHasil[1].Y == ArrayHasil[idxhasil-1].Y)
   {
       int i =1;
        while (i<idxhasil-1)
        {
            cout << "(" <<  ArrayHasil[i].X << "," <<ArrayHasil[i].Y <<"),";
            //line(400+ArrayHasil[i].X*4 ,400-ArrayHasil[i].Y*4,400+ArrayHasil[i+1].X*4,400-ArrayHasil[i+1].Y*4);
            i++;
        }
        cout << "(" <<  ArrayHasil[idxhasil-1].X << "," <<ArrayHasil[idxhasil-1].Y<<")";
   }
   cout <<"]"<<endl; 
    cout << fixed << setprecision(3) << "Waktu yang diperlukan: " << waktu <<" nanosekon "<<endl;


	//line x -axis	
	//line(0,400,800,400);
	//outtextxy(700,420, "Sumbu X");
	//line y-axis
	//line(400,0,400,800);
	//outtextxy(380,20, "Sumbu Y");
	//getch();
	
	return 0;
}