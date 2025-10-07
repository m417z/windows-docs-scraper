# glPrioritizeTextures function

The **glPrioritizeTextures** function sets the residence priority of textures.

## Parameters

*n*

The number of textures to be prioritized.

*textures*

A pointer to the first element of an array containing the names of the textures to be prioritized.

*priorities*

A pointer to the first element of an array containing the texture priorities. A priority given in an element of the *priorities* parameter applies to the texture named by the corresponding element of the *textures* parameter.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_VALUE** | *n* was a negative value.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glPrioritizeTextures** function assigns the *n* texture priorities specified in the *priorities* parameter to the *n* textures named in the *textures* parameter. On computers with a limited amount of texture memory, OpenGL establishes a "working set" of textures that are resident in texture memory. These textures can be bound to a texture target much more efficiently than textures that are not resident.

By specifying a priority for each texture, the **glPrioritizeTextures** function enables you to determine which textures should be resident.

The texture priorities elements in *priorities* are clamped to the range \[0.0, 1.0\] before being assigned. Zero indicates the lowest priority; thus textures with priority zero are least likely to be resident. The value 1.0 indicates the highest priority; thus textures with priority 1.0 are most likely to be resident. However, textures are not guaranteed to be resident until they are bound.

The **glPrioritizeTextures** function ignores attempts to prioritize texture 0, or any texture name that does not correspond to an existing texture. None of the functions named by the *textures* parameter need to be bound to a texture target.

If a texture is currently bound, you can also use the [**glTexParameter**](https://learn.microsoft.com/windows/win32/opengl/gltexparameter-functions) function to set its priority. This is the only way to set the priority of a default texture.

You can include **glPrioritizeTextures** in display lists.

The following function retrieves the priority of a currently-bound texture related to **glPrioritizeTextures**:

- [**glGetTexParameter**](https://learn.microsoft.com/windows/win32/opengl/glgettexparameter) with parameter name GL\_TEXTURE\_PRIORITY

> [!Note]
> The **glPrioritizeTextures** function is only available in OpenGL version 1.1 or later.

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

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGetTexParameter**](https://learn.microsoft.com/windows/win32/opengl/glgettexparameter)

[**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d)

[**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d)

[**glTexParameter**](https://learn.microsoft.com/windows/win32/opengl/gltexparameter-functions)

