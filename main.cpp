// Author : Abdullah Baron

#include<iostream>
#include<string>
#include<vector>
#include "bitmap.h"

using namespace std; 


// this function will take files name by using loop that it'll keep taking files name until user write "DONE" or they go to the maximum number of the pics which is 10
string Images(string);
//check if the image is valid image
bool checkImage(string);
// take the image and put it inside a matrix
vector<vector <Pixel>> imageMatrix(vector<vector<Pixel>>);
//use another matrix to combine images and take the averege of the total value
vector<vector <Pixel>> valueAverege( vector<vector<Pixel>>);
// cout the number of images and keep counting until it combile all images
int counting (int);


int main()
{
        string imageName;
        Bitmap image;
        vector < vector <Pixel>> bmp;
        Pixel rgb;
        bool BmpImage;

        //save the combined images 

}

string Images(string name)
{

        while ( name != "Done")
        {
                cout << " what is the file name?\n";
                cin >> name;
        }
        return name;
}

bool checkImage(string check)
{
        if ( check == "bmp")
        {
                return true;
        }
        else
        {
            return false;
        }





        //first ask for the file name
        // keep asking ( by using loop) until they write "DONE" or they goes to the maximum files number which is 10
        // we need to use .isImage() to make sure that the image is a bmp image
        // use matrix to compine the valid images together and get the averege values of RGB
        // we take the average vlaue to make sure that we can see all images when we combine them.
        // make a cout to show the total of the pictures and how many picture are done.
        // finally we need to save the combined pic.
