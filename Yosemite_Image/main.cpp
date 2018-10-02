//
//  main.cpp
//  Yosemite_Image
//
//  Created by Loi Phung on 9/29/18.
//  Copyright © 2018 Loi Phung. All rights reserved.
//

#include <iostream>
#include "Image.cpp"
#include "src/Bridges.h"
#include "src/Color.h"
#include "src/ColorGrid.h"

using namespace std;
using namespace bridges;




int main() {

    Bridges::initialize(3, "lphung1@uncc.edu", "234291986029"); //enter's api credentials
    Bridges::setTitle("Greedy Algorithm");
    
    Image yosemite("yosemite.ppm");
    
    ColorGrid *cg  = new ColorGrid(807, 1038, Color("white"));
    
    Bridges::setDataStructure(cg);
    
    //displays original image
    for (int i = 0; i < 807; i++){
        for(int j = 0; j < 1038; j++){
            int red = yosemite.getImagePixel(i, j, 0);
            int green = yosemite.getImagePixel(i, j, 1);
            int blue = yosemite.getImagePixel(i, j, 2);
            cg -> set(i, j, Color(red, green, blue, 255));
        }
    }
    Bridges::visualize();
    
    //turn image into grayscale and displays
    yosemite.toGrayScale();
    
    for (int i = 0; i < 807; i++){
        for(int j = 0; j < 1038; j++){
            int red = yosemite.getImagePixel(i, j, 0);
            int green = yosemite.getImagePixel(i, j, 1);
            int blue = yosemite.getImagePixel(i, j, 2);
            cg -> set(i, j, Color(red, green, blue, 255));
        }
    }
    Bridges::visualize();
    
    //flatten red values and displays image
    yosemite.flattenRed();
    
    for (int i = 0; i < 807; i++){
        for(int j = 0; j < 1038; j++){
            int red = yosemite.getImagePixel(i, j, 0);
            int green = yosemite.getImagePixel(i, j, 1);
            int blue = yosemite.getImagePixel(i, j, 2);
            cg -> set(i, j, Color(red, green, blue, 255));
        }
    }
    Bridges::visualize();
    
    //negates the blue and displays image
    yosemite.negateBlue();
    
    for (int i = 0; i < 807; i++){
        for(int j = 0; j < 1038; j++){
            int red = yosemite.getImagePixel(i, j, 0);
            int green = yosemite.getImagePixel(i, j, 1);
            int blue = yosemite.getImagePixel(i, j, 2);
            cg -> set(i, j, Color(red, green, blue, 255));
        }
    }
    Bridges::visualize();
    
    //flips image and display image
    yosemite.flipHorizontal();
    
    for (int i = 0; i < 807; i++){
        for(int j = 0; j < 1038; j++){
            int red = yosemite.getImagePixel(i, j, 0);
            int green = yosemite.getImagePixel(i, j, 1);
            int blue = yosemite.getImagePixel(i, j, 2);
            cg -> set(i, j, Color(red, green, blue, 255));
        }
    }
    Bridges::visualize();
    
    
    
    return 0;
    
}




