# wglCreateContext function

## Description

The **wglCreateContext** function creates a new OpenGL rendering context, which is suitable for drawing on the device referenced by *hdc*. The rendering context has the same pixel format as the device context.

## Parameters

### `unnamedParam1`

Typically named `handleToDeviceContext`. Handle to a device context for which the function creates a suitable OpenGL rendering context.

## Return value

If the function succeeds, the return value is a valid handle to an OpenGL rendering context.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A rendering context is not the same as a device context. Set the pixel format of the device context before creating a rendering context. For more information on setting the device context's pixel format, see the [SetPixelFormat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpixelformat) function.

To use OpenGL, you create a rendering context, select it as a thread's current rendering context, and then call OpenGL functions. When you are finished with the rendering context, you dispose of it by calling the [wglDeleteContext](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wgldeletecontext) function.

The following code example shows **wglCreateContext** usage.

``` syntax
HDC    hdc;
HGLRC  hglrc;

// create a rendering context
hglrc = wglCreateContext (hdc);

// make it the calling thread's current rendering context
wglMakeCurrent (hdc, hglrc);

// call OpenGL APIs as desired ...

// when the rendering context is no longer needed ...

// make the rendering context not current
wglMakeCurrent (NULL, NULL) ;

// delete the rendering context
wglDeleteContext (hglrc);
```

## See also

[OpenGL on Windows](https://learn.microsoft.com/windows/desktop/OpenGL/opengl-on-windows-nt--windows-2000--and-windows-95-98)

[SetPixelFormat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpixelformat)

[WGL Functions](https://learn.microsoft.com/windows/desktop/OpenGL/wgl-functions)

[wglDeleteContext](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wgldeletecontext)

[wglGetCurrentContext](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglgetcurrentcontext)

[wglGetCurrentDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglgetcurrentdc)

[wglMakeCurrent](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglmakecurrent)