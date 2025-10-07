# gluSphere function

The **gluSphere** function draws a sphere.

## Parameters

*qobj*

The quadric object (created with [**gluNewQuadric**](https://learn.microsoft.com/windows/win32/opengl/glunewquadric)).

*radius*

The radius of the sphere.

*slices*

The number of subdivisions around the z-axis (similar to lines of longitude).

*stacks*

The number of subdivisions along the z-axis (similar to lines of latitude).

## Return value

This function does not return a value.

## Remarks

The **gluSphere** function draws a sphere of the given radius centered around the origin. The sphere is subdivided around the z-axis into slices and along the z-axis into stacks (similar to lines of longitude and latitude).

If the orientation is set to GLU\_OUTSIDE (with **gluQuadricOrientation**), any normals generated point away from the center of the sphere. Otherwise, they point toward the center of the sphere.

If texturing is turned on (with **gluQuadricTexture**): texture coordinates are generated so that *t* ranges from 0.0 at *z* = -*radius* to 1.0 at *z* = *radius* (*t* increases linearly along longitudinal lines); and *s* ranges from 0.0 at the positive y-axis, to 0.25 at the positive x-axis, to 0.5 at the negative y-axis, to 0.75 at the negative x-axis, and back to 1.0 at the positive y-axis.

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

[**gluPartialDisk**](https://learn.microsoft.com/windows/win32/opengl/glupartialdisk)

[**gluQuadricOrientation**](https://learn.microsoft.com/windows/win32/opengl/gluquadricorientation)

[**gluQuadricTexture**](https://learn.microsoft.com/windows/win32/opengl/gluquadrictexture)

