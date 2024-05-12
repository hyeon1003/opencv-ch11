//11-2 1��

/*#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main(void)
{
   Mat Morp_Rect = getStructuringElement(MORPH_RECT, Size(3, 3));
   Mat Morp_Croos = getStructuringElement(MORPH_CROSS, Size(3, 3));
   Mat Morp_ELL = getStructuringElement(MORPH_ELLIPSE, Size(5, 3));
   cout << "MORPH_RECT" << endl;
   cout << Morp_Rect << endl;
   cout << "MORPH_CROSS" << endl;
   cout << Morp_Croos << endl;
   cout << "MORPH_ELLIPSE" << endl;
   cout << Morp_ELL << endl;
   return 0;
}*/

//11-2 2��
/*#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main(void)
{
	Mat src = imread("letterj.png");
	Mat dst;
	cvtColor(src, dst, COLOR_BGR2GRAY);
	Mat filter = getStructuringElement(MORPH_RECT, Size(3, 3));
	Mat bin,ero;
	threshold(dst, bin,100, 255, THRESH_BINARY);
	imshow("src", src);
	imshow("bin", bin);
	morphologyEx(bin, ero, MORPH_OPEN, filter);
	morphologyEx(ero, ero, MORPH_CLOSE, filter);
	imshow("erode", ero);
	waitKey();
	return 0;
}*/

//11-2 3��
/*#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main(void)
{
	Mat src = imread("letterj2.png");
	if (src.empty()) { cerr << "image load failed" << endl; return -1; }
	Mat dst,bin,edge;
	Mat filter = getStructuringElement(MORPH_RECT, Size(2,2));//����ũ�� ���� ������ �����ϱ� ���� ����� 2*2�� ���� 3*3���� �ϸ� ������ �β���
	cvtColor(src, dst, COLOR_BGR2GRAY);//�׷��̷� ��ȯ
	imshow("src", src);
	threshold(dst, bin, 100, 255, THRESH_BINARY);//����ȭ
	imshow("bin", bin);
	morphologyEx(bin, edge, MORPH_CLOSE, filter,Point(-1,-1),3);//close ������ ����Ͽ� ħ���Ͽ� ��踦 ��Ƴ��� ��â������ �Ͽ� ��踦 �ٽ� Ȯ���Ѵ�.
	morphologyEx(edge, edge, MORPH_GRADIENT, filter);//�׷����Ʈ ������ �Ͽ� �����κ��� ����
	imshow("edge", edge);
	waitKey();
	return 0;
}*/
//11-2 4��
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main(void)
{
   Mat src = imread("car.png",IMREAD_GRAYSCALE);
   if (src.empty()) { cerr << "image load failed" << endl; return -1; }
   blur(src, src, Size(5, 5), Point(-1, -1));
   Mat dx;
   Sobel(src, dx,-1, 1, 0);
   Mat inv,close;
   threshold(dx, inv,120,255, THRESH_BINARY);
   Mat kerneal = getStructuringElement(MORPH_RECT, Size(30,5));
   morphologyEx(inv,close, MORPH_CLOSE, kerneal);
   imshow("src", src);
   imshow("x�� ����Һ�",dx);
   imshow("����ȭ ����", inv);
   imshow("�ݱ⿵��", close);
   waitKey();
   return 0;
}