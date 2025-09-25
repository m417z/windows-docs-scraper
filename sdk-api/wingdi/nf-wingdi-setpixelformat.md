# SetPixelFormat function

## Description

The **SetPixelFormat** function sets the pixel format of the specified device context to the format specified by the *iPixelFormat* index.

## Parameters

### `hdc`

Specifies the device context whose pixel format the function attempts to set.

### `format`

Index that identifies the pixel format to set. The various pixel formats supported by a device context are identified by one-based indexes.

### `ppfd`

Pointer to a [PIXELFORMATDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pixelformatdescriptor) structure that contains the logical pixel format specification. The system's metafile component uses this structure to record the logical pixel format specification. The structure has no other effect upon the behavior of the **SetPixelFormat** function.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If *hdc* references a window, calling the **SetPixelFormat** function also changes the pixel format of the window. Setting the pixel format of a window more than once can lead to significant complications for the Window Manager and for multithread applications, so it is not allowed. An application can only set the pixel format of a window one time. Once a window's pixel format is set, it cannot be changed.

You should select a pixel format in the device context before calling the [wglCreateContext](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglcreatecontext) function. The **wglCreateContext** function creates a rendering context for drawing on the device in the selected pixel format of the device context.

An OpenGL window has its own pixel format. Because of this, only device contexts retrieved for the client area of an OpenGL window are allowed to draw into the window. As a result, an OpenGL window should be created with the WS_CLIPCHILDREN and WS_CLIPSIBLINGS styles. Additionally, the window class attribute should not include the CS_PARENTDC style.

#### Examples

The following code example shows **SetPixelFormat** usage.

```cpp
PIXELFORMATDESCRIPTOR pfd = {
    sizeof(PIXELFORMATDESCRIPTOR),   // size of this pfd
    1,                     // version number
    PFD_DRAW_TO_WINDOW |   // support window
    PFD_SUPPORT_OPENGL |   // support OpenGL
    PFD_DOUBLEBUFFER,      // double buffered
    PFD_TYPE_RGBA,         // RGBA type
    24,                    // 24-bit color depth
    0, 0, 0, 0, 0, 0,      // color bits ignored
    0,                     // no alpha buffer
    0,                     // shift bit ignored
    0,                     // no accumulation buffer
    0, 0, 0, 0,            // accum bits ignored
    32,                    // 32-bit z-buffer
    0,                     // no stencil buffer
    0,                     // no auxiliary buffer
    PFD_MAIN_PLANE,        // main layer
    0,                     // reserved
    0, 0, 0                // layer masks ignored
};
HDC  hdc;
int  iPixelFormat;

// get the best available match of pixel format for the device context
iPixelFormat = ChoosePixelFormat(hdc, &pfd);

// make that the pixel format of the device context
SetPixelFormat(hdc, iPixelFormat, &pfd);
```

## See also

[ChoosePixelFormat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-choosepixelformat)

[DescribePixelFormat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-describepixelformat)

[GetPixelFormat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getpixelformat)

[OpenGL on Windows](https://learn.microsoft.com/windows/desktop/OpenGL/opengl-on-windows-nt--windows-2000--and-windows-95-98)

[Windows Functions](https://learn.microsoft.com/windows/desktop/OpenGL/win32-functions)