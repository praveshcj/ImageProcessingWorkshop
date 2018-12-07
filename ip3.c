#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>


using namespace std;
using namespace cv;
int Max(int a,int b,int c);
int Min(int a,int b,int c);

int main()
{
  Mat img = imread("lena.jpg",1);
  Mat a(img.rows, img.cols,CV_8UC1,Scalar(0));
  Mat b(img.rows, img.cols,CV_8UC1,Scalar(0));
  Mat c(img.rows, img.cols,CV_8UC1,Scalar(0));
  for(int i=0;i<img.rows;i++)
  {
    for(int j=0;j<img.cols;j++)
    {
      a.at<uchar>(i,j)= (img.at<Vec3b>(i,j)[0]+img.at<Vec3b>(i,j)[1]+img.at<Vec3b>(i,j)[2])/3;
      c.at<uchar>(i,j)= (img.at<Vec3b>(i,j)[0]*0.07+img.at<Vec3b>(i,j)[1]*0.72+img.at<Vec3b>(i,j)[2]*0.21);
      b.at<uchar>(i,j) = (Max(img.at<Vec3b>(i,j)[0],img.at<Vec3b>(i,j)[1],img.at<Vec3b>(i,j)[2])
      +Min(img.at<Vec3b>(i,j)[0],img.at<Vec3b>(i,j)[1],img.at<Vec3b>(i,j)[2]))/2;
      a.at<uchar>(i,j)= (a.at<uchar>(i,j)<125)?0:255;
      b.at<uchar>(i,j)= (b.at<uchar>(i,j)<125)?0:255;
      c.at<uchar>(i,j)= (c.at<uchar>(i,j)<125)?0:255;

    }
  }
  namedWindow("win",WINDOW_NORMAL);
  imshow("win",a);
  namedWindow("win1",WINDOW_NORMAL);
  namedWindow("win2",WINDOW_NORMAL);
  imshow("win1",b);
  imshow("win2",c);

  waitKey(0);
  return 0;
}
int Max(int a,int b,int c)
{
  int temp =a;
  if(temp<b)temp=b;
  if(temp<c)temp =c;
  return temp;
}
int Min(int a,int b,int c)
{
  int temp =a;
  if(temp>b)temp=b;
  if(temp>c)temp =c;
  return temp;
}
