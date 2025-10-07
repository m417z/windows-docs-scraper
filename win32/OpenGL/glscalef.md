# glScalef function

The [**glScaled**](https://learn.microsoft.com/windows/win32/opengl/glscaled) and **glScalef** functions multiply the current matrix by a general scaling matrix.

## Parameters

*x*

Scale factors along the *x* axis.

*y*

Scale factors along the *y* axis.

*z*

Scale factors along the *z* axis.

## Return value

This function does not return a value.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glScalef** function produces a general scaling along the *x*, *y*, and *z* axes. The three arguments indicate the desired scale factors along each of the three axes. The resulting matrix appears in the following image.

![Diagram showing the matrix of scale factors along the x, y, and z axes.](https://learn.microsoft.com/windows/win32/opengl/images/scale01.png)

The current matrix (see [**glMatrixMode**](https://learn.microsoft.com/windows/win32/opengl/glmatrixmode)) is multiplied by this scale matrix, with the product replacing the current matrix. That is, if M is the current matrix and S is the scale matrix, then M is replaced with M S.

If the matrix mode is either GL\_MODELVIEW or GL\_PROJECTION, all objects drawn after **glScalef** is called are scaled. Use [**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix) and [**glPopMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpopmatrix) to save and restore the unscaled coordinate system.

If scale factors other than 1.0 are applied to the modelview matrix and lighting is enabled, automatic normalization of normals should probably also be enabled ([**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable) and [**glDisable**](https://learn.microsoft.com/windows/win32/opengl/gldisable) with argument GL\_NORMALIZE).

The following functions retrieve information related to **glScalef**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_MATRIX\_MODE

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_MODELVIEW\_MATRIX

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_PROJECTION\_MATRIX

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_TEXTURE\_MATRIX

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

[**glMatrixMode**](https://learn.microsoft.com/windows/win32/opengl/glmatrixmode)

[**glMultMatrix**](https://learn.microsoft.com/windows/win32/opengl/glmultmatrix)

[**glPopMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpopmatrix)

[**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix)

[**glRotated**](https://learn.microsoft.com/windows/win32/opengl/glrotated)

[**glRotatef**](https://learn.microsoft.com/windows/win32/opengl/glrotatef)

[**glTranslate**](https://learn.microsoft.com/windows/win32/opengl/gltranslate)

