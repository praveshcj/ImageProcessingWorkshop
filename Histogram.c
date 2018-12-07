#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>


using namespace std;
using namespace cv;

Mat img = imread("lenasalt.png",1);

Mat a(img.rows,img.cols,CV_8UC1,Scalar(0));

int check(int i, int j)
{
  if(i>0&&i<img.rows-1&&j>0&&j<img.cols-1)return 1;
  else return 0;
}

int main()
{
  float arr[256];
  for(int i =0;i<256;i++)
  {
    arr[i]=0;
  }
  for(int i=0;i<img.rows-1;i++)
  {
    for(int j=0;j<img.cols-1;j++)
    {
      arr[(int)img.at<uchar>(i,j)]= arr[(int)img.at<uchar>(i,j)] +0.1;
      cout<<(int)img.at<uchar>(i,j)<<"arr: "<<arr[(int)img.at<uchar>(i,j)]<<'\n';

    }
  }
  int height = img.rows*img.cols/100;
  Mat grph(height,256*8,CV_8UC1,Scalar(255));
  for(int j=0;j<grph.cols;j++)
  {
    for(int i=0;i<arr[j/8];i++)
    {
      grph.at<uchar>(height-i,j) = 0;
    }
  }
  cout<<"Printing the arrray now\n";
  for(int i =0;i<256*3;i++)
  {
    cout<<arr[i]<<'\n';
  }
  namedWindow("win",WINDOW_NORMAL);
  resizeWindow("win",256*3,1000);
  imshow("win",grph);
  waitKey(0);
}
