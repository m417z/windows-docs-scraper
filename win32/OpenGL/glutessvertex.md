# gluTessVertex function

The **gluTessVertex** function specifies a vertex on a polygon.

## Parameters

*tess*

The tessellation object (created with [**gluNewTess**](https://learn.microsoft.com/windows/win32/opengl/glunewtess)).

*coords*

The location of the vertex.

*data*

An pointer passed back to the program with the vertex callback (as specified by [*gluTessCallback*](https://learn.microsoft.com/windows/win32/opengl/glutess)).

## Return value

This function does not return a value.

## Remarks

The **gluTessVertex** function describes a vertex on a polygon that the user is defining. Successive **gluTessVertex** calls describe a closed contour. For example, to describe a quadrilateral, call **gluTessVertex** four times. You can only call **gluTessVertex** between [**gluTessBeginContour**](https://learn.microsoft.com/windows/win32/opengl/glutessbegincontour) and [**gluTessEndContour**](https://learn.microsoft.com/windows/win32/opengl/glutessendcontour).

The *data* parameter normally points to a structure containing the vertex location, as well as other per-vertex attributes such as color and normal. This pointer is passed back to the program through the GLU\_VERTEX callback after tessellation (see [*gluTessCallback*](https://learn.microsoft.com/windows/win32/opengl/glutess)).

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

[**gluTessBeginPolygon**](https://learn.microsoft.com/windows/win32/opengl/glubeginpolygon)

[*gluTessCallback*](https://learn.microsoft.com/windows/win32/opengl/glutess)

[**gluTessEndContour**](https://learn.microsoft.com/windows/win32/opengl/glutessendcontour)

[**gluTessNormal**](https://learn.microsoft.com/windows/win32/opengl/glutessnormal)

[**gluTessProperty**](https://learn.microsoft.com/windows/win32/opengl/glutessproperty)

