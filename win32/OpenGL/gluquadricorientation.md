# gluQuadricOrientation function

The **gluQuadricOrientation** function specifies inside or outside orientation for quadrics.

## Parameters

*quadObject*

The quadric object (created with [**gluNewQuadric**](https://learn.microsoft.com/windows/win32/opengl/glunewquadric)).

*orientation*

The desired orientation. The following values are valid.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------|
|

**GLU\_OUTSIDE**

| Draw quadrics with normals pointing outward. This is the default value.<br> |
|

**GLU\_INSIDE**

| Draw quadrics with normals pointing inward.<br> |

## Return value

This function does not return a value.

## Remarks

The **gluQuadricOrientation** function specifies what kind of orientation is desired for quadrics rendered with **quadObject**. The interpretation of outward and inward depends on the quadric being drawn.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Glu.h |
| Library<br> | Glu32.lib |
| DLL<br> | Glu32.dll |

## See also

[**gluNewQuadric**](https://learn.microsoft.com/windows/win32/opengl/glunewquadric)

[**gluQuadricDrawStyle**](https://learn.microsoft.com/windows/win32/opengl/gluquadricdrawstyle)

[**gluQuadricNormals**](https://learn.microsoft.com/windows/win32/opengl/gluquadricnormals)

[**gluQuadricTexture**](https://learn.microsoft.com/windows/win32/opengl/gluquadrictexture)

