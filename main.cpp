#include <SDL3/SDL.h>
#include <iostream>
using namespace std;
int main()
{
    //初始化SDL3
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) 
    {
        cout << "SDL3初始化失败：" << SDL_GetError() << endl;
        return -1;
    }
    //创建窗口
    SDL_Window* window = SDL_CreateWindow("Space Shooter", 600,800,SDL_WINDOW_OPENGL);
    if (window == NULL) {
        cout << "窗口创建失败：" << SDL_GetError() << endl;
        return -1;
    }
    //创建渲染器
    SDL_Renderer* renderer = SDL_CreateRenderer(window, SDL_PROP_RENDERER_CREATE_VULKAN_INSTANCE_POINTER);
    if (renderer == NULL) {
        cout << "渲染器创建失败：" << SDL_GetError() << endl;
        return -1;
    }


    return 0;
}