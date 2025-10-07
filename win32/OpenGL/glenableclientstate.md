# glEnableClientState function

The **glEnableClientState** and [**glDisableClientState**](https://learn.microsoft.com/windows/win32/opengl/gldisableclientstate) functions enable and disable arrays respectively.

## Parameters

*array*

A symbolic constant for the array you want to enable or disable. This parameter can assume one of the following values.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_COLOR\_ARRAY** | If enabled, use color arrays with calls to [**glArrayElement**](https://learn.microsoft.com/windows/win32/opengl/glarrayelement), [**glDrawElements**](https://learn.microsoft.com/windows/win32/opengl/gldrawelements), or [**glDrawArrays**](https://learn.microsoft.com/windows/win32/opengl/gldrawarrays).<br> See also [**glColorPointer**](https://learn.microsoft.com/windows/win32/opengl/glcolorpointer).<br> |
| **GL\_EDGE\_FLAG\_ARRAY** | If enabled, use edge flag arrays with calls to [**glArrayElement**](https://learn.microsoft.com/windows/win32/opengl/glarrayelement), [**glDrawElements**](https://learn.microsoft.com/windows/win32/opengl/gldrawelements), or [**glDrawArrays**](https://learn.microsoft.com/windows/win32/opengl/gldrawarrays).<br> See also [**glEdgeFlagPointer**](https://learn.microsoft.com/windows/win32/opengl/gledgeflagpointer).<br> |
| **GL\_INDEX\_ARRAY** | If enabled, use index arrays with calls to [**glArrayElement**](https://learn.microsoft.com/windows/win32/opengl/glarrayelement), [**glDrawElements**](https://learn.microsoft.com/windows/win32/opengl/gldrawelements), or [**glDrawArrays**](https://learn.microsoft.com/windows/win32/opengl/gldrawarrays).<br> See also [**glIndexPointer**](https://learn.microsoft.com/windows/win32/opengl/glindexpointer).<br> |
| **GL\_NORMAL\_ARRAY** | If enabled, use normal arrays with calls to [**glArrayElement**](https://learn.microsoft.com/windows/win32/opengl/glarrayelement), [**glDrawElements**](https://learn.microsoft.com/windows/win32/opengl/gldrawelements), or [**glDrawArrays**](https://learn.microsoft.com/windows/win32/opengl/gldrawarrays).<br> See also [**glNormalPointer**](https://learn.microsoft.com/windows/win32/opengl/glnormalpointer).<br> |
| **GL\_TEXTURE\_COORD\_ARRAY** | If enabled, use texture coordinate arrays with calls to [**glArrayElement**](https://learn.microsoft.com/windows/win32/opengl/glarrayelement), [**glDrawElements**](https://learn.microsoft.com/windows/win32/opengl/gldrawelements), or [**glDrawArrays**](https://learn.microsoft.com/windows/win32/opengl/gldrawarrays).<br> See also [**glTexCoordPointer**](https://learn.microsoft.com/windows/win32/opengl/gltexcoordpointer).<br> |
| **GL\_VERTEX\_ARRAY** | If enabled, use vertex arrays with calls to [**glArrayElement**](https://learn.microsoft.com/windows/win32/opengl/glarrayelement), [**glDrawElements**](https://learn.microsoft.com/windows/win32/opengl/gldrawelements), or [**glDrawArrays**](https://learn.microsoft.com/windows/win32/opengl/gldrawarrays).<br> See also [**glVertexPointer**](https://learn.microsoft.com/windows/win32/opengl/glvertexpointer).<br> |

## Return value

This function does not return a value.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|--------------------------------------------------------------------------------------------------|-----------------------------------------------|
| **GL\_INVALID\_ENUM** | *array* was not an accepted value.<br> |

## Remarks

The **glEnableClientState** and **glDisableClientState** functions enable and disable various individual arrays. Use [**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) or [**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) to determine the current setting of any capability.

Calling **glEnableClientState** and **glDisableClientState** between calls to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend) can cause an error. If no error is generated, the behavior is undefined.

> [!Note]
> The **glEnableClientState** and **glDisableClientState** functions are only available in OpenGL version 1.1 or later.

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

[**glDisableClientState**](https://learn.microsoft.com/windows/win32/opengl/gldisableclientstate)

[**glDrawArrays**](https://learn.microsoft.com/windows/win32/opengl/gldrawarrays)

[**glDrawElements**](https://learn.microsoft.com/windows/win32/opengl/gldrawelements)

[**glEdgeFlagPointer**](https://learn.microsoft.com/windows/win32/opengl/gledgeflagpointer)

[**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGetPointerv**](https://learn.microsoft.com/windows/win32/opengl/glgetpointerv)

[**glIndexPointer**](https://learn.microsoft.com/windows/win32/opengl/glindexpointer)

[**glInterleavedArrays**](https://learn.microsoft.com/windows/win32/opengl/glinterleavedarrays)

[**glNormalPointer**](https://learn.microsoft.com/windows/win32/opengl/glnormalpointer)

[**glTexCoordPointer**](https://learn.microsoft.com/windows/win32/opengl/gltexcoordpointer)

[**glVertexPointer**](https://learn.microsoft.com/windows/win32/opengl/glvertexpointer)

