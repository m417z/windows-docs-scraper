# glDepthRange function

The **glDepthRange** function specifies the mapping of *z* values from normalized device coordinates to window coordinates.

## Parameters

*zNear*

The mapping of the near clipping plane to window coordinates. The default value is zero.

*zFar*

The mapping of the far clipping plane to window coordinates. The default value is 1.

## Return value

This function does not return a value.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

After clipping and division by *w*, *z* -coordinates range from 0.0 to 1.0, corresponding to the near and far clipping planes. The **glDepthRange** function specifies a linear mapping of the normalized *z*-coordinates in this range to window *z*-coordinates. Regardless of the actual depth buffer implementation, window coordinate depth values are treated as though they range from 0.0 through 1.0 (like color components). Thus, the values accepted by **glDepthRange** are both clamped to this range before they are accepted.

The default mapping of (0,1) maps the near plane to 0 and the far plane to 1. With this mapping, the depth buffer range is fully utilized.

It is not necessary that *zNear* be less than *zFar*. Reverse mappings such as (1,0) are acceptable.

The following function retrieves information related to **glDepthRange**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_DEPTH\_RANGE

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

[**glDepthFunc**](https://learn.microsoft.com/windows/win32/opengl/gldepthfunc)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glViewport**](https://learn.microsoft.com/windows/win32/opengl/glviewport)

