# glColorPointer function

The **glColorPointer** function defines an array of colors.

## Parameters

*size*

The number of components per color. The value must be either 3 or 4.

*type*

The data type of each color component in a color array. Acceptable data types are specified with the following constants: GL\_BYTE, GL\_UNSIGNED\_BYTE, GL\_SHORT, GL\_UNSIGNED\_SHORT, GL\_INT, GL\_UNSIGNED\_INT, GL\_FLOAT, or GL\_DOUBLE.

*stride*

The byte offset between consecutive colors. When *stride* is zero, the colors are tightly packed in the array.

*pointer*

A pointer to the first component of the first color element in a color array.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|---------------------------------------------------------------------------------------------------|----------------------------------------------|
| **GL\_INVALID\_VALUE** | *size* was not 3 or 4.<br> |
| **GL\_INVALID\_ENUM** | *type* was not an accepted value.<br> |
| **GL\_INVALID\_VALUE** | *stride* or *count* was negative.<br> |

## Remarks

The **glColorPointer** function specifies the location and data format of an array of color components to use when rendering. The *stride* parameter determines the byte offset from one color to the next, enabling the packing of vertex attributes in a single array or storage in separate arrays. In some implementations, storing vertex attributes in a single array can be more efficient than the use of separate arrays.

Enabled the color array by specifying the GL\_COLOR\_ARRAY constant with [**glEnableClientState**](https://learn.microsoft.com/windows/win32/opengl/glenableclientstate). Calling [**glArrayElement**](https://learn.microsoft.com/windows/win32/opengl/glarrayelement), [**glDrawElements**](https://learn.microsoft.com/windows/win32/opengl/gldrawelements), or [**glDrawArrays**](https://learn.microsoft.com/windows/win32/opengl/gldrawarrays) uses the color array that is thus enabled. By default, the color array is disabled. The **glColorPointer** calls cannot by entered in display lists.

When you specify a color array using **glColorPointer**, the values of all the function's color array parameters are saved in a client-side state, and you can cache static array elements. Because the color array parameters are in a client-side state, [**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib) and [**glPopAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpopattrib) do not save or restore the parameters' values.

Although specifying the color array within [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and [**glend**](https://learn.microsoft.com/windows/win32/opengl/glend) pairs does not generate an error, the results are undefined.

The following functions retrieve information related to the **glColorPointer** function:

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument GL\_COLOR\_ARRAY

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_COLOR\_ARRAY\_SIZE

**glGet** with argument GL\_COLOR\_ARRAY\_TYPE

**glGet** with argument GL\_COLOR\_ARRAY\_STRIDE

**glGet** with argument GL\_COLOR\_ARRAY\_COUNT

[**glGetPointerv**](https://learn.microsoft.com/windows/win32/opengl/glgetpointerv) with argument GL\_COLOR\_ARRAY\_POINTER

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

[**glDrawArrays**](https://learn.microsoft.com/windows/win32/opengl/gldrawarrays)

[**glEdgeFlagPointer**](https://learn.microsoft.com/windows/win32/opengl/gledgeflagpointer)

[**glEnableClientState**](https://learn.microsoft.com/windows/win32/opengl/glenableclientstate)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glGetString**](https://learn.microsoft.com/windows/win32/opengl/glgetstring)

[**glGetPointerv**](https://learn.microsoft.com/windows/win32/opengl/glgetpointerv)

[**glIndexPointer**](https://learn.microsoft.com/windows/win32/opengl/glindexpointer)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled)

[**glNormalPointer**](https://learn.microsoft.com/windows/win32/opengl/glnormalpointer)

[**glPopAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpopattrib)

[**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib)

[**glTexCoordPointer**](https://learn.microsoft.com/windows/win32/opengl/gltexcoordpointer)

[**glVertexPointer**](https://learn.microsoft.com/windows/win32/opengl/glvertexpointer)

