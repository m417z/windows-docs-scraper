# glGetTexParameterfv function

The **glGetTexParameterfv** and [**glGetTexParameteriv**](https://learn.microsoft.com/windows/win32/opengl/glgettexparameteriv) functions return texture parameter values.

## Parameters

*target*

The symbolic name of the target texture. GL\_TEXTURE\_1D and GL\_TEXTURE\_2D are accepted.

*pname*

The symbolic name of a texture parameter. The following values are accepted.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_TEXTURE\_MAG\_FILTER** | Returns the single-valued texture magnification filter, a symbolic constant.<br> |
| **GL\_TEXTURE\_MIN\_FILTER** | Returns the single-valued texture minification filter, a symbolic constant.<br> |
| **GL\_TEXTURE\_WRAP\_S** | Returns the single-valued wrapping function for texture coordinate *s*, a symbolic constant.<br> |
| **GL\_TEXTURE\_WRAP\_T** | Returns the single-valued wrapping function for texture coordinate *t*, a symbolic constant.<br> |
| **GL\_TEXTURE\_BORDER\_COLOR** | Returns four integer or floating-point numbers that comprise the RGBA color of the texture border. Floating-point values are returned in the range \[0,1\]. Integer values are returned as a linear mapping of the internal floating-point representation such that 1.0 maps to the most positive representable integer and -1.0 maps to the most negative representable integer.<br> |
| **GL\_TEXTURE\_PRIORITY** | Returns the residence priority of the target texture (or the named texture bound to it). The initial value is 1. See [**glPrioritizeTextures**](https://learn.microsoft.com/windows/win32/opengl/glprioritizetextures).<br> |
| **GL\_TEXTURE\_RESIDENT** | Returns the residence status of the target texture. If the value returned in params is GL\_TRUE, the texture is resident in texture memory. See [**glAreTexturesResident**](https://learn.microsoft.com/windows/win32/opengl/glaretexturesresident).<br> |

*params*

Returns the texture parameters.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *target* or *name* was not an accepted value.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glGetTexParameter** function returns in *params* the value or values of the texture parameter specified as *pname*. The *target* parameter defines the target texture, either GL\_TEXTURE\_1D or GL\_TEXTURE\_2D, to specify one-dimensional or two-dimensional texturing. The *pname* parameter accepts the same symbols as [**glTexParameter**](https://learn.microsoft.com/windows/win32/opengl/gltexparameter-functions), with the same interpretations.

If an error is generated, no change is made to the contents of *params*.

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

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glTexParameter**](https://learn.microsoft.com/windows/win32/opengl/gltexparameter-functions)

