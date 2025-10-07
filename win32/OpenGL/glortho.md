# glOrtho function

The **glOrtho** function multiplies the current matrix by an orthographic matrix.

## Parameters

*left*

The coordinates for the left vertical clipping plane.

*right*

The coordinates for theright vertical clipping plane.

*bottom*

The coordinates for the bottom horizontal clipping plane.

*top*

The coordinates for the top horizontal clipping plans.

*zNear*

The distances to the nearer depth clipping plane. This distance is negative if the plane is to be behind the viewer.

*zFar*

The distances to the farther depth clipping plane. This distance is negative if the plane is to be behind the viewer.

## Return value

This function does not return a value.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glOrtho** function describes a perspective matrix that produces a parallel projection. The (*left*, *bottom*, *near*) and (*right*, *top*, *near*) parameters specify the points on the near clipping plane that are mapped to the lower-left and upper-right corners of the window, respectively, assuming that the eye is located at (0, 0, 0). The *far* parameter specifies the location of the far clipping plane. Both *zNear* and *zFar* can be either positive or negative. The corresponding matrix is shown in the following image.

![Diagram showing the perspective matrix the glOrtho function describes.](https://learn.microsoft.com/windows/win32/opengl/images/ortho1.png)

where

![Equations describing the perspective matrix.](https://learn.microsoft.com/windows/win32/opengl/images/ortho2.png)

The current matrix is multiplied by this matrix with the result replacing the current matrix. That is, if M is the current matrix and O is the ortho matrix, then M is replaced with M O.

Use [**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix) and **glPopMatrix** to save and restore the current matrix stack. Use [**glMatrixMode**](https://learn.microsoft.com/windows/win32/opengl/glmatrixmode) to set the current matrix.

The following functions retrieve information related to **glOrtho**:

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

[**glFrustum**](https://learn.microsoft.com/windows/win32/opengl/glfrustum)

[**glMatrixMode**](https://learn.microsoft.com/windows/win32/opengl/glmatrixmode)

[**glMultMatrix**](https://learn.microsoft.com/windows/win32/opengl/glmultmatrix)

[**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix)

[**glViewport**](https://learn.microsoft.com/windows/win32/opengl/glviewport)

