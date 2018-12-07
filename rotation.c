#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

float pi = 3.1415;
using namespace std;
using namespace cv;



Mat img = imread("rubik.jpg",0);
int r = (img.rows);
int c = (img.cols);
int k = 2*(sqrt(r*r +c*c));
Mat a(k,k,CV_8UC1,Scalar(0));
// Mat b(k,k,CV_8UC1,Scalar(0));


void update(int t,void*)
{
  Mat b(k,k,CV_8UC1,Scalar(0));

    for(int i=0;i<img.rows;i++)
    {
      for(int j=0;j<img.cols;j++)
      {
          b.at<uchar>(cos(t*pi/180)*(i)+k/2+sin(t*pi/180)*(j),cos(t*pi/180)*(j)-sin(t*pi/180)*(i)+k/2) = a.at<uchar>(i+k/2,j+k/2);
          // b.at<uchar>(i+k/2,j+k/2) =0;
      }
    }
    imshow("win",b);
}

int main()
{
  cout<<r<<' '<<c<<"\n";
  cout<<k;
  for(int i=k/2;i<img.rows+k/2;i++)
  {
    for(int j=k/2;j<img.cols+k/2;j++)
    {
      a.at<uchar>(i,j)= img.at<uchar>(i-k/2,j-k/2);
    }
  }
  int t;
  t=0;
  namedWindow("win",WINDOW_NORMAL);
  resizeWindow("win", 600,600);
  // imshow("win",a);
  // waitKey(0);

  createTrackbar("theta","win",&t,360,update);
  // createTrackbar("size","win",&bl,255,update);
  waitKey(0);
}
