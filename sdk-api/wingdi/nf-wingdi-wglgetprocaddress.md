# wglGetProcAddress function

## Description

The **wglGetProcAddress** function returns the address of an OpenGL extension function for use with the current OpenGL rendering context.

## Parameters

### `unnamedParam1`

Points to a **null**-terminated string that is the name of the extension function. The name of the extension function must be identical to a corresponding function implemented by OpenGL.

## Return value

When the function succeeds, the return value is the address of the extension function.

When no current rendering context exists or the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The OpenGL library supports multiple implementations of its functions. Extension functions supported in one rendering context are not necessarily available in a separate rendering context. Thus, for a given rendering context in an application, use the function addresses returned by the **wglGetProcAddress** function only.

The spelling and the case of the extension function pointed to by *lpszProc* must be identical to that of a function supported and implemented by OpenGL. Because extension functions are not exported by OpenGL, you must use **wglGetProcAddress** to get the addresses of vendor-specific extension functions.

The extension function addresses are unique for each pixel format. All rendering contexts of a given pixel format share the same extension function addresses.

## See also

[OpenGL on Windows](https://learn.microsoft.com/windows/desktop/OpenGL/opengl-on-windows-nt--windows-2000--and-windows-95-98)

[WGL Functions](https://learn.microsoft.com/windows/desktop/OpenGL/wgl-functions)

[glGetString](https://learn.microsoft.com/windows/desktop/OpenGL/glgetstring)

[wglMakeCurrent](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglmakecurrent)