# gluCylinder function

The **gluCylinder** function draws a cylinder.

## Parameters

*qobj*

The quadric object (created with [**gluNewQuadric**](https://learn.microsoft.com/windows/win32/opengl/glunewquadric)).

*baseRadius*

The radius of the cylinder at *z* = 0.

*topRadius*

The radius of the cylinder at *z* = *height*.

*height*

The height of the cylinder.

*slices*

The number of subdivisions around the z-axis.

*stacks*

The number of subdivisions along the z-axis.

## Return value

This function does not return a value.

## Remarks

The **gluCylinder** function draws a cylinder oriented along the z-axis. The base of the cylinder is placed at *z* = 0, and the top at *z* = *height*. Like a sphere, a cylinder is subdivided around the z-axis into slices, and along the z-axis into stacks.

Note that if *topRadius* is set to zero, then this routine will generate a cone.

If the orientation is set to GLU\_OUTSIDE (with [**gluQuadricOrientation**](https://learn.microsoft.com/windows/win32/opengl/gluquadricorientation)), then any generated normals point away from the z-axis. Otherwise, they point toward the z-axis.

If texturing is turned on (with [**gluQuadricTexture**](https://learn.microsoft.com/windows/win32/opengl/gluquadrictexture)): texture coordinates are generated so that *t* ranges linearly from 0.0 at *z* = 0 to 1.0 at *z* = *height*; and *s* ranges from 0.0 at the positive y-axis, to 0.25 at the positive x-axis, to 0.5 at the negative y-axis, to 0.75 at the negative x-axis, and back to 1.0 at the positive y-axis.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Glu.h |
| Library<br> | Glu32.lib |
| DLL<br> | Glu32.dll |

## See also

[**gluDisk**](https://learn.microsoft.com/windows/win32/opengl/gludisk)

[**gluNewQuadric**](https://learn.microsoft.com/windows/win32/opengl/glunewquadric)

[**gluPartialDisk**](https://learn.microsoft.com/windows/win32/opengl/glupartialdisk)

[**gluQuadricOrientation**](https://learn.microsoft.com/windows/win32/opengl/gluquadricorientation)

[**gluQuadricTexture**](https://learn.microsoft.com/windows/win32/opengl/gluquadrictexture)

[**gluSphere**](https://learn.microsoft.com/windows/win32/opengl/glusphere)

