#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>


using namespace std;
using namespace cv;

Mat img = imread("dilated.jpg",0);

Mat a(img.rows,img.cols,CV_8UC1,Scalar(0));
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
int check(int a, int b, int c, int d, int e,int f, int g, int h,int i)
{
  if(a==255||b==255||c==255||d==255|e==255||f==255||g==255||h==255||i==255)return 255;
  else return 0;
}

int main()
{
  for(int i=1;i<img.rows-1;i++)
  {
    for(int j=1;j<img.cols-1;j++)
    {
        a.at<uchar>(i,j) = check(img.at<uchar>(i-1,j-1),img.at<uchar>(i,j),img.at<uchar>(i-1,j),img.at<uchar>(i-1,j+1),img.at<uchar>(i,j-1),img.at<uchar>(i,j+1),img.at<uchar>(i+1,j-1),img.at<uchar>(i+1,j),img.at<uchar>(i+1,j+1));
    }
  }
  //
  // for(int i=1;i<img.rows-1;i++)
  // {
  //   for(int j=1;j<img.cols-1;j++)
  //   {
  //       a.at<uchar>(i,j) = (a.at<uchar>(i-1,j-1)+a.at<uchar>(i-1,j)+a.at<uchar>(i-1,j+1)+a.at<uchar>(i,j-1)+a.at<uchar>(i,j+1)+a.at<uchar>(i+1,j-1)+a.at<uchar>(i+1,j)+a.at<uchar>(i+1,j+1))/8;
  //   }
  // }
  namedWindow("win",WINDOW_NORMAL);
  resizeWindow("win", 1000,1000);
  imshow("win",a);

  waitKey(0);
  // imwrite( "dilated.jpg",a);
}
