# glPixelMapusv function

The **glPixelMapusv** function sets up pixel transfer maps.

## Parameters

*map*

A symbolic map name. The ten maps are as follows.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------|
|

**GL\_PIXEL\_MAP\_I\_TO\_I**

| Maps color indexes to color indexes.<br> |
|

**GL\_PIXEL\_MAP\_S\_TO\_S**

| Maps stencil indexes to stencil indexes.<br> |
|

**GL\_PIXEL\_MAP\_I\_TO\_R**

| Maps color indexes to red components.<br> |
|

**GL\_PIXEL\_MAP\_I\_TO\_G**

| Maps color indexes to green components.<br> |
|

**GL\_PIXEL\_MAP\_I\_TO\_B**

| Maps color indexes to blue components.<br> |
|

**GL\_PIXEL\_MAP\_I\_TO\_A**

| Maps color indexes to alpha components.<br> |
|

**GL\_PIXEL\_MAP\_R\_TO\_R**

| Maps red components to red components.<br> |
|

**GL\_PIXEL\_MAP\_G\_TO\_G**

| Maps green components to green components.<br> |
|

**GL\_PIXEL\_MAP\_B\_TO\_B**

| Maps blue components to blue components.<br> |
|

**GL\_PIXEL\_MAP\_A\_TO\_A**

| Maps alpha components to alpha components.<br> |

*mapsize*

The size of the map being defined.

*values*

An array of *mapsize* values.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *map* was not an accepted value.<br> |
| **GL\_INVALID\_VALUE** | *mapsize* was negative or larger than GL\_PIXEL\_MAP\_TABLE. <br> |
| **GL\_INVALID\_VALUE** | *map* was GL\_PIXEL\_MAP\_I\_TO\_I, GL\_PIXEL\_MAP\_S\_TO\_S, GL\_PIXEL\_MAP\_I\_TO\_R, GL\_PIXEL\_MAP\_I\_TO\_G, GL\_PIXEL\_MAP\_I\_TO\_B, or GL\_PIXEL\_MAP\_I\_TO\_A, and *mapsize* was not a power of two. <br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend). <br> |

## Remarks

The **glPixelMap** function sets up translation tables, or *maps*, used by [**glCopyPixels**](https://learn.microsoft.com/windows/win32/opengl/glcopypixels), [**glCopyTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glcopyteximage1d), [**glCopyTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glcopyteximage2d), [**glCopyTexSubImage1D**](https://learn.microsoft.com/windows/win32/opengl/glcopytexsubimage1d), [**glCopyTexSubImage2D**](https://learn.microsoft.com/windows/win32/opengl/glcopytexsubimage2d), [**glDrawPixels**](https://learn.microsoft.com/windows/win32/opengl/gldrawpixels), [**glReadPixels**](https://learn.microsoft.com/windows/win32/opengl/glreadpixels), [**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d), [**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d), [**glTexSubImage1D**](https://learn.microsoft.com/windows/win32/opengl/gltexsubimage1d), and [**glTexSubImage2D**](https://learn.microsoft.com/windows/win32/opengl/gltexsubimage2d). Use of these maps is described completely in the [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer) topic, and partly in the topics for the pixel and texture image commands. Only the specification of the maps is described in this topic.

The *map* parameter is a symbolic map name, indicating one of ten maps to set. The *mapsize* parameter specifies the number of entries in the map, and *values* is a pointer to an array of *mapsize* map values.

The entries in a map can be specified as single-precision floating-point numbers, unsigned short integers, or unsigned long integers. Maps that store color component values (all but GL\_PIXEL\_MAP\_I\_TO\_I and GL\_PIXEL\_MAP\_S\_TO\_S) retain their values in floating-point format, with unspecified mantissa and exponent sizes. Floating-point values specified by [**glPixelMapfv**](https://learn.microsoft.com/windows/win32/opengl/glpixelmap) are converted directly to the internal floating-point format of these maps, and then clamped to the range \[0,1\]. Unsigned integer values specified by **glPixelMapusv** and **glPixelMapuiv** are converted linearly such that the largest representable integer maps to 1.0, and zero maps to 0.0.

Maps that store indexes, GL\_PIXEL\_MAP\_I\_TO\_I and GL\_PIXEL\_MAP\_S\_TO\_S, retain their values in fixed-point format, with an unspecified number of bits to the right of the binary point. Floating-point values specified by [**glPixelMapfv**](https://learn.microsoft.com/windows/win32/opengl/glpixelmap) are converted directly to the internal fixed-point format of these maps. Unsigned integer values specified by **glPixelMapusv** and **glPixelMapuiv** specify integer values, with all zeros to the right of the binary point.

The following table shows the initial sizes and values for each of the maps. Maps that are indexed by either color or stencil indexes must have *mapsize* = 2 ^ *n* for some *n* or results are undefined. The maximum allowable size for each map depends on the implementation and can be determined by calling **glGet** with argument GL\_MAX\_PIXEL\_MAP\_TABLE. The single maximum applies to all maps, and it is at least 32.

| Map | Lookup Index | Lookup Value | Initial Size | Initial Value |
|--------------------------|---------------|---------------|--------------|---------------|
| GL\_PIXEL\_MAP\_I\_TO\_I | color index | color index | 1 | 0.0 |
| GL\_PIXEL\_MAP\_S\_TO\_S | stencil index | stencil index | 1 | 0.0 |
| GL\_PIXEL\_MAP\_I\_TO\_R | color index | R | 1 | 0.0 |
| GL\_PIXEL\_MAP\_I\_TO\_G | color index | G | 1 | 0.0 |
| GL\_PIXEL\_MAP\_I\_TO\_B | color index | B | 1 | 0.0 |
| GL\_PIXEL\_MAP\_I\_TO\_A | color index | A | 1 | 0.0 |
| GL\_PIXEL\_MAP\_R\_TO\_R | R | R | 1 | 0.0 |
| GL\_PIXEL\_MAP\_G\_TO\_G | G | G | 1 | 0.0 |
| GL\_PIXEL\_MAP\_B\_TO\_B | B | B | 1 | 0.0 |
| GL\_PIXEL\_MAP\_A\_TO\_A | A | A | 1 | 0.0 |

The following functions retrieve information related to **glPixelMap**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_PIXEL\_MAP\_I\_TO\_I\_SIZE

**glGet** with argument GL\_PIXEL\_MAP\_S\_TO\_S\_SIZE

**glGet** with argument GL\_PIXEL\_MAP\_I\_TO\_R\_SIZE

**glGet** with argument GL\_PIXEL\_MAP\_I\_TO\_G\_SIZE

**glGet** with argument GL\_PIXEL\_MAP\_I\_TO\_B\_SIZE

**glGet** with argument GL\_PIXEL\_MAP\_I\_TO\_A\_SIZE

**glGet** with argument GL\_PIXEL\_MAP\_R\_TO\_R\_SIZE

**glGet** with argument GL\_PIXEL\_MAP\_G\_TO\_G\_SIZE

**glGet** with argument GL\_PIXEL\_MAP\_B\_TO\_B\_SIZE

**glGet** with argument GL\_PIXEL\_MAP\_A\_TO\_A\_SIZE

**glGet** with argument GL\_MAX\_PIXEL\_MAP\_TABLE

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

[**glCopyPixels**](https://learn.microsoft.com/windows/win32/opengl/glcopypixels)

[**glDrawPixels**](https://learn.microsoft.com/windows/win32/opengl/gldrawpixels)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glPixelStore**](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions)

[**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer)

[**glReadPixels**](https://learn.microsoft.com/windows/win32/opengl/glreadpixels)

[**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d)

[**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d)

