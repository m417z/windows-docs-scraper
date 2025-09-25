# ChoosePixelFormat function

## Description

The **ChoosePixelFormat** function attempts to match an appropriate pixel format supported by a device context to a given pixel format specification.

## Parameters

### `hdc`

Specifies the device context that the function examines to determine the best match for the pixel format descriptor pointed to by *ppfd*.

### `ppfd`

Pointer to a [PIXELFORMATDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pixelformatdescriptor) structure that specifies the requested pixel format. In this context, the members of the **PIXELFORMATDESCRIPTOR** structure that *ppfd* points to are used as follows:

|  |  |
| --- | --- |
| *nSize* | Specifies the size of the [PIXELFORMATDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pixelformatdescriptor) data structure. Set this member to `sizeof(PIXELFORMATDESCRIPTOR)`. |
| *nVersion* | Specifies the version number of the [PIXELFORMATDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pixelformatdescriptor) data structure. Set this member to 1. |
| *dwFlags* | A set of bit flags that specify properties of the pixel buffer. You can combine the following bit flag constants by using bitwise-OR. If any of the following flags are set, the **ChoosePixelFormat** function attempts to match pixel formats that also have that flag or flags set. Otherwise, **ChoosePixelFormat** ignores that flag in the pixel formats: **PFD_DRAW_TO_WINDOW**, **PFD_DRAW_TO_BITMAP**, **PFD_SUPPORT_GDI**, **PFD_SUPPORT_OPENGL** If any of the following flags are set, **ChoosePixelFormat** attempts to match pixel formats that also have that flag or flags set. Otherwise, it attempts to match pixel formats without that flag set: **PFD_DOUBLEBUFFER PFD_STEREO** If the following flag is set, the function ignores the **PFD_DOUBLEBUFFER** flag in the pixel formats: **PFD_DOUBLEBUFFER_DONTCARE** If the following flag is set, the function ignores the **PFD_STEREO** flag in the pixel formats: **PFD_STEREO_DONTCARE** |
| *iPixelType* | Specifies the type of pixel format for the function to consider: **PFD_TYPE_RGBA**, **PFD_TYPE_COLORINDEX** |
| *cColorBits* | Zero or greater. |
| *cRedBits* | Not used. |
| *cRedShift* | Not used. |
| *cGreenBits* | Not used. |
| *cGreenShift* | Not used. |
| *cBlueBits* | Not used. |
| *cBlueShift* | Not used. |
| *cAlphaBits* | Zero or greater. |
| *cAlphaShift* | Not used. |
| *cAccumBits* | Zero or greater. |
| *cAccumRedBits* | Not used. |
| *cAccumGreenBits* | Not used. |
| *cAccumBlueBits* | Not used. |
| *cAccumAlphaBits* | Not used. |
| *cDepthBits* | Zero or greater. |
| *cStencilBits* | Zero or greater. |
| *cAuxBuffers* | Zero or greater. |
| *iLayerType* | Specifies one of the following layer type values: **PFD_MAIN_PLANE**, **PFD_OVERLAY_PLANE**, **PFD_UNDERLAY_PLANE** |
| *bReserved* | Not used. |
| *dwLayerMask* | Not used. |
| *dwVisibleMask* | Not used. |
| *dwDamageMask* | Not used. |

## Return value

If the function succeeds, the return value is a pixel format index (one-based) that is the closest match to the given pixel format descriptor.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

You must ensure that the pixel format matched by the **ChoosePixelFormat** function satisfies your requirements. For example, if you request a pixel format with a 24-bit RGB color buffer but the device context offers only 8-bit RGB color buffers, the function returns a pixel format with an 8-bit RGB color buffer.

#### Examples

The following code sample shows how to use **ChoosePixelFormat** to match a specified pixel format.

```cpp
PIXELFORMATDESCRIPTOR pfd = {
    sizeof(PIXELFORMATDESCRIPTOR),  //  size of this pfd
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

iPixelFormat = ChoosePixelFormat(hdc, &pfd);
```

## See also

[DescribePixelFormat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-describepixelformat)

[GetPixelFormat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getpixelformat)

[OpenGL on Windows](https://learn.microsoft.com/windows/desktop/OpenGL/opengl-on-windows-nt--windows-2000--and-windows-95-98)

[SetPixelFormat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpixelformat)

[Windows Functions](https://learn.microsoft.com/windows/desktop/OpenGL/win32-functions)