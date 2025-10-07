# glInterleavedArrays function

The **glInterleavedArrays** function simultaneously specifies and enables several interleaved arrays in a larger aggregate array.

## Parameters

*format*

The type of array to enable. The parameter can assume one of the following symbolic values: GL\_V2F, GL\_V3F, GL\_C4UB\_V2F, GL\_C4UB\_V3F, GL\_C3F\_V3F, GL\_N3F\_V3F, GL\_C4F\_N3F\_V3F, GL\_T2F\_V3F, GL\_T4F\_V4F, GL\_T2F\_C4UB\_V3F, GL\_T2F\_C3F\_V3F, GL\_T2F\_N3F\_V3F, GL\_T2F\_C4F\_N3F\_V3F, or GL\_T4F\_C4F\_N3F\_V4F.

*stride*

The offset in bytes between each aggregate array element.

*pointer*

A pointer to the first element of an aggregate array.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *format* was not an accepted value.<br> |
| **GL\_INVALID\_VALUE** | *stride* was a negative value.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

With the **glInterleavedArrays** function, you can simultaneously specify and enable several interleaved color, normal, texture, and vertex arrays whose elements are part of a larger aggregate array element. For some memory architectures, this is more efficient than specifying the arrays separately.

If the *stride* parameter is zero then the aggregate array elements are stored consecutively; otherwise *stride* bytes occur between aggregate array elements.

The *format* parameter serves as a key that describes how to extract individual arrays from the aggregate array:

- If *format* contains a T, then texture coordinates are extracted from the interleaved array.
- If C is present, color values are extracted.
- If N is present, normal coordinates are extracted.
- Vertex coordinates are always extracted.
- The digits 2, 3, and 4 denote how many values are extracted.
- F indicates that values are extracted as floating point values.
- If 4UB follows the C, colors may also be extracted as 4 unsigned bytes. If a color is extracted as 4 unsigned bytes, the vertex array element that follows is located at the first possible floating-point aligned address.

If you call **glInterleavedArrays** while compiling a display list, it is not compiled into the list but is executed immediately.

You cannot include calls to **glInterleavedArrays** in **glDisableClientState** between calls to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to **glEnd**.

> [!Note]
> The **glInterleavedArrays** function is only available in OpenGL version 1.1 or later.

The **glInterleavedArrays** function is implemented on the client side with no protocol. Because the vertex array parameters are client-side state, they are not saved or restored by [**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib) and **glPopAttrib**. Use [**glPushClientAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushclientattrib) and **glPopClientAttrib** instead.

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

[**glDrawElements**](https://learn.microsoft.com/windows/win32/opengl/gldrawelements)

[**glEdgeFlagPointer**](https://learn.microsoft.com/windows/win32/opengl/gledgeflagpointer)

[**glEnableClientState**](https://learn.microsoft.com/windows/win32/opengl/glenableclientstate)

[**glGetPointerv**](https://learn.microsoft.com/windows/win32/opengl/glgetpointerv)

[**glIndexPointer**](https://learn.microsoft.com/windows/win32/opengl/glindexpointer)

[**glNormalPointer**](https://learn.microsoft.com/windows/win32/opengl/glnormalpointer)

[**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib)

[**glPushClientAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushclientattrib)

[**glTexCoordPointer**](https://learn.microsoft.com/windows/win32/opengl/gltexcoordpointer)

[**glVertexPointer**](https://learn.microsoft.com/windows/win32/opengl/glvertexpointer)

