#include "sdlqtrgb.h"
#include <sdl/SDL.h>
#include <fstream>
#include <QMessageBox>
#include "xvideoview.h"
using namespace std;

#pragma comment(lib, "SDL2.lib")

//static SDL_Window* sdl_win = NULL;
//static SDL_Renderer* sdl_render = NULL;
//static SDL_Texture* sdl_texture = NULL;
static int sdl_width = 0;
static int sdl_height = 0;
//static unsigned char* rgb = NULL;
static unsigned char* yuv = NULL;
static int pix_size = 2;

static ifstream yuv_file;
static XVideoView* view = nullptr;

void SdlQtRGB::timerEvent(QTimerEvent* ev) {
    yuv_file.read((char*)yuv, sdl_width * sdl_height * 1.5);
    
    if (view->IsExit()) {
        view->Close();
        exit(0);
    }

    view->Draw(yuv);
}

void SdlQtRGB::resizeEvent(QResizeEvent* ev) {
    ui.label->resize(size());
    ui.label->move(0, 0);

    view->Scale(width(), height());
}

SdlQtRGB::SdlQtRGB(QWidget *parent)
    : QWidget(parent)
{
    //打开yuv文件
    yuv_file.open("400_300_25.yuv", ios::binary);
    if (!yuv_file) {
        QMessageBox::information(this, "", "open yuv file failed!");
        return;
    }

    ui.setupUi(this);
    
    sdl_width = 400;
    sdl_height = 300;

    ui.label->resize(sdl_width, sdl_height);

    view = XVideoView::Create();
    view->Init(sdl_width, sdl_height,
        XVideoView::YUV420P);

    view->Close();
    view->Init(sdl_width, sdl_height,
        XVideoView::YUV420P, (void*)ui.label->winId());

    //存放图像的数据
    yuv = new unsigned char[sdl_width * sdl_height * pix_size];

    startTimer(10);
}