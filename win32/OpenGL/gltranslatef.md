# glTranslatef function

The [**glTranslatef**](https://learn.microsoft.com/windows/win32/opengl/gltranslate) function multiplies the current matrix by a translation matrix.

## Parameters

*x*

The *x* coordinate of a translation vector.

*y*

The *y* coordinate of a translation vector.

*z*

The *z* coordinate of a translation vector.

## Return value

This function does not return a value.

## Remarks

The **glTranslatef** function produces the translation specified by (*x*, *y*, *z*). The translation vector is used to compute a 4x4 translation matrix:

![Diagram showing the 4x4 translation matrix specified by x, y, z.](https://learn.microsoft.com/windows/win32/opengl/images/trans01.png)

The current matrix (see [**glMatrixMode**](https://learn.microsoft.com/windows/win32/opengl/glmatrixmode)) is multiplied by this translation matrix, with the product replacing the current matrix. That is, if M is the current matrix and T is the translation matrix, then M is replaced with M T.

If the matrix mode is either GL\_MODELVIEW or GL\_PROJECTION, all objects drawn after **glTranslatef** is called are translated. Use [**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix) and **glPopMatrix** to save and restore the untranslated coordinate system.

The following functions retrieve information related to [**glTranslated**](https://learn.microsoft.com/windows/win32/opengl/gltranslate) and **glTranslatef**:

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

[**glMatrixMode**](https://learn.microsoft.com/windows/win32/opengl/glmatrixmode)

[**glMultMatrix**](https://learn.microsoft.com/windows/win32/opengl/glmultmatrix)

[**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix)

[**glRotate**](https://learn.microsoft.com/windows/win32/opengl/glrotate)

[**glScale**](https://learn.microsoft.com/windows/win32/opengl/glscale)

