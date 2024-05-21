#ifndef C3D_GUI_WINDOW_H__
#define C3D_GUI_WINDOW_H__

typedef struct C3DWindow C3DWindow;

typedef struct {
    int x_pos;
    int y_pos;
    int width;
    int height;
    const char* title;
} WindowConfig;

typedef struct 
{
    int width;
    int height;
} C3DWindowDimension;


C3DWindow* c3dOpenWindow(WindowConfig *config);

void c3dCloseWindow(C3DWindow* window);

C3DWindowDimension c3dGetWindowDimension(C3DWindow* window);


#endif