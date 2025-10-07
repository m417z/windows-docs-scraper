# gluQuadricDrawStyle function

The **gluQuadricDrawStyle** function specifies the draw style desired for quadrics.

## Parameters

*quadObject*

The quadric object (created with [**gluNewQuadric**](https://learn.microsoft.com/windows/win32/opengl/glunewquadric)).

*drawStyle*

The desired draw style. The following values are valid.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**GLU\_FILL**

| Quadrics are rendered with polygon primitives. The polygons are drawn in a counterclockwise fashion with respect to their normals (as defined with [**gluQuadricOrientation**](https://learn.microsoft.com/windows/win32/opengl/gluquadricorientation)).<br> |
|

**GLU\_LINE**

| Quadrics are rendered as a set of lines.<br> |
|

**GLU\_SILHOUETTE**

| Quadrics are rendered as a set of lines, except that edges separating coplanar faces will not be drawn.<br> |
|

**GLU\_POINT**

| Quadrics are rendered as a set of points.<br> |

## Return value

This function does not return a value.

## Remarks

The **gluQuadricDrawStyle** function specifies the draw style for quadrics rendered with **quadObject**.

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

[**gluQuadricNormals**](https://learn.microsoft.com/windows/win32/opengl/gluquadricnormals)

[**gluQuadricOrientation**](https://learn.microsoft.com/windows/win32/opengl/gluquadricorientation)

[**gluQuadricTexture**](https://learn.microsoft.com/windows/win32/opengl/gluquadrictexture)

