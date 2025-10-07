# gluQuadricCallback function

The **gluQuadricCallback** function defines a callback for a quadric object.

## Parameters

*qobj*

The quadric object (created with [**gluNewQuadric**](https://learn.microsoft.com/windows/win32/opengl/glunewquadric)).

*which*

The callback being defined. The only valid value is GLU\_ERROR.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GLU\_ERROR** | The **gluQuadricCallback** function is called when an error is encountered. Its single argument is of type **GLenum**, and it indicates the specific error that occurred. Character strings describing these errors can be retrieved with the [**gluErrorString**](https://learn.microsoft.com/windows/win32/opengl/gluerrorstring) call.<br> |

*fn*

The function to be called.

## Return value

This function does not return a value.

## Remarks

Use **gluQuadricCallback** to define a new callback to be used by a quadric object. If the specified callback is already defined, it is replaced. If *fn* is **NULL**, any existing callback is erased.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Glu.h |
| Library<br> | Glu32.lib |
| DLL<br> | Glu32.dll |

## See also

[**gluErrorString**](https://learn.microsoft.com/windows/win32/opengl/gluerrorstring)

[**gluNewQuadric**](https://learn.microsoft.com/windows/win32/opengl/glunewquadric)

