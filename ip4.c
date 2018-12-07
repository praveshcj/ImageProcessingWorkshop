#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>


using namespace std;
using namespace cv;

Mat img = imread("lena.jpg",1);

// int Max(int a,int b,int c);
// int Min(int a,int b,int c);
Mat a(img.rows, img.cols,CV_8UC3,Scalar(0,0,0));

// Mat img = imread("lena.jpg",1);
void update(int t,void *)
{

  for(int i=0;i<img.rows;i++)
  {
    for(int j=0;j<img.cols;j++)
    {
      // c.at<uchar>(i,j)= (img.at<Vec3b>(i,j)[0]*0.07+img.at<Vec3b>(i,j)[1]*0.72+img.at<Vec3b>(i,j)[2]*0.21);
      // b.at<uchar>(i,j) = (Max(img.at<Vec3b>(i,j)[0],img.at<Vec3b>(i,j)[1],img.at<Vec3b>(i,j)[2])
      // +Min(img.at<Vec3b>(i,j)[0],img.at<Vec3b>(i,j)[1],img.at<Vec3b>(i,j)[2]))/2;
      a.at<Vec3b>(i,j)[0]= (img.at<Vec3b>(i,j)[0]<t)?0:255;
      // b.at<uchar>(i,j)= (b.at<uchar>(i,j)<t)?0:255;
      // c.at<uchar>(i,j)= (c.at<uchar>(i,j)<t)?0:255;

    }
  }
  imshow("win",a);
}
void update1(int t,void *)
{
  // Mat a(img.rows, img.cols,CV_8UC3,Scalar(0,0,0));
  for(int i=0;i<img.rows;i++)
  {
    for(int j=0;j<img.cols;j++)
    {
      // c.at<uchar>(i,j)= (img.at<Vec3b>(i,j)[0]*0.07+img.at<Vec3b>(i,j)[1]*0.72+img.at<Vec3b>(i,j)[2]*0.21);
      // b.at<uchar>(i,j) = (Max(img.at<Vec3b>(i,j)[0],img.at<Vec3b>(i,j)[1],img.at<Vec3b>(i,j)[2])
      // +Min(img.at<Vec3b>(i,j)[0],img.at<Vec3b>(i,j)[1],img.at<Vec3b>(i,j)[2]))/2;
      a.at<Vec3b>(i,j)[1]= (img.at<Vec3b>(i,j)[1]<t)?0:255;
      // b.at<uchar>(i,j)= (b.at<uchar>(i,j)<t)?0:255;
      // c.at<uchar>(i,j)= (c.at<uchar>(i,j)<t)?0:255;

    }
  }
  imshow("win",a);
}
void update2(int t,void *)
{ 
  // Mat a(img.rows, img.cols,CV_8UC3,Scalar(0,0,0));
  for(int i=0;i<img.rows;i++)
  {
    for(int j=0;j<img.cols;j++)
    {
      // c.at<uchar>(i,j)= (img.at<Vec3b>(i,j)[0]*0.07+img.at<Vec3b>(i,j)[1]*0.72+img.at<Vec3b>(i,j)[2]*0.21);
      // b.at<uchar>(i,j) = (Max(img.at<Vec3b>(i,j)[0],img.at<Vec3b>(i,j)[1],img.at<Vec3b>(i,j)[2])
      // +Min(img.at<Vec3b>(i,j)[0],img.at<Vec3b>(i,j)[1],img.at<Vec3b>(i,j)[2]))/2;
      a.at<Vec3b>(i,j)[2]= (img.at<Vec3b>(i,j)[2]<t)?0:255;
      // b.at<uchar>(i,j)= (b.at<uchar>(i,j)<t)?0:255;
      // c.at<uchar>(i,j)= (c.at<uchar>(i,j)<t)?0:255;

    }
  }
  imshow("win",a);

}
int main()
{
  int t1,t2,t3;
  t1=0,t2=0,t3=0;
  namedWindow("win",CV_WINDOW_NORMAL);
  // namedWindow("win1",CV_WINDOW_NORMAL);
  // namedWindow("win2",CV_WINDOW_NORMAL);
  createTrackbar("Bar","win",&t1,255,update);
  createTrackbar("Bar1","win",&t2,255,update1);
  createTrackbar("Bar2","win",&t3,255,update2);
  // imshow("win",a);
  waitKey(0);
}
