# glMapGrid2f function

Defines a one-dimensional mesh.

## Parameters

*un*

The number of partitions in the grid range interval \[u1, u2\]. This value must be positive.

*u1*

A value used as the mapping for integer grid domain value i = 0.

*u2*

A value used as the mapping for integer grid domain value i = un.

*vn*

The number of partitions in the grid range interval \[v1, v2\].

*v1*

A value used as the mapping for integer grid domain value j = 0.

*v2*

A value used as the mapping for integer grid domain value j = vn.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_VALUE** | Either *un* or *vn* was not positive.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glMapGrid** and [glEvalMesh](https://learn.microsoft.com/windows/win32/opengl/glevalmesh-functions) functions are used in tandem to efficiently generate and evaluate a series of evenly spaced map domain values. The glEvalMesh function steps through the integer domain of a one- or two-dimensional grid, whose range is the domain of the evaluation maps specified by [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1) and [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2).

The [**glMapGrid1**](https://learn.microsoft.com/windows/win32/opengl/glmapgrid1d) and [**glMapGrid2**](https://learn.microsoft.com/windows/win32/opengl/glmapgrid2d) functions specify the linear grid mappings between the i (or i and j) integer grid coordinates, to the u (or u and v) floating-point evaluation map coordinates. See [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1) and [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2) for details of how u and v coordinates are evaluated.

The [**glMapGrid1**](https://learn.microsoft.com/windows/win32/opengl/glmapgrid1d) function specifies a single linear mapping such that integer grid coordinate 0 maps exactly to u1, and integer grid coordinate *un* maps exactly to *u2*. All other integer grid coordinates *i* are mapped such that:

*u = i(u2 u1)/un + u1*

The [**glMapGrid2**](https://learn.microsoft.com/windows/win32/opengl/glmapgrid2d) function specifies two such linear mappings. One maps integer grid coordinate *i = 0* exactly to *u1*, and integer grid coordinate *i = un* exactly to *u2*. The other maps integer grid coordinate *j = 0* exactly to *v1*, and integer grid coordinate *j = vn* exactly to *v2*. Other integer grid coordinates i and j are mapped such that

*u = i(u2 u1)/un + u1*

*v = j (v2 v1)/vn + v1*

The mappings specified by [**glMapGrid**](https://learn.microsoft.com/windows/win32/opengl/glmapgrid1d) are used identically by [glEvalMesh](https://learn.microsoft.com/windows/win32/opengl/glevalmesh-functions) and [**glEvalPoint**](https://learn.microsoft.com/windows/win32/opengl/glevalpoint).

The following functions retrieve information related to [**glMapGrid**](https://learn.microsoft.com/windows/win32/opengl/glmapgrid1d):

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_MAP1\_GRID\_DOMAIN
[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_MAP2\_GRID\_DOMAIN
[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_MAP1\_GRID\_SEGMENTS
[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_MAP2\_GRID\_SEGMENTS

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

[**glEvalCoord**](https://learn.microsoft.com/windows/win32/opengl/glevalcoord-functions)

[glEvalMesh](https://learn.microsoft.com/windows/win32/opengl/glevalmesh-functions)

[**glEvalPoint**](https://learn.microsoft.com/windows/win32/opengl/glevalpoint)

[**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1)

[**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2)

