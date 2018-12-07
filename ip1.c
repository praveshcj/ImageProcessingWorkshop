#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>


using namespace std;
using namespace cv;

int main()
{
  Mat img(100,100,CV_8UC3,Scalar(0,0,0));
  for(int i=0;i<img.rows;i++)
  {
    for(int j=0;j<img.cols;j++)
    {
      if(i+j>99)
      {
        img.at<Vec3b>(i,j) = {0,0,255};
      }
      else if(i+j==99)
      {
        img.at<Vec3b>(i,j) = {0,255,255};
      }
      else
      {
        img.at<Vec3b>(i,j) = {0,255,0};

      }
    }
  }
  Mat img1(256,256,CV_8UC1,Scalar(0));
  for(int i=0;i<img1.rows;i++)
  {
    for(int j=0;j<img1.cols;j++)
    {
      if(((i/32+j/32))%2==0)
      {
        img1.at<uchar>(i,j) = 255;
      }
      else
      {
        img1.at<uchar>(i,j) = 0;
      }
    }
  }
  namedWindow("win",WINDOW_NORMAL);
  imshow("win",img);
  namedWindow("win1",WINDOW_NORMAL);
  imshow("win1",img1);
  imwrite("chessboard.jpg",img1);
  waitKey(0);
  return 0;
}
