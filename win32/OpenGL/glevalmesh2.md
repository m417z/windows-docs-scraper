# glEvalMesh2 function

Computes a two-dimensional grid of points or lines.

## Parameters

*mode*

A value that specifies whether to compute a two-dimensional mesh of points, lines, or polygons. The following symbolic constants are accepted: GL\_POINT, GL\_LINE, and GL\_FILL.

*i1*

The first integer value for grid domain variable i.

*i2*

The last integer value for grid domain variable i.

*j1*

The first integer value for grid domain variable j.

*j2*

The last integer value for grid domain variable j.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | Indicates that *mode* is not an accepted value. <br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend). <br> |

## Remarks

Use [**glMapGrid**](https://learn.microsoft.com/windows/win32/opengl/glmapgrid-functions) and [**glEvalMesh**](https://learn.microsoft.com/windows/win32/opengl/glevalmesh-functions) in tandem to efficiently generate and evaluate a series of evenly spaced map domain values. The **glEvalMesh** function steps through the integer domain of a one- or two-dimensional grid, whose range is the domain of the evaluation maps specified by [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1) and [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2). The mode parameter determines whether the resulting vertices are connected as points, lines, or filled polygons.

In the two-dimensional case, **glEvalMesh2**, let

? u = (u2 u1)/n

? v = (v2 v1)/m,

where n, u1, u2, m, v1, and v2 are the arguments to the most recent [**glMapGrid2**](https://learn.microsoft.com/windows/win32/opengl/glmapgrid-functions) function. Then, if *mode* is GL\_FILL, **glEvalMesh2** is equivalent to:

for (j = j1; j < j2; j += 1)

{

[**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin)(GL\_QUAD\_STRIP);

for (i = i1; i <= i2; i += 1)

{

[**glEvalCoord2**](https://learn.microsoft.com/windows/win32/opengl/glevalcoord2d)(i? u + u1 ( ) , j ? v + v1);

[**glEvalCoord2**](https://learn.microsoft.com/windows/win32/opengl/glevalcoord2d)(i? u + u1 ( ) , (j+1) ? v + v1);

}

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)( ); }

If *mode* is GL\_LINE, then a call to **glEvalMesh2** is equivalent to:

for (j = j1; j <= j2; j += 1)

{

[**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin)(GL\_LINE\_STRIP);

for (i = i1; i <= i2; i += 1)

{

[**glEvalCoord2**](https://learn.microsoft.com/windows/win32/opengl/glevalcoord2d)(i? u + u1, j? v + v1);

}

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)( );

}

for (i = i1; i <= i2; i += 1)

{

[**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin)(GL\_LINE\_STRIP);

for (j = j1; j <= j1; j += 1)

{

[**glEvalCoord2**](https://learn.microsoft.com/windows/win32/opengl/glevalcoord2d)(i? u + u1, j? v + v1);

}

glEnd( );

}

And finally, if *mode* is GL\_POINT, then a call to **glEvalMesh2** is equivalent to:

[**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin)(GL\_POINTS);

for (j = j1; j <= j2; j += 1)

{

for (i = i1; i <= i2; i += 1)

{

[**glEvalCoord2**](https://learn.microsoft.com/windows/win32/opengl/glevalcoord2d)(i? u + u1, j? v + v1);

}

}

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)( );

In all three cases, the only absolute numeric requirements are that if i = n, then the value computed from i? u + u1 is exactly u2, and if j = m, then the value computed from j? v + v1 is exactly v2. The following functions retrieve information relating to **glEvalMesh**:

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

