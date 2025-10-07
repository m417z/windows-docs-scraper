# glPointSize function

The **glPointSize** function specifies the diameter of rasterized points.

## Parameters

*size*

The diameter of rasterized points. The default is 1.0.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_VALUE** | *size* was less than or equal to zero.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glPointSize** function specifies the rasterized diameter of both aliased and antialiased points. Using a point size other than 1.0 has different effects, depending on whether point antialiasing is enabled. Point antialiasing is controlled by calling [**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable) and **glDisable** with argument GL\_POINT\_SMOOTH.

If point antialiasing is disabled, the actual size is determined by rounding the supplied size to the nearest integer. (If the rounding results in the value 0, it is as if the point size were 1.) If the rounded size is odd, then the center point (*x*,*y*) of the pixel fragment that represents the point is computed as

(*x*w + .5, *y*w + .5)

where *w* subscripts indicate window coordinates. All pixels that lie within the square grid of the rounded size centered at (*x*,*y*) make up the fragment. If the size is even, the center point is

(*x*w + .5, *y*w + .5)

and the rasterized fragment's centers are the half-integer window coordinates within the square of the rounded size centered at (*x*,*y*). All pixel fragments produced in rasterizing a nonantialiased point are assigned the same associated data; that of the vertex corresponding to the point.

If antialiasing is enabled, then point rasterization produces a fragment for each pixel square that intersects the region lying within the circle having diameter equal to the current point size and centered at the points (*x*w ,*y*w ). The coverage value for each fragment is the window coordinate area of the intersection of the circular region with the corresponding pixel square. This value is saved and used in the final rasterization step. The data associated with each fragment is the data associated with the point being rasterized.

Not all sizes are supported when point antialiasing is enabled. If an unsupported size is requested, the nearest supported size is used. Only size 1.0 is guaranteed to be supported; others depend on the implementation. The range of supported sizes and the size difference between supported sizes within the range can be queried by calling [**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with arguments GL\_POINT\_SIZE\_RANGE and GL\_POINT\_SIZE\_GRANULARITY.

The point size specified by **glPointSize** is always returned when GL\_POINT\_SIZE is queried. Clamping and rounding for aliased and antialiased points have no effect on the specified value.

Non-antialiased point size may be clamped to an implementation-dependent maximum. Although this maximum cannot be queried, it must be no less than the maximum value for antialiased points, rounded to the nearest integer value.

The following functions retrieve information related to **glPointSize**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_POINT\_SIZE

**glGet** with argument GL\_POINT\_SIZE\_RANGE

**glGet** with argument GL\_POINT\_SIZE\_GRANULARITY

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument GL\_POINT\_SMOOTH

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

[**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled)

