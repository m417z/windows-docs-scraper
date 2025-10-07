# glGetLightfv function

The **glGetLightfv** and [**glGetLightiv**](https://learn.microsoft.com/windows/win32/opengl/glgetlightiv) functions return light source parameter values.

## Parameters

*light*

A light source. The number of possible lights depends on the implementation, but at least eight lights are supported. They are identified by symbolic names of the form GL\_LIGHT *i* where 0 = *i* < GL\_MAX\_LIGHTS.

*pname*

A light source parameter for *light*. The following symbolic names are accepted.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_AMBIENT** | The *params* parameter returns four integer or floating-point values representing the ambient intensity of the light source. Integer values, when requested, are linearly mapped from the internal floating-point representation such that 1.0 maps to the most positive representable integer value, and -1.0 maps to the most negative representable integer value. If the internal value is outside the range \[-1,1\], the corresponding integer return value is undefined.<br> |
| **GL\_DIFFUSE** | The *params* parameter returns four integer or floating-point values representing the diffuse intensity of the light source. Integer values, when requested, are linearly mapped from the internal floating-point representation such that 1.0 maps to the most positive representable integer value, and -1.0 maps to the most negative representable integer value. If the internal value is outside the range \[-1,1\], the corresponding integer return value is undefined.<br> |
| **GL\_SPECULAR** | The *params* parameter returns four integer or floating-point values representing the specular intensity of the light source. Integer values, when requested, are linearly mapped from the internal floating-point representation such that 1.0 maps to the most positive representable integer value, and -1.0 maps to the most negative representable integer value. If the internal value is outside the range \[-1,1\], the corresponding integer return value is undefined.<br> |
| **GL\_POSITION** | The *params* parameter returns four integer or floating-point values representing the position of the light source. Integer values, when requested, are computed by rounding the internal floating-point values to the nearest integer value. The returned values are those maintained in eye coordinates. They will not be equal to the values specified using [**glLight**](https://learn.microsoft.com/windows/win32/opengl/gllight-functions), unless the modelview matrix was identified at the time **glLight** was called.<br> |
| **GL\_SPOT\_DIRECTION** | The *params* parameter returns three integer or floating-point values representing the direction of the light source. Integer values, when requested, are computed by rounding the internal floating-point values to the nearest integer value. The returned values are those maintained in eye coordinates. They will not be equal to the values specified using **glLight**, unless the modelview matrix was identified at the time **glLight** was called. Although spot direction is normalized before being used in the lighting equation, the returned values are the transformed versions of the specified values prior to normalization.<br> |
| **GL\_SPOT\_EXPONENT** | The *params* parameter returns a single integer or floating-point value representing the spot exponent of the light. An integer value, when requested, is computed by rounding the internal floating-point representation to the nearest integer.<br> |
| **GL\_SPOT\_CUTOFF** | The *params* parameter returns a single integer or floating-point value representing the spot cutoff angle of the light. An integer value, when requested, is computed by rounding the internal floating-point representation to the nearest integer.<br> |
| **GL\_CONSTANT\_ATTENUATION** | The *params* parameter returns a single integer or floating-point value representing the constant (not distance-related) attenuation of the light. An integer value, when requested, is computed by rounding the internal floating-point representation to the nearest integer.<br> |
| **GL\_LINEAR\_ATTENUATION** | The *params* parameter returns a single integer or floating-point value representing the linear attenuation of the light. An integer value, when requested, is computed by rounding the internal floating-point representation to the nearest integer.<br> |
| **GL\_QUADRATIC\_ATTENUATION** | The *params* parameter returns a single integer or floating-point value representing the quadratic attenuation of the light. An integer value, when requested, is computed by rounding the internal floating-point representation to the nearest integer.<br> |

*params*

Returns the requested data.

## Return value

This function does not return a value.

## Remarks

The **glGetLight** function returns in *params* the value or values of a light source parameter. The *light* parameter names the light and is a symbolic name of the form GL\_LIGHT*i* for 0 = *i* < GL\_MAX\_LIGHTS, where GL\_MAX\_LIGHTS is an implementation-dependent constant that is greater than or equal to eight. The *pname* parameter specifies one of ten light source parameters, again by symbolic name.

It is always the case that GL\_LIGHT*i* = GL\_LIGHT0 + *i*.

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

[**glLight**](https://learn.microsoft.com/windows/win32/opengl/gllight-functions)

