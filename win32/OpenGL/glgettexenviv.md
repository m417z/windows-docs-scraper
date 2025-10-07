# glGetTexEnviv function

The [**glGetTexEnvfv**](https://learn.microsoft.com/windows/win32/opengl/glgettexenvfv) and **glGetTexEnviv** functions return texture environment parameters.

## Parameters

*target*

A texture environment. Must be GL\_TEXTURE\_ENV.

*pname*

The symbolic name of a texture environment parameter. The following values are accepted.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_TEXTURE\_ENV\_MODE** | The *params* parameter returns the single-valued texture environment mode, a symbolic constant.<br> |
| **GL\_TEXTURE\_ENV\_COLOR** | The *params* parameter returns four integer or floating-point values that are the texture environment color. Integer values, when requested, are linearly mapped from the internal floating-point representation such that 1.0 maps to the most positive representable integer, and -1.0 maps to the most negative representable integer.<br> |

*params*

Returns the requested data.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *target* or *pname* was not an accepted value.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glGetTexEnv** function returns in *params* selected values of a texture environment that was specified with [**glTexEnv**](https://learn.microsoft.com/windows/win32/opengl/gltexenv-functions). The *target* parameter specifies a texture environment. Currently, only one texture environment is defined and supported: GL\_TEXTURE\_ENV.

The *pname* parameter names a specific texture environment parameter.

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

[**glTexEnv**](https://learn.microsoft.com/windows/win32/opengl/gltexenv-functions)

