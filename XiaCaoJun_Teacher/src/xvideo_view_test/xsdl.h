#pragma once
#include "xvideoview.h"
struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;
class XSDL : public XVideoView{
public:
    ////////////////////////////////////////////////
    /// 初始化渲染窗口 线程安全
    /// @para w 窗口宽度
    /// @para h 窗口高度
    /// @para fmt 绘制的像素格式
    /// @para win_id 窗口句柄，如果为空，创建新窗口
    /// @return 是否创建成功
    bool Init(int w, int h,
        Format fmt = RGBA,
        void* win_id = nullptr) override;

    void Close() override;

    //////////////////////////////////////////////////
    /// 渲染图像 线程安全
    ///@para data 渲染的二进制数据
    ///@para linesize 一行数据的字节数，对于YUV420P就是Y一行字节数
    /// linesize<=0 就根据宽度和像素格式自动算出大小
    /// @return 渲染是否成功
    bool Draw(const unsigned char* data, int linesize = 0) override;

    bool IsExit() override;
private:
    SDL_Window* win_ = nullptr;
    SDL_Renderer* render_ = nullptr;
    SDL_Texture* texture_ = nullptr;
};

