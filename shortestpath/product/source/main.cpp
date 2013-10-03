/******************************************************************************

                  版权所有 (C), 2010-2020, 脑袋空空技术有限公司

 ******************************************************************************
  文 件 名   : main.cpp
  版 本 号   : 初稿
  作    者   : ndkk
  生成日期   : 2013年10月3日
  最近修改   :
  功能描述   :  广度优先算法
                本例采用广度优先算法进行计算
                找到从(0,0)到(4,4)的最短路径
                灰集合 黑集合
                找到顶点 -> 相邻点 -> 再相邻点 -> 终点 -> 反向追溯
  函数列表   :
              main
  修改历史   :
  1.日    期   : 2013年10月3日
    作    者   : ndkk
    修改内容   : 创建文件

******************************************************************************/

#include <stdio.h>
#include <memory.h>
#include <set>
#include <list>
#include <assert.h>
using namespace std;

#include "shortestpath.h"

static const int in_map[3][10] = 
{
    0,1,0,0,0,0,0,0,0,1,  
    0,1,0,1,0,1,1,1,0,1,
    0,0,0,0,1,1,1,1,0,0,    
};

int main()
{
    CShortestPath sPath;
    ST_PT bPt(0,0);
    ST_PT ePt(2,9);
    sPath.SetBeginPoint(bPt);
    sPath.SetEndPoint(ePt);        
    int **ppMap = new int*[MAX_X];
    for (int i = 0; i < MAX_X; i++)
    {        
        int *pMap = new int[MAX_Y];        
        for (int j = 0; j < MAX_Y; j++)
        {
            pMap[j] = in_map[i][j];            
        }
        ppMap[i] = pMap;
    }
    
    sPath.SetMap(MAX_X, MAX_Y, ppMap);
    sPath.DoService();
    sPath.ShowResult();
    
    //释放内存
    for (int m = 0; m < MAX_X; m++)
    {
        delete[] ppMap[m];
    }
    delete[] ppMap;
    
    return 0;
}