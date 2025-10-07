# glHint function

The **glHint** function specifies implementation-specific hints.

## Parameters

*target*

A symbolic constant indicating the behavior to be controlled. The following symbolic constants, along with suggested semantics, are accepted.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**GL\_FOG\_HINT**

| Indicates the accuracy of fog calculation. If per-pixel fog calculation is not efficiently supported by the OpenGL implementation, hinting GL\_DONT\_CARE or GL\_FASTEST can result in per-vertex calculation of fog effects.<br> |
|

**GL\_LINE\_SMOOTH\_HINT**

| Indicates the sampling quality of antialiased lines. Hinting GL\_NICEST can result in more pixel fragments being generated during rasterization, if a larger filter function is applied.<br> |
|

**GL\_PERSPECTIVE\_CORRECTION\_HINT**

| Indicates the quality of color and texture coordinate interpolation. If perspective-corrected parameter interpolation is not efficiently supported by the OpenGL implementation, hinting GL\_DONT\_CARE or GL\_FASTEST can result in simple linear interpolation of colors and/or texture coordinates.<br> |
|

**GL\_POINT\_SMOOTH\_HINT**

| Indicates the sampling quality of antialiased points. Hinting GL\_NICEST can result in more pixel fragments being generated during rasterization, if a larger filter function is applied.<br> |
|

**GL\_POLYGON\_SMOOTH\_HINT**

| Indicates the sampling quality of antialiased polygons. Hinting GL\_NICEST can result in more pixel fragments being generated during rasterization, if a larger filter function is applied.<br> |

*mode*

A symbolic constant indicating the desired behavior. The following symbolic constants are accepted.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------|
|

**GL\_FASTEST**

| The most efficient option should be chosen.<br> |
|

**GL\_NICEST**

| The most correct, or highest quality, option should be chosen.<br> |
|

**GL\_DONT\_CARE**

| The client doesn't have a preference.<br> |

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *target* or *mode* was not an accepted value.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

When there is room for interpretation, you can control certain aspects of OpenGL behavior with hints. You specify a hint with two arguments. The *target* parameter is a symbolic constant indicating the behavior to be controlled, and *mode* is another symbolic constant indicating the desired behavior.

Though the implementation aspects that can be hinted are well defined, the interpretation of the hints depends on the implementation.

The **glHint** function can be ignored.

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

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

