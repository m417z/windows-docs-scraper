# glDrawElements function

The **glDrawElements** function renders primitives from array data.

## Parameters

*mode*

The kind of primitives to render. It can assume one of the following symbolic values: GL\_POINTS, GL\_LINE\_STRIP, GL\_LINE\_LOOP, GL\_LINES, GL\_TRIANGLE\_STRIP, GL\_TRIANGLE\_FAN, GL\_TRIANGLES, GL\_QUAD\_STRIP, GL\_QUADS, and GL\_POLYGON.

*count*

The number of elements to be rendered.

*type*

The type of the values in indices. Must be one of GL\_UNSIGNED\_BYTE, GL\_UNSIGNED\_SHORT, or GL\_UNSIGNED\_INT.

*indices*

A pointer to the location where the indices are stored.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *mode* was not an accepted value.<br> |
| **GL\_INVALID\_VALUE** | *count* was a negative value.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glDrawElements** function enables you to specify multiple geometric primitives with very few function calls. Instead of calling an OpenGL function to pass each individual vertex, normal, or color, you can specify separate arrays of vertices, normals, and colors beforehand and use them to define a sequence of primitives (all of the same type) with a single call to **glDrawElements**.

When you call the **glDrawElements** function, it uses *count* sequential elements from *indices* to construct a sequence of geometric primitives. The *mode* parameter specifies what kind of primitives are constructed, and how the array elements are used to construct these primitives. If GL\_VERTEX\_ARRAY is not enabled, no geometric primitives are generated.

Vertex attributes that are modified by **glDrawElements** have an unspecified value after **glDrawElements** returns. For example, if GL\_COLOR\_ARRAY is enabled, the value of the current color is undefined after **glDrawElements** executes. Attributes that aren't modified remain unchanged.

You can include the **glDrawElements** function in display lists. When **glDrawElements** is included in a display list, the necessary array data (determined by the array pointers and enables) is also entered into the display list. Because the array pointers and enables are client-side state variables, their values affect display lists when the lists are created, not when the lists are executed.

> [!Note]
> The **glDrawElements** function is only available in OpenGL version 1.1 or later.

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

[**glDrawArrays**](https://learn.microsoft.com/windows/win32/opengl/gldrawarrays)

[**glEdgeFlagPointer**](https://learn.microsoft.com/windows/win32/opengl/gledgeflagpointer)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGetPointerv**](https://learn.microsoft.com/windows/win32/opengl/glgetpointerv)

[**glIndexPointer**](https://learn.microsoft.com/windows/win32/opengl/glindexpointer)

[**glNormalPointer**](https://learn.microsoft.com/windows/win32/opengl/glnormalpointer)

[**glTexCoordPointer**](https://learn.microsoft.com/windows/win32/opengl/gltexcoordpointer)

[**glVertexPointer**](https://learn.microsoft.com/windows/win32/opengl/glvertexpointer)

