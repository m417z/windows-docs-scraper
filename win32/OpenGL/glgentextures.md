# glGenTextures function

The **glGenTextures** function generates texture names.

## Parameters

*n*

The number of texture names to be generated.

*textures*

A pointer to the first element of an array in which the generated texture names are stored.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_VALUE** | *n* was a negative value.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glGenTextures** function returns *n* texture names in the *textures* parameter. The texture names are not necessarily a contiguous set of integers, however, none of the returned names can have been in use immediately prior to calling the **glGenTextures** function. The generated textures assume the dimensionality of the texture target to which they are first bound with the [**glBindTexture**](https://learn.microsoft.com/windows/win32/opengl/glbindtexture) function. Texture names returned by **glGenTextures** are not returned by subsequent calls to **glGenTextures** unless they are first deleted by calling [**glDeleteTextures**](https://learn.microsoft.com/windows/win32/opengl/gldeletetextures).

You cannot include **glGenTextures** in display lists.

> [!Note]
> The **glGenTextures** function is only available in OpenGL version 1.1 or later.

The following function retrieves information related to **glGenTextures**:

- [**glIsTexture**](https://learn.microsoft.com/windows/win32/opengl/glistexture)

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

[**glDeleteTextures**](https://learn.microsoft.com/windows/win32/opengl/gldeletetextures)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glGetTexParameter**](https://learn.microsoft.com/windows/win32/opengl/glgettexparameter)

[**glIsTexture**](https://learn.microsoft.com/windows/win32/opengl/glistexture)

[**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d)

[**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d)

[**glTexParameter**](https://learn.microsoft.com/windows/win32/opengl/gltexparameter-functions)

