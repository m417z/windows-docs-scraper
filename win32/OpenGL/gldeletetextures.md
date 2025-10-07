# glDeleteTextures function

The **glDeleteTextures** function deletes named textures.

## Parameters

*n*

The number of textures to be deleted.

*textures*

An array of textures to be deleted.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_VALUE** | *n* was a negative value.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glDeleteTextures** function deletes *n* textures named by the elements of the array *textures*. After a texture is deleted, it has no contents or dimensionality, and its name is free for reuse (for example, by **glGenTextures**). The **glDeleteTextures** function ignores zeros and names that do not correspond to existing textures.

If a texture that is currently bound is deleted, the binding reverts to zero (the default texture).

You cannot include calls to **glDeleteTextures** in display lists.

> [!Note]
> The **glDeleteTextures** function is only available in OpenGL version 1.1 or later.

The following function retrieves information related to **glDeleteTextures**:

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

[**glAreTexturesResident**](https://learn.microsoft.com/windows/win32/opengl/glaretexturesresident)

[**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin)

[**glBindTexture**](https://learn.microsoft.com/windows/win32/opengl/glbindtexture)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGenTextures**](https://learn.microsoft.com/windows/win32/opengl/glgentextures)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glGetTexParameter**](https://learn.microsoft.com/windows/win32/opengl/glgettexparameter)

[**glIsTexture**](https://learn.microsoft.com/windows/win32/opengl/glistexture)

[**glPrioritizeTextures**](https://learn.microsoft.com/windows/win32/opengl/glprioritizetextures)

[**glTexGen**](https://learn.microsoft.com/windows/win32/opengl/gltexgen-functions)

[**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d)

[**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d)

[**glTexParameter**](https://learn.microsoft.com/windows/win32/opengl/gltexparameter-functions)

