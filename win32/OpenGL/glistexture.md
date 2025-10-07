# glIsTexture function

The **glIsTexture** function determines if a name corresponds to a texture.

## Parameters

*texture*

A value that is the name of a texture.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

If the *texture* parameter is currently the name of a texture, the **glIsTexture** function returns GL\_TRUE. The **glIsTexture** function returns GL\_FALSE if *texture* is zero. It also returns GL\_FALSE if it is a non-zero value that is not currently the name of a texture, or if an error occurs.

You cannot include calls to **glIsTexture** in display lists.

> [!Note]
> The **glIsTexture** function is only available in OpenGL version 1.1 or later.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Gl.h |
| Library<br> | Opengl32.lib |
| DLL<br> | Opengl32.dll |

## See also

[**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin)

[**glBindTexture**](https://learn.microsoft.com/windows/win32/opengl/glbindtexture)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGenTextures**](https://learn.microsoft.com/windows/win32/opengl/glgentextures)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glGetTexParameter**](https://learn.microsoft.com/windows/win32/opengl/glgettexparameter)

[**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d)

[**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d)

[**glTexParameter**](https://learn.microsoft.com/windows/win32/opengl/gltexparameter-functions)

