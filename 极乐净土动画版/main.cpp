
#include <iostream>
#include <stdio.h>
#include  <graphics.h> 	// ���� EasyX ͼ�ο�
#include  <Windows.h>
#include <mmsystem.h> // mci��ͷ�ļ�
#pragma comment(lib, "winmm.lib")

#define COUNT 148

using namespace std;

int main(void) {
	IMAGE  images[148];
	char fileName[128];

	cout << "���ڼ���..." << endl;
	//Ԥ�ȼ�����Դ
	for (int i = 1; i <= COUNT; i++) {
		sprintf(fileName, "F:\\tmp\\images2\\_%04d_ͼ��-%d.jpg", COUNT - i, i);
		loadimage(&images[i - 1], fileName);
	}

	initgraph(800, 450);
	mciSendString("play ���־���.mp3 repeat", 0, 0, 0); //�ظ�����


	while (1) {
		//���β��Ÿ���ͼƬ
		for (int i = 0; i < COUNT; i++) {
			putimage(0, 0, &images[i]);
			Sleep(75);
		}
	}

	system("pause");
	closegraph();
	return 0;
}
