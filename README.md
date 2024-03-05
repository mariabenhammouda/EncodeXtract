# EncodeXtract
Image Steganography Software

The objective is to develop software that provides the user with options to encode and decode images. The software presents the user with a main menu, with options to encode a message, decode a message, and exit the program. When the user selects the encode option, he/she is prompted to enter the secret message and the name of the bitmap file where the secret message must be encoded in. When the user selects the decode option, the program prompts the user for the encoded bitmap image name, extracts the secret test message, and displays it on the output screen. The program enables the user to perform multiple filter analyses by repeating the process as desired When the user selects the exit option, a message confirming exit is printed on the screen, and the program is terminated.


Relevant information:
A watermark adds information to a document or image by placing a logo or seal in plain sight. The watermark protects the owner’s rights by showing ownership. TV broadcasters commonly do this by placing their logo in a corner of the broadcast picture. A watermark can be hidden in an image. Hiding the watermark does not change the appearance of the image. This protects the owner’s rights, without disturbing the image. Steganography is a technique of hiding the data (file, text, image, etc.) within another data file (file, text, image, etc.). 

This program uses the Least significant bit steganography. The least Significant bit is the lowest bit of a binary number. In this type of steganography, the program  embeds the secret message in the least significant bits of a media file. This leads to  minimal visible effect so it is not recognizable for a common viewer. Each pixel of the image contains three channels, Red, Green, and Blue. Each channel contains eight bits. The program compares the binary of the secret message to the least significant bit of each channel. Therefore eight channels store the character of the secret message. At the end of the secret message a delimiter character ‘\0’ is embedded into pixel bytes so that the message can be extracted back into the decode process. The example below illustrates how one character ‘K’ can be stored in the channels of the image pixels. 

An image can be represented as a three-dimensional array (M-by-N-by-3 array) where M is the number of pixels in the vertical direction (rows) and N is the number of pixels in the horizontal direction(cols), while each 3-vector corresponds to the blue, green, and red intensities of each pixel. 

The pixel values are 1-byte characters and are between 0 and 255. A “BitmapHelper” header script is used to read Bitmap images (.bmp) into a 3D image array and to write Bitmap images (.bmp) to an image file. A bitmap image has the following structure. 

A bitmap file BGR pixel data can be read using BitmapHelper.

![Screen Shot 2024-03-05 at 8 05 13 AM](https://github.com/mariabenhammouda/EncodeXtract/assets/102983688/5a276d3d-7f83-486d-aab5-1c8cd120a90e)


The following explains how the program executes:
 
Enter the choice of encoding, decoding, or exit
Enter '1' for encoding
Enter '2' for decoding
Or enter '0' to exit
1 (for encoding)
Enter the name of the file you would like to encode your message in
NYUAD.bmp
 
Enter the secret message
This is a computer programming for engineers
 
Enter a name for the file with the encoded message
Newnyuad.bmp
 
(back to the main menu)
Enter the choice of encoding, decoding, or exit
Enter '1' for encoding
Enter '2' for decoding
Or enter '0' to exit
 
2(for decoding)
 
Enter the name of the file with the encoded message
Newnyuad.bmp
 
The secret message is:
Each pixel of the image contains three channels, Red, Green and Blue.
(back to the main menu)
 
Enter the choice of encoding, decoding, or exit
Enter '1' for encoding
Enter '2' for decoding
Or enter '0' to exit
(When the user enters ‘0’, the program exits)


The outcome: 
![Screen Shot 2024-03-05 at 8 04 36 AM](https://github.com/mariabenhammouda/EncodeXtract/assets/102983688/8c67fdb4-e390-4a66-afbb-49dd9a075dd3)

