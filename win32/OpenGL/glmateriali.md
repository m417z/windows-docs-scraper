# glMateriali function

The**glMateriali** function specifies material parameters for the lighting model.

## Parameters

*face*

The face or faces that are being updated. Must be one of the following: GL\_FRONT, GL\_BACK, or GL\_FRONT and GL\_BACK.

*pname*

The single-valued material parameter of the face or faces being updated. Must be GL\_SHININESS.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**GL\_SHININESS**

| The *param* parameter is a single integer that specifies the RGBA specular exponent of the material. Integer values are mapped directly. Only values in the range \[0, 128\] are accepted. The default specular exponent for both front-facing and back-facing materials is 0. <br> |

*param*

The value to which parameter GL\_SHININESS will be set.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|---------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | Either *face* or *pname* was not an accepted value.<br> |
| **GL\_INVALID\_VALUE** | A specular exponent outside the range of \[0, 128\] was specified.<br> |

## Remarks

The **glMateriali** function assigns values to material parameters. There are two matched sets of material parameters. One, the *front-facing* set, is used to shade points, lines, bitmaps, and all polygons (when two-sided lighting is disabled), or just front-facing polygons (when two-sided lighting is enabled). The other set, *back-facing*, is used to shade back-facing polygons only when two-sided lighting is enabled. Refer to [**glLightModel**](https://learn.microsoft.com/windows/win32/opengl/gllightmodel-functions) for details concerning one-sided and two-sided lighting calculations.

The **glMateriali** function takes three arguments. The first, *face*, specifies whether the GL\_FRONT materials, the GL\_BACK materials, or both GL\_FRONT\_AND\_BACK materials will be modified. The second, *pname*, specifies which of several parameters in one or both sets will be modified. The third, *param*, specifies what value will be assigned to the specified parameter.

Material parameters are used in the lighting equation that is optionally applied to each vertex. The equation is discussed in [**glLightModel**](https://learn.microsoft.com/windows/win32/opengl/gllightmodel-functions).

The material parameters can be updated at any time. In particular, **glMateriali** can be called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend). If only a single material parameter is to be changed per vertex, however, [**glColorMaterial**](https://learn.microsoft.com/windows/win32/opengl/glcolormaterial) is preferred over **glMateriali**.

The following function retrieves information related to **glMateriali**:

[**glGetMaterial**](https://learn.microsoft.com/windows/win32/opengl/glgetmaterial)

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Gl.h |
| Library<br> | Opengl32.lib |
| DLL<br> | Opengl32.dll |

## See also

[**glColorMaterial**](https://learn.microsoft.com/windows/win32/opengl/glcolormaterial)

[**glLight**](https://learn.microsoft.com/windows/win32/opengl/gllight-functions)

[**glLightModel**](https://learn.microsoft.com/windows/win32/opengl/gllightmodel-functions)

