# glFogiv function

The **glFogfv** function specifies fog parameters.

## Parameters

*pname*

Specifies a fog parameter.

Accepts one of the following values.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_FOG\_MODE** | The *params* parameter is a single integer value that specifies the equation to be used to compute the fog blend factor, *f*. Three symbolic constants are accepted: GL\_LINEAR, GL\_EXP, and GL\_EXP2. The equations corresponding to these symbolic constants are defined in the following Remarks section. The default fog mode is GL\_EXP.<br> |
| **GL\_FOG\_DENSITY** | The *params* parameter is a single integer value that specifies *density*, the fog density used in both exponential fog equations. Only nonnegative densities are accepted. The default fog density is 1.0.<br> |
| **GL\_FOG\_START** | The *params* parameter is a single integer value that specifies *start*, the near distance used in the linear fog equation. The default near distance is 0.0.<br> |
| **GL\_FOG\_END** | The *params* parameter is a single integer value that specifies *end*, the far distance used in the linear fog equation. The default far distance is 1.0.<br> |
| **GL\_FOG\_INDEX** | The *params* parameter is a single integer value that specifies *i*f , the fog color index. The default fog index is 0.0.<br> |
| **GL\_FOG\_COLOR** | The *params* parameter contains four integer or floating-point values that specify *C*f , the fog color. Integer values are mapped linearly such that the most positive representable value maps to 1.0, and the most negative representable value maps to -1.0. Floating-point values are mapped directly. After conversion, all color components are clamped to the range \[0,1\]. The default fog color is (0,0,0,0).<br> |

*params*

Specifies the value or values to be assigned to *pname*. GL\_FOG\_COLOR requires an array of four values. All other parameters accept an array containing only a single value.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *pname* was not an accepted value.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

You enable and disable fog with [**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable) and [**glDisable**](https://learn.microsoft.com/windows/win32/opengl/gldisable), using the argument GL\_FOG. While enabled, fog affects rasterized geometry, bitmaps, and pixel blocks, but not buffer-clear operations.

The **glFogiv** function assigns the value or values in *params* to the fog parameter specified by *pname*.

Fog blends a fog color with each rasterized pixel fragment's posttexturing color using a blending factor *f*. Factor *f* is computed in one of three ways, depending on the fog mode. Let *z* be the distance in eye coordinates from the origin to the fragment being fogged. The equation for GL\_LINEAR fog is:

![Equation showing the value of the blending factor in GL_LINEAR fog mode as a function of distance.](https://learn.microsoft.com/windows/win32/opengl/images/fog01.png)

The equation for GL\_EXP fog is:

![Equation showing the value of the blending factor in GL_EXP fog mode.](https://learn.microsoft.com/windows/win32/opengl/images/fog02.png)

The equation for GL\_EXP2 fog is:

![Equation showing the value of the blending factor in GL_EXP2 fog mode.](https://learn.microsoft.com/windows/win32/opengl/images/fog03.png)

Regardless of the fog mode, *f* is clamped to the range \[0,1\] after it is computed. Then, if OpenGL is in RGBA color mode, the fragment's color *C*r is replaced by

![Equation showing the fogged fragment's color as a function of blending factor and fog color.](https://learn.microsoft.com/windows/win32/opengl/images/fog04.png)

In color-index mode, the fragment's color index *i*r is replaced by

![Equation showing the fogged fragment's color index as a function of blending factor and indexed color.](https://learn.microsoft.com/windows/win32/opengl/images/fog05.png)

The following functions retrieve information related to the **glFog** functions:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_FOG\_COLOR

**glGet** with argument GL\_FOG\_INDEX

**glGet** with argument GL\_FOG\_DENSITY

**glGet** with argument GL\_FOG\_START

**glGet** with argument GL\_FOG\_END

**glGet** with argument GL\_FOG\_MODE

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument GL\_FOG

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

[**glDisable**](https://learn.microsoft.com/windows/win32/opengl/gldisable)

[**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled)

