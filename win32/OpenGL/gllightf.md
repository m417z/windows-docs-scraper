# glLightf function

The **glLightf** function returns light source parameter values.

## Parameters

*light*

The identifier of a light. The number of possible lights depends on the implementation, but at least eight lights are supported. They are identified by symbolic names of the form GL\_LIGHT*i* where *i* is a value: 0 to GL\_MAX\_LIGHTS - 1.

*pname*

A single-valued light source parameter for *light*. The following symbolic names are accepted.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_SPOT\_EXPONENT** | The *param* parameter is a single floating-point value that specifies the intensity distribution of the light. Floating-point values are mapped directly. Only values in the range \[0, 128\] are accepted. <br> Effective light intensity is attenuated by the cosine of the angle between the direction of the light and the direction from the light to the vertex being lighted, raised to the power of the spot exponent. Thus, higher spot exponents result in a more focused light source, regardless of the spot cutoff angle. The default spot exponent is 0, resulting in uniform light distribution.<br> |
| **GL\_SPOT\_CUTOFF** | The *param* parameter is a single floating-point value that specifies the maximum spread angle of a light source. Floating-point values are mapped directly. Only values in the range \[0, 90\], and the special value 180, are accepted. <br> If the angle between the direction of the light and the direction from the light to the vertex being lighted is greater than the spot cutoff angle, then the light is completely masked. Otherwise, its intensity is controlled by the spot exponent and the attenuation factors. The default spot cutoff is 180, resulting in uniform light distribution.<br> |
| **GL\_CONSTANT\_ATTENUATION, GL\_LINEAR\_ATTENUATION, GL\_QUADRATIC\_ATTENUATION** | The *param* parameter is a single floating-point value that specifies one of the three light attenuation factors. Floating-point values are mapped directly. Only nonnegative values are accepted. <br> If the light is positional, rather than directional, its intensity is attenuated by the reciprocal of the sum of: the constant factor, the linear factor multiplied by the distance between the light and the vertex being lighted, and the quadratic factor multiplied by the square of the same distance. The default attenuation factors are (1,0,0), resulting in no attenuation.<br> |

*param*

Specifies the value that parameter *pname* of light source *light* will be set to.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *light* or *pname* was not an accepted value.<br> |
| **GL\_INVALID\_VALUE** | A spot exponent value was specified outside the range \[0, 128\], or spot cutoff was specified outside the range \[0, 90\] (except for the special value 180), or a negative attenuation factor was specified.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glLightf** function sets the value or values of individual light source parameters. The *light* parameter names the light and is a symbolic name of the form GL\_LIGHT*i*, where 0 = *i* < GL\_MAX\_LIGHTS.

The *pname* parameter specifies one of the light source parameters, again by symbolic name. The *param* parameter is either a single value or a pointer to an array that contains the new values.

Lighting calculation is enabled and disabled using [**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable) and [**glDisable**](https://learn.microsoft.com/windows/win32/opengl/gldisable) with argument GL\_LIGHTING. When lighting is enabled, light sources that are enabled contribute to the lighting calculation. Light source *i* is enabled and disabled using **glEnable** and **glDisable** with argument GL\_LIGHT*i*.

It is always the case that GL\_LIGHT*i* = GL\_LIGHT0 + *i*.

The following functions retrieve information related to the **glLightf** function:

[**glGetLight**](https://learn.microsoft.com/windows/win32/opengl/glgetlight)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument GL\_LIGHTING

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

[**glColorMaterial**](https://learn.microsoft.com/windows/win32/opengl/glcolormaterial)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glLightModel**](https://learn.microsoft.com/windows/win32/opengl/gllightmodel-functions)

[**glMaterial**](https://learn.microsoft.com/windows/win32/opengl/glmaterial-functions)

