# gluQuadricTexture function

The **gluQuadricTexture** function specifies whether quadrics are to be textured.

## Parameters

*quadObject*

The quadric object (created with [**gluNewQuadric**](https://learn.microsoft.com/windows/win32/opengl/glunewquadric)).

*textureCoords*

A flag indicating whether texture coordinates are to be generated. The following values are valid.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------|
| **GL\_TRUE** | Generate texture coordinates.<br> |
| **GL\_FALSE** | Do not generate texture coordinates. This is the default value.<br> |

## Return value

This function does not return a value.

## Remarks

The **gluQuadricTexture** function specifies whether texture coordinates are to be generated for quadrics rendered with **quadObject**.

The manner in which texture coordinates are generated depends upon the specific quadric rendered.

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

