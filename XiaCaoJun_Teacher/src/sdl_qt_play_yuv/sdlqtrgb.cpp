#include "sdlqtrgb.h"
#include <sdl/SDL.h>
#include <fstream>
#include <QMessageBox>

using namespace std;

#pragma comment(lib, "SDL2.lib")

static SDL_Window* sdl_win = NULL;
static SDL_Renderer* sdl_render = NULL;
static SDL_Texture* sdl_texture = NULL;
static int sdl_width = 0;
static int sdl_height = 0;
//static unsigned char* rgb = NULL;
static unsigned char* yuv = NULL;
static int pix_size = 2;

static ifstream yuv_file;

void SdlQtRGB::timerEvent(QTimerEvent* ev) {
    //static unsigned char tmp = 255;
    //tmp--;

    //for (int j = 0; j < sdl_height; j++) {
    //    int b = j * sdl_width * pix_size;
    //    for (int i = 0; i < sdl_width * pix_size; i += pix_size) {
    //        rgb[b + i] = 0;         //B
    //        rgb[b + i + 1] = tmp;   //G
    //        rgb[b + i + 2] = 0;     //R
    //        rgb[b + i + 3] = 0;     //A
    //    }
    //}

    yuv_file.read((char*)yuv, sdl_width * sdl_height * 1.5);

    //yuv ƽ��洢
    //5 ���ڴ�����д�����
    SDL_UpdateTexture(sdl_texture, NULL, yuv, sdl_width); //sdl_width һ��y���ֽ���

    //6 ������Ļ
    SDL_RenderClear(sdl_render);

    //7 ���Ʋ��ʵ���Ⱦ����
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = sdl_width;
    rect.h = sdl_height;
    SDL_RenderCopy(sdl_render, sdl_texture, NULL, &rect);

    //8.��Ⱦ
    SDL_RenderPresent(sdl_render);
}

SdlQtRGB::SdlQtRGB(QWidget *parent)
    : QWidget(parent)
{
    //��yuv�ļ�
    yuv_file.open("400_300_25.yuv", ios::binary);
    if (!yuv_file) {
        QMessageBox::information(this, "", "open yuv file failed!");
        return;
    }

    ui.setupUi(this);
    
    sdl_width = 400;
    sdl_height = 300;

    ui.label->resize(sdl_width, sdl_height);

    //1.��ʼ��SDL video��
    SDL_Init(SDL_INIT_VIDEO);
    
    //2.����SDL���ڣ�ʹ��QT�Ŀؼ���Ϊ����

    sdl_win = SDL_CreateWindowFrom((void*)ui.label->winId());
    //3.������Ⱦ��
    sdl_render = SDL_CreateRenderer(sdl_win, -1, SDL_RENDERER_ACCELERATED);
    //4.���ɲ��ʣ�֧��YUV
    sdl_texture = SDL_CreateTexture(sdl_render,
        SDL_PIXELFORMAT_IYUV,
        SDL_TEXTUREACCESS_STREAMING,
        sdl_width,
        sdl_height
        );

    //���ͼ�������
    yuv = new unsigned char[sdl_width * sdl_height * pix_size];

    startTimer(10);
}
