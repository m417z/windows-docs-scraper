# glGetTexGenfv function

The [**glGetTexGendv**](https://learn.microsoft.com/windows/win32/opengl/glgettexgendv), **glGetTexGenfv**, and [**glGetTexGeniv**](https://learn.microsoft.com/windows/win32/opengl/glgettexgeniv) functions return texture coordinate generation parameters.

## Parameters

*coord*

A texture coordinate. Must be GL\_S, GL\_T, GL\_R, or GL\_Q.

*pname*

The symbolic name of the value(s) to be returned. Must be either GL\_TEXTURE\_GEN\_MODE or the name of one of the texture generation plane equations: GL\_OBJECT\_PLANE or GL\_EYE\_PLANE. These values are as follows.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**GL\_TEXTURE\_GEN\_MODE**

| The *params* parameter returns the single-valued texture generation function, a symbolic constant.<br> |
|

**GL\_OBJECT\_PLANE**

| The *params* parameter returns the four plane equation coefficients that specify object linear-coordinate generation. Integer values, when requested, are mapped directly from the internal floating-point representation.<br> |
|

**GL\_EYE\_PLANE**

| The *params* parameter returns the four plane equation coefficients that specify eye linear-coordinate generation. Integer values, when requested, are mapped directly from the internal floating-point representation. The returned values are those maintained in eye coordinates. They are not equal to the values specified using [**glTexGen**](https://learn.microsoft.com/windows/win32/opengl/gltexgen-functions), unless the modelview matrix was identified at the time **glTexGen** was called.<br> |

*params*

Returns the requested data.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *coord* or *pname* was not an accepted value.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glGetTexGen** function returns in *params* selected parameters of a texture-coordinate generation function that you specified with **glTexGen**. The *coord* parameter names one of the (*s*, *t*, *r*, *q*) texture coordinates, using the symbolic constant GL\_S, GL\_T, GL\_R, or GL\_Q.

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

[**glTexGen**](https://learn.microsoft.com/windows/win32/opengl/gltexgen-functions)

