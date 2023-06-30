# simple_image_steganography

**SCENARIO**: Steganography is a technique for hiding secret information by enclosing it in a regular, nonsecret file or communication and the information is extracted at the intended location, thus avoiding detection. In this work, a simple tool for image steganography is experimented. This tool uses the the Least Significant Bit (LSB) algorithm.

**HOW IT WORKS**: 

For example, we have a red pixel RGB(255,0,0) with the 8-bit value of each colour is 11111111, 00000000 and 00000000 respectively and a letter B with 8-bit value is 01000010. Now, we will replace 2 LSB of the 8-bit value of each colour by 2 MSB of the B character by from left to right. In the example above, after replacing, the 8-bit colours will have the values of 00000001, 00000000 and 00000000 respectively. The 8-bit value of letter B still has 10 but it will replace the next red pixel’s 8-bit value. That is how our tool encodes the message into an image. For decoding, we will just need to reverse the process.

**INSTALLATION**:

For this tool to work, the installation of OpenCV library is required.
- Linux: https://docs.opencv.org/4.x/d7/d9f/tutorial_linux_install.html
- Windows: https://docs.opencv.org/4.x/d3/d52/tutorial_windows_install.html

Folder arrangment:
- Place your picture inside ’source code/ImageSteganography/image’ folder.
- Place your text inside ’source code/ImageSteganography/message’ folder.
