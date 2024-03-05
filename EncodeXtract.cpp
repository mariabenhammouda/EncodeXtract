
// EncodeXtract.cpp
//  ascii to binary
//
//  Created by Maria  on 06/11/2020.
//
#include "BitMapHeader.h"
#include "Encode.h"
#include "Decode.h"

#include <iostream>
#include<string.h>
#include <string>
using namespace std;

int main(){
    const char* fileName;
    string phrase;
    string userfilename;
    bool ended=true;
    unsigned char*** imageData;
    int imageWidth,imageHeight;
    int answer;
    char *filename1= new char;
    while( ended== true){
        //main menu
        cout <<endl<< "Enter 1 to Encode" <<endl << "Enter 2 to Decode" <<endl << "Enter 0 to exit"<<endl;
        cin >> answer;
        
        switch (answer) {
            case 1:{
                cout << "Enter the name of the image file you would like to encode the message in" <<endl;
                cin >> filename1;
                fileName=filename1;
                //ensure image file was open successfully
                if (ReadBitmapImage(fileName, imageData, imageWidth, imageHeight)){
                    cout << "The image file was opened successfully" <<endl;
                }
                encodeimage(imageData, imageHeight, imageWidth);
                cout <<"Enter the name of file you would like to store your encoded image in"<<endl;
                //get the name for the new encoded image from user
                cin>> userfilename;
                    //creates new image with encoded message
                fileName=userfilename.c_str();
                // if image data was written successfully, print message to user
                    if( WriteBitmapImage(fileName, imageData, imageWidth, imageHeight)){
                        cout<<"Message has been encoded in the image file successfully" <<endl;
                    }
                ReleaseMemory(imageData, imageHeight, imageWidth);
                break;
        }
            case 2:
            {
                cout << "Enter the name of the image File that contains the encoded message" <<endl;
                cin >> filename1;
                fileName=filename1;
                // if image data was read successfully, print message to user
                if (ReadBitmapImage(fileName, imageData, imageWidth, imageHeight)){
                    cout << "The image file was opened successfully" <<endl;
                }
                DecodeImage(imageData, imageHeight, imageWidth);
                ReleaseMemory(imageData, imageHeight, imageWidth);
               
                break;
            }
            case 0:{
                cout << "The program is terminating ... " <<endl;
                //breaks loop, doesnt display main menu again
                ended=false;
                break;
            }
            default:
            {
                cout <<"Invalid choice, please enter a valid menu option" <<endl;
                break;
            }
        }
    }
}

