# GetPixelFormat function

## Description

The **GetPixelFormat** function obtains the index of the currently selected pixel format of the specified device context.

## Parameters

### `hdc`

Specifies the device context of the currently selected pixel format index returned by the function.

## Return value

If the function succeeds, the return value is the currently selected pixel format index of the specified device context. This is a positive, one-based index value.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[ChoosePixelFormat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-choosepixelformat)

[DescribePixelFormat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-describepixelformat)

[OpenGL on Windows](https://learn.microsoft.com/windows/desktop/OpenGL/opengl-on-windows-nt--windows-2000--and-windows-95-98)

[SetPixelFormat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpixelformat)

[Windows Functions](https://learn.microsoft.com/windows/desktop/OpenGL/win32-functions)