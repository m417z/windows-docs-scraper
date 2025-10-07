# glGetColorTableParameterfvEXT function

The **glGetColorTableParameterfvEXT** and [**glGetColorTableParameterivEXT**](https://learn.microsoft.com/windows/win32/opengl/glgetcolortableparameterivext) functions get palette parameters from color tables.

## Parameters

*target*

The target texture of the palette for which you want parameter data. Must be TEXTURE\_1D, TEXTURE\_2D, PROXY\_TEXTURE\_1D, or PROXY\_TEXTURE\_2D.

*pname*

A symbolic constant for the type of palette parameter data pointed to by *params*.

The following are the accepted symbolic constants and their meanings.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_COLOR\_TABLE\_FORMAT\_EXT** | Return the internal format specified by the most recent call to [**glColorTableEXT**](https://learn.microsoft.com/windows/win32/opengl/glcolortableext) or the default value.<br> |
| **GL\_COLOR\_TABLE\_WIDTH\_EXT** | Return the width of the current palette.<br> |
| **GL\_COLOR\_TABLE\_RED\_SIZE\_EXT** | Return the actual size used internally to store the red component of the palette data.<br> |
| **GL\_COLOR\_TABLE\_GREEN\_SIZE\_EXT** | Return the actual size used internally to store the green component of the palette data.<br> |
| **GL\_COLOR\_TABLE\_BLUE\_SIZE\_EXT** | Return the actual size used internally to store the blue component of the palette data.<br> |
| **GL\_COLOR\_TABLE\_ALPHA\_SIZE\_EXT** | Return the actual size used internally to store the alpha component of the palette data.<br> |

*params*

Points to the color table parameter data specified by the *pname* parameter.

## Return value

This function does not return a value.

## Remarks

You use the **glGetColorTableParameterivEXT** and **glGetColorTableParameterfvEXT** functions to retrieve specific parameter data from color tables set with [**glColorTableEXT**](https://learn.microsoft.com/windows/win32/opengl/glcolortableext) for targeted texture palettes. Also you can use these functions to determine the number of color table entries that **glGetColorTableEXT** returns.

When the *target* parameter is GL\_PROXY\_TEXTURE\_1D or GL\_PROXY\_TEXTURE\_2D, and the implementation does not support the values specified for either *format* or *width*, **glColorTableEXT** can fail to create the requested color table. In this case, the color table is empty and all parameters retrieved will be zero. You can determine whether OpenGL supports a particular color table format and size by calling **glColorTableEXT** with a proxy target, and then calling **glGetColorTableParameterivEXT** or **glGetColorTableParameterfvEXT** to determine whether the width parameter matches that set by **glColorTableEXT**. If the retrieved width is zero, the color table request by **glColorTable** failed. If the retrieved width is not zero, you can call **glColorTable** with the real target with TEXTURE\_1D or TEXTURE\_2D to set the color table.

The **glGetColorTableParameterivEXT** and **glGetColorTableParameterfvEXT** functions are extension functions that are not part of the standard OpenGL library but are part of the GL\_EXT\_paletted\_texture extension. To check whether your implementation of OpenGL supports **glGetColorTableParameterivEXT** and **glGetColorTableParameterfvEXT**, call [**glGetString**](https://learn.microsoft.com/windows/win32/opengl/glgetstring)**(**GL\_EXTENSIONS**)**. If it returns GL\_EXT\_paletted\_texture, **glGetColorTableParameterivEXT** and **glGetColorTableParameterfvEXT** are supported. To obtain the function address of an extension function, call [**wglGetProcAddress**](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglgetprocaddress).

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Gl.h |

## See also

[**glColorSubTableEXT**](https://learn.microsoft.com/windows/win32/opengl/glcolorsubtableext)

[**glColorTableEXT**](https://learn.microsoft.com/windows/win32/opengl/glcolortableext)

[**glGetColorTableEXT**](https://learn.microsoft.com/windows/win32/opengl/glgetcolortableext)

[**glGetColorTableParameterivEXT**](https://learn.microsoft.com/windows/win32/opengl/glgetcolortableparameterivext)

[**wglGetProcAddress**](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglgetprocaddress)

