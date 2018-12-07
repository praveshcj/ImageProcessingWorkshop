#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>


using namespace std;
using namespace cv;

Mat img = imread("Capture.jpg",1);

// int Max(int a,int b,int c);
// int Min(int a,int b,int c);
Mat a(img.rows, img.cols,CV_8UC1,Scalar(0));
Mat b(img.rows, img.cols,CV_8UC3,Scalar(0,0,0));

// Mat img = imread("lena.jpg",1);
int ru,rl,bl,bu,gl,gu;
void update(int t,void *)
{
  // Mat a(img.rows, img.cols,CV_8UC3,Scalar(0,0,0));
  for(int i=0;i<img.rows;i++)
  {
    for(int j=0;j<img.cols;j++)
    {
      // c.at<uchar>(i,j)= (img.at<Vec3b>(i,j)[0]*0.07+img.at<Vec3b>(i,j)[1]*0.72+img.at<Vec3b>(i,j)[2]*0.21);

      // b.at<uchar>(i,j) = (Max(img.at<Vec3b>(i,j)[0],img.at<Vec3b>(i,j)[1],img.at<Vec3b>(i,j)[2])
      // if()
      // {
      //
      //   a.at<Vec3b>(i,j)[0]= 255;
      // }// +Min(img.at<Vec3b>(i,j)[0],img.at<Vec3b>(i,j)[1],img.at<Vec3b>(i,j)[2]))/2;
      // else
      // {
      //   a.at<Vec3b>(i,j)[0]= 0;
      // }
      if(img.at<Vec3b>(i,j)[0]>bl && img.at<Vec3b>(i,j)[0]<bu && img.at<Vec3b>(i,j)[1]>gl && img.at<Vec3b>(i,j)[1]<gu && img.at<Vec3b>(i,j)[2]>rl && img.at<Vec3b>(i,j)[2]<ru)
      {
        a.at<uchar>(i,j)= 255;
      }// +Min(img.at<Vec3b>(i,j)[0],img.at<Vec3b>(i,j)[1],img.at<Vec3b>(i,j)[2]))/2;
      else
      {
        a.at<uchar>(i,j)= 0;
      }
      // if()
      // {
      //   a.at<Vec3b>(i,j)[2]= 255;
      // }// +Min(img.at<Vec3b>(i,j)[0],img.at<Vec3b>(i,j)[1],img.at<Vec3b>(i,j)[2]))/2;
      // else
      // {
      //   a.at<Vec3b>(i,j)[2]= 0;
      // }
    }
  }
  imshow("win",a);
}
int main()
{
  ru=0,rl=0,bl=0,bu=0,gl=0,gu=0;
  namedWindow("win",WINDOW_NORMAL);
  resizeWindow("win", 1000,1000);
  // namedWindow("win1",CV_WINDOW_NORMAL);
  // namedWindow("win2",CV_WINDOW_NORMAL);
  createTrackbar("BlueL","win",&bl,255,update);
  createTrackbar("BlueU","win",&bu,255,update);
  createTrackbar("GreenL","win",&gl,255,update);
  createTrackbar("GreenU","win",&gu,255,update);
  createTrackbar("RedL","win",&rl,255,update);
  createTrackbar("RedU","win",&ru,255,update);
  // imshow("win",a);
  waitKey(0);
}
