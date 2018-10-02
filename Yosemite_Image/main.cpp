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
    //yosemite.display();

    ColorGrid *cg  = new ColorGrid(807, 1038, Color("white"));
    Bridges::setDataStructure(cg);
    
    for (int i = 0; i < 1038; i++){
        for(int j = 0; j < 807; j++){
            int red = yosemite.getImagePixel(i, j, 0);
            int green = yosemite.getImagePixel(i, j, 1);
            int blue = yosemite.getImagePixel(i, j, 2);
            cg -> set(j, i, Color(red, green, blue, 255));
        }
    }
    
    Bridges::visualize();
    
    yosemite.toGrayScale();
    
    for (int i = 0; i < 1038; i++){
        for(int j = 0; j < 807; j++){
            int red = yosemite.getImagePixel(i, j, 0);
            int green = yosemite.getImagePixel(i, j, 1);
            int blue = yosemite.getImagePixel(i, j, 2);
            cg -> set(j, i, Color(red, green, blue, 255));
        }
    }

    
    
    Bridges::visualize();
    
    
    
    return 0;
    
}




