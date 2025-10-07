# glColorMaterial function

The **glColorMaterial** function causes a material color to track the current color.

## Parameters

*face*

Specifies whether front, back, or both front and back material parameters should track the current color. Accepted values are GL\_FRONT, GL\_BACK, and GL\_FRONT\_AND\_BACK. The default value is GL\_FRONT\_AND\_BACK.

*mode*

Specifies which of several material parameters track the current color. Accepted values are GL\_EMISSION, GL\_AMBIENT, GL\_DIFFUSE, GL\_SPECULAR, and GL\_AMBIENT\_AND\_DIFFUSE. The default value is GL\_AMBIENT\_AND\_DIFFUSE.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *face* or *mode* was not an accepted value.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glColorMaterial** function specifies which material parameters track the current color. When you enable GL\_COLOR\_MATERIAL, for each of the material or materials specified by *face*, the material parameter or parameters specified by *mode* track the current color at all times. Enable and disable GL\_COLOR\_MATERIAL with the functions [**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable) and [**glDisable**](https://learn.microsoft.com/windows/win32/opengl/gldisable), which you call with GL\_COLOR\_MATERIAL as their argument. By default, GL\_COLOR\_MATERIAL is disabled.

With **glColorMaterial**, you can change a subset of material parameters for each vertex using only the [**glColor**](https://learn.microsoft.com/windows/win32/opengl/glcolor-functions) function, without calling [**glMaterial**](https://learn.microsoft.com/windows/win32/opengl/glmaterial-functions). If you are going to specify only such a subset of parameters for each vertex, it is better to do so with **glColorMaterial** than with **glMaterial**.

The following functions retrieve information related to **glColorMaterial**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_COLOR\_MATERIAL\_PARAMETER

**glGet** with argument GL\_COLOR\_MATERIAL\_FACE

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument GL\_COLOR\_MATERIAL

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

[**glColor**](https://learn.microsoft.com/windows/win32/opengl/glcolor-functions)

[**glDisable**](https://learn.microsoft.com/windows/win32/opengl/gldisable)

[**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled)

[**glLight**](https://learn.microsoft.com/windows/win32/opengl/gllight-functions)

[**glLightModel**](https://learn.microsoft.com/windows/win32/opengl/gllightmodel-functions)

[**glMaterial**](https://learn.microsoft.com/windows/win32/opengl/glmaterial-functions)

