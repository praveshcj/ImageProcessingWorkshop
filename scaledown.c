#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>


using namespace std;
using namespace cv;

Mat img = imread("lenasalt.png",0);

Mat a(img.rows/3,img.cols/3,CV_8UC1,Scalar(0));
int median(int a, int b, int c, int d, int e,int f, int g, int h,int i)
{
  int arr[9];
  arr[0] = a;
  arr[1] = b;
  arr[2] =c;
  arr[3] =d;
  arr[4] =e;
  arr[5] =f;
  arr[6] = g;
  arr[7] =h;
  arr[8] =i;
  sort(arr, arr+9);
  return (arr[4]);
}



int main()
{
  for(int i=1;i<img.rows;i=i+3)
  {
    for(int j=1;j<img.cols;j=j+3)
    {
      a.at<uchar>(i/3,j/3) = median(img.at<uchar>(i-1,j-1),img.at<uchar>(i,j),img.at<uchar>(i-1,j),img.at<uchar>(i-1,j+1),img.at<uchar>(i,j-1),img.at<uchar>(i,j+1),img.at<uchar>(i+1,j-1),img.at<uchar>(i+1,j),img.at<uchar>(i+1,j+1));

    }
  }
    namedWindow("win",WINDOW_AUTOSIZE);
    // resizeWindow("win", 1000,1000);
    imshow("win",a);

    waitKey(0);
    imwrite( "scaledown.jpg",a);
  }
