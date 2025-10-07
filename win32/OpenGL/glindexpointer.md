# glIndexPointer function

The **glIndexPointer** function defines an array of color indexes.

## Parameters

*type*

The data type of each color index in the array using the following symbolic constants: GL\_SHORT, GL\_INT, GL\_FLOAT, GL\_DOUBLE.

*stride*

The byte offset between consecutive color indexes. When *stride* is zero, the color indexes are tightly packed in the array.

*pointer*

A pointer to the first color index in the array.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|---------------------------------------------------------------------------------------------------|----------------------------------------------|
| **GL\_INVALID\_ENUM** | *type* was not an accepted value.<br> |
| **GL\_INVALID\_VALUE** | *stride* or *count* was negative.<br> |

## Remarks

The **glIndexPointer** function specifies the location and data of an array of color indexes to use when rendering. The *type* parameter specifies the data type of each color index and *stride* determines the byte offset from one color index to the next, enabling the packing of vertices and attributes in a single array or storage in separate arrays. In some implementations, storing the vertices and attributes in a single array can be more efficient than using separate arrays. For more information, see [**glInterleavedArrays**](https://learn.microsoft.com/windows/win32/opengl/glinterleavedarrays).

A color-index array is enabled when you specify the GL\_INDEX\_ARRAY constant with [**glEnableClientState**](https://learn.microsoft.com/windows/win32/opengl/glenableclientstate). When enabled, [**glDrawArrays**](https://learn.microsoft.com/windows/win32/opengl/gldrawarrays) and [**glArrayElement**](https://learn.microsoft.com/windows/win32/opengl/glarrayelement) use the color-index array. By default the color-index array is disabled.

You cannot include **glIndexPointer** in display lists.

When you specify a color-index array using **glIndexPointer**, the values of all the function's color-index array parameters are saved in a client-side state and static array elements can be cached. Because the color-index array parameters are client-side state, their values are not saved or restored by [**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib) and **glPopAttrib**.

Although no error is generated when you call **glIndexPointer** within [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and **glEnd** pairs, the results are undefined.

The following functions retrieve information related to **glIndexPointer**:

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument GL\_INDEX\_ARRAY

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_INDEX\_ARRAY\_STRIDE

**glGet** with argument GL\_INDEX\_ARRAY\_COUNT

**glGet** with argument GL\_INDEX\_ARRAY\_TYPE

**glGet** with argument GL\_INDEX\_ARRAY\_SIZE

[**glGetPointerv**](https://learn.microsoft.com/windows/win32/opengl/glgetpointerv) with argument GL\_INDEX\_ARRAY\_POINTER

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

[**glGetPointerv**](https://learn.microsoft.com/windows/win32/opengl/glgetpointerv)

[**glGetString**](https://learn.microsoft.com/windows/win32/opengl/glgetstring)

[**glNormalPointer**](https://learn.microsoft.com/windows/win32/opengl/glnormalpointer)

[**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib)

[**glTexCoordPointer**](https://learn.microsoft.com/windows/win32/opengl/gltexcoordpointer)

[**glVertexPointer**](https://learn.microsoft.com/windows/win32/opengl/glvertexpointer)

