# gluTessBeginPolygon function

The **gluTessBeginPolygon** and [**gluTessEndPolygon**](https://learn.microsoft.com/windows/win32/opengl/glutessendpolygon) functions delimit a polygon description.

## Parameters

*tess*

The tessellation object (created with [**gluNewTess**](https://learn.microsoft.com/windows/win32/opengl/glunewtess)).

*polygon\_data*

A pointer to a programmer-defined polygon data structure.

## Return value

This function does not return a value.

## Remarks

The **gluTessBeginPolygon** and [**gluTessEndPolygon**](https://learn.microsoft.com/windows/win32/opengl/glutessendpolygon) functions delimit the definition of a nonconvex polygon. Within each **gluTessBeginPolygon** / **gluTessEndPolygon** pair, include one or more calls to [**gluTessBeginContour**](https://learn.microsoft.com/windows/win32/opengl/glutessbegincontour). Within each contour, there are zero or more calls to [**gluTessVertex**](https://learn.microsoft.com/windows/win32/opengl/glutessvertex). The vertexes specify a closed contour (the last vertex of each contour is automatically linked to the first).

The *polygon\_data* parameter is a pointer to a programmer-defined data structure. If the appropriate callbacks are specified (see [*gluTessCallback*](https://learn.microsoft.com/windows/win32/opengl/glutess)), this pointer is returned to the callback function or functions, making it a convenient way to store per-polygon information.

When you call [**gluTessEndPolygon**](https://learn.microsoft.com/windows/win32/opengl/glutessendpolygon), the polygon is tessellated, and the resulting triangles are described through callbacks. For descriptions of the callback functions, see [*gluTessCallback*](https://learn.microsoft.com/windows/win32/opengl/glutess).

## Examples

The following describes a quadrilateral with a triangular hole:

``` syntax
gluTessBeginPolygon(tobj, NULL);
  gluTessBeginContour(tobj);
    gluTessVertex(tobj, v1, v1);
    gluTessVertex(tobj, v2, v2);
    gluTessVertex(tobj, v3, v3);
    gluTessVertex(tobj, v4, v4);
  gluTessEndContour(tobj);
  gluTessBeginContour(tobj);
    gluTessVertex(tobj, v5, v5);
    gluTessVertex(tobj, v6, v6);
    gluTessVertex(tobj, v7, v7);
  gluTessEndContour(tobj);
gluTessEndPolygon(tobj);
```

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Glu.h |
| Library<br> | Glu32.lib |
| DLL<br> | Glu32.dll |

## See also

[**gluNewTess**](https://learn.microsoft.com/windows/win32/opengl/glunewtess)

[**gluTessBeginContour**](https://learn.microsoft.com/windows/win32/opengl/glutessbegincontour)

[*gluTessCallback*](https://learn.microsoft.com/windows/win32/opengl/glutess)

[**gluTessEndContour**](https://learn.microsoft.com/windows/win32/opengl/glutessendcontour)

[**gluTessNormal**](https://learn.microsoft.com/windows/win32/opengl/glutessnormal)

[**gluTessProperty**](https://learn.microsoft.com/windows/win32/opengl/glutessproperty)

[**gluTessVertex**](https://learn.microsoft.com/windows/win32/opengl/glutessvertex)

