# wglCreateLayerContext function

## Description

The **wglCreateLayerContext** function creates a new OpenGL rendering context for drawing to a specified layer plane on a device context.

## Parameters

### `unnamedParam1`

Specifies the device context for a new rendering context.

### `unnamedParam2`

Specifies the layer plane to which you want to bind a rendering context. The value 0 identifies the main plane. Positive values of *iLayerPlane* identify overlay planes, where 1 is the first overlay plane over the main plane, 2 is the second overlay plane over the first overlay plane, and so on. Negative values identify underlay planes, where 1 is the first underlay plane under the main plane, 2 is the second underlay plane under the first underlay plane, and so on. The number of overlay and underlay planes is given in the **bReserved** member of the [PIXELFORMATDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pixelformatdescriptor) structure.

## Return value

If the function succeeds, the return value is a handle to an OpenGL rendering context.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A rendering context is a port through which all OpenGL commands pass. Every thread that makes OpenGL calls must have one current, active rendering context. A rendering context is not the same as a device context; a rendering context contains information specific to OpenGL, while a device context contains information specific to GDI.

Before you create a rendering context, set the pixel format of the device context with the [SetPixelFormat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpixelformat) function. You can use a rendering context in a specified layer plane of a window with identical pixel formats only.

With OpenGL applications that use multiple threads, you create a rendering context, select it as the current rendering context of a thread, and make OpenGL calls for the specified thread. When you are finished with the rendering context of the thread, call the [wglDeleteContext](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wgldeletecontext) function.

#### Examples

The following code example shows how to use **wglCreateLayerContext**.

```cpp
// The following code fragment shows how to render to overlay 1
// This example assumes that the pixel format of hdc includes
// overlay plane 1

HDC hdc;
HGLRC;

// create a rendering context for overlay plane 1
hglrc = wglCreateLayerContext(hdc, 1);

// make it the calling thread's current rendering context
wglMakeCurrent(hdc, hglrc);

// call OpenGL functions here. . .

// when the rendering context is no longer needed. . .

// make the rendering context not current
wglMakeCurrent(NULL, NULL);

// delete the rendering context
wglDeleteContext(hglrc);
```

## See also

[OpenGL on Windows](https://learn.microsoft.com/windows/desktop/OpenGL/opengl-on-windows-nt--windows-2000--and-windows-95-98)

[PIXELFORMATDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pixelformatdescriptor)

[SetPixelFormat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpixelformat)

[WGL Functions](https://learn.microsoft.com/windows/desktop/OpenGL/wgl-functions)

[wglCreateContext](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglcreatecontext)

[wglDeleteContext](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wgldeletecontext)

[wglGetCurrentContext](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglgetcurrentcontext)

[wglGetCurrentDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglgetcurrentdc)

[wglMakeCurrent](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglmakecurrent)