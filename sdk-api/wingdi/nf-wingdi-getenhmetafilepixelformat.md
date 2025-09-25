# GetEnhMetaFilePixelFormat function

## Description

The **GetEnhMetaFilePixelFormat** function retrieves pixel format information for an enhanced metafile.

## Parameters

### `hemf`

Identifies the enhanced metafile.

### `cbBuffer`

Specifies the size, in bytes, of the buffer into which the pixel format information is copied.

### `ppfd`

Pointer to a [PIXELFORMATDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pixelformatdescriptor) structure that contains the logical pixel format specification. The metafile uses this structure to record the logical pixel format specification.

## Return value

If the function succeeds and finds a pixel format, the return value is the size of the metafile's pixel format.

If no pixel format is present, the return value is zero.

If an error occurs and the function fails, the return value is GDI_ERROR. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

When an enhanced metafile specifies a pixel format in its **ENHMETAHEADER** structure and the pixel format fits in the buffer, the pixel format information is copied into *ppfd*. When *cbBuffer* is too small to contain the pixel format of the metafile, the pixel format is not copied to the buffer. In either case, the function returns the size of the metafile's pixel format.

For information on metafile recording and other operations, see Enhanced Metafile Operations.

## See also

[ENHMETAHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-enhmetaheader)

[OpenGL on Windows](https://learn.microsoft.com/windows/desktop/OpenGL/opengl-on-windows-nt--windows-2000--and-windows-95-98)

[PIXELFORMATDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pixelformatdescriptor)

[Windows Functions](https://learn.microsoft.com/windows/desktop/OpenGL/win32-functions)