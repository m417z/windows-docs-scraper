# gluQuadricNormals function

The **gluQuadricNormals** function specifies what kind of normals are to be used for quadrics.

## Parameters

*quadObject*

The quadric object (created with [**gluNewQuadric**](https://learn.microsoft.com/windows/win32/opengl/glunewquadric)).

*normals*

The desired type of normals. The following values are valid.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------|
|

**GLU\_NONE**

| No normals are generated.<br> |
|

**GLU\_FLAT**

| One normal is generated for every facet of a quadric.<br> |
|

**GLU\_SMOOTH**

| One normal is generated for every vertex of a quadric. This is the default value.<br> |

## Return value

This function does not return a value.

## Remarks

The **gluQuadricNormals** function specifies what kind of normals are to be used for quadrics rendered with **quadObject**.

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

[**gluQuadricOrientation**](https://learn.microsoft.com/windows/win32/opengl/gluquadricorientation)

[**gluQuadricTexture**](https://learn.microsoft.com/windows/win32/opengl/gluquadrictexture)

