# DescribePixelFormat function

## Description

The **DescribePixelFormat** function obtains information about the pixel format identified by *iPixelFormat* of the device associated with *hdc*. The function sets the members of the [PIXELFORMATDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pixelformatdescriptor) structure pointed to by *ppfd* with that pixel format data.

## Parameters

### `hdc`

Specifies the device context.

### `iPixelFormat`

Index that specifies the pixel format. The pixel formats that a device context supports are identified by positive one-based integer indexes.

### `nBytes`

The size, in bytes, of the structure pointed to by *ppfd*. The **DescribePixelFormat** function stores no more than *nBytes* bytes of data to that structure. Set this value to **sizeof**(**PIXELFORMATDESCRIPTOR**).

### `ppfd`

Pointer to a **PIXELFORMATDESCRIPTOR** structure whose members the function sets with pixel format data. The function stores the number of bytes copied to the structure in the structure's **nSize** member. If, upon entry, *ppfd* is **NULL**, the function writes no data to the structure. This is useful when you only want to obtain the maximum pixel format index of a device context.

## Return value

If the function succeeds, the return value is the maximum pixel format index of the device context. In addition, the function sets the members of the **PIXELFORMATDESCRIPTOR** structure pointed to by *ppfd* according to the specified pixel format.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[ChoosePixelFormat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-choosepixelformat)

[GetPixelFormat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getpixelformat)

[OpenGL on Windows](https://learn.microsoft.com/windows/desktop/OpenGL/opengl-on-windows-nt--windows-2000--and-windows-95-98)

[SetPixelFormat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpixelformat)

[Windows Functions](https://learn.microsoft.com/windows/desktop/OpenGL/win32-functions)