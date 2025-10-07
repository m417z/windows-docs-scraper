# glGetPointerv function

The **glGetPointerv** function returns the address of a vertex data array.

## Parameters

*pname*

The type of array pointer to return from the following symbolic constants: GL\_COLOR\_ARRAY\_POINTER, GL\_EDGE\_FLAG\_ARRAY\_POINTER, GL\_FEEDBACK\_BUFFER\_POINTER, GL\_INDEX\_ARRAY\_POINTER, GL\_NORMAL\_ARRAY\_POINTER, GL\_TEXTURE\_COORD\_ARRAY\_POINTER, GL\_SELECTION\_BUFFER\_POINTER, and GL\_VERTEX\_ARRAY\_POINTER.

*params*

Returns the value of the array pointer specified by *pname*.

## Return value

This function does not return a value.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|--------------------------------------------------------------------------------------------------|-----------------------------------------------|
| **GL\_INVALID\_ENUM** | *pname* was not an accepted value.<br> |

## Remarks

The **glGetPointerv** function returns array pointer information. The *pname* parameter is a symbolic constant specifying the kind of array pointer to return, and *params* is a pointer to a location to place the returned data.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Gl.h |
| Library<br> | Opengl32.lib |
| DLL<br> | Opengl32.dll |

## See also

[**glArrayElement**](https://learn.microsoft.com/windows/win32/opengl/glarrayelement)

[**glColorPointer**](https://learn.microsoft.com/windows/win32/opengl/glcolorpointer)

[**glDrawArrays**](https://learn.microsoft.com/windows/win32/opengl/gldrawarrays)

[**glEdgeFlagPointer**](https://learn.microsoft.com/windows/win32/opengl/gledgeflagpointer)

[**glGetString**](https://learn.microsoft.com/windows/win32/opengl/glgetstring)

[**glIndexPointer**](https://learn.microsoft.com/windows/win32/opengl/glindexpointer)

[**glNormalPointer**](https://learn.microsoft.com/windows/win32/opengl/glnormalpointer)

[**glTexCoordPointer**](https://learn.microsoft.com/windows/win32/opengl/gltexcoordpointer)

[**glVertexPointer**](https://learn.microsoft.com/windows/win32/opengl/glvertexpointer)

