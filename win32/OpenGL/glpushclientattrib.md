# glPushClientAttrib function

The **glPushClientAttrib** and [**glPopClientAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpopclientattrib) functions save and restore groups of client-state variables on the client-attribute stack.

## Parameters

*mask*

A mask that indicates which attributes to save. The following are the symbolic mask constants and their associated OpenGL client states.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------|
| **GL\_CLIENT\_PIXEL\_STORE\_BIT** | Pixel storage mode attributes.<br> |
| **GL\_CLIENT\_VERTEX\_ARRAY\_BIT** | Vertex array attributes.<br> |
| **GL\_CLIENT\_ALL\_ATTRIB\_BITs** | all stackable client-state attributes.<br> |

## Return value

This function does not return a value.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|----------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------|
| **GL\_STACK\_OVERFLOW** | The function was called while the client-attribute stack was full.<br> |

## Remarks

The **glPushClientAttrib** function uses its mask parameter to determine which groups of client-state variables are saved on the client-attribute stack. You can use the bitwise OR operator to join together accepted symbolic constants to set bits and construct a mask.

The [**glPopClientAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpopclientattrib) function restores the values of the client-state variables last saved with **glPushclientAttrib**. Client-state variables not previously saved are left unchanged. Pushing attributes onto a full client-attribute stack or popping attributes off an empty stack sets an error flag and no other change is made to the OpenGL state. By default the client attribute stack is empty.

Some OpenGL client-state values cannot be saved on the client-attribute stack. For example, you cannot save the select or feedback states on the client-attribute stack. The depth of the client-attribute stack is at least 16.

The **glPushclientAttrib** and **glPopClientAttrib** functions are not compiled into display lists, but are executed immediately.

The **glPushClientAttrib** and **glPopClientAttrib** functions can only push and pop pixel storage modes and vertex array client states. You must use [**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib) and [**glPopAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpopattrib) to push and pop states that are kept on the server.

> [!Note]
> The **glPushClientAttrib** and **glPopClientAttrib** functions are only available in OpenGL version 1.1 or later.

The following functions retrieve information related to **glPushClientAttrib** and **glPopClientAttrib**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_CLIENT\_ATTRIB\_STACK\_DEPTH

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_MAX\_CLIENT\_ATTRIB\_STACK\_DEPTH

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Gl.h |
| Library<br> | Opengl32.lib |
| DLL<br> | Opengl32.dll |

## See also

[**glColorPointer**](https://learn.microsoft.com/windows/win32/opengl/glcolorpointer)

[**glDisableClientState**](https://learn.microsoft.com/windows/win32/opengl/gldisableclientstate)

[**glEdgeFlagPointer**](https://learn.microsoft.com/windows/win32/opengl/gledgeflagpointer)

[**glEnableClientState**](https://learn.microsoft.com/windows/win32/opengl/glenableclientstate)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror)

[**glIndexPointer**](https://learn.microsoft.com/windows/win32/opengl/glindexpointer)

[**glNormalPointer**](https://learn.microsoft.com/windows/win32/opengl/glnormalpointer)

[**glNewList**](https://learn.microsoft.com/windows/win32/opengl/glnewlist)

[**glPixelStore**](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions)

[**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib)

[**glTexCoordPointer**](https://learn.microsoft.com/windows/win32/opengl/gltexcoordpointer)

[**glVertexPointer**](https://learn.microsoft.com/windows/win32/opengl/glvertexpointer)

