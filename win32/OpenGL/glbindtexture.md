# glBindTexture function

The **glBindTexture** function enables the creation of a named texture that is bound to a texture target.

## Parameters

*target*

The target to which the texture is bound. Must have the value GL\_TEXTURE\_1D or GL\_TEXTURE\_2D.

*texture*

The name of a texture; the texture name cannot currently be in use.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | The parameter *target* was not an accepted value.<br> |
| **GL\_INVALID\_OPERATION** | The parameter *texture* did not have the same dimensionality as *target*, or the function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glBindTexture** function enables you to create a named texture. Calling **glBindTexture** with *target* set to GL\_TEXTURE\_1D or GL\_TEXTURE\_2D, and *texture* set to the name of the new texture you have created binds the texture name to the appropriate texture target. When a texture is bound to a target, the previous binding for that target is no longer in effect.

Texture names are unsigned integers with the value zero reserved to represent the default texture for each texture target. Texture names and the corresponding texture contents are local to the shared display-list space of the current OpenGL rendering context; two rendering contexts share texture names only if they also share display lists. You can generate a set of new texture names using [**glGenTextures**](https://learn.microsoft.com/windows/win32/opengl/glgentextures).

When a texture is first bound, it assumes the dimensionality of its texture target; a texture bound to GL\_TEXTURE\_1D becomes one-dimensional and a texture bound to GL\_TEXTURE\_2D becomes two-dimensional. Operations you perform on a texture target also affect a texture bound to the target. When you query a texture target, the return value is the state of the texture bound to it. Texture targets become aliases for textures currently bound to them.

When you bind a texture with **glBindTexture**, the binding remains active until a different texture is bound to the same target or you delete the bound texture with the [**glDeleteTextures**](https://learn.microsoft.com/windows/win32/opengl/gldeletetextures) function. Once you create a named texture you can bind it to a texture target that has the same dimensionality as often as needed.

It is usually much faster to use **glBindTexture** to bind an existing named texture to one of the texture targets than it is to reload the texture image using [**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d) or [**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d). For additional control of texturing performance, use [**glPrioritizeTextures**](https://learn.microsoft.com/windows/win32/opengl/glprioritizetextures).

You can include calls to **glBindTexture** in display lists.

> [!Note]
> The **glBindTexture** function is only available in OpenGL version 1.1 or later.

The following functions retrieve information related to **glBindTexture**:

- [**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_TEXTURE\_1D\_BINDING

**glGet** with argument GL\_TEXTURE\_2D\_BINDING

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

[**glDeleteTextures**](https://learn.microsoft.com/windows/win32/opengl/gldeletetextures)

[**glGenTextures**](https://learn.microsoft.com/windows/win32/opengl/glgentextures)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glGetTexParameter**](https://learn.microsoft.com/windows/win32/opengl/glgettexparameter)

[**glIsTexture**](https://learn.microsoft.com/windows/win32/opengl/glistexture)

[**glPrioritizeTextures**](https://learn.microsoft.com/windows/win32/opengl/glprioritizetextures)

[**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d)

[**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d)

[**glTexParameter**](https://learn.microsoft.com/windows/win32/opengl/gltexparameter-functions)

