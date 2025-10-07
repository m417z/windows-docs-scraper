# glEnd function

The [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and **glEnd** functions delimit the vertices of a primitive or a group of like primitives.

## Parameters

This function has no parameters.

## Return value

This function does not return a value.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_OPERATION** | A function other than **glVertex**, **glColor**, **glIndex**, **glNormal**, **glTexCoord**, **glEvalCoord**, **glEvalPoint**, **glMaterial**, **glEdgeFlag**, **glCallList**, or **glCallLists** was called between **glBegin** and the corresponding **glEnd**. The function **glEnd** was called before the corresponding **glBegin** was called, or **glBegin** was called within a **glBegin**/**glEnd** sequence. <br> |

## Remarks

The [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and **glEnd** functions delimit the vertices that define a primitive or a group of like primitives. The **glBegin** function accepts a single argument that specifies which of ten primitives the vertices compose. Taking *n* as an integer count starting at one, and *N* as the total number of vertices specified, the interpretations are as follows:

- You can use only a subset of OpenGL functions between **glBegin** and **glEnd**. The functions you can use are:

    - [**glVertex**](https://learn.microsoft.com/windows/win32/opengl/glvertex-functions)
    - [**glColor**](https://learn.microsoft.com/windows/win32/opengl/glcolor-functions)
    - [**glIndex**](https://learn.microsoft.com/windows/win32/opengl/glindex-functions)
    - [**glNormal**](https://learn.microsoft.com/windows/win32/opengl/glnormal-functions)
    - [**glTexCoord**](https://learn.microsoft.com/windows/win32/opengl/gltexcoord-functions)
    - [**glEvalCoord**](https://learn.microsoft.com/windows/win32/opengl/glevalcoord-functions)
    - [**glEvalPoint**](https://learn.microsoft.com/windows/win32/opengl/glevalpoint)
    - [**glMaterial**](https://learn.microsoft.com/windows/win32/opengl/glmaterial-functions)
    - [**glEdgeFlag**](https://learn.microsoft.com/windows/win32/opengl/gledgeflag-functions)

 You can also use [**glCallList**](https://learn.microsoft.com/windows/win32/opengl/glcalllist) or [**glCallLists**](https://learn.microsoft.com/windows/win32/opengl/glcalllists) to execute display lists that include only the preceding functions. If any other OpenGL function is called between **glBegin** and **glEnd**, the error flag is set and the function is ignored.

- Regardless of the value chosen for *mode* in **glBegin**, there is no limit to the number of vertices you can define between **glBegin** and **glEnd**. Lines, triangles, quadrilaterals, and polygons that are incompletely specified are not drawn. Incomplete specification results when either too few vertices are provided to specify even a single primitive or when an incorrect multiple of vertices is specified. The incomplete primitive is ignored; the complete primitives are drawn.
- The minimum specification of vertices for each primitive is:

 | Minimum number of vertices | Type of primitive |
|----------------------------|-------------------|
| 1 | point |
| 2 | line |
| 3 | triangle |
| 4 | quadrilateral |
| 3 | polygon |

- Modes that require a certain multiple of vertices are GL\_LINES (2), GL\_TRIANGLES (3), GL\_QUADS (4), and GL\_QUAD\_STRIP (2).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Gl.h |
| Library<br> | Opengl32.lib |
| DLL<br> | Opengl32.dll |

## See also

[**glBegin**](https://learn.microsoft.com/windows/desktop/OpenGL/glbegin)

[**glCallLists**](https://learn.microsoft.com/windows/win32/opengl/glcalllists)

[**glColor**](https://learn.microsoft.com/windows/win32/opengl/glcolor-functions)

[**glEdgeFlag**](https://learn.microsoft.com/windows/win32/opengl/gledgeflag-functions)

[**glEvalCoord**](https://learn.microsoft.com/windows/win32/opengl/glevalcoord-functions)

[**glEvalPoint**](https://learn.microsoft.com/windows/win32/opengl/glevalpoint)

[**glIndex**](https://learn.microsoft.com/windows/win32/opengl/glindex-functions)

[**glMaterial**](https://learn.microsoft.com/windows/win32/opengl/glmaterial-functions)

[**glNormal**](https://learn.microsoft.com/windows/win32/opengl/glnormal-functions)

[**glTexCoord**](https://learn.microsoft.com/windows/win32/opengl/gltexcoord-functions)

[**glVertex**](https://learn.microsoft.com/windows/win32/opengl/glvertex-functions)

