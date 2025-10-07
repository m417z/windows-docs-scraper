# gluDisk function

The **gluDisk** function draws a disk.

## Parameters

*qobj*

The quadric object (created with [**gluNewQuadric**](https://learn.microsoft.com/windows/win32/opengl/glunewquadric)).

*innerRadius*

The inner radius of the disk (may be zero).

*outerRadius*

The outer radius of the disk.

*slices*

The number of subdivisions around the z-axis.

*loops*

The number of concentric rings about the origin into which the disk is subdivided.

## Return value

This function does not return a value.

## Remarks

The **gluDisk** function renders a disk on the *z* = 0 plane. The disk has a radius of *outerRadius*, and contains a concentric circular hole with a radius of *innerRadius*. If *innerRadius* is 0, then no hole is generated. The disk is subdivided around the z-axis into slices (like pizza slices) and also about the z-axis into rings (as specified by *slices* and *loops*, respectively).

With respect to orientation, the positive *z*-side of the disk is considered to be *outside* (see [**gluQuadricOrientation**](https://learn.microsoft.com/windows/win32/opengl/gluquadricorientation)). This means that if the orientation is set to GLU\_OUTSIDE, then any normals generated point along the positive z-axis.

If texturing is turned on (with [**gluQuadricTexture**](https://learn.microsoft.com/windows/win32/opengl/gluquadrictexture)), texture coordinates are generated linearly such that where *r* = *outerRadius*, the value at (*r*, 0, 0) is (1, 0.5); at (0, *r*, 0) it is (0.5, 1); at (-*r*, 0, 0) it is (0, 0.5); and at (0, -*r*, 0) it is (0.5, 0).

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Glu.h |
| Library<br> | Glu32.lib |
| DLL<br> | Glu32.dll |

## See also

[**gluCylinder**](https://learn.microsoft.com/windows/win32/opengl/glucylinder)

[**gluNewQuadric**](https://learn.microsoft.com/windows/win32/opengl/glunewquadric)

[**gluPartialDisk**](https://learn.microsoft.com/windows/win32/opengl/glupartialdisk)

[**gluQuadricOrientation**](https://learn.microsoft.com/windows/win32/opengl/gluquadricorientation)

[**gluQuadricTexture**](https://learn.microsoft.com/windows/win32/opengl/gluquadrictexture)

[**gluSphere**](https://learn.microsoft.com/windows/win32/opengl/glusphere)

