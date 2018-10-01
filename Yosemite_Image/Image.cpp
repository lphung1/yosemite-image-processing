//
//  Image.cpp
//  Yosemite_Image
//
//  Created by Loi Phung on 9/29/18.
//  Copyright © 2018 Loi Phung. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;





class Image{
    
private:
    // image dimensions
    int width, height;
    // pointer to the dynamically allocated image array
    const int red = 0;
    const int green = 1;
    const int blue = 2;
    ifstream file;
    string fileSize; //size of file
    int *image_array;
    int * pic_array = (int *)malloc(1038*807*3*sizeof(int));
    #define ARR(i,j,k) (pic_array[807*3*i + 3*j + k])
    
    
    
public:
    
    
    
    
    Image(){
        width = height = 0;

        
        //image_array = image_arr;
        
    }
    
    //constructor with string file
    Image(string i){

        
        
        //RGB* image_arr = (RGB*)malloc(1038 * 807);
        pic_array = (int *)malloc(1038*807*3*sizeof(int));
        
        
        string type, resolution, maxValue;
        
        string fileName = i;
        cout << fileName;
        
        file.open(fileName);
        if (file.is_open()){
            cout << "File open\n";
            getline(file, type); //to skip first 3 lines
            getline(file, resolution);
            getline(file, maxValue);
            //cout << type << "\n" << resolution << "\n" << maxValue << "\n";
            
            for(int i = 0; i < 807; i++){
                for(int j = 0; j < 1038; j ++){
                    file >> ARR(i,j,red);
                    file >> ARR(i,j,green);
                    file >> ARR(i,j,blue);
                    
                }
                
            }
            
            
        }
        else{
            cout << "Issue opening file";
        }
        file.close();
        
        
        
    }//end constructor
    //creates an image object using the given dimensions
    Image (int width, int height){
        
        
    }
   // destructor  - provide as many destructors as needed
    
    // accessors/mutators
    int getWidth();
    void setWidth(int w);
    int getHeight();
    void setHeight(int h);
    
    // set/get an image pixel given row and column addresses
    // pixel is a 3 element r,g,b triple
    int getImagePixel (int row, int col, int pixel){
        
        return ARR(col, row, pixel);
        
    }
    
    void setImagePixel (int col, int row, int *pixel){
        
    }
    
    // reads an image from  the given input image file
    void read(string infile);
    
    // writes image to file
    void display (){
        
        for(int i = 0; i < 1038; i++){
            for(int j = 0; j < 807; j ++){
                
                cout << ARR(i,j,red) << " ";
                cout << ARR(i,j,green) << " ";
                cout << ARR(i,j,blue) << " ";
                
            }
            
        }
        
    }
    
    // Converts RGB to grayscale
    void toGrayScale ();
    
    // flips the image  horizontally each row of pixesl
    void flipHorizontal();
    
    // sets the red component of each pixel to zero
    void flattenRed();
    
    // flips the blue component of image about 255
    void negateBlue();
    
    
    
    
    
};
