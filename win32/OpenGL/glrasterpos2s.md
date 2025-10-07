# glRasterPos2s function

Specifies the raster position for pixel operations.

## Parameters

*x*

Specifies the x-coordinate for the current raster position.

*y*

Specifies the y-coordinate for the current raster position.

## Return value

This function does not return a value.

## Remarks

OpenGL maintains a 3-D position in window coordinates. This position, called the raster position, is maintained with subpixel accuracy. It is used to position pixel and bitmap write operations. See [**glBitmap**](https://learn.microsoft.com/windows/win32/opengl/glbitmap), [**glDrawPixels**](https://learn.microsoft.com/windows/win32/opengl/gldrawpixels), and [**glCopyPixels**](https://learn.microsoft.com/windows/win32/opengl/glcopypixels).

The current raster position consists of three window coordinates (*x, y, z*), a clip coordinate *w* value, an eye coordinate distance, a valid bit, and associated color data and texture coordinates. The *w* coordinate is a clip coordinate, because *w* is not projected to window coordinates. The [glRasterPos4](https://learn.microsoft.com/windows/win32/opengl/glrasterpos-functions) function specifies object coordinates *x, y, z*, and *w* explicitly. The glRasterPos3 function specifies object coordinates *x, y,* and *z* explicitly, while *w* is implicitly set to one. The glRasterPos2 function uses the argument values for *x* and *y* while implicitly setting *z* and *w* to zero and one.

The object coordinates presented by [glRasterPos](https://learn.microsoft.com/windows/win32/opengl/glrasterpos-functions) are treated just like those of a [glVertex](https://learn.microsoft.com/windows/win32/opengl/glvertex-functions) command. They are transformed by the current modelview and projection matrices and passed to the clipping stage. If the vertex is not culled, then it is projected and scaled to window coordinates, which become the new current raster position, and the GL\_CURRENT\_RASTER\_POSITION\_VALID flag is set. If the vertex is culled, then the valid bit is cleared and the current raster position and associated color and texture coordinates are undefined.

The current raster position also includes some associated color data and texture coordinates. If lighting is enabled, then GL\_CURRENT\_RASTER\_COLOR, in RGBA mode, or the GL\_CURRENT\_RASTER\_INDEX, in color-index mode, is set to the color produced by the lighting calculation (see [glLight](https://learn.microsoft.com/windows/win32/opengl/gllight-functions), [glLightModel](https://learn.microsoft.com/windows/win32/opengl/gllightmodel-functions), and [**glShadeModel**](https://learn.microsoft.com/windows/win32/opengl/glshademodel)). If lighting is disabled, current color (in RGBA mode, state variable GL\_CURRENT\_COLOR) or color index (in color-index mode, state variable GL\_CURRENT\_INDEX) is used to update the current raster color.

Likewise, GL\_CURRENT\_RASTER\_TEXTURE\_COORDS is updated as a function of GL\_CURRENT\_TEXTURE\_COORDS, based on the texture matrix and the texture generation functions (see [glTexGen](https://learn.microsoft.com/windows/win32/opengl/gltexgen-functions)). Finally, the distance from the origin of the eye coordinate system to the vertex, as transformed by only the modelview matrix, replaces GL\_CURRENT\_RASTER\_DISTANCE.

Initially, the current raster position is (0,0,0,1), the current raster distance is 0, the valid bit is set, the associated RGBA color is (1,1,1,1), the associated color index is 1, and the associated texture coordinates are (0, 0, 0, 1). In RGBA mode, GL\_CURRENT\_RASTER\_INDEX is always 1; in color-index mode, the current raster RGBA color always maintains its initial value.

> [!Note]
> The raster position is modified both by [glRasterPos](https://learn.microsoft.com/windows/win32/opengl/glrasterpos-functions) and by [**glBitmap**](https://learn.microsoft.com/windows/win32/opengl/glbitmap).

> [!Note]
> When the raster position coordinates are invalid, drawing commands that are based on the raster position are ignored (that is, they do not result in changes to the OpenGL state).

The following functions retrieve information related to [glRasterPos](https://learn.microsoft.com/windows/win32/opengl/glrasterpos-functions):

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_CURRENT\_RASTER\_POSITION
[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_CURRENT\_RASTER\_POSITION\_VALID
[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_CURRENT\_RASTER\_DISTANCE
[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_CURRENT\_RASTER\_COLOR
[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_CURRENT\_RASTER\_INDEX
[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_CURRENT\_RASTER\_TEXTURE\_COORDS

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Gl.h |
| Library<br> | Opengl32.lib |
| DLL<br> | Opengl32.dll |

## See also

[**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin)

[**glBitmap**](https://learn.microsoft.com/windows/win32/opengl/glbitmap)

[**glCopyPixels**](https://learn.microsoft.com/windows/win32/opengl/glcopypixels)

[**glDrawPixels**](https://learn.microsoft.com/windows/win32/opengl/gldrawpixels)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[glLight](https://learn.microsoft.com/windows/win32/opengl/gllight-functions)

[glLightModel](https://learn.microsoft.com/windows/win32/opengl/gllightmodel-functions)

[**glShadeModel**](https://learn.microsoft.com/windows/win32/opengl/glshademodel)

[**glTexCoord**](https://learn.microsoft.com/windows/win32/opengl/gltexcoord-functions)

[glTexGen](https://learn.microsoft.com/windows/win32/opengl/gltexgen-functions)

[glVertex](https://learn.microsoft.com/windows/win32/opengl/glvertex-functions)

