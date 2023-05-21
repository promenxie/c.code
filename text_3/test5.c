//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>

//typedef struct item
//{
//	int num; //页号
//	int time; //等待时间，LRU算法会用到这个属性
//}Pro;
//int pageNum; //系统分配给作业的主存中的页面数
//int memoryNum; //可用内存页面数
//
////打印当前的页面
//void print(Pro* memory1)
//{
//	int j;
//	for (j = 0; j < memoryNum; j++)
//		printf("    %d\t\t\t", memory1[j].num);
//	printf("\n————————————————————————————————————————————————————————\n");
//}
////在页面集memory1中查找num1，如果找到，返回其在memory1中的下标，否则返回-1
//int Search(int num1, Pro* memory) {
//	int j;
//	for (j = 0; j < memoryNum; j++)
//	{
//		if (num1 == memory[j].num)
//			return j;
//
//	}
//
//	return -1;
//}
////最近最久未使用页号
//int Max(Pro* memory1) {
//	int max = 0;
//	int i; 
//	for (i = 1; i < memoryNum; i++)
//	{
//		if (memory1[i].time > memory1[max].time)
//			max = i;
//	}
//
//	return max;
//}
////未来最久不会访问页号
//int Optimal(int tag, Pro* memory1, Pro* page1) {
//	int i;
//	int	j;
//	int n;
//	int max = 0;
//	int* min = (int*)malloc(memoryNum*4);
//	for (i = 0; i < memoryNum; i++)
//	{
//		n = tag;
//		do
//		{
//			n++;
//			if (n > pageNum)
//				break;
//			
//		}
//		while (page1[n].num != memory1[i].num);
//		min[i] = n;
//	}
//	for(j = 1; j < memoryNum; j++)
//	{
//		if (min[j] > min[max])
//			max = j;
//	}
//
//	return max;
//}
////FIFO置换算法
//void FIFO(Pro* page, Pro* memory) {
//	int i = 0;
//	int curmemory = 0;//调入主存中的页面个数
//	int missNum = 0;//缺页次数
//	float missRate;//缺页率
//	printf("FIFO页面置换情况:\n");
//	printf("置换的页面号\t\t");
//	for (i = 0; i < memoryNum; i++)
//		printf("物理块号%d\t\t", i + 1);
//	printf("\n————————————————————————————————————————————————————————\n");
//	for (i = 0; i < pageNum; i++)
//	{
//		if (Search(page[i].num, memory) < 0)//若在主存中没有找到该页面
//		{
//			if (memory[curmemory].num > -1)
//			{
//				printf("      %d\t\t\t", memory[curmemory].num);
//			}
//			else
//			{
//				printf("      -\t\t\t");
//			}
//			missNum++;
//			memory[curmemory].num = page[i].num;
//			print(memory);
//			curmemory = (curmemory + 1) % memoryNum;
//		}//endfor	
//	}
//	missRate = (float)missNum / pageNum;
//	printf("缺页次数：%d  缺页率:%f  命中率:%f\n", missNum, missRate, 1-missRate);
//}
////OPT置换算法
//void OPT(Pro* page, Pro* memory) {
//	int i = 0;
//	int n; //要进行置换的内存号
//	int curmemory = 0;//调入主存中的页面个数
//	int missNum = 0;//缺页次数
//	float missRate;//缺页率
//	printf("OPT页面置换情况:\n");
//	printf("置换的页面号\t\t");
//	for (i = 0; i < memoryNum; i++)
//		printf("物理块号%d\t\t", i + 1);
//	printf("\n————————————————————————————————————————————————————————\n");
//	for (i = 0; i < pageNum; i++)
//	{
//		if (Search(page[i].num, memory) < 0)//若在主存中没有找到该页面
//		{
//			if (curmemory < memoryNum)
//			{
//				printf("      -\t\t\t");
//				memory[curmemory++].num = page[i].num;
//			}
//			else
//			{
//				n = Optimal(i, memory, page);
//				printf("      %d\t\t\t", memory[n].num);
//				memory[n].num = page[i].num;
//			}
//			print(memory);
//			missNum++;
//		}
//	}
//	missRate = (float)missNum / pageNum;
//	printf("缺页次数：%d  缺页率:%f  命中率:%f\n", missNum, missRate, 1-missRate);
//}
////LRU置换算法
//void LRU(Pro* page, Pro* memory) {
//	int i = 0;
//	int j = 0;
//	int n; //要进行置换的内存号
//	int curmemory = 0;//调入主存中的页面个数
//	int missNum = 0;//缺页次数
//	float missRate;//缺页率
//	printf("LRU页面置换情况:\n");
//	printf("置换的页面号\t\t");
//	for (i = 0; i < memoryNum; i++)
//		printf("物理块号%d\t\t", i + 1);
//	printf("\n————————————————————————————————————————————————————————\n");
//	for (i = 0; i < pageNum; i++)
//	{
//		for (j = 0; j < memoryNum; j++)
//		{
//			if(memory[j].num>=0)
//				memory[j].time++;
//		}
//		if (Search(page[i].num, memory) < 0)//若在主存中没有找到该页面
//		{
//			if (curmemory < memoryNum)
//			{
//				printf("      -\t\t\t");
//				memory[curmemory++] = page[i];
//			}
//			else
//			{
//				n = Max(memory);
//				printf("      %d\t\t\t", memory[n].num);
//				memory[n] = page[i];
//			}
//			print(memory);
//			missNum++;
//		}
//		else
//		{
//			n = Search(page[i].num, memory);
//			memory[n].time = 0;
//		}
//	}
//	missRate = (float)missNum / pageNum;
//	printf("缺页次数：%d  缺页率:%f  命中率:%f\n", missNum, missRate, 1-missRate);
//}
////主函数 
//int main() {
//	int i;
//	int c;//得到用户的输入，来选择相应的置换算法
//	Pro* page;//作业页面集
//	Pro* memory;//内存页面集
//	printf("页面置换算法  @作者；谢大龙\n"); 
//	printf("输入系统分配给作业的主存中的页面数:");
//	scanf("%d", &pageNum);
//	printf("输入内存页面数:");
//	scanf("%d", &memoryNum);
//	page = (Pro*)malloc(sizeof(Pro) * pageNum);
//	memory = (Pro*)malloc(sizeof(Pro) * memoryNum);
//	for (i = 0; i < pageNum; i++)
//	{
//		printf("第%02d个页面号为:", i);
//		scanf("%d", &page[i].num);
//		page[i].time = 0;//等待时间开始默认为0
//	}
//	do
//	{
//		for (i = 0; i < memoryNum; i++)//初始化内存中页面
//		{
//			memory[i].num = -1;//页面为空用-1表示
//			memory[i].time = -1;//页面为空用-1表示
//		}
//		printf("*****1:FIFO页面置换*****谢******\n");
//		printf("*****2:OPT页面置换********大****\n");
//		printf("*****3:LRU页面置换**********龙**\n");
//		printf("*****请选择操作类型(1,2,3),按其它键结束******\n");
//		if(scanf("%d", &c) == 1);
//			break;
//		switch (c)
//		{
//		case 1: FIFO(page, memory); break;
//		case 2: OPT(page, memory); break;
//		case 3: LRU(page, memory); break;
//		}
//	} while (c == 1 || c == 2 || c == 3);
//
//	return 0;
//}
