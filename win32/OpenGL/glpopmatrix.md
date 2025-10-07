# glPopMatrix function

The [**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix) and **glPopMatrix** functions push and pop the current matrix stack.

## Parameters

This function has no parameters.

## Return value

This function does not return a value.

## Error codes

It is an error to push a full matrix stack, or to pop a matrix stack that contains only a single matrix. In either case, the error flag is set and no other change is made to the OpenGL state.

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_STACK\_UNDERFLOW** | The function was called while the current matrix stack contained only a single matrix.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

There is a stack of matrices for each of the matrix modes. In GL\_MODELVIEW mode, the stack depth is at least 32. In the other two modes, GL\_PROJECTION and GL\_TEXTURE, the depth is at least 2. The current matrix in any mode is the matrix on the top of the stack for that mode.

The [**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix) function pushes the current matrix stack down by one, duplicating the current matrix. That is, after a **glPushMatrix** call, the matrix on the top of the stack is identical to the one below it. The **glPopMatrix** function pops the current matrix stack, replacing the current matrix with the one below it on the stack. Initially, each of the stacks contains one matrix, an identity matrix.

The following functions retrieve information related to [**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix) and **glPopMatrix**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_MATRIX\_MODE

**glGet** with argument GL\_MODELVIEW\_MATRIX

**glGet** with argument GL\_PROJECTION\_MATRIX

**glGet** with argument GL\_TEXTURE\_MATRIX

**glGet** with argument GL\_MODELVIEW\_STACK\_DEPTH

**glGet** with argument GL\_PROJECTION\_STACK\_DEPTH

**glGet** with argument GL\_TEXTURE\_STACK\_DEPTH

**glGet** with argument GL\_MAX\_MODELVIEW\_STACK\_DEPTH

**glGet** with argument GL\_MAX\_PROJECTION\_STACK\_DEPTH

**glGet** with argument GL\_MAX\_TEXTURE\_STACK\_DEPTH

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

[**glLoadIdentity**](https://learn.microsoft.com/windows/win32/opengl/glloadidentity)

[**glLoadMatrix**](https://learn.microsoft.com/windows/win32/opengl/glloadmatrix)

[**glMatrixMode**](https://learn.microsoft.com/windows/win32/opengl/glmatrixmode)

[**glMultMatrix**](https://learn.microsoft.com/windows/win32/opengl/glmultmatrix)

[**glOrtho**](https://learn.microsoft.com/windows/win32/opengl/glortho)

[**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix)

[**glRotate**](https://learn.microsoft.com/windows/win32/opengl/glrotate)

[**glScale**](https://learn.microsoft.com/windows/win32/opengl/glscale)

[**glTranslate**](https://learn.microsoft.com/windows/win32/opengl/gltranslate)

[**glViewport**](https://learn.microsoft.com/windows/win32/opengl/glviewport)

