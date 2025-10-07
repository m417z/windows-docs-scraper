# glEdgeFlag function

Flags edges as either boundary or nonboundary.

## Parameters

*flag*

Specifies the current edge flag value, either **TRUE** or **FALSE**.

## Return value

This function does not return a value.

## Remarks

Each vertex of a polygon, separate triangle, or separate quadrilateral specified between a [**glBegin**](https://learn.microsoft.com/windows/desktop/OpenGL/glbegin)/[**glEnd**](https://learn.microsoft.com/windows/desktop/OpenGL/glend) pair is marked as the start of either a boundary or nonboundary edge. If the current edge flag is **TRUE** when the vertex is specified, the vertex is marked as the start of a boundary edge. If the current edge flag is **FALSE**, the vertex is marked as the start of a nonboundary edge. The **glEdgeFlag** function sets the edge flag to **TRUE** if flag is nonzero, **FALSE** otherwise.

The vertices of connected triangles and connected quadrilaterals are always marked as boundary, regardless of the value of the edge flag.

Boundary and nonboundary edge flags on vertices are significant only if GL\_POLYGON\_MODE is set to GL\_POINT or GL\_LINE. See [**glPolygonMode**](https://learn.microsoft.com/windows/desktop/OpenGL/glpolygonmode).

Initially, the edge flag bit is **TRUE**.

The current edge flag can be updated at any time. In particular, **glEdgeFlag** can be called between a call to [**glBegin**](https://learn.microsoft.com/windows/desktop/OpenGL/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/desktop/OpenGL/glend).

The following functions retrieve information related to **glEdgeFlag**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_EDGE\_FLAG

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Gl.h |
| Library<br> | Opengl32.lib |
| DLL<br> | Opengl32.dll |

