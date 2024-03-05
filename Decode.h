#ifndef Decode_h
#define Decode_h
#define bitsperchannel 8
void DecodeImage(unsigned char*** imageData,int imageHeight, int imageWidth){
    bool column2=true, row2=true;
    const int BYTES_PER_PIXEL = 3;
    char* letter;
    letter = new char;
    int numberofchars=0;
    int numberofbit = 0;
    int ascii=0;
    cout << "The message encoded in the image is: "<<endl;
    for ( int h=0; h<imageHeight; h++){
        for ( int w=0; w<imageWidth; w++){
            for (int channel=0; channel<  BYTES_PER_PIXEL; channel++){
                // calculates ascii for each 8 bits
                ascii+= (((imageData[h][w][channel]>>0)&1))*pow(2,numberofbit);
                numberofbit++;
                // once number of bits reaches 8, ascii is converted to equivalent char
                if( numberofbit== bitsperchannel){
                    letter[numberofchars]=(char)ascii;
                    cout << letter[numberofchars];
                    ascii = 0;
                    numberofbit = 0;
                    //once ascii reaches the delimiter, exit loop, sets column2 to false to exit the outer loops
                    if( letter[numberofchars] == '\0'){
                        cout <<endl;
                        column2=false;
                        break;
                    }
                }
                
                numberofchars++;
            }
            //exits the loop for imagewidth
            if( column2 == false){
                row2=false;
                break;
            }
        }
        //exits the loop for imageheight
        if( row2 == false){
            break;
        }
    }
    //delete dynamic memory allocated for letter
    delete letter;
    letter=NULL;
    
}

#endif /* Decode_h */

