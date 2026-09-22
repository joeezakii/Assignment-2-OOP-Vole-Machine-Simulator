#include <iostream>
#include <string>
#include "Image_Class.h"
using namespace std;

int main() {
    Image image("Habetik.jpg");
    for (int i = 0; i<image.width; i++) {
        for (int j =0; j<image.height; j++) {
            for (int k = 0; k<3; k++) {
               
                image (i,j,k)= image (128,0,128);
            }
        }
        }
image.saveImage("Habetik_purple.jpg");

return 0;

} I