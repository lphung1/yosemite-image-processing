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
    #define ARR(i,j,k) (pic_array[1038*3*i + 3*j + k])
    string fileName;
    
    
public:
    
    Image(){
        width = height = 0;
        
    }
    
    /* constructor with string file, constructor generates new image with file and stores
    into array
     */
    Image(string i){
        
        pic_array = (int *)malloc(1038*807*3*sizeof(int));
        
        string type, resolution, maxValue;
        
        fileName = i;
        //cout << fileName;
        
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
    Image (int w, int h){
        
        width = w;
        height = h;
        
    }

    
    // accessors/mutators
    int getWidth(){
        return width;
    }
    
    //sets width
    void setWidth(int w){
        width = w;
    }
    
    //gets height
    int getHeight(){
        return height;
    }
    
    //sets height
    void setHeight(int h){
        height = h;
    }
    
    // set/get an image pixel given row and column addresses
    // pixel is a 3 element r,g,b triple
    /*
     int col - column
     int row - row
     int pixel - r, g or b. 0 for r, 1 for g, 2 for b.
     */
    int getImagePixel (int col, int row, int pixel){
        
        return ARR(col, row, pixel);
        
    }
    
    /*
     int col - column
     int row - row
     int pixel - r, g or b. 0 for r, 1 for g, 2 for b.
     int value - new value
     */
    int setImagePixel (int col, int row, int pixel, int value){
        if(value > 255 || value < 0){
            return 0;
        }
        else{
        ARR(col, row, pixel) = value;
        return 1;
        }
        
    }
    
    /*
     reads file and stores in array
     */
    void read(string infile){
        pic_array = (int *)malloc(1038*807*3*sizeof(int));
        
        string type, resolution, maxValue;
        
        fileName = infile;
        //cout << fileName;
        
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
    }//end read
    
    /*
     displays values of array
     */
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
    void toGrayScale (){
        for(int i = 0; i < 807; i++){
            for(int j = 0; j < 1038; j ++){
                int R, G, B, grey = 0;
    
                R = ARR(i,j,red);
                G = ARR(i,j,green);
                B = ARR(i,j,blue);
                
                grey = (R + G + B) / 3;
                ARR(i,j,red) = grey;
                ARR(i,j,green) = grey;
                ARR(i,j,blue) = grey;
                
            }
            
        }
    }
    
    // flips the image  horizontally each row of pixesl
    void flipHorizontal(){
        resetImage();
        
        string type, resolution, maxValue;
        file.open(fileName);
        if (file.is_open()){
            //cout << "File open\n";
            getline(file, type); //to skip first 3 lines
            getline(file, resolution);
            getline(file, maxValue);
            //cout << type << "\n" << resolution << "\n" << maxValue << "\n";
            
            for(int i = 0; i < 807; i++){
                for(int j = 1038; j > 0; j --){
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
        
    }
        
        
    
    
    // sets the red component of each pixel to zero
    void flattenRed(){
        resetImage();
        for(int i = 0; i < 807; i++){
            for(int j = 0; j < 1038; j ++){
                ARR(i,j,red) = 0;
            }
            
        }
    }
    
    // flips the blue component of image about 255
    void negateBlue(){
        resetImage();
        for(int i = 0; i < 807; i++){
            for(int j = 0; j < 1038; j ++){
                int B = 0;
                B = ARR(i,j,blue);
                ARR(i,j,blue) = 255 - B;
            }
            
        }
        
    }
    
    /*
     resets modified image to original image that was provided
     */
    void resetImage(){
        
        string type, resolution, maxValue;
        
        file.open(fileName);
        if (file.is_open()){
            //cout << "File open\n";
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
    }
    
};
