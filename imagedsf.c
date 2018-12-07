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
int th =200;
Mat a(th,th,CV_8UC1,Scalar(0));
// Mat b(k,k,CV_8UC1,Scalar(0));


int isValid(int i, int j)
{
  if(i>=0&&i<th&&j>=0&&j<th)return 1;
  else return 0;
}

int randfourdigitgen(int k)
{
  int num=0;
  int count=0;
  int flag[k];
  for(int i=0;i<k;i++)
  {
    flag[i]=0;
  }
  srand(time(NULL));
  while(count<k)
  {

    int rand1 = rand() %k;
    if(flag[rand1]==0)
    {
      num = 10*num + rand1;
      count++;
      flag[rand1]=1;
    }
  }
  return num;
}

// int stackshow(stack <point> s)
// {
//     for(int i=0;i)
// }



int main()
{
  // int a = randfourdigitgen();

  stack <point> s,sc;
  // point new1;
  namedWindow("win",WINDOW_NORMAL);
  // resizeWindow("win",9,9);
  point one;
  one.x =1;
  one.y=1;
  s.push(one);
  a.at<uchar>(1,1)=255;

  while(!s.empty())
  {
    point new1 = s.top();
    s.pop();
    cout<<s.top().x<<" "<<s.top().y<<"\n";

    point arr[9];
    int count=0;

    for(int i=-1;i<2;i++)
    {
      for(int j=-1;j<2;j++)
      {
        if(i==0||j==0)
        {
          point new2 ;
          new2.x= new1.x+3*i;
          new2.y = new1.y +3*j;
          if(isValid(new2.x,new2.y))
          {
            if(a.at<uchar>(new2.x,new2.y) ==0)
            {
              //
              arr[count] = new2;
              count++;
               // s.push(new2);
              // cout<<s.top().x<<" "<<s.top().y<<"\n";
              // cout<<(int)a.at<uchar>(s.top().x,s.top().y)<<'\n';
            }
          }
       }
     }
   }

   int rand1 = randfourdigitgen(count);
   cout<<"Random Dig: "<<rand1<<'\n';
   for(int key=0;key<count;key++)
        {
          int randdig = rand1%10;
          rand1 =rand1/10;
          // a.at<uchar>(arr[randdig].x,arr[randdig].y) =255;
          s.push(arr[randdig]);


      point new3 = arr[randdig];
      if(new3.x ==new1.x)
      {
        if(new3.y>new1.y)
        {
          // a.at<uchar>(new1.y+1,new1.x) = 255;
          for(int k=new1.y;k<=new3.y;k++)
          {
            a.at<uchar>(new1.x,k) = 255;
          }
        }
        else
        {
          for(int k=new3.y;k<=new1.y;k++)
          {
            a.at<uchar>(new1.x,k) = 255;
          }
        }

      }
      if(new3.y==new1.y)
      {
        if(new3.x>new1.x)
        {
          // a.at<uchar>(new1.y+1,new1.x) = 255;
          for(int k=new1.x;k<=new3.x;k++)
          {
            a.at<uchar>(k,new1.y) = 255;
          }
        }
        else
        {
          for(int k=new3.x;k<=new1.x;k++)
          {
            a.at<uchar>(k,new1.y) = 255;
          }
        }
    }
     }
     imshow("win",a);
     waitKey(1);
     cout<<s.size()<<'\n';

    }
    imshow("win",a);
    waitKey(0);
}
