#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>
#include <iostream>




using namespace std;
using namespace cv;

typedef struct
{
  int x;
  int y;
} point;


Mat img = imread("dfs_path.jpg",0);
// int r = (img.rows);
// int c = (img.cols);
// int k = 2*(sqrt(r*r +c*c));
Mat a(img.rows,img.cols,CV_8UC1,Scalar(255));
// Mat b(k,k,CV_8UC1,Scalar(0));


int isValid(int i, int j)
{
  if(i>=0&&i<img.rows&&j>=0&&j<img.cols)return 1;
  else return 0;
}


int main()
{
  queue <point> q;
  point new1;
  namedWindow("win",WINDOW_NORMAL);
  resizeWindow("win",1000,1000);
  int count=0;
  for(int i=0;i<img.rows;i++)
  {
    for(int j=0;j<img.cols;j++)
    {
      if(a.at<uchar>(i,j)==255)
      {
        if(img.at<uchar>(i,j)==255)
        {
          a.at<uchar>(i,j)= 0;
        }
        if(img.at<uchar>(i,j)==0)
        {
          a.at<uchar>(i,j)= 125;
          new1.x = i;
          new1.y=j;
          q.push(new1);
        }
        int flag =0;
        while(!q.empty())
        {
          flag =1;
          new1 =q.front();
          q.pop();
          for(int i=-1;i<=1;i++)
          {
            for(int j=-1;j<=1;j++)
            {
              if(isValid(new1.x+i,new1.y+j)==1)
              {
                if(a.at<uchar>(new1.x+i,new1.y+j)==255&&img.at<uchar>(new1.x+i,new1.y+j)==0)
                {
                  point new2;
                  new2.x = new1.x+i;
                  new2.y = new1.y+j;
                  q.push(new2);
                  a.at<uchar>(new1.x+i,new1.y+j)=125;
                }
              }
            }
          }
          }
          if(flag==1)count++;
      }

    }
  }
  printf("Count= %d\n",count);
  imshow("win",a);
  waitKey(0);

}
