# glMaterialfv function

The **glMaterialfv** function specifies material parameters for the lighting model.

## Parameters

*face*

The face or faces that are being updated. Must be one of the following: GL\_FRONT, GL\_BACK, or GL\_FRONT and GL\_BACK.

*pname*

The material parameter of the face or faces being updated. The parameters that can be specified using **glMaterialfv**, and their interpretations by the lighting equation, are as follows.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**GL\_AMBIENT**

| The params parameter contains four floating-point values that specify the ambient RGBA reflectance of the material. Integer values are mapped linearly such that the most positive representable value maps to 1.0, and the most negative representable value maps to -1.0. Floating-point values are mapped directly. Neither integer nor floating-point values are clamped. The default ambient reflectance for both front-facing and back-facing materials is (0.2, 0.2, 0.2, 1.0). <br> |
|

**GL\_DIFFUSE**

| The params parameter contains four floating-point values that specify the diffuse RGBA reflectance of the material. Integer values are mapped linearly such that the most positive representable value maps to 1.0, and the most negative representable value maps to -1.0. Floating-point values are mapped directly. Neither integer nor floating-point values are clamped. The default diffuse reflectance for both front-facing and back-facing materials is (0.8, 0.8, 0.8, 1.0). <br> |
|

**GL\_SPECULAR**

| The params parameter contains four floating-point values that specify the specular RGBA reflectance of the material. Integer values are mapped linearly such that the most positive representable value maps to 1.0, and the most negative representable value maps to -1.0. Floating-point values are mapped directly. Neither integer nor floating-point values are clamped. The default specular reflectance for both front-facing and back-facing materials is (0.0, 0.0, 0.0, 1.0). <br> |
|

**GL\_EMISSION**

| The params parameter contains four floating-point values that specify the RGBA emitted light intensity of the material. Integer values are mapped linearly such that the most positive representable value maps to 1.0, and the most negative representable value maps to -1.0. Floating-point values are mapped directly. Neither integer nor floating-point values are clamped. The default emission intensity for both front-facing and back-facing materials is (0.0, 0.0, 0.0, 1.0). <br> |
|

**GL\_SHININESS**

| The *param* parameter is a single integer value that specifies the RGBA specular exponent of the material. Integer values are mapped directly. Only values in the range \[0, 128\] are accepted. The default specular exponent for both front-facing and back-facing materials is 0. <br> |
|

**GL\_AMBIENT\_AND\_DIFFUSE**

| Equivalent to calling [**glMaterial**](https://learn.microsoft.com/windows/win32/opengl/glmaterial-functions) twice with the same parameter values, once with GL\_AMBIENT and once with GL\_DIFFUSE. <br> |
|

**GL\_COLOR\_INDEXES**

| The params parameter contains three floating-point values specifying the color indexes for ambient, diffuse, and specular lighting. These three values, and GL\_SHININESS, are the only material values used by the color-index mode lighting equation. Refer to [**glLightModel**](https://learn.microsoft.com/windows/win32/opengl/gllightmodel-functions) for a discussion of color-index lighting.<br> |

*params*

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

The [**glMaterialfv**](https://learn.microsoft.com/windows/win32/opengl/glmaterialf) function assigns values to material parameters. There are two matched sets of material parameters. One, the *front-facing* set, is used to shade points, lines, bitmaps, and all polygons (when two-sided lighting is disabled), or just front-facing polygons (when two-sided lighting is enabled). The other set, *back-facing*, is used to shade back-facing polygons only when two-sided lighting is enabled. Refer to [**glLightModel**](https://learn.microsoft.com/windows/win32/opengl/gllightmodel-functions) for details concerning one-sided and two-sided lighting calculations.

The [**glMaterialfv**](https://learn.microsoft.com/windows/win32/opengl/glmaterialf) function takes three arguments. The first, *face*, specifies whether the GL\_FRONT materials, the GL\_BACK materials, or both GL\_FRONT\_AND\_BACK materials will be modified. The second, *pname*, specifies which of several parameters in one or both sets will be modified. The third, *param*, specifies what value will be assigned to the specified parameter.

Material parameters are used in the lighting equation that is optionally applied to each vertex. The equation is discussed in [**glLightModel**](https://learn.microsoft.com/windows/win32/opengl/gllightmodel-functions).

The material parameters can be updated at any time. In particular, [**glMaterialfv**](https://learn.microsoft.com/windows/win32/opengl/glmaterialf) can be called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend). If only a single material parameter is to be changed per vertex, however, [**glColorMaterial**](https://learn.microsoft.com/windows/win32/opengl/glcolormaterial) is preferred over **glMaterialfv**.

The following function retrieves information related to [**glMaterialfv**](https://learn.microsoft.com/windows/win32/opengl/glmaterialf):

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

