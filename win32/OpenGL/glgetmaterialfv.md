# glGetMaterialfv function

The **glGetMaterialfv** and [**glGetMaterialiv**](https://learn.microsoft.com/windows/win32/opengl/glgetmaterialiv) functions return material parameters.

## Parameters

*face*

Specifies which of the two materials is being queried. GL\_FRONT or GL\_BACK are accepted, representing the front and back materials, respectively.

*pname*

The material parameter to return. The following values are accepted.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_AMBIENT** | The *params* parameter returns four integer or floating-point values representing the ambient reflectance of the material. Integer values, when requested, are linearly mapped from the internal floating-point representation such that 1.0 maps to the most positive representable integer value, and -1.0 maps to the most negative representable integer value. If the internal value is outside the range \[-1,1\], the corresponding integer return value is undefined.<br> |
| **GL\_DIFFUSE** | The *params* parameter returns four integer or floating-point values representing the diffuse reflectance of the material. Integer values, when requested, are linearly mapped from the internal floating-point representation such that 1.0 maps to the most positive representable integer value, and -1.0 maps to the most negative representable integer value. If the internal value is outside the range \[-1,1\], the corresponding integer return value is undefined.<br> |
| **GL\_SPECULAR** | The *params* parameter returns four integer or floating-point values representing the specular reflectance of the material. Integer values, when requested, are linearly mapped from the internal floating-point representation such that 1.0 maps to the most positive representable integer value, and -1.0 maps to the most negative representable integer value. If the internal value is outside the range \[-1,1\], the corresponding integer return value is undefined.<br> |
| **GL\_EMISSION** | The *params* parameter returns four integer or floating-point values representing the emitted light intensity of the material. Integer values, when requested, are linearly mapped from the internal floating-point representation such that 1.0 maps to the most positive representable integer value, and -1.0 maps to the most negative representable integer value. If the internal value is outside the range \[-1,1\], the corresponding integer return value is undefined.<br> |
| **GL\_SHININESS** | The *params* parameter returns one integer or floating-point value representing the specular exponent of the material. Integer values, when requested, are computed by rounding the internal floating-point value to the nearest integer value.<br> |
| **GL\_COLOR\_INDEXES** | The *params* parameter returns three integer or floating-point values representing the ambient, diffuse, and specular indexes of the material. Use these indexes only for color-index lighting. (The other parameters are all used only for RGBA lighting.) Integer values, when requested, are computed by rounding the internal floating-point values to the nearest integer values.<br> |

*params*

Returns the requested data.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *target* or *query* was not an accepted value.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glGetMaterial** function returns in *params* the value or values of parameter *pname* of material *face*.

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

[**glMaterial**](https://learn.microsoft.com/windows/win32/opengl/glmaterial-functions)

