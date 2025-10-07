# gluNextContour function

\[The **gluNextContour** function is obsolete and is provided for backward compatibility only. The **gluNextContour** function is mapped to [**gluTessEndContour**](https://learn.microsoft.com/windows/win32/opengl/glutessendcontour) followed by [**gluTessBeginContour**](https://learn.microsoft.com/windows/win32/opengl/glutessbegincontour).\]

The **gluNextContour** function marks the beginning of another contour.

## Parameters

*tess*

The tessellation object (created with [**gluNewTess**](https://learn.microsoft.com/windows/win32/opengl/glunewtess)).

*type*

The type of the contour being defined. The following values are valid.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GLU\_EXTERIOR** | An exterior contour defines an exterior boundary of the polygon.<br> |
| **GLU\_INTERIOR** | An interior contour defines an interior boundary of the polygon (such as a hole).<br> |
| **GLU\_UNKNOWN** | An unknown contour is analyzed by the library to determine whether it is interior or exterior.<br> |
| **GLU\_CCW, GLU\_CW** | The first GLU\_CCW or GLU\_CW contour defined is considered to be exterior. All other contours are considered to be exterior if they are oriented in the same direction (clockwise or counterclockwise) as the first contour, and interior if they are not.<br> If one contour is of type GLU\_CCW or GLU\_CW, then all contours must be of the same type (if they are not, then all GLU\_CCW and GLU\_CW contours will be changed to GLU\_UNKNOWN). Note that there is no real difference between the GLU\_CCW and GLU\_CW contour types.<br> |

## Return value

This function does not return a value.

## Remarks

Use the **gluNextContour** function to describe polygons with multiple contours. After you describe the first contour through a series of [**gluTessVertex**](https://learn.microsoft.com/windows/win32/opengl/glutessvertex) calls, a **gluNextContour** call indicates that the previous contour is complete and that the next contour is about to begin. Perform another series of **gluTessVertex** calls to describe the new contour. Repeat this process until all contours have been described.

The *type* parameter defines what type of contour follows.

To define the type of the first contour, you can call **gluNextContour** before describing the first contour. If you do not call **gluNextContour** before the first contour, the first contour is marked GLU\_EXTERIOR.

## Examples

You can describe a quadrilateral with a triangular hole in it as follows:

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

[**gluTessBeginContour**](https://learn.microsoft.com/windows/win32/opengl/glutessbegincontour)

[**gluTessBeginPolygon**](https://learn.microsoft.com/windows/win32/opengl/glubeginpolygon)

[*gluTessCallback*](https://learn.microsoft.com/windows/win32/opengl/glutess)

[**gluTessEndContour**](https://learn.microsoft.com/windows/win32/opengl/glutessendcontour)

[**gluTessVertex**](https://learn.microsoft.com/windows/win32/opengl/glutessvertex)

