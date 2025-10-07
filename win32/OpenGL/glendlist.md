# glEndList function

The [**glNewList**](https://learn.microsoft.com/windows/win32/opengl/glnewlist) and **glEndList** functions create or replace a display list.

## Parameters

This function has no parameters.

## Return value

This function does not return a value.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_OPERATION** | **glEndList** was called without a preceding **glNewList**, or if **glnewlist** was called while a display list was being defined.<br> |

## Remarks

Display lists are groups of OpenGL commands that have been stored for subsequent execution. The display lists are created with [**glNewList**](https://learn.microsoft.com/windows/win32/opengl/glnewlist). All subsequent commands are placed in the display list, in the order issued, until **glEndList** is called.

The [**glNewList**](https://learn.microsoft.com/windows/win32/opengl/glnewlist) function has two parameters. The first parameter, *list*, is a positive integer that becomes the unique name for the display list. Names can be created and reserved with [**glGenLists**](https://learn.microsoft.com/windows/win32/opengl/glgenlists) and tested for uniqueness with [**glIsList**](https://learn.microsoft.com/windows/win32/opengl/glislist). The second parameter, *mode*, is a symbolic constant that can assume one of the two preceding values.

Certain commands are not compiled into the display list, but are executed immediately, regardless of the display list mode. These commands are [**glColorPointer**](https://learn.microsoft.com/windows/win32/opengl/glcolorpointer), [**glDeleteLists**](https://learn.microsoft.com/windows/win32/opengl/gldeletelists), [**glDisableClientState**](https://learn.microsoft.com/windows/win32/opengl/gldisableclientstate), [**glEdgeFlagPointer**](https://learn.microsoft.com/windows/win32/opengl/gledgeflagpointer), [**glEnableClientState**](https://learn.microsoft.com/windows/win32/opengl/glenableclientstate), [**glFeedbackBuffer**](https://learn.microsoft.com/windows/win32/opengl/glfeedbackbuffer), [**glFinish**](https://learn.microsoft.com/windows/win32/opengl/glfinish), [**glFlush**](https://learn.microsoft.com/windows/win32/opengl/glflush), [**glGenLists**](https://learn.microsoft.com/windows/win32/opengl/glgenlists), [**glIndexPointer**](https://learn.microsoft.com/windows/win32/opengl/glindexpointer), [**glInterleavedArrays**](https://learn.microsoft.com/windows/win32/opengl/glinterleavedarrays), [**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled), [**glIsList**](https://learn.microsoft.com/windows/win32/opengl/glislist), [**glNormalPointer**](https://learn.microsoft.com/windows/win32/opengl/glnormalpointer), [**glPopClientAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpopclientattrib), [**glPixelStore**](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions), [**glPushClientAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushclientattrib), [**glReadPixels**](https://learn.microsoft.com/windows/win32/opengl/glreadpixels), [**glRenderMode**](https://learn.microsoft.com/windows/win32/opengl/glrendermode), [**glSelectBuffer**](https://learn.microsoft.com/windows/win32/opengl/glselectbuffer), [**glTexCoordPointer**](https://learn.microsoft.com/windows/win32/opengl/gltexcoordpointer), [**glVertexPointer**](https://learn.microsoft.com/windows/win32/opengl/glvertexpointer), and all of the [**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) routines.

Similarly, [**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d) and [**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d) are executed immediately and not compiled into the display list when their first argument is GL\_PROXY\_TEXTURE\_2D or GL\_PROXY\_TEXTURE\_1D, respectively.

When the **glEndList** function is encountered, the display list definition is completed by associating the list with the unique name *list* (specified in the [**glNewList**](https://learn.microsoft.com/windows/win32/opengl/glnewlist) command). If a display list with name *list* already exists, it is replaced only when **glEndList** is called.

The [**glCallList**](https://learn.microsoft.com/windows/win32/opengl/glcalllist) and [**glCallLists**](https://learn.microsoft.com/windows/win32/opengl/glcalllists) functions can be entered into display lists. The commands in the display list or lists executed by **glCallList** or **glCallLists** are not included in the display list being created, even if the list creation mode is GL\_COMPILE\_AND\_EXECUTE.

The following function retrieves information related to [**glNewList**](https://learn.microsoft.com/windows/win32/opengl/glnewlist):

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_MATRIX\_MODE

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

[**glCallLists**](https://learn.microsoft.com/windows/win32/opengl/glcalllists)

[**glDeleteLists**](https://learn.microsoft.com/windows/win32/opengl/gldeletelists)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGenLists**](https://learn.microsoft.com/windows/win32/opengl/glgenlists)

[**glIsList**](https://learn.microsoft.com/windows/win32/opengl/glislist)

[**glNewList**](https://learn.microsoft.com/windows/win32/opengl/glnewlist)

