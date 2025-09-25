# wglDeleteContext function

## Description

The **wglDeleteContext** function deletes a specified OpenGL rendering context.

## Parameters

### `unnamedParam1`

Handle to an OpenGL rendering context that the function will delete.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

It is an error to delete an OpenGL rendering context that is the current context of another thread. However, if a rendering context is the calling thread's current context, the **wglDeleteContext** function changes the rendering context to being not current before deleting it.

The **wglDeleteContext** function does not delete the device context associated with the OpenGL rendering context when you call the **wglMakeCurrent** function. After calling **wglDeleteContext**, you must call [DeleteDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletedc) to delete the associated device context.

## See also

[DeleteDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletedc)

[OpenGL on Windows](https://learn.microsoft.com/windows/desktop/OpenGL/opengl-on-windows-nt--windows-2000--and-windows-95-98)

[WGL Functions](https://learn.microsoft.com/windows/desktop/OpenGL/wgl-functions)

[wglCreateContext](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglcreatecontext)

[wglGetCurrentContext](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglgetcurrentcontext)

[wglGetCurrentDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglgetcurrentdc)

[wglMakeCurrent](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglmakecurrent)