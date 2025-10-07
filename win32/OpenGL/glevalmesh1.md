# glEvalMesh1 function

Computes a one-dimensional grid of points or lines.

## Parameters

*mode*

A value that specifies whether to compute a one-dimensional mesh of points or lines. The following symbolic constants are accepted: GL\_POINT and GL\_LINE.

*i1*

The first integer value for grid domain variable i.

*i2*

The last integer value for grid domain variable i.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | Indicates that *mode* is not an accepted value. <br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend). <br> |

## Remarks

Use [**glMapGrid**](https://learn.microsoft.com/windows/win32/opengl/glmapgrid-functions) and [**glEvalMesh**](https://learn.microsoft.com/windows/win32/opengl/glevalmesh-functions) together to efficiently generate and evaluate a series of evenly spaced map domain values. The **glEvalMesh** function steps through the integer domain of a one- or two-dimensional grid, whose range is the domain of the evaluation maps specified by [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1) and [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2). The mode parameter determines whether the resulting vertices are connected as points, lines, or filled polygons.

In the one-dimensional case, **glEvalMesh1**, the mesh is generated as if the following code fragment were executed:

[**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin)(*type*);

for (i = i1; i <= i2; i += 1)

{

[**glEvalCoord1**](https://learn.microsoft.com/windows/win32/opengl/glevalcoord1d)(i?u + u1)

}

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)( );

where

?u = (u2 u1) / n

and n, u1, and u2 are the arguments to the most recent [**glMapGrid1**](https://learn.microsoft.com/windows/win32/opengl/glmapgrid1d) function. The *type* parameter is GL\_POINTS if mode is GL\_POINT, or GL\_LINES if mode is GL\_LINE. The one absolute numeric requirement is that if i = n, then the value computed from i?u + u1 is exactly u2.

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

