# glNormalPointer function

The **glNormalPointer** function defines an array of normals.

## Parameters

*type*

The data type of each coordinate in the array using the following symbolic constants: GL\_BYTE, GL\_SHORT, GL\_INT, GL\_FLOAT, and GL\_DOUBLE.

*stride*

The byte offset between consecutive normals. When *stride* is zero, the normals are tightly packed in the array.

*pointer*

A pointer to the first normal in the array.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|----------------------------------------------|
| **GL\_INVALID\_ENUM** | *type* was not an accepted value.<br> |
| **GL\_INVALID\_OPERATION** | *stride* or *count* was negative.<br> |

## Remarks

The **glNormalPointer** function specifies the location and data of an array of normals to use when rendering. The *type* parameter specifies the data type of each normal coordinate. The *stride* parameter determines the byte offset from one normal to the next, enabling the packing of vertices and attributes in a single array or storage in separate arrays. In some implementations storing the vertices and attributes in a single array can be more efficient than using separate arrays; see [**glInterleavedArrays**](https://learn.microsoft.com/windows/win32/opengl/glinterleavedarrays) for details.

A normal array is enabled when you specify the GL\_NORMAL\_ARRAY constant with [**glEnableClientState**](https://learn.microsoft.com/windows/win32/opengl/glenableclientstate). When enabled, [**glDrawArrays**](https://learn.microsoft.com/windows/win32/opengl/gldrawarrays), [**glDrawElements**](https://learn.microsoft.com/windows/win32/opengl/gldrawelements) and [**glArrayElement**](https://learn.microsoft.com/windows/win32/opengl/glarrayelement) use the normal array. By default the normal array is disabled.

You cannot include **glNormalPointer** in display lists.

When you specify a normal array using **glNormalPointer**, the values of all the function's normal array parameters are saved in a client-side state. Because the normal array parameters are saved in a client-side state, their values are not saved or restored by [**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib) and [**glPopAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpopattrib).

Although no error is generated when you call **glNormalPointer** within [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend) pairs, the results are undefined.

The following functions are associated with **glNormalPointer**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_NORMAL\_ARRAY\_STRIDE

**glGet** with argument GL\_NORMAL\_ARRAY\_COUNT

**glGet** with argument GL\_NORMAL\_ARRAY\_TYPE

**glGetPointerv** with argument GL\_NORMAL\_ARRAY\_POINTER

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument GL\_NORMAL\_ARRAY

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

[**glDrawElements**](https://learn.microsoft.com/windows/win32/opengl/gldrawelements)

[**glDrawArrays**](https://learn.microsoft.com/windows/win32/opengl/gldrawarrays)

[**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable)

[**glEdgeFlagPointer**](https://learn.microsoft.com/windows/win32/opengl/gledgeflagpointer)

[**glGetPointerv**](https://learn.microsoft.com/windows/win32/opengl/glgetpointerv)

[**glIndexPointer**](https://learn.microsoft.com/windows/win32/opengl/glindexpointer)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled)

[**glInterleavedArrays**](https://learn.microsoft.com/windows/win32/opengl/glinterleavedarrays)

[**glTexCoordPointer**](https://learn.microsoft.com/windows/win32/opengl/gltexcoordpointer)

[**glVertexPointer**](https://learn.microsoft.com/windows/win32/opengl/glvertexpointer)

[**glGetString**](https://learn.microsoft.com/windows/win32/opengl/glgetstring)

