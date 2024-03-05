
#ifndef Encode_h
#define Encode_h
#define bitsperchannel 8
#include "BitMapHeader.h"
void encodeimage(unsigned char*** imageData, int imageHeight, int imageWidth){
    const int BYTES_PER_PIXEL = 3;
    string phrase;
    int *intptr;
    intptr= new int;
    bool columns = true, rows=true;
    int numberofchar;
    
    cout<< "Enter the message you would like to encode in the image" <<endl;
    cin.ignore();
    //get the line given by user
    getline(cin, phrase);
    //get the size of phrase entered by user
    numberofchar = phrase.length();
   
    
char phrasecharacter[numberofchar+1];
int phrasebinary[numberofchar+1][bitsperchannel];
    //loop converts characters from user message to binary and stores it in a new array
for (int i = 0; i <= numberofchar; i++){
    phrasecharacter[i] = phrase[i];
    for(int z =0; z< bitsperchannel ;z++ ){
        phrasebinary[i][z] = (phrasecharacter[i]>>z)&1;
    }
}
    //int pointer points at the first value of array that stores the binary of the user message
intptr=&phrasebinary[0][0];
int  numberofbits=0;
for ( int h=0; h< imageHeight;h++ ){
    for ( int w=0; w<imageWidth; w++){
        for (int channel=0; channel< BYTES_PER_PIXEL ; channel++){
            //compares the bit from user message to the LSB of the image data, then sets the LSB of image to one
            if(*intptr != ((imageData[h][w][channel]>>0)&1) && (((imageData[h][w][channel]>>0)&1)==0)){
                
                imageData[h][w][channel] = ( imageData[h][w][channel]&~(1 << 0))|(1 << 0);
                
            }
            //compares the bit from user message to the LSB of the image data, then sets the LSB of image to zero
            if( *intptr !=((imageData[h][w][channel]>>0)&1) && (((imageData[h][w][channel]>>0)&1)==1) ){
                
                imageData[h][w][channel] =(imageData[h][w][channel]&~(1 << 0))|(0 <<0);
                
            }
            //increments the address of array, therefore moves pointer across the array
            intptr++;
            //counter for number of bits read from the array of binary values
            numberofbits++;
            //if the number of bits is equal to the total bits from user message then break loop by setting columns to false
            if (numberofbits == (((numberofchar+1)*bitsperchannel) ) ){
                columns=false;
                break;
            }
        }
        //exits the loop for imagewidth
        if( columns == false){
            rows=false;
            break;
        }
    }
    //exits the loop for imageheight
    if( rows == false){
        break;
    }
}


}
#endif /* Encode_h */

