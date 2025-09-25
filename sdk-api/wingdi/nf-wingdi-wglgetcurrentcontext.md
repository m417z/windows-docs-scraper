# wglGetCurrentContext function

## Description

The **wglGetCurrentContext** function obtains a handle to the current OpenGL rendering context of the calling thread.

## Return value

If the calling thread has a current OpenGL rendering context, **wglGetCurrentContext** returns a handle to that rendering context. Otherwise, the return value is **NULL**.

## Remarks

The current OpenGL rendering context of a thread is associated with a device context by means of the **wglMakeCurrent** function. You can use the **wglGetCurrentDC** function to obtain a handle to the device context associated with the current OpenGL rendering context.

## See also

[OpenGL on Windows](https://learn.microsoft.com/windows/desktop/OpenGL/opengl-on-windows-nt--windows-2000--and-windows-95-98)

[WGL Functions](https://learn.microsoft.com/windows/desktop/OpenGL/wgl-functions)

[wglCreateContext](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglcreatecontext)

[wglDeleteContext](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wgldeletecontext)

[wglGetCurrentDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglgetcurrentdc)

[wglMakeCurrent](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglmakecurrent)