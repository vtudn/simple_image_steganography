#include <iostream>
#include <fstream>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

bool isBitSet(char ch, int pos)
{
	// 7 6 5 4 3 2 1 0
	ch = ch >> pos;
	if (ch & 1)
		return true;
	return false;
}

int main(int argc, char **argv)
{
	// ./encode image.png textfile.txt output_image.png
	// argv[0] = ./encode
	if (argc != 4)
	{
		cout << "Arguments Error"
			 << "\n";
		exit(-1);
	}
	// argv[1] = image.png
	Mat image = imread(argv[1]);
	if (image.empty())
	{
		cout << "Image Error\n";
		exit(-1);
	}
	// argv[2] = textfile.txt
	ifstream file(argv[2]);
	if (!file.is_open())
	{
		cout << "Message Error\n";
		exit(-1);
	}
	// encoding process
	char ch;
	file.get(ch);
	int bit_count = 0;
	bool last_null_char = false;
	bool encoded = false;
	for (int row = 0; row < image.rows; row++)
	{
		for (int col = 0; col < image.cols; col++)
		{
			for (int color = 0; color < 3; color++)
			{
				Vec3b pixel = image.at<Vec3b>(Point(row, col));
				if (isBitSet(ch, 7 - bit_count))
					pixel.val[color] |= 1;
				else
					pixel.val[color] &= ~1;
				image.at<Vec3b>(Point(row, col)) = pixel;
				bit_count++;
				if (last_null_char && bit_count == 8)
				{
					encoded = true;
					goto OUT;
				}
				if (bit_count == 8)
				{
					bit_count = 0;
					file.get(ch);
					if (file.eof())
					{
						last_null_char = true;
						ch = '\0';
					}
				}
			}
		}
	}
OUT:;
	if (!encoded)
	{
		cout << "Message Error: too much content!\n";
		exit(-1);
	}
	// argv[3] = output_image.png
	imwrite(argv[3], image);
	return 0;
}
