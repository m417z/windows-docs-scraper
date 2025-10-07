# gluTessBeginContour function

The **gluTessBeginContour** and [**gluTessEndContour**](https://learn.microsoft.com/windows/win32/opengl/glutessendcontour) functions delimit a contour description.

## Parameters

*tess*

The tessellation object (created with [**gluNewTess**](https://learn.microsoft.com/windows/win32/opengl/glunewtess)).

## Return value

This function does not return a value.

## Remarks

The **gluTessBeginContour** and [**gluTessEndPolygon**](https://learn.microsoft.com/windows/win32/opengl/glutessendpolygon) functions delimit the definition of a polygon contour. Within each **gluTessBeginContour**/**gluTessEndPolygon** pair, there can be zero or more calls to [**gluTessVertex**](https://learn.microsoft.com/windows/win32/opengl/glutessvertex). The vertexes specify a closed contour (the last vertex of each contour is automatically linked to the first). You can call **gluTessBeginContour** only between [**gluTessBeginPolygon**](https://learn.microsoft.com/windows/win32/opengl/glutessbeginpolygon) and **gluTessEndPolygon**.

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

[**gluTessBeginPolygon**](https://learn.microsoft.com/windows/win32/opengl/glutessbeginpolygon)

[*gluTessCallback*](https://learn.microsoft.com/windows/win32/opengl/glutess)

[**gluTessEndPolygon**](https://learn.microsoft.com/windows/win32/opengl/glutessendpolygon)

[**gluTessNormal**](https://learn.microsoft.com/windows/win32/opengl/glutessnormal)

[**gluTessProperty**](https://learn.microsoft.com/windows/win32/opengl/glutessproperty)

[**gluTessVertex**](https://learn.microsoft.com/windows/win32/opengl/glutessvertex)

