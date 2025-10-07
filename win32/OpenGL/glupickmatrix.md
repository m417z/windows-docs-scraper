# gluPickMatrix function

The **gluPickMatrix** function defines a picking region.

## Parameters

*x*

The x window coordinate of a picking region.

*y*

The y window coordinate of a picking region.

*height*

The height of the picking region in window coordinates.

*width*

The width of the picking region in window coordinates.

*viewport*

The current viewport (as from a [**glGetIntegerv**](https://learn.microsoft.com/windows/win32/opengl/glgetintegerv) call).

## Return value

This function does not return a value.

## Remarks

The **gluPickMatrix** function creates a projection matrix you can use to restrict drawing to a small region of the viewport.

1. Use **gluPickMatrix** to restrict drawing to a small region around the cursor.
2. Enter selection mode (with [**glRenderMode**](https://learn.microsoft.com/windows/win32/opengl/glrendermode)), and then rerender the scene.

 All primitives that would have been drawn near the cursor are identified and stored in the selection buffer.

The matrix created by **gluPickMatrix** is multiplied by the current matrix just as if [**glMultMatrix**](https://learn.microsoft.com/windows/win32/opengl/glmultmatrix) were called with the generated matrix.

1. Call [**glLoadIdentity**](https://learn.microsoft.com/windows/win32/opengl/glloadidentity) to load an identity matrix onto the perspective matrix stack.
2. Call **gluPickMatrix**.
3. Call a function (such as [**gluPerspective**](https://learn.microsoft.com/windows/win32/opengl/gluperspective)) to multiply the perspective matrix by the pick matrix.

When using **gluPickMatrix** to pick Non-Uniform Rational B-Spline ([NURBS](https://learn.microsoft.com/windows/win32/opengl/using-nurbs-curves-and-surfaces)), be careful to turn off the NURBS property, GLU\_AUTO\_LOAD\_MATRIX. If GLU\_AUTO\_LOAD\_MATRIX is not turned off, any NURBS surface rendered is subdivided differently with the pick matrix from how it was subdivided without the pick matrix.

## Examples

When rendering a scene as follows:

```
glMatrixMode(GL_PROJECTION);
glLoadIdentity( );
gluPerspective(. . .);
glMatrixMode(GL_MODELVIEW);
/* Draw the scene */
```

the following code selects a portion of the viewport:

```
glMatrixMode(GL_PROJECTION);
glLoadIdentity( );
gluPickMatrix(x, y, width, height, viewport);
gluPerspective(. . .);
glMatrixMode(GL_MODELVIEW);
/* Draw the scene */
```

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Glu.h |
| Library<br> | Glu32.lib |
| DLL<br> | Glu32.dll |

## See also

[**glGetIntegerv**](https://learn.microsoft.com/windows/win32/opengl/glgetintegerv)

[**glLoadIdentity**](https://learn.microsoft.com/windows/win32/opengl/glloadidentity)

[**glMultMatrix**](https://learn.microsoft.com/windows/win32/opengl/glmultmatrix)

[**glRenderMode**](https://learn.microsoft.com/windows/win32/opengl/glrendermode)

[**gluPerspective**](https://learn.microsoft.com/windows/win32/opengl/gluperspective)

