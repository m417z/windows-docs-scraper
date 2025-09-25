# wglMakeCurrent function

## Description

The **wglMakeCurrent** function makes a specified OpenGL rendering context the calling thread's current rendering context. All subsequent OpenGL calls made by the thread are drawn on the device identified by *hdc*. You can also use **wglMakeCurrent** to change the calling thread's current rendering context so it's no longer current.

## Parameters

### `unnamedParam1`

Handle to a device context. Subsequent OpenGL calls made by the calling thread are drawn on the device identified by *hdc*.

### `unnamedParam2`

Handle to an OpenGL rendering context that the function sets as the calling thread's rendering context.

If *hglrc* is **NULL**, the function makes the calling thread's current rendering context no longer current, and releases the device context that is used by the rendering context. In this case, *hdc* is ignored.

## Return value

When the **wglMakeCurrent** function succeeds, the return value is **TRUE**; otherwise the return value is **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The *hdc* parameter must refer to a drawing surface supported by OpenGL. It need not be the same *hdc* that was passed to [wglCreateContext](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglcreatecontext) when *hglrc* was created, but it must be on the same device and have the same pixel format. GDI transformation and clipping in *hdc* are not supported by the rendering context. The current rendering context uses the *hdc* device context until the rendering context is no longer current.

Before switching to the new rendering context, OpenGL flushes any previous rendering context that was current to the calling thread.

A thread can have one current rendering context. A process can have multiple rendering contexts by means of multithreading. A thread must set a current rendering context before calling any OpenGL functions. Otherwise, all OpenGL calls are ignored.

A rendering context can be current to only one thread at a time. You cannot make a rendering context current to multiple threads.

An application can perform multithread drawing by making different rendering contexts current to different threads, supplying each thread with its own rendering context and device context.

If an error occurs, the **wglMakeCurrent** function makes the thread's current rendering context not current before returning.

## See also

[OpenGL on Windows](https://learn.microsoft.com/windows/desktop/OpenGL/opengl-on-windows-nt--windows-2000--and-windows-95-98)

[WGL Functions](https://learn.microsoft.com/windows/desktop/OpenGL/wgl-functions)

[wglCreateContext](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglcreatecontext)

[wglDeleteContext](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wgldeletecontext)

[wglGetCurrentContext](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglgetcurrentcontext)

[wglGetCurrentDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglgetcurrentdc)