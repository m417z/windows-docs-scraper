# glEdgeFlagPointer function

The **glEdgeFlagPointer** function defines an array of edge flags.

## Parameters

*stride*

The byte offset between consecutive edge flags. When *stride* is zero, the edge flags are tightly packed in the array.

*pointer*

A pointer to the first edge flag in the array.

## Return value

This function does not return a value.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|--------------------------------------------------------------------------------------------------|----------------------------------------------|
| **GL\_INVALID\_ENUM** | *stride* or *count* was negative.<br> |

## Remarks

The **glEdgeFlagPointer** function specifies the location and data of an array of Boolean edge flags to use when rendering. The *stride* parameter determines the byte offset from one edge flag to the next, which enables the packing of vertices and attributes in a single array or storage in separate arrays. In some implementations, storing the vertices and attributes in a single array can be more efficient than using separate arrays.

An edge-flag array is enabled when you specify the GL\_EDGE\_FLAG\_ARRAY constant with [**glEnableClientState**](https://learn.microsoft.com/windows/win32/opengl/glenableclientstate). When enabled, [**glDrawArrays**](https://learn.microsoft.com/windows/win32/opengl/gldrawarrays) or [**glArrayElement**](https://learn.microsoft.com/windows/win32/opengl/glarrayelement) uses the edge-flag array. By default the edge-flag array is disabled.

Use **glDrawArrays** to construct a sequence of primitives (all of the same type) from prespecified vertex and vertex attribute arrays. Use **glArrayElement** to specify primitives by indexing vertices and vertex attributes, and [**glDrawElements**](https://learn.microsoft.com/windows/win32/opengl/gldrawelements) to construct a sequence of primitives by indexing vertices and vertex attributes.

You cannot include **glEdgeFlagPointer** in display lists.

When you specify an edge-flag array using **glEdgeFlagPointer**, the values of all the function's edge-flag array parameters are saved in a client-side state and static array elements can be cached. Because the edge-flag array parameters are in a client-side state, [**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib) and [**glPopAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpopattrib) do not save or restore their values.

Although calling **glEdgeFlagPointer** within a [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin)/[**glend**](https://learn.microsoft.com/windows/win32/opengl/glend) pair does not generate an error, the results are undefined.

The following functions retrieve information related to the **glEdgeFlagPointer** function:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_EDGE\_FLAG\_ARRAY\_STRIDE

**glGet** with argument GL\_EDGE\_FLAG\_ARRAY\_COUNT

[**glGetPointerv**](https://learn.microsoft.com/windows/win32/opengl/glgetpointerv) with argument GL\_EDGE\_FLAG\_ARRAY\_POINTER

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument GL\_EDGE\_FLAG\_ARRAY

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

[**glEnableClientState**](https://learn.microsoft.com/windows/win32/opengl/glenableclientstate)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glGetPointerv**](https://learn.microsoft.com/windows/win32/opengl/glgetpointerv)

[**glGetString**](https://learn.microsoft.com/windows/win32/opengl/glgetstring)

[**glIndexPointer**](https://learn.microsoft.com/windows/win32/opengl/glindexpointer)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled)

[**glNormalPointer**](https://learn.microsoft.com/windows/win32/opengl/glnormalpointer)

[**glPopAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpopattrib)

[**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib)

[**glTexCoordPointer**](https://learn.microsoft.com/windows/win32/opengl/gltexcoordpointer)

[**glVertexPointer**](https://learn.microsoft.com/windows/win32/opengl/glvertexpointer)

