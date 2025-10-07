# glEvalPoint1 function

The [**glEvalPoint1**](https://learn.microsoft.com/windows/win32/opengl/glevalpoint) and **glEvalPoint2** functions generate and evaluate a single point in a mesh.

## Parameters

*i*

The integer value for grid domain variable *i*.

## Return value

This function does not return a value.

## Remarks

The [**glMapGrid**](https://learn.microsoft.com/windows/win32/opengl/glmapgrid-functions) and [**glEvalMesh**](https://learn.microsoft.com/windows/win32/opengl/glevalmesh-functions) functions are used in tandem to efficiently generate and evaluate a series of evenly spaced map domain values. You can use **glEvalPoint** to evaluate a single grid point in the same gridspace that is traversed by **glEvalMesh**. Calling [**glEvalPoint1**](https://learn.microsoft.com/windows/win32/opengl/glevalpoint) is equivalent to calling

**glEvalCoord1** (*i* ?*u* +*u*1 );

where

?*u* = (*u*2 *u*1 )/*n*

and *n*, *u*1 , and *u*2 are the arguments to the most recent **glMapGrid1** function. The one absolute numeric requirement is that if *i* = *n*, then the value computed from (*i* ?*u* + u1 ) is exactly *u*2 .

In the two-dimensional case, **glEvalPoint2**, let

?*u* = (*u*2 *u*1 )/*n*

?*v* = (*v*2 *v*1 )/*m*

where *n*, *u*1 , *u*2 , *m*, *v*1 , and *v*2 are the arguments to the most recent **glMapGrid2** function. Then the **glEvalPoint2** function is equivalent to calling

**glEvalCoord2** (*i* ?*u* + *u*1 , *j* ?*v* + *v*1 );

The only absolute numeric requirements are that if *i*=*n*, then the value computed from (*i* ?*u* + *u*1 ) is exactly u2 , and if *j* = *m*, then the value computed from (*j* ?*v* + *v*1 ) is exactly *v*2 .

The following functions retrieve information relating to [**glEvalPoint1**](https://learn.microsoft.com/windows/win32/opengl/glevalpoint) and **glEvalPoint2**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_MAP1\_GRID\_DOMAIN

**glGet** with argument GL\_MAP2\_GRID\_DOMAIN

**glGet** with argument GL\_MAP1\_GRID\_SEGMENTS

**glGet** with argument GL\_MAP2\_GRID\_SEGMENTS

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Gl.h |
| Library<br> | Opengl32.lib |
| DLL<br> | Opengl32.dll |

## See also

[**glEvalCoord**](https://learn.microsoft.com/windows/win32/opengl/glevalcoord-functions)

[**glEvalMesh**](https://learn.microsoft.com/windows/win32/opengl/glevalmesh-functions)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1)

[**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2)

[**glMapGrid**](https://learn.microsoft.com/windows/win32/opengl/glmapgrid-functions)

