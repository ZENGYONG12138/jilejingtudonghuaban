
#include <iostream>
#include <stdio.h>
#include  <graphics.h> 	// 引用 EasyX 图形库
#include  <Windows.h>
#include <mmsystem.h> // mci库头文件
#pragma comment(lib, "winmm.lib")

#define COUNT 148

using namespace std;

int main(void) {
	IMAGE  images[148];
	char fileName[128];

	cout << "正在加载..." << endl;
	//预先加载资源
	for (int i = 1; i <= COUNT; i++) {
		sprintf(fileName, "F:\\tmp\\images2\\_%04d_图层-%d.jpg", COUNT - i, i);
		loadimage(&images[i - 1], fileName);
	}

	initgraph(800, 450);
	mciSendString("play 极乐净土.mp3 repeat", 0, 0, 0); //重复播放


	while (1) {
		//依次播放各个图片
		for (int i = 0; i < COUNT; i++) {
			putimage(0, 0, &images[i]);
			Sleep(75);
		}
	}

	system("pause");
	closegraph();
	return 0;
}
