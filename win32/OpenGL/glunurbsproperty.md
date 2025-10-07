# gluNurbsProperty function

The **gluNurbsProperty** function sets a Non-Uniform Rational B-Spline ([NURBS](https://learn.microsoft.com/windows/win32/opengl/using-nurbs-curves-and-surfaces)) property.

## Parameters

*nobj*

The NURBS object (created with [**gluNewNurbsRenderer**](https://learn.microsoft.com/windows/win32/opengl/glunewnurbsrenderer)).

*property*

The property to be set. The following values are valid:

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GLU\_SAMPLING\_TOLERANCE** | Specifies the maximum length, in pixels, to use when the sampling method is set to GLU\_PATH\_LENGTH. The default value is 50.0 pixels.<br> |
| **GLU\_DISPLAY\_MODE** | The *value* parameter defines how a NURBS surface is to be rendered. You can set *value* to GLU\_FILL, GLU\_OUTLINE\_POLYGON, or GLU\_OUTLINE\_PATCH. <br> GLU\_FILL. The surface is rendered as a set of polygons. This is the default value. <br> GLU\_OUTLINE\_POLYGON. The NURBS library draws only the outlines of the polygons created by tessellation. <br> GLU\_OUTLINE\_PATCH. Only the outlines of patches and trim curves defined by the user are drawn.<br> |
| **GLU\_CULLING** | The *value* parameter is a Boolean value. When value is set to GL\_TRUE, NURBS curves whose control points lie outside the current viewport are discarded prior to tessellation. The default is GL\_FALSE (because a NURBS curve cannot fall entirely within the convex hull of its control points).<br> |
| **GLU\_AUTO\_LOAD\_MATRIX** | The *value* parameter is a Boolean value. When set to GL\_TRUE, the NURBS code downloads the projection matrix, modelview matrix, and viewport from the OpenGL server to compute sampling and culling matrices for each NURBS curve that is rendered. Sampling and culling matrices are required to determine the tessellation of a NURBS surface into line segments or polygons and to cull a NURBS surface if it lies outside of the viewport. <br> If this mode is set to GL\_FALSE, you must provide a projection matrix, modelview matrix, and viewport for the NURBS renderer to use to construct sampling and culling matrices. You can do this with the [**gluLoadSamplingMatrices**](https://learn.microsoft.com/windows/win32/opengl/gluloadsamplingmatrices) function.<br> The default for this mode is GL\_TRUE. Changing this mode from GL\_TRUE to GL\_FALSE does not affect the sampling and culling matrices until you call [**gluLoadSamplingMatrices**](https://learn.microsoft.com/windows/win32/opengl/gluloadsamplingmatrices). <br> The following property parameters are supported in GLU version 1.1 or later and are not valid for GLU version 1.0: GLU\_PARAMETRIC\_TOLERANCE, GLU\_SAMPLING\_METHOD, GLU\_U\_STEP, and GLU\_V\_STEP.<br> The following value parameters are supported in GLU version 1.1 or later and are not valid for GLU version 1.0: GLU\_PATH\_LENGTH, GLU\_PARAMETRIC\_ERROR, and GLU\_DOMAIN\_DISTANCE.<br> |
| **GLU\_PARAMETRIC\_TOLERANCE** | Specifies the maximum distance, in pixels, to use when the sampling method is set to GLU\_PARAMETRIC\_ERROR. The default value is 0.5.<br> |
| **GLU\_SAMPLING\_METHOD** | Specifies how to tessallate a NURBS surface. GLU\_SAMPLING\_METHOD can have one of the following three values. <br> GLU\_PATH\_LENGTH. The default value. Specifies that surfaces rendered with the maximum length, in pixels, of the edges of the tessellation polygons are no greater than the value specified by GLU\_SAMPLING\_TOLERANCE. <br> GLU\_PARAMETRIC\_ERROR. Specifies that in rendering the surface, the value of GLU\_PARAMETRIC\_TOLERANCE specifies the maximum distance, in pixels, between the tessellation polygons and the surfaces they approximate. <br> GLU\_DOMAIN\_DISTANCE. Specifies, in parametric coordinates, how many sample points per unit length to take in the *u* and *v* dimensions.<br> |
| **GLU\_U\_STEP** | Specifies the number of sample points per unit length taken along the *u* dimension in parametric coordinates. The value of GLU\_U\_STEP is used when GLU\_SAMPLING\_METHOD is set to GLU\_DOMAIN\_DISTANCE. The default value is 100.<br> |
| **GLU\_V\_STEP** | Specifies the number of sample points per unit length taken along the *v* dimension in parametric coordinates. The value of GLU\_V\_STEP is used when GLU\_SAMPLING\_METHOD is set to GLU\_DOMAIN\_DISTANCE. The default value is 100.<br> |

*value*

The value to which to set the indicated property. The *value* parameter can be a numeric value or one of the following three values: GLU\_PATH\_LENGTH, GLU\_PARAMETRIC\_ERROR, or GLU\_DOMAIN\_DISTANCE.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GLU\_PATH\_LENGTH** | The default value. Specifies that surfaces rendered with the maximum length, in pixels, of the edges of the tessellation polygons are no greater than the value specified by GLU\_SAMPLING\_TOLERANCE.<br> |
| **GLU\_PARAMETRIC\_ERROR** | Specifies that in rendering the surface, the value of GLU\_PARAMETRIC\_TOLERANCE specifies the maximum distance, in pixels, between the tessellation polygons and the surfaces they approximate.<br> |
| **GLU\_DOMAIN\_DISTANCE** | Specifies, in parametric coordinates, how many sample points per unit length to take in the *u* and *v* dimensions.<br> |

## Return value

This function does not return a value.

## Remarks

Use **gluNurbsProperty** to control properties stored in a NURBS object. These properties affect the way a NURBS curve is rendered.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Glu.h |
| Library<br> | Glu32.lib |
| DLL<br> | Glu32.dll |

## See also

[**gluGetNurbsProperty**](https://learn.microsoft.com/windows/win32/opengl/glugetnurbsproperty)

[**gluGetString**](https://learn.microsoft.com/windows/win32/opengl/glugetstring)

[**gluLoadSamplingMatrices**](https://learn.microsoft.com/windows/win32/opengl/gluloadsamplingmatrices)

[**gluNewNurbsRenderer**](https://learn.microsoft.com/windows/win32/opengl/glunewnurbsrenderer)

