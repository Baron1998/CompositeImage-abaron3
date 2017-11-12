// Author : Abdullah Baron

#include <iostream>
#include <string>
#include <vector>
#include "bitmap.h"

using namespace std;

// Function to check the size of the two images
int checkSize(Bitmap ,Bitmap );

// Function to combine images
void makePic(Bitmap & image ,Bitmap (&images)[10] ,int );

int main()
{
        Bitmap image[10];
        Bitmap imagefinal;
        vector <vector <Pixel> > bmp;
        Pixel rgb;
        string name;
        int files = 0;
        bool BmpImage;
        int check = 0;
        
        do{
                // Get the file names from the users
                cout<< "Enter a file name (notice the file need to be in BMP format)\n";
                cin>> name;

                //  if the user inputs "DONE" the program will break from the loop

                if(name == "DONE")
                {

                        break;
                }

                image[files].open(name);
                BmpImage = image[files].isImage();
                if(BmpImage = 1) // If the Bmp is valid

                        check = checkSize(image[files],image[0]);
                        if(check == 1)
                        {
                                files++;
                        }
                        else
                        {
                                cout <<"Bitmap files should be the same size" << endl;  

                        }

                
        }while(files<10);

        if(files>1)
        {

        makePic(imagefinal,image,files);
        imagefinal.save("composite-abaron3.bmp");
        
        }

        else{
        cout <<"Need More than 1 image to create the composite" << endl;
            }

return 0 ;
}


int checkSize (Bitmap image, Bitmap imagefirst)
{
        vector <vector <Pixel> > bmp;
        vector <vector <Pixel> > bmp2;

        bmp = image.toPixelMatrix();
        bmp2 = imagefirst.toPixelMatrix();

        if(bmp.size() == bmp2.size())
        {
                if(bmp[0].size() == bmp2[0].size())
                {
                        return 1;
                }

        }


        return 0;
}

void makePic(Bitmap &image,Bitmap (&images)[10],int files)
{
        cout <<"files : "<<files <<endl;
        vector <vector <Pixel> > bmp;
        vector <vector <Pixel> > bmp2;
        Pixel rgb;
        Pixel rgb2;
        int red[10];
        int green[10];
        int blue[10];
        int aver = 0;
        image = images[0];
        bmp2 = image.toPixelMatrix();

        for(int f = 0;f<files;f++)
        {
                bmp = images[f].toPixelMatrix();

                for(int h = 0; h<bmp2.size(); h++)  //h = hight 
                { 

                        for(int w = 0; w<bmp2[0].size(); w++) // w = width
                        {

                                if(f >0)
                                {   
                                        rgb = bmp[h][w];
                                        rgb2 = bmp2[h][w];
                                        aver = (rgb.red+rgb.green+rgb.blue+rgb2.red+rgb2.green+rgb.blue) / 6;
                                        rgb2.red = aver;
                                        rgb2.green = aver;
                                        rgb2.blue = aver;

                                        bmp2[h][w] = rgb2;  

                                }    

                        }

                }
                cout <<"Image "<< f+1 << " Out of "<< files<< " Completed" << endl; 
        }   
        image.fromPixelMatrix(bmp2);



}



//first ask for the file name
// keep asking ( by using loop) until they write "DONE" or they goes to the maximum files number which is 10
// we need to use .isImage() to make sure that the image is a bmp image
// use matrix to compine the valid images together and get the averege values of RGB
// we take the average vlaue to make sure that we can see all images when we combine them.
// make a cout to show the total of the pictures and how many picture are done.
// finally we need to save the combined pic.
