# glArrayElement function

The **glArrayElement** function specifies the array elements used to render a vertex.

## Parameters

*index*

An index in the enabled arrays.

## Return value

This function does not return a value.

## Remarks

Use the **glArrayElement** function within [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend) pairs to specify vertex and attribute data for point, line, and polygon primitives. The **glArrayElement** function specifies the data for a single vertex using vertex and attribute data located at the *index* of the enabled vertex arrays.

You can use **glArrayElement** to construct primitives by indexing vertex data, rather than by streaming through arrays of data in first-to-last order. Because **glArrayElement** specifies a single vertex only, you can explicitly specify attributes for individual primitives. For example, you can set a single normal for each individual triangle.

When you include calls to **glArrayElement** in display lists, the necessary array data, determined by the array pointers and enable values, is entered in the display list also. Array pointer and enable values are determined when display lists are created, not when display lists are executed.

You can read and cache static array data at any time with **glArrayElement**. When you modify the elements of a static array without specifying the array again, the results of any subsequent calls to **glArrayElement** are undefined.

When you call **glArrayElement** without first calling **glEnableClientState**(GL\_VERTEX\_ARRAY), no drawing occurs, but the attributes corresponding to enabled arrays are modified. Although no error is generated when you specify an array within **glBegin** and **glEnd** pairs, the results are undefined.

> [!Note]
> The **glArrayElement** function is only available in OpenGL version 1.1 or later.

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

[**glColorPointer**](https://learn.microsoft.com/windows/win32/opengl/glcolorpointer)

[**glDrawArrays**](https://learn.microsoft.com/windows/win32/opengl/gldrawarrays)

[**glEdgeFlagPointer**](https://learn.microsoft.com/windows/win32/opengl/gledgeflagpointer)

[**glEnableClientState**](https://learn.microsoft.com/windows/win32/opengl/glenableclientstate)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGetPointerv**](https://learn.microsoft.com/windows/win32/opengl/glgetpointerv)

[**glGetString**](https://learn.microsoft.com/windows/win32/opengl/glgetstring)

[**glIndexPointer**](https://learn.microsoft.com/windows/win32/opengl/glindexpointer)

[**glNormalPointer**](https://learn.microsoft.com/windows/win32/opengl/glnormalpointer)

[**glTexCoordPointer**](https://learn.microsoft.com/windows/win32/opengl/gltexcoordpointer)

[**glVertexPointer**](https://learn.microsoft.com/windows/win32/opengl/glvertexpointer)

