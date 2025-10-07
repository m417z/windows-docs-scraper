# glCallLists function

The **glCallLists** function executes a list of display lists.

## Parameters

*n*

The number of display lists to be executed.

*type*

The type of values in *lists*. The following symbolic constants are accepted.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_BYTE** | The *lists* parameter is treated as an array of signed bytes, each in the range -128 through 127.<br> |
| **GL\_UNSIGNED\_BYTE** | The *lists* parameter is treated as an array of unsigned bytes, each in the range 0 through 255.<br> |
| **GL\_SHORT** | The *lists* parameter is treated as an array of signed 2-byte integers, each in the range -32768 through 32767.<br> |
| **GL\_UNSIGNED\_SHORT** | The *lists* parameter is treated as an array of unsigned 2-byte integers, each in the range 0 through 65535.<br> |
| **GL\_INT** | The *lists* parameter is treated as an array of signed 4-byte integers.<br> |
| **GL\_UNSIGNED\_INT** | The *lists* parameter is treated as an array of unsigned 4-byte integers.<br> |
| **GL\_FLOAT** | The *lists* parameter is treated as an array of 4-byte, floating-point values.<br> |
| **GL\_2\_BYTES** | The *lists* parameter is treated as an array of unsigned bytes. Each pair of bytes specifies a single display-list name. The value of the pair is computed as 256 times the unsigned value of the first byte plus the unsigned value of the second byte.<br> |
| **GL\_3\_BYTES** | The *lists* parameter is treated as an array of unsigned bytes. Each triplet of bytes specifies a single display list name. The value of the triplet is computed as 65536 times the unsigned value of the first byte, plus 256 times the unsigned value of the second byte, plus the unsigned value of the third byte.<br> |
| **GL\_4\_BYTES** | The *lists* parameter is treated as an array of unsigned bytes. Each quadruplet of bytes specifies a single display list name. The value of the quadruplet is computed as 16777216 times the unsigned value of the first byte, plus 65536 times the unsigned value of the second byte, plus 256 times the unsigned value of the third byte, plus the unsigned value of the fourth byte.<br> |

*lists*

The address of an array of name offsets in the display list. The pointer type is void because the offsets can be bytes, shorts, ints, or floats, depending on the value of *type*.

## Return value

This function does not return a value.

## Remarks

The **glCallLists** function causes each display list in the list of names passed as *lists* to be executed. As a result, the functions saved in each display list are executed in order, just as if they were called without using a display list. Names of display lists that have not been defined are ignored.

The **glCallLists** function provides an efficient means for executing display lists. The *n* parameter specifies the number of lists with various name formats (specified by the *type* parameter) **glCallLists** executes.

The list of display list names is not null-terminated. Rather, *n* specifies how many names are to be taken from *lists*.

The [**glListBase**](https://learn.microsoft.com/windows/win32/opengl/gllistbase) function makes an additional level of indirection available. The **glListBase** function specifies an unsigned offset that is added to each display list name specified in *lists* before that display list is executed.

The **glCallLists** function can appear inside a display list. To avoid the possibility of infinite recursion resulting from display lists calling one another, a limit is placed on the nesting level of display lists during display list execution. This limit must be at least 64, and it depends on the implementation.

The OpenGL state is not saved and restored across a call to **glCallLists**. Thus, changes made to the OpenGL state during the execution of the display lists remain after execution is completed. Use [**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib), [**glPopAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpopattrib), [**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix), and [**glPopMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpopmatrix) to preserve the OpenGL state across **glCallLists** calls.

You can execute display lists between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend), as long as the display list includes only functions that are allowed in this interval.

The following functions retrieve information related to the **glCallLists** function:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_LIST\_BASE

**glGet** with argument GL\_MAX\_LIST\_NESTING

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

[**glCallList**](https://learn.microsoft.com/windows/win32/opengl/glcalllist)

[**glDeleteLists**](https://learn.microsoft.com/windows/win32/opengl/gldeletelists)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGenLists**](https://learn.microsoft.com/windows/win32/opengl/glgenlists)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glIsList**](https://learn.microsoft.com/windows/win32/opengl/glislist)

[**glListBase**](https://learn.microsoft.com/windows/win32/opengl/gllistbase)

[**glNewList**](https://learn.microsoft.com/windows/win32/opengl/glnewlist)

[**glPopAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpopattrib)

[**glPopMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpopmatrix)

[**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib)

[**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix)

