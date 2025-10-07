# glPopAttrib function

Pops the attribute stack.

## Parameters

This function has no parameters.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_STACK\_UNDERFLOW** | The function was called while the attribute stack was empty.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The [**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib) function takes one argument, a mask that indicates which groups of state variables to save on the attribute stack. Symbolic constants are used to set bits in the mask. The mask parameter is typically constructed by **OR**ing several of these constants together. The special mask GL\_ALL\_ATTRIB\_BITS can be used to save all stackable states.

The **glPopAttrib** function restores the values of the state variables saved with the last [**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib) command. Those not saved are left unchanged.

It is an error to push attributes onto a full stack, or to pop attributes off an empty stack. In either case, the error flag is set and no other change is made to the OpenGL state.

Initially, the attribute stack is empty.

Not all values for the OpenGL state can be saved on the attribute stack. For example, pixel pack and unpack state, render mode state, and select and feedback state cannot be saved.

The depth of the attribute stack depends on the implementation, but it must be at least 16.

The following functions retrieve information related to [**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib) and **glPopAttrib**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_ATTRIB\_STACK\_DEPTH

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_MAX\_ATTRIB\_STACK\_DEPTH

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

[**glGetClipPlane**](https://learn.microsoft.com/windows/win32/opengl/glgetclipplane)

[**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror)

[**glGetLight**](https://learn.microsoft.com/windows/win32/opengl/glgetlight)

[**glGetMap**](https://learn.microsoft.com/windows/win32/opengl/glgetmap)

[**glGetMaterial**](https://learn.microsoft.com/windows/win32/opengl/glgetmaterial)

[**glGetPixelMap**](https://learn.microsoft.com/windows/win32/opengl/glgetpixelmap)

[**glGetPolygonStipple**](https://learn.microsoft.com/windows/win32/opengl/glgetpolygonstipple)

[**glGetString**](https://learn.microsoft.com/windows/win32/opengl/glgetstring)

[**glGetTexEnv**](https://learn.microsoft.com/windows/win32/opengl/glgettexenv)

[**glGetTexGen**](https://learn.microsoft.com/windows/win32/opengl/glgettexgen)

[**glGetTexImage**](https://learn.microsoft.com/windows/win32/opengl/glgetteximage)

[**glGetTexLevelParameter**](https://learn.microsoft.com/windows/win32/opengl/glgettexlevelparameter)

[**glGetTexParameter**](https://learn.microsoft.com/windows/win32/opengl/glgettexparameter)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled)

