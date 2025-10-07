# glTexCoordPointer function

The **glTexCoordPointer** function defines an array of texture coordinates.

## Parameters

*size*

The number of coordinates per array element. The value of *size* must be 1, 2, 3, or 4.

*type*

The data type of each texture coordinate in the array using the following symbolic constants: **GL\_SHORT**, **GL\_INT**, **GL\_FLOAT**, and **GL\_DOUBLE**.

*stride*

The byte offset between consecutive array elements. When *stride* is zero, the array elements are tightly packed in the array.

*pointer*

A pointer to the first coordinate of the first element in the array.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|---------------------------------------------------------------------------------------------------|----------------------------------------------|
| **GL\_INVALID\_ENUM** | *type* was not an accepted value.<br> |
| **GL\_INVALID\_VALUE** | *size* was not 1, 2, 3, or 4.<br> |
| **GL\_INVALID\_VALUE** | *stride* was negative.<br> |

## Remarks

The **glTexCoordPointer** function specifies the location and data of an array of texture coordinates to use when rendering.The *size* parameter specifies the number of coordinates used for each element of the array.The *type* parameter specifies the data type of each texture coordinate. The *stride* parameter determines the byte offset from one array element to the next, enabling the packing of vertices and attributes in a single array or storage in separate arrays. In some implementations, storing the vertices and attributes in a single array can be more efficient than using separate arrays. For more information, see [**glInterleavedArrays**](https://learn.microsoft.com/windows/win32/opengl/glinterleavedarrays). When a texture coordinate array is specified, size, type, stride, and pointer are saved client-side state.

A texture coordinate array is enabled when you specify the **GL\_TEXTURE\_COORD\_ARRAY** constant with [**glEnableClientState**](https://learn.microsoft.com/windows/win32/opengl/glenableclientstate). When enabled, [**glDrawArrays**](https://learn.microsoft.com/windows/win32/opengl/gldrawarrays), [**glDrawElements**](https://learn.microsoft.com/windows/win32/opengl/gldrawelements), and [**glArrayElement**](https://learn.microsoft.com/windows/win32/opengl/glarrayelement) use the texture coordinate array. By default the texture coordinate array is disabled.

You cannot include **glTexCoordPointer** in display lists.

When you specify a texture coordinate array using **glTexCoordPointer**, the values of all the function's texture coordinate array parameters are saved in a client-side state, and static array elements can be cached. Because the texture coordinate array parameters are client-side state, their values are not saved or restored by [**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib) and [**glPopAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpopattrib).

Although no error is generated when you call **glTexCoordPointer** within [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend) pairs, the results are undefined.

The following functions retrieve information related to **glTexCoordPointer**:

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument **GL\_TEXTURE\_COORD\_ARRAY**

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument **GL\_TEXTURE\_COORD\_ARRAY\_SIZE**

**glGet** with argument **GL\_TEXTURE\_COORD\_ARRAY\_STRIDE**

**glGet** with argument **GL\_TEXTURE\_COORD\_ARRAY\_COUNT**

**glGet** with argument **GL\_TEXTURE\_COORD\_ARRAY\_TYPE**

[**glGetPointerv**](https://learn.microsoft.com/windows/win32/opengl/glgetpointerv) with argument **GL\_TEXTURE\_COORD\_ARRAY\_POINTER**

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

[**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable)

[**glGetPointerv**](https://learn.microsoft.com/windows/win32/opengl/glgetpointerv)

[**glGetString**](https://learn.microsoft.com/windows/win32/opengl/glgetstring)

[**glIndexPointer**](https://learn.microsoft.com/windows/win32/opengl/glindexpointer)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled)

[**glNormalPointer**](https://learn.microsoft.com/windows/win32/opengl/glnormalpointer)

[**glPopClientAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpopclientattrib)

[**glPushClientAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushclientattrib)

[**glTexCoord**](https://learn.microsoft.com/windows/win32/opengl/gltexcoord-functions)

[**glVertexPointer**](https://learn.microsoft.com/windows/win32/opengl/glvertexpointer)

