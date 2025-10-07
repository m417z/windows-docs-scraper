# glCallList function

The **glCallList** function executes a display list.

## Parameters

*list*

The integer name of the display list to be executed.

## Return value

This function does not return a value.

## Remarks

Invoking the **glCallList** function begins execution of the named display list. The functions saved in the display list are executed in order, just as if you called them without using a display list. If *list* has not been defined as a display list, **glCallList** is ignored.

The **glCallList** function can appear inside a display list. To avoid the possibility of infinite recursion resulting from display lists calling one another, a limit is placed on the nesting level of display lists during display-list execution. This limit is at least 64, however, it depends on the implementation.

The OpenGL state is not saved and restored across a call to **glCallList**. Thus, changes made to the OpenGL state during the execution of a display list remain after execution of the display list is completed. To preserve the OpenGL state across **glCallList** calls, use [**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib), [**glPopAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpopattrib), [**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix), and [**glPopMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpopmatrix).

You can execute display lists between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend), as long as the display list includes only functions that are allowed in this interval.

The following functions retrieve information related to **glCallList**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_MAX\_LIST\_NESTING

[**glIsList**](https://learn.microsoft.com/windows/win32/opengl/glislist)

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

[**glCallLists**](https://learn.microsoft.com/windows/win32/opengl/glcalllists)

[**glDeleteLists**](https://learn.microsoft.com/windows/win32/opengl/gldeletelists)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGenLists**](https://learn.microsoft.com/windows/win32/opengl/glgenlists)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glIsList**](https://learn.microsoft.com/windows/win32/opengl/glislist)

[**glNewList**](https://learn.microsoft.com/windows/win32/opengl/glnewlist)

[**glPopAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpopattrib)

[**glPopMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpopmatrix)

[**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib)

[**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix)

