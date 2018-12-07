#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>


using namespace std;
using namespace cv;

Mat img = imread("logobat.jpg",0);

Mat a(img.rows,img.cols,CV_8UC1,Scalar(255));
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
int check(int i, int j)
{
  if(i>0&&i<img.rows-1&&j>0&&j<img.cols-1)return 1;
  else return 0;
}
void update(int t,void *)
{

  float gx=0,gy=0;
  for(int i=1;i<img.rows-1;i++)
  {
    for(int j=1;j<img.cols-1;j++)
    {
        gx = (img.at<uchar>(i-1,j-1)*(-1)+img.at<uchar>(i-1,j+1)+img.at<uchar>(i+1,j-1)*(-1)+img.at<uchar>(i,j-1)*(-2)+img.at<uchar>(i+1,j+1)+img.at<uchar>(i,j+1)*2)/8;
        gy = (img.at<uchar>(i-1,j-1)*(-1)+img.at<uchar>(i-1,j+1)*(-1) +img.at<uchar>(i-1,j)*(-2)+img.at<uchar>(i+1,j-1)+img.at<uchar>(i+1,j)*2+img.at<uchar>(i+1,j+1))/8;
        if(sqrt(gx*gx+gy*gy)>t)
        {
          a.at<uchar>(i,j) = 0;
        }
        else
        {
          a.at<uchar>(i,j) = 255;

        }
    }
  }
  imshow("win",a);
}

int main()
{
  // for(int i=1;i<img.rows-1;i++)
  // {
  //   for(int j=1;j<img.cols-1;j++)
  //   {
  //       a.at<uchar>(i,j) = median(img.at<uchar>(i-1,j-1),img.at<uchar>(i,j),img.at<uchar>(i-1,j),img.at<uchar>(i-1,j+1),img.at<uchar>(i,j-1),img.at<uchar>(i,j+1),img.at<uchar>(i+1,j-1),img.at<uchar>(i+1,j),img.at<uchar>(i+1,j+1));
  //   }
  // }
  VideoCapture cap(0); // open the default camera
      if(!cap.isOpened())  // check if we succeeded
          return -1;

      Mat edges;
      namedWindow("frame",1);
      for(;;)
      {
          Mat frame;
          cap >> frame;
          Mat img = frame; // get a new frame from camera
          // cvtColor(frame, edges, COLOR_BGR2GRAY);
          // GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
          // Canny(edges, edges, 0, 30, 3);
          Mat a(frame.rows,frame.cols,CV_8UC1,Scalar(0));
          for(int i=0;i<img.rows;i++)
          {
            for(int j=0;j<img.cols;j++)
            {
            if(img.at<Vec3b>(i,j)[0]>35 && img.at<Vec3b>(i,j)[0]<110 && img.at<Vec3b>(i,j)[1]>147 && img.at<Vec3b>(i,j)[1]<237 && img.at<Vec3b>(i,j)[2]>143 && img.at<Vec3b>(i,j)[2]<227)
            {
              a.at<uchar>(i,j)= 255;
            }// +Min(img.at<Vec3b>(i,j)[0],img.at<Vec3b>(i,j)[1],img.at<Vec3b>(i,j)[2]))/2;
            else
            {
              a.at<uchar>(i,j)= 0;
            }
            }
          }
          imshow("a",a);
          waitKey(30);
          // if(waitKey(30)>=0)
          // {
          //   imwrite("Capture.jpg",frame);
          //   break;
          // }
      }
  int t;
  t=0;
  // namedWindow("win",WINDOW_NORMAL);
  // resizeWindow("win", 1000,1000);
  // // imshow("win",a);
  // // waitKey(0);
  //
  // createTrackbar("Bar","win",&t,255,update);
  // waitKey(0);
  //   imwrite( "edgedetected.jpg",a);
  return 0;
}
