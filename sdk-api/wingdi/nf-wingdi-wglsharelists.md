# wglShareLists function

## Description

The **wglShareLists** function enables multiple OpenGL rendering contexts to share a single display-list space.

## Parameters

### `unnamedParam1`

Specifies the OpenGL rendering context with which to share display lists.

### `unnamedParam2`

Specifies the OpenGL rendering context to share display lists with *hglrc1*. The *hglrc2* parameter should not contain any existing display lists when **wglShareLists** is called.

## Return value

When the function succeeds, the return value is **TRUE**.

When the function fails, the return value is **FALSE** and the display lists are not shared. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

When you create an OpenGL rendering context, it has its own display-list space. The **wglShareLists** function enables a rendering context to share the display-list space of another rendering context; any number of rendering contexts can share a single display-list space. Once a rendering context shares a display-list space, the rendering context always uses the display-list space until the rendering context is deleted. When the last rendering context of a shared display-list space is deleted, the shared display-list space is deleted. All the indexes and definitions of display lists in a shared display-list space are shared.

You can only share display lists with rendering contexts within the same process. However, not all rendering contexts in a process can share display lists. Rendering contexts can share display lists only if they use the same implementation of OpenGL functions. All client rendering contexts of a given pixel format can always share display lists.

All rendering contexts of a shared display list must use an identical pixel format. Otherwise the results depend on the implementation of OpenGL used.

**Note** The **wglShareLists** function is only available with OpenGL version 1.01 or later. To determine the version number of the implementation of OpenGL, call **glGetString**.

## See also

[OpenGL on Windows](https://learn.microsoft.com/windows/desktop/OpenGL/opengl-on-windows-nt--windows-2000--and-windows-95-98)

[WGL Functions](https://learn.microsoft.com/windows/desktop/OpenGL/wgl-functions)

[glGetString](https://learn.microsoft.com/windows/desktop/OpenGL/glgetstring)