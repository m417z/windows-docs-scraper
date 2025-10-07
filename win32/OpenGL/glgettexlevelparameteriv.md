# glGetTexLevelParameteriv function

The [**glGetTexLevelParameterfv**](https://learn.microsoft.com/windows/win32/opengl/glgettexlevelparameterfv) and **glGetTexLevelParameteriv** functions return texture parameter values for a specific level of detail.

## Parameters

*target*

The symbolic name of the target texture: either GL\_TEXTURE\_1D, GL\_TEXTURE\_2D, GL\_PROXY\_TEXTURE\_1D, or GL\_PROXY\_TEXTURE\_2D.

*level*

The level-of-detail number of the desired image. Level 0 is the base image level. Level *n* is the *n*th mipmap reduction image.

*pname*

The symbolic name of a texture parameter. The following parameter names are accepted.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**GL\_TEXTURE\_WIDTH**

| The *params* parameter returns a single value containing the width of the texture image. This value includes the border of the texture image.<br> |
|

**GL\_TEXTURE\_HEIGHT**

| The *params* parameter returns a single value containing the height of the texture image. This value includes the border of the texture image.<br> |
|

**GL\_TEXTURE\_INTERNAL\_FORMAT**

| The *params* parameter returns a single value which describes the texel format of the texture.<br> |
|

**GL\_TEXTURE\_BORDER**

| The *params* parameter returns a single value: the width in pixels of the border of the texture image.<br> |
|

**GL\_TEXTURE\_RED\_SIZE**

| The internal storage resolution of the red component of a texel. The resolution chosen by the OpenGL will be a close match for the resolution requested by the user with the component argument of [**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d) or [**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d).<br> |
|

**GL\_TEXTURE\_GREEN\_SIZE**

| The internal storage resolution of the green component of a texel. The resolution chosen by the OpenGL will be a close match for the resolution requested by the user with the component argument of [**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d) or [**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d).<br> |
|

**GL\_TEXTURE\_BLUE\_SIZE**

| The internal storage resolution of the blue component of a texel. The resolution chosen by the OpenGL will be a close match for the resolution requested by the user with the component argument of [**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d) or [**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d).<br> |
|

**GL\_TEXTURE\_ALPHA\_SIZE**

| The internal storage resolution of the alpha component of a texel. The resolution chosen by the OpenGL will be a close match for the resolution requested by the user with the component argument of [**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d) or [**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d).<br> |
|

**GL\_TEXTURE\_LUMINANCE\_SIZE**

| The internal storage resolution of the luminance component of a texel. The resolution chosen by the OpenGL will be a close match for the resolution requested by the user with the component argument of [**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d) or [**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d).<br> |
|

**GL\_TEXTURE\_INTENSITY\_SIZE**

| The internal storage resolution of the intensity component of a texel. The resolution chosen by the OpenGL will be a close match for the resolution requested by the user with the component argument of [**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d) or [**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d).<br> |
|

**GL\_TEXTURE\_COMPONENTS**

| The *params* parameter returns a single value: the number of components in the texture image.<br> |

*params*

Returns the requested data.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *target* or *pname* was not an accepted value.<br> |
| **GL\_INVALID\_VALUE** | *level* is less than zero or greater than *log*2*(max)*, where *max* is the returned value of GL\_MAX\_TEXTURE\_SIZE.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glGetTexLevelParameter** function returns in *params* texture parameter values for a specific level-of-detail value, specified as *level*. The *target* parameter defines the target texture, either GL\_TEXTURE\_1D, GL\_TEXTURE\_2D, GL\_PROXY\_TEXTURE\_1D, or GL\_PROXY\_TEXTURE\_2D to specify one-dimensional or two-dimensional texturing. The *pname* parameter specifies the texture parameter whose value or values will be returned.

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

[**glGetTexParameter**](https://learn.microsoft.com/windows/win32/opengl/glgettexparameter)

[**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d)

[**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d)

[**glTexParameter**](https://learn.microsoft.com/windows/win32/opengl/gltexparameter-functions)

