# gluEndPolygon function

\[The **gluEndPolygon** function is obsolete and is provided for backward compatibility only. The **gluEndPolygon** function is mapped to **gluTessEndPolygon** followed by **gluTessEndContour**.\]

The [**gluBeginPolygon**](https://learn.microsoft.com/windows/win32/opengl/glubeginpolygon) and **gluEndPolygon** functions delimit a polygon description.

## Parameters

*tess*

The tessellation object (created with [**gluNewTess**](https://learn.microsoft.com/windows/win32/opengl/glunewtess)).

## Return value

This function does not return a value.

## Remarks

Use [**gluBeginPolygon**](https://learn.microsoft.com/windows/win32/opengl/glubeginpolygon) and **gluEndPolygon** to delimit the definition of a nonconvex polygon.

1. Call **gluBeginPolygon**.
2. Define the contours of the polygon by calling [**gluTessVertex**](https://learn.microsoft.com/windows/win32/opengl/glutessvertex) for each vertex and [**gluNextContour**](https://learn.microsoft.com/windows/win32/opengl/glunextcontour) to start each new contour.
3. Call **gluEndPolygon** to signal the end of the definition.

 Once **gluEndPolygon** is called, the polygon is tessellated, and the resulting triangles are described through callbacks. For descriptions of the callback functions, see [*gluTessCallback*](https://learn.microsoft.com/windows/win32/opengl/glutess).

## Examples

The following example describes a quadrilateral with a triangular hole:

``` syntax
gluBeginPolygon(tess);
    gluTessVertex(tess, v1, v1);
    gluTessVertex(tess, v2, v2);
    gluTessVertex(tess, v3, v3);
    gluTessVertex(tess, v4, v4);
gluNextContour(tess, GLU_INTERIOR);
    gluTessVertex(tess, v5, v5);
    gluTessVertex(tess, v6, v6);
    gluTessVertex(tess, v7, v7);
gluEndPolygon(tess);
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

[**gluNextContour**](https://learn.microsoft.com/windows/win32/opengl/glunextcontour)

[**gluTessBeginContour**](https://learn.microsoft.com/windows/win32/opengl/glutessbegincontour)

[**gluTessBeginPolygon**](https://learn.microsoft.com/windows/win32/opengl/glutessbeginpolygon)

[*gluTessCallback*](https://learn.microsoft.com/windows/win32/opengl/glutess)

[**gluTessVertex**](https://learn.microsoft.com/windows/win32/opengl/glutessvertex)

