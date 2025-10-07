# gluPartialDisk function

The **gluPartialDisk** function draws an arc of a disk.

## Parameters

*qobj*

A quadric object (created with [**gluNewQuadric**](https://learn.microsoft.com/windows/win32/opengl/glunewquadric)).

*innerRadius*

The inner radius of the partial disk (can be zero).

*outerRadius*

The outer radius of the partial disk.

*slices*

The number of subdivisions around the z-axis.

*loops*

The number of concentric rings about the origin into which the partial disk is subdivided.

*startAngle*

The starting angle, in degrees, of the disk portion.

*sweepAngle*

The sweep angle, in degrees, of the disk portion.

## Return value

This function does not return a value.

## Remarks

The **gluPartialDisk** function renders a partial disk on the *z* = 0 plane. A partial disk is similar to a full disk, except that only the subset of the disk from *startAngle* through *startAngle* + *sweepAngle* is included (where 0 degrees is along the positive y-axis, 90 degrees is along the positive x-axis, 180 degrees is along the negative y-axis, and 270 degrees is along the negative x-axis).

The partial disk has a radius of *outerRadius* and contains a concentric circular hole with a radius of *innerRadius*. If *innerRadius* is zero, then no hole is generated. The partial disk is subdivided around the z-axis into slices (like pizza slices), and also about the z-axis into rings (as specified by *slices* and *loops*, respectively).

With respect to orientation, the positive z-side of the partial disk is considered to be outside (see [**gluQuadricOrientation**](https://learn.microsoft.com/windows/win32/opengl/gluquadricorientation)). This means that if the orientation is set to GLU\_OUTSIDE, then any normals generated point along the positive z-axis.

If you have turned on texturing (with [**gluQuadricTexture**](https://learn.microsoft.com/windows/win32/opengl/gluquadrictexture)), **gluPartialDisk** generates texture coordinates linearly such that where *r* = *outerRadius*, the value at (*r*, 0, 0) is (1, 0.5); at (0, *r*, 0) it is (0.5, 1); at (*r*, 0, 0) it is (0, 0.5); and at (0, *r*, 0) it is (0.5, 0).

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

[**gluDisk**](https://learn.microsoft.com/windows/win32/opengl/gludisk)

[**gluNewQuadric**](https://learn.microsoft.com/windows/win32/opengl/glunewquadric)

[**gluQuadricOrientation**](https://learn.microsoft.com/windows/win32/opengl/gluquadricorientation)

[**gluQuadricTexture**](https://learn.microsoft.com/windows/win32/opengl/gluquadrictexture)

[**gluSphere**](https://learn.microsoft.com/windows/win32/opengl/glusphere)

