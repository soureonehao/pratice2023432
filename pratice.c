#include<stdio.h>//ע��gets();������scanf���ã��������Ҫ��scanf�������getchar();
float rankmax(float figure1, float figure2) {
	if (figure1 > figure2)
		return figure1;
	else
		return figure2;
}
float rankmin(float figure1, float figure2) {
	if (figure1 < figure2)
		return figure1;
	else
		return figure2;
}
float rankM(float rank[]) {
	int i, j;
	float box;
	for (i = 0; i < 2; i++) {
		for(j = 0 ; j < 2; j++)
		if (rank[j] < rank[j + 1])
		{
			box = rank[j];
			rank[j] = rank[j + 1];
			rank[j + 1] = box;
		}
	}
}
void main() {
	char name1[3][80];
	int i, j, a;
	float score[7], max, min, sum, lscore, rank[3], box,rankx[3];
	for (i = 0; i < 3; i++) {
		printf("�������%dλ�����ߵ�������", i + 1);
		gets(name1[i]);
		printf("\n��%dΪ����Ϊ��", i + 1);
		puts(name1[i]);
		printf("\n����%s��7������ <NO.%d>:", name1[i], i + 1);
		for (j = 0; j < 7; j++)
			scanf_s("%f", &score[j]); getchar();
		for (j = 0; j < 7; j++)
			printf("%.2f  ", score[j]);
		max = score[0];
		min = score[0];
		for (j = 1; j < 7; j++)
			max = rankmax(max, score[j]);
		printf("\n��%dλ����߷�Ϊ��%.2f", i + 1, max);
		for (j = 1; j < 7; j++)
			min = rankmin(min, score[j]);
		printf("\n��%dλ����ͷ�Ϊ��%.2f", i + 1, min);
		sum = 0;
		for (j = 0; j < 7; j++)
			sum += score[j];
		lscore = (sum - min - max) / 5;
		printf("\n��%dλ���������ĵ÷֣�%.2f\n", i + 1, lscore);
		rank[i] = lscore;
		rankx[i] = lscore;
	}
	rankM(rank);
	for (i = 0; i < 3; i++) {	
		for (j = 0; j < 3; j++) {
			if (rank[i] == rankx[j])
				printf("%d�� ,%s, %.2f\n", i + 1, name1[j], rank[i]);
		}	
	}
}
