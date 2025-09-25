# wglGetCurrentDC function

## Description

The **wglGetCurrentDC** function obtains a handle to the device context that is associated with the current OpenGL rendering context of the calling thread.

## Return value

If the calling thread has a current OpenGL rendering context, the function returns a handle to the device context associated with that rendering context by means of the **wglMakeCurrent** function. Otherwise, the return value is **NULL**.

## Remarks

You associate a device context with an OpenGL rendering context when it calls the **wglMakeCurrent** function. You can use the **wglGetCurrentContext** function to obtain a handle to the calling thread's current OpenGL rendering context.

## See also

[OpenGL on Windows](https://learn.microsoft.com/windows/desktop/OpenGL/opengl-on-windows-nt--windows-2000--and-windows-95-98)

[WGL Functions](https://learn.microsoft.com/windows/desktop/OpenGL/wgl-functions)

[wglCreateContext](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglcreatecontext)

[wglDeleteContext](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wgldeletecontext)

[wglGetCurrentContext](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglgetcurrentcontext)

[wglMakeCurrent](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglmakecurrent)