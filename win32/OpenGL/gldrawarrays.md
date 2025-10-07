# glDrawArrays function

The **glDrawArrays** function specifies multiple primitives to render.

## Parameters

*mode*

The kind of primitives to render. The following constants specify acceptable types of primitives: GL\_POINTS, GL\_LINE\_STRIP, GL\_LINE\_LOOP, GL\_LINES, GL\_TRIANGLE\_STRIP, GL\_TRIANGLE\_FAN, GL\_TRIANGLES, GL\_QUAD\_STRIP, GL\_QUADS, and GL\_POLYGON.

*first*

The starting index in the enabled arrays.

*count*

The number of indexes to render.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_VALUE** | *count* was negative.<br> |
| **GL\_INVALID\_ENUM** | *mode* was not an accepted value.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

With **glDrawArrays**, you can specify multiple geometric primitives to render. Instead of calling separate OpenGL functions to pass each individual vertex, normal, or color, you can specify separate arrays of vertices, normals, and colors to define a sequence of primitives (all the same kind) with a single call to **glDrawArrays**.

When you call **glDrawArrays**, *count* sequential elements from each enabled array are used to construct a sequence of geometric primitives, beginning with the *first* element. The *mode* parameter specifies what kind of primitive to construct and how to use the array elements to construct the primitives.

After **glDrawArrays** returns, the values of vertex attributes that are modified by **glDrawArrays** are undefined. For example, if GL\_COLOR\_ARRAY is enabled, the value of the current color is undefined after **glDrawArrays** returns. Attributes not modified by **glDrawArrays** remain defined. When GL\_VERTEX\_ARRAY is not enabled, no geometric primitives are generated but the attributes corresponding to enabled arrays are modified.

You can include **glDrawArrays** in display lists. When you include **glDrawArrays** in a display list, the necessary array data, determined by the array pointers and the enables, are generated and entered in the display list. The values of array pointers and enables are determined during the creation of display lists.

You can read static array data at any time. If any static array elements are modified and the array is not specified again, the results of any subsequent calls to **glDrawArrays** are undefined.

Although no error is generated when you specify an array more than once within [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and [**glend**](https://learn.microsoft.com/windows/win32/opengl/glend) pairs, the results are undefined.

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

[**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin)

[**glColorPointer**](https://learn.microsoft.com/windows/win32/opengl/glcolorpointer)

[**glEdgeFlagPointer**](https://learn.microsoft.com/windows/win32/opengl/gledgeflagpointer)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGetPointerv**](https://learn.microsoft.com/windows/win32/opengl/glgetpointerv)

[**glGetString**](https://learn.microsoft.com/windows/win32/opengl/glgetstring)

[**glIndexPointer**](https://learn.microsoft.com/windows/win32/opengl/glindexpointer)

[**glNormalPointer**](https://learn.microsoft.com/windows/win32/opengl/glnormalpointer)

[**glTexCoordPointer**](https://learn.microsoft.com/windows/win32/opengl/gltexcoordpointer)

[**glVertexPointer**](https://learn.microsoft.com/windows/win32/opengl/glvertexpointer)

