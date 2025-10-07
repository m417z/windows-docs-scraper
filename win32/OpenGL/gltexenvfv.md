# glTexEnvfv function

The **glTexEnvfv** function sets a texture environment parameter.

## Parameters

*target*

A texture environment. Must be GL\_TEXTURE\_ENV.

*pname*

The symbolic name of a single-valued texture environment parameter. Accepted values are GL\_TEXTURE\_ENV\_MODE and GL\_TEXTURE\_ENV\_COLOR.

*params*

A pointer to an array of parameters: either a single symbolic constant or an RGBA color.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *target* or *pname* was not one of the accepted defined values, or when *params* should have had a defined constant value (based on the value of *pname*) and did not.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

A texture environment specifies how texture values are interpreted when a fragment is textured. The *target* parameter must be GL\_TEXTURE\_ENV. The *pname* parameter can be either GL\_TEXTURE\_ENV\_MODE or GL\_TEXTURE\_ENV\_COLOR.

If *pname* is GL\_TEXTURE\_ENV\_MODE, then *params* is (or points to) the symbolic name of a texture function. Three texture functions are defined: GL\_MODULATE, GL\_DECAL, and GL\_BLEND.

A texture function acts on the fragment to be textured using the texture image value that applies to the fragment (see [**glTexParameter**](https://learn.microsoft.com/windows/win32/opengl/gltexparameter-functions)) and produces an RGBA color for that fragment. The following table shows how the RGBA color is produced for each of the three texture functions that can be chosen. *C* is a triple of color values (RGB) and *A* is the associated alpha value. RGBA values extracted from a texture image are in the range \[0, 1\]. The subscript *f* refers to the incoming fragment, the subscript *t* to the texture image, the subscript *c* to the texture environment color, and subscript *v* indicates a value produced by the texture function.

A texture image can have up to four components per texture element (see [**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d) and [**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d)). In a one-component image, Lt indicates that single component. A two-component image uses *L?* and *A?* . A three-component image has only a color value, *C?* . A four-component image has both a color value *C?* and an alpha value *A?* .

| Number of components | GL_MODULATE | GL_DECAL | GL_BLEND |
| --- | --- | --- | --- |
| 1${REMOVE}$\ | *Cv* = *L?* *Cf* | undefined${REMOVE}$\ | *Cv* = *(1* - *L?* *)Cf* + *L?* *Cc* |
| *Av* = *Af* | *Av* = *Af* |

| 2${REMOVE}$\ | *Cv* = *L?* *Cf* | undefined${REMOVE}$\ | *Cv* = *(1* - *L?* *)Cf* + *L?* *Cc* |
| *A* *v* = *Af* | *Av* = *Af* |

| 3${REMOVE}$\ | *Cv* = *C?* *Cf* | *Cv* = *C?* | undefined${REMOVE}$\ |
| *Av* = *Af* | *Av* = *Af* |

| 4${REMOVE}$\ | *Cv* = *C?* *Cf* | *Cv* = (1 - *A?* *)Cf* + *A?* *C?* | undefined${REMOVE}$\ |
| *Av* = *A?* *Af* | *Av* = *Af* |

If pname is GL\_TEXTURE\_ENV\_COLOR, *params* is a pointer to an array that holds an RGBA color consisting of four values. Integer color components are interpreted linearly such that the most positive integer maps to 1.0, and the most negative integer maps to -1.0. The values are clamped to the range \[0, 1\] when they are specified. *Cc* takes these four values.

GL\_TEXTURE\_ENV\_MODE defaults to GL\_MODULATE and GL\_TEXTURE\_ENV\_COLOR defaults to (0, 0, 0, 0).

The following function retrieves information related to **glTexEnvfv**:

[**glTexGetEnvfv**](https://learn.microsoft.com/windows/win32/opengl/glgettexenvfv)

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

[**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d)

[**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d)

[**glTexParameter**](https://learn.microsoft.com/windows/win32/opengl/gltexparameter-functions)

