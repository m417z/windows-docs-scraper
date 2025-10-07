# gluTessNormal function

The **gluTessNormal** function specifies a normal for a polygon.

## Parameters

*tess*

The tessellation object (created with [**gluNewTess**](https://learn.microsoft.com/windows/win32/opengl/glunewtess)).

*x*

The x-coordinate component of a normal.

*y*

The y-coordinate component of a normal.

*z*

The z-coordinate component of a normal.

## Return value

This function does not return a value.

## Remarks

The **gluTessNormal** function describes a normal for a polygon that you define. All input data is projected onto a plane perpendicular to one of the three coordinate axes before tessellation, and all output triangles are oriented counterclockwise with respect to the normal. (To obtain clockwise orientation, reverse the sign of the supplied normal). For example, if you know that all polygons lie in the x-y plane, call **gluTessNormal**(tess, 0.0, 0.0, 1.0) before rendering any polygons.

If the supplied normal is (0.0, 0.0, 0.0) (the default value), the normal is determined as follows:

1. The direction of the normal, up to its sign, is found by fitting a plane to the vertexes, without regard to how the vertexes are connected. It is expected that the input data lies approximately in the plane; otherwise projection perpendicular to one of the three coordinate axes can change the geometry substantially.
2. The sign of the normal is chosen so that the sum of the signed areas of all input contours is nonnegative (where a counterclockwise contour has positive area).

The supplied normal persists until another call to **gluTessNormal** changes it.

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

[**gluTessEndPolygon**](https://learn.microsoft.com/windows/win32/opengl/glutessendpolygon)

