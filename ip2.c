#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>


using namespace std;
using namespace cv;

int main()
{
  Mat img = imread("lena.jpg",1);
  Mat img1(img.rows, img.cols,CV_8UC3,Scalar(0,0,0));
  for(int i=0;i<img.rows;i++)
  {
    for(int j=0;j<img.cols;j++)
    {

      img1.at<Vec3b>(i,j)= img.at<Vec3b>(img.rows -i-1,j);
      // img1.at<Vec3b>(i,img.cols+j-1) = img.at<Vec3b>(i,img.cols-j-1);
    }
  }
    namedWindow("win",WINDOW_NORMAL);
    imshow("win",img1);
    waitKey(0);
    return 0;
}
