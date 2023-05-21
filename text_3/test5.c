//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct item
//{
//	int num; //ҳ��
//	int time; //�ȴ�ʱ�䣬LRU�㷨���õ��������
//}Pro;
//int pageNum; //ϵͳ�������ҵ�������е�ҳ����
//int memoryNum; //�����ڴ�ҳ����
//
////��ӡ��ǰ��ҳ��
//void print(Pro* memory1)
//{
//	int j;
//	for (j = 0; j < memoryNum; j++)
//		printf("    %d\t\t\t", memory1[j].num);
//	printf("\n����������������������������������������������������������������������������������������������������������������\n");
//}
////��ҳ�漯memory1�в���num1������ҵ�����������memory1�е��±꣬���򷵻�-1
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
////������δʹ��ҳ��
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
////δ����ò������ҳ��
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
////FIFO�û��㷨
//void FIFO(Pro* page, Pro* memory) {
//	int i = 0;
//	int curmemory = 0;//���������е�ҳ�����
//	int missNum = 0;//ȱҳ����
//	float missRate;//ȱҳ��
//	printf("FIFOҳ���û����:\n");
//	printf("�û���ҳ���\t\t");
//	for (i = 0; i < memoryNum; i++)
//		printf("������%d\t\t", i + 1);
//	printf("\n����������������������������������������������������������������������������������������������������������������\n");
//	for (i = 0; i < pageNum; i++)
//	{
//		if (Search(page[i].num, memory) < 0)//����������û���ҵ���ҳ��
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
//	printf("ȱҳ������%d  ȱҳ��:%f  ������:%f\n", missNum, missRate, 1-missRate);
//}
////OPT�û��㷨
//void OPT(Pro* page, Pro* memory) {
//	int i = 0;
//	int n; //Ҫ�����û����ڴ��
//	int curmemory = 0;//���������е�ҳ�����
//	int missNum = 0;//ȱҳ����
//	float missRate;//ȱҳ��
//	printf("OPTҳ���û����:\n");
//	printf("�û���ҳ���\t\t");
//	for (i = 0; i < memoryNum; i++)
//		printf("������%d\t\t", i + 1);
//	printf("\n����������������������������������������������������������������������������������������������������������������\n");
//	for (i = 0; i < pageNum; i++)
//	{
//		if (Search(page[i].num, memory) < 0)//����������û���ҵ���ҳ��
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
//	printf("ȱҳ������%d  ȱҳ��:%f  ������:%f\n", missNum, missRate, 1-missRate);
//}
////LRU�û��㷨
//void LRU(Pro* page, Pro* memory) {
//	int i = 0;
//	int j = 0;
//	int n; //Ҫ�����û����ڴ��
//	int curmemory = 0;//���������е�ҳ�����
//	int missNum = 0;//ȱҳ����
//	float missRate;//ȱҳ��
//	printf("LRUҳ���û����:\n");
//	printf("�û���ҳ���\t\t");
//	for (i = 0; i < memoryNum; i++)
//		printf("������%d\t\t", i + 1);
//	printf("\n����������������������������������������������������������������������������������������������������������������\n");
//	for (i = 0; i < pageNum; i++)
//	{
//		for (j = 0; j < memoryNum; j++)
//		{
//			if(memory[j].num>=0)
//				memory[j].time++;
//		}
//		if (Search(page[i].num, memory) < 0)//����������û���ҵ���ҳ��
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
//	printf("ȱҳ������%d  ȱҳ��:%f  ������:%f\n", missNum, missRate, 1-missRate);
//}
////������ 
//int main() {
//	int i;
//	int c;//�õ��û������룬��ѡ����Ӧ���û��㷨
//	Pro* page;//��ҵҳ�漯
//	Pro* memory;//�ڴ�ҳ�漯
//	printf("ҳ���û��㷨  @���ߣ�л����\n"); 
//	printf("����ϵͳ�������ҵ�������е�ҳ����:");
//	scanf("%d", &pageNum);
//	printf("�����ڴ�ҳ����:");
//	scanf("%d", &memoryNum);
//	page = (Pro*)malloc(sizeof(Pro) * pageNum);
//	memory = (Pro*)malloc(sizeof(Pro) * memoryNum);
//	for (i = 0; i < pageNum; i++)
//	{
//		printf("��%02d��ҳ���Ϊ:", i);
//		scanf("%d", &page[i].num);
//		page[i].time = 0;//�ȴ�ʱ�俪ʼĬ��Ϊ0
//	}
//	do
//	{
//		for (i = 0; i < memoryNum; i++)//��ʼ���ڴ���ҳ��
//		{
//			memory[i].num = -1;//ҳ��Ϊ����-1��ʾ
//			memory[i].time = -1;//ҳ��Ϊ����-1��ʾ
//		}
//		printf("*****1:FIFOҳ���û�*****л******\n");
//		printf("*****2:OPTҳ���û�********��****\n");
//		printf("*****3:LRUҳ���û�**********��**\n");
//		printf("*****��ѡ���������(1,2,3),������������******\n");
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
