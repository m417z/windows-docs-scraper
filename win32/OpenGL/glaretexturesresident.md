# glAreTexturesResident function

The **glAreTexturesResident** function determines whether specified texture objects are resident in texture memory.

## Parameters

*n*

The number of textures to be queried.

*textures*

The address of an array containing the names of the textures to be queried.

*residences*

The address of an array in which the texture residence status is returned. The residence status of a texture named by an element of *textures* is returned in the corresponding element of *residences*.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_VALUE** | *n* was a negative value, an element in *textures* was zero, or an element in *textures* did not contain a texture identifier.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

On machines with a limited amount of texture memory, OpenGL establishes a working set of textures that are resident in texture memory. These textures can be bound to a texture target much more efficiently than textures that are not resident.

The **glAreTexturesResident** function queries the texture residence status of the *n* textures named by the elements of *textures*. If all the named textures are resident, **glAreTexturesResident** returns GL\_TRUE, and the contents of *residences* are undisturbed. If any of the named textures are not resident, **glAreTexturesResident** returns GL\_FALSE, and detailed status is returned in the *n* elements of *residences*.

If an element of *residences* is GL\_TRUE, then the texture named by the corresponding element of *textures* is resident in texture memory.

To query the residence status of a single bound texture, call [**glGetTexParameter**](https://learn.microsoft.com/windows/win32/opengl/glgettexparameter) with the *target* parameter set to the target texture to which the target is bound and set the *pname* parameter to GL\_TEXTURE\_RESIDENT. You must use this method to query the resident status of a default texture.

You cannot include **glAreTexturesResident** in display lists.

The **glAreTexturesResident** function returns the residency status of the textures at the time of invocation. It does not guarantee that the textures will remain resident at any other time.

If textures reside in virtual memory (there is no texture memory), they are considered always resident.

> [!Note]
> The **glAreTexturesResident** function is only available in OpenGL version 1.1 or later.

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

[**glGetTexParameter**](https://learn.microsoft.com/windows/win32/opengl/glgettexparameter)

[**glPrioritizeTextures**](https://learn.microsoft.com/windows/win32/opengl/glprioritizetextures)

[**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d)

[**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d)

