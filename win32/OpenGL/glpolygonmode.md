# glPolygonMode function

The **glPolygonMode** function selects a polygon rasterization mode.

## Parameters

*face*

The polygons that *mode* applies to. Must be GL\_FRONT for front-facing polygons, GL\_BACK for back-facing polygons, or GL\_FRONT\_AND\_BACK for front- and back-facing polygons.

*mode*

The way polygons will be rasterized. The following modes are defined and can be specified in *mode*. The default is GL\_FILL for both front- and back-facing polygons.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_POINT** | Polygon vertices that are marked as the start of a boundary edge are drawn as points. Point attributes such as GL\_POINT\_SIZE and GL\_POINT\_SMOOTH control the rasterization of the points. Polygon rasterization attributes other than GL\_POLYGON\_MODE have no effect.<br> |
| **GL\_LINE** | Boundary edges of the polygon are drawn as line segments. They are treated as connected line segments for line stippling; the line stipple counter and pattern are not reset between segments (see [**glLineStipple**](https://learn.microsoft.com/windows/win32/opengl/gllinestipple)). Line attributes such as GL\_LINE\_WIDTH and GL\_LINE\_SMOOTH control the rasterization of the lines. Polygon rasterization attributes other than GL\_POLYGON\_MODE have no effect.<br> |
| **GL\_FILL** | The interior of the polygon is filled. Polygon attributes such as GL\_POLYGON\_STIPPLE and GL\_POLYGON\_SMOOTH control the rasterization of the polygon.<br> |

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | Either *face* or *mode* was not an accepted value.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glPolygonMode** function controls the interpretation of polygons for rasterization. The *face* parameter describes which polygons *mode* applies to: front-facing polygons (GL\_FRONT), back-facing polygons (GL\_BACK), or both (GL\_FRONT\_AND\_BACK). The polygon mode affects only the final rasterization of polygons. In particular, a polygon's vertices are lit and the polygon is clipped and possibly culled before these modes are applied.

To draw a surface with filled back-facing polygons and outlined front-facing polygons, call

**glPolygonMode**(GL\_FRONT, GL\_LINE);

Vertices are marked as boundary or nonboundary with an edge flag. Edge flags are generated internally by OpenGL when it decomposes polygons, and they can be set explicitly using [**glEdgeFlag**](https://learn.microsoft.com/windows/win32/opengl/gledgeflag-functions).

The following function retrieves information related to **glPolygonMode**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_POLYGON\_MODE

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

[**glEdgeFlag**](https://learn.microsoft.com/windows/win32/opengl/gledgeflag-functions)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glLineStipple**](https://learn.microsoft.com/windows/win32/opengl/gllinestipple)

[**glLineWidth**](https://learn.microsoft.com/windows/win32/opengl/gllinewidth)

[**glPointSize**](https://learn.microsoft.com/windows/win32/opengl/glpointsize)

[**glPolygonStipple**](https://learn.microsoft.com/windows/win32/opengl/glpolygonstipple)

