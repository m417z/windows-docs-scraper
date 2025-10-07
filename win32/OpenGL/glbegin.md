# glBegin function

The **glBegin** and [**glend**](https://learn.microsoft.com/windows/win32/opengl/glend) functions delimit the vertices of a primitive or a group of like primitives.

## Parameters

*mode*

The primitive or primitives that will be created from vertices presented between **glBegin** and the subsequent [**glend**](https://learn.microsoft.com/windows/win32/opengl/glend). The following are accepted symbolic constants and their meanings:

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**GL\_POINTS**

| Treats each vertex as a single point. Vertex *n* defines point *n*. *N* points are drawn.<br> |
|

**GL\_LINES**

| Treats each pair of vertices as an independent line segment. Vertices *2n - 1* and *2n* define line *n*. *N/2* lines are drawn.<br> |
|

**GL\_LINE\_STRIP**

| Draws a connected group of line segments from the first vertex to the last. Vertices *n* and *n+1* define line *n*. *N - 1* lines are drawn.<br> |
|

**GL\_LINE\_LOOP**

| Draws a connected group of line segments from the first vertex to the last, then back to the first. Vertices *n* and *n + 1* define line *n*. The last line, however, is defined by vertices *N* and *1*. *N* lines are drawn.<br> |
|

**GL\_TRIANGLES**

| Treats each triplet of vertices as an independent triangle. Vertices *3n - 2*, *3n - 1*, and *3n* define triangle *n*. *N/3* triangles are drawn.<br> |
|

**GL\_TRIANGLE\_STRIP**

| Draws a connected group of triangles. One triangle is defined for each vertex presented after the first two vertices. For odd *n*, vertices *n*, *n + 1*, and *n + 2* define triangle *n*. For even *n*, vertices *n + 1*, *n*, and *n + 2* define triangle *n*. *N - 2* triangles are drawn.<br> |
|

**GL\_TRIANGLE\_FAN**

| Draws a connected group of triangles. one triangle is defined for each vertex presented after the first two vertices. Vertices *1*, *n + 1*, *n + 2* define triangle *n*. *N - 2* triangles are drawn.<br> |
|

**GL\_QUADS**

| Treats each group of four vertices as an independent quadrilateral. Vertices *4n - 3*, *4n - 2*, *4n - 1*, and *4n* define quadrilateral *n*. *N/4* quadrilaterals are drawn.<br> |
|

**GL\_QUAD\_STRIP**

| Draws a connected group of quadrilaterals. One quadrilateral is defined for each pair of vertices presented after the first pair. Vertices *2n - 1*, *2n*, *2n + 2*, and *2n + 1* define quadrilateral *n*. *N/2 - 1* quadrilaterals are drawn. Note that the order in which vertices are used to construct a quadrilateral from strip data is different from that used with independent data.<br> |
|

**GL\_POLYGON**

| Draws a single, convex polygon. Vertices *1* through *N* define this polygon.<br> |

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *mode* was set to an unaccepted value.<br> |
| **GL\_INVALID\_OPERATION** | A function other than [glVertex](https://learn.microsoft.com/windows/win32/opengl/glvertex-functions), [glColor](https://learn.microsoft.com/windows/win32/opengl/glcolor-functions), [glIndex](https://learn.microsoft.com/windows/win32/opengl/glindex-functions), [glNormal](https://learn.microsoft.com/windows/win32/opengl/glnormal-functions), [glTexCoord](https://learn.microsoft.com/windows/win32/opengl/gltexcoord-functions), [glEvalCoord](https://learn.microsoft.com/windows/win32/opengl/glevalcoord-functions), [glEvalPoint](https://learn.microsoft.com/windows/win32/opengl/glevalpoint), [glMaterial](https://learn.microsoft.com/windows/win32/opengl/glmaterial-functions), [glEdgeFlag](https://learn.microsoft.com/windows/win32/opengl/gledgeflag-functions), [**glCallList**](https://learn.microsoft.com/windows/win32/opengl/glcalllist), or [**glCallLists**](https://learn.microsoft.com/windows/win32/opengl/glcalllists) was called between **glBegin** and the corresponding [**glend**](https://learn.microsoft.com/windows/win32/opengl/glend). The function **glend** was called before the corresponding **glBegin** was called, or **glBegin** was called within a **glBegin**/**glend** sequence. <br> |

## Remarks

The **glBegin** and [**glend**](https://learn.microsoft.com/windows/win32/opengl/glend) functions delimit the vertices that define a primitive or a group of like primitives. The **glBegin** function accepts a single argument that specifies which of ten primitives the vertices compose. Taking *n* as an integer count starting at one, and *N* as the total number of vertices specified, the interpretations are as follows:

- You can use only a subset of OpenGL functions between **glBegin** and [**glend**](https://learn.microsoft.com/windows/win32/opengl/glend). The functions you can use are:

 [**glVertex**](https://learn.microsoft.com/windows/win32/opengl/glvertex-functions)

 [**glColor**](https://learn.microsoft.com/windows/win32/opengl/glcolor-functions)

 [**glIndex**](https://learn.microsoft.com/windows/win32/opengl/glindex-functions)

 [**glNormal**](https://learn.microsoft.com/windows/win32/opengl/glnormal-functions)

 [**glTexCoord**](https://learn.microsoft.com/windows/win32/opengl/gltexcoord-functions)

 [**glEvalCoord**](https://learn.microsoft.com/windows/win32/opengl/glevalcoord-functions)

 [**glEvalPoint**](https://learn.microsoft.com/windows/win32/opengl/glevalpoint)

 [**glMaterial**](https://learn.microsoft.com/windows/win32/opengl/glmaterial-functions)

 [**glEdgeFlag**](https://learn.microsoft.com/windows/win32/opengl/gledgeflag-functions)

 You can also use [**glCallList**](https://learn.microsoft.com/windows/win32/opengl/glcalllist) or [**glCallLists**](https://learn.microsoft.com/windows/win32/opengl/glcalllists) to execute display lists that include only the preceding functions. If any other OpenGL function is called between **glBegin** and [**glend**](https://learn.microsoft.com/windows/win32/opengl/glend), the error flag is set and the function is ignored.

- Regardless of the value chosen for *mode* in **glBegin**, there is no limit to the number of vertices you can define between **glBegin** and [**glend**](https://learn.microsoft.com/windows/win32/opengl/glend). Lines, triangles, quadrilaterals, and polygons that are incompletely specified are not drawn. Incomplete specification results when either too few vertices are provided to specify even a single primitive or when an incorrect multiple of vertices is specified. The incomplete primitive is ignored; the complete primitives are drawn.
- The minimum specification of vertices for each primitive is:

 | Minimum number of vertices | Type of primitive |
|----------------------------|-------------------|
| 1 | point |
| 2 | line |
| 3 | triangle |
| 4 | quadrilateral |
| 3 | polygon |

- Modes that require a certain multiple of vertices are GL\_LINES (2), GL\_TRIANGLES (3), GL\_QUADS (4), and GL\_QUAD\_STRIP (2).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Gl.h |
| Library<br> | Opengl32.lib |
| DLL<br> | Opengl32.dll |

## See also

[**glCallList**](https://learn.microsoft.com/windows/win32/opengl/glcalllist)

[**glCallLists**](https://learn.microsoft.com/windows/win32/opengl/glcalllists)

[**glColor**](https://learn.microsoft.com/windows/win32/opengl/glcolor-functions)

[**glEdgeFlag**](https://learn.microsoft.com/windows/win32/opengl/gledgeflag-functions)

[**glEnd**](https://learn.microsoft.com/windows/desktop/OpenGL/glend)

[**glEvalCoord**](https://learn.microsoft.com/windows/win32/opengl/glevalcoord-functions)

[**glEvalPoint**](https://learn.microsoft.com/windows/win32/opengl/glevalpoint)

[**glIndex**](https://learn.microsoft.com/windows/win32/opengl/glindex-functions)

[**glMaterial**](https://learn.microsoft.com/windows/win32/opengl/glmaterial-functions)

[**glNormal**](https://learn.microsoft.com/windows/win32/opengl/glnormal-functions)

[**glTexCoord**](https://learn.microsoft.com/windows/win32/opengl/gltexcoord-functions)

[**glVertex**](https://learn.microsoft.com/windows/win32/opengl/glvertex-functions)

