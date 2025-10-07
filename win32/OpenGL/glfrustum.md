# glFrustum function

The **glFrustum** function multiplies the current matrix by a perspective matrix.

## Parameters

*left*

The coordinate for the left-vertical clipping plane.

*right*

The coordinate for the right-vertical clipping plane.

*bottom*

The coordinate for the bottom-horizontal clipping plane.

*top*

The coordinate for the bottom-horizontal clipping plane.

*zNear*

The distances to the near-depth clipping plane. Must be positive.

*zFar*

The distances to the far-depth clipping planes. Must be positive.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *zNear* or *zFar* was not postitive.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glFrustum** function describes a perspective matrix that produces a perspective projection. The (*left*, *bottom*, *zNear*) and (*right*, *top*, *zNear*) parameters specify the points on the near clipping plane that are mapped to the lower-left and upper-right corners of the window, respectively, assuming that the eye is located at (0,0,0). The *zFar* parameter specifies the location of the far clipping plane. Both *zNear* and *zFar* must be positive. The corresponding matrix is shown in the following image.

![Diagram showing the perspective matrix that produces a perspective projection.](https://learn.microsoft.com/windows/win32/opengl/images/frust01.png)![Equations showing the glFrustum function that describes a perspective matrix.](https://learn.microsoft.com/windows/win32/opengl/images/frust02.png)

The **glFrustum** function multiplies the current matrix by this matrix, with the result replacing the current matrix. That is, if M is the current matrix and F is the frustum perspective matrix, then **glFrustum** replaces M with M F.

Use [**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix) and [**glPopMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpopmatrix) to save and restore the current matrix stack.

Depth-buffer precision is affected by the values specified for *zNear* and *zFar*. The greater the ratio of *zFar* to *zNear* is, the less effective the depth buffer will be at distinguishing between surfaces that are near each other. If

![Equation showing the ratio of far to near.](https://learn.microsoft.com/windows/win32/opengl/images/frust03.png)

roughly *log*2 (*r*) bits of depth buffer precision are lost. Because *r* approaches infinity as *zNear* approaches zero, you should never set *zNear* to zero.

The following functions retrieve information about **glFrustum**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_MATRIX\_MODE

**glGet** with argument GL\_MODELVIEW\_MATRIX

**glGet** with argument GL\_PROJECTION\_MATRIX

**glGet** with argument GL\_TEXTURE\_MATRIX

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

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glMatrixMode**](https://learn.microsoft.com/windows/win32/opengl/glmatrixmode)

[**glMultMatrix**](https://learn.microsoft.com/windows/win32/opengl/glmultmatrix)

[**glOrtho**](https://learn.microsoft.com/windows/win32/opengl/glortho)

[**glPopMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpopmatrix)

[**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix)

[**glViewport**](https://learn.microsoft.com/windows/win32/opengl/glviewport)

