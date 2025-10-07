# glVertexPointer function

The **glVertexPointer** function defines an array of vertex data.

## Parameters

*size*

The number of coordinates per vertex. The value of *size* must be 2, 3, or 4.

*type*

The data type of each coordinate in the array using the following symbolic constants: GL\_SHORT, GL\_INT, GL\_FLOAT, and GL\_DOUBLE.

*stride*

The byte offset between consecutive vertices. When *stride* is zero, the vertices are tightly packed in the array.

*pointer*

A pointer to the first coordinate of the first vertex in the array.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|---------------------------------------------------------------------------------------------------|-----------------------------------------------|
| **GL\_INVALID\_VALUE** | *size* was not 2, 3, or 4. <br> |
| **GL\_INVALID\_ENUM** | *type* was not an accepted value.<br> |
| **GL\_INVALID\_VALUE** | *stride* or *count* was negative. <br> |

## Remarks

The **glVertexPointer** function specifies the location and data of an array of vertex coordinates to use when rendering. The *size* parameter specifies the number of coordinates per vertex. The *type* parameter specifies the data type of each vertex coordinate. The *stride* parameter determines the byte offset from one vertex to the next, enabling the packing of vertices and attributes in a single array or storage in separate arrays. In some implementations, storing the vertices and attributes in a single array can be more efficient than using separate arrays (see [**glInterleavedArrays**](https://learn.microsoft.com/windows/win32/opengl/glinterleavedarrays)).

A vertex array is enabled when you specify the GL\_VERTEX\_ARRAY constant with [**glEnableClientState**](https://learn.microsoft.com/windows/win32/opengl/glenableclientstate). When enabled, [**glDrawArrays**](https://learn.microsoft.com/windows/win32/opengl/gldrawarrays), [**glDrawElements**](https://learn.microsoft.com/windows/win32/opengl/gldrawelements), and [**glArrayElement**](https://learn.microsoft.com/windows/win32/opengl/glarrayelement) use the vertex array. By default, the vertex array is disabled.

You cannot include **glVertexPointer** in display lists.

When you specify a vertex array using **glVertexPointer**, the values of all the function's vertex array parameters are saved in a client-side state, and static array elements can be cached. Because the vertex array parameters are client-side state, their values are not saved or restored by [**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib) and **glPopAttrib**.

Although no error is generated if you call **glVertexPointer** within [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend) pairs, the results are undefined.

The following functions retrieve information related to **glVertexPointer**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_VERTEX\_ARRAY\_SIZE

**glGet** with argument GL\_VERTEX\_ARRAY\_STRIDE

**glGet** with argument GL\_VERTEX\_ARRAY\_COUNT

**glGet** with argument GL\_VERTEX\_ARRAY\_TYPE

[**glGetPointerv**](https://learn.microsoft.com/windows/win32/opengl/glgetpointerv) with argument GL\_VERTEX\_ARRAY\_POINTER

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument GL\_VERTEX\_ARRAY

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

[**glEnableClientState**](https://learn.microsoft.com/windows/win32/opengl/glenableclientstate)

[**glGetPointerv**](https://learn.microsoft.com/windows/win32/opengl/glgetpointerv)

[**glGetString**](https://learn.microsoft.com/windows/win32/opengl/glgetstring)

[**glIndexPointer**](https://learn.microsoft.com/windows/win32/opengl/glindexpointer)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled)

[**glNormalPointer**](https://learn.microsoft.com/windows/win32/opengl/glnormalpointer)

[**glTexCoordPointer**](https://learn.microsoft.com/windows/win32/opengl/gltexcoordpointer)

