# glBlendFunc function

The **glBlendFunc** function specifies pixel arithmetic.

## Parameters

*sfactor*

Specifies how the red, green, blue, and alpha source-blending factors are computed. Nine symbolic constants are accepted: GL\_ZERO, GL\_ONE, GL\_DST\_COLOR, GL\_ONE\_MINUS\_DST\_COLOR, GL\_SRC\_ALPHA, GL\_ONE\_MINUS\_SRC\_ALPHA, GL\_DST\_ALPHA, GL\_ONE\_MINUS\_DST\_ALPHA, and GL\_SRC\_ALPHA\_SATURATE.

*dfactor*

Specifies how the red, green, blue, and alpha destination-blending factors are computed. Eight symbolic constants are accepted: GL\_ZERO, GL\_ONE, GL\_SRC\_COLOR, GL\_ONE\_MINUS\_SRC\_COLOR, GL\_SRC\_ALPHA, GL\_ONE\_MINUS\_SRC\_ALPHA, GL\_DST\_ALPHA, and GL\_ONE\_MINUS\_DST\_ALPHA.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | Either *sfactor* or *dfactor* was not an accepted value.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

In RGB mode, pixels can be drawn using a function that blends the incoming (source) RGBA values with the RGBA values that are already in the framebuffer (the destination values). By default, blending is disabled. Use [**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable) and [**glDisable**](https://learn.microsoft.com/windows/win32/opengl/gldisable) with the GL\_BLEND argument to enable and disable blending.

When enabled, **glBlendFunc** defines the operation of blending. The *sfactor* parameter specifies which of nine methods is used to scale the source color components. The *dfactor* parameter specifies which of eight methods is used to scale the destination color components. The eleven possible methods are described in the following table. Each method defines four scale factors one each for red, green, blue, and alpha.

In the table and in subsequent equations, source and destination color components are referred to as (*R*? , *G*? , *B*? , *A*? ) and (*R*d , *G*d , *B*d , *A*d ). They are understood to have integer values between zero and (*k*R , *k*G , *k*R , *k*A ), where

*k*R = 2m*R* - 1

*k*G = 2m*G* - 1

*k*B = 2m*B* - 1

*k*A = 2m*A* - 1

and (*m*R , *m*G , *m*B , *m*A ) is the number of red, green, blue, and alpha bitplanes.

Source and destination scale factors are referred to as (*s*R , *s*G , *s*B , *s*A ) and (*d*R , *d*G , *d*B , *d*A ). The scale factors described in the table, denoted (*f*R , *f*G , *f*B , *f*A ), represent either source or destination factors. All scale factors have range \[0,1\].

| Parameter | (*f*R , *f*G , *f*B , *f*A ) |
|----------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------|
| GL\_ZERO | (0,0,0,0) |
| GL\_ONE | (1,1,1,1) |
| GL\_SRC\_COLOR | (*R*? / *k*R , *G*? / *k*G , *B*? / *k*B , *A*? / *k*A ) |
| GL\_ONE\_MINUS\_SRC\_COLOR | (1,1,1,1) - (*R*? / *k*R , *G*? / *k*G , *B*? / *k*B , *A*? / *k*A ) |
| GL\_DST\_COLOR | (*R*d / *k*R , *G*d / *k*G , *B*d / *k*B , *A*d / *k*A ) |
| GL\_ONE\_MINUS\_DST\_COLOR | (1,1,1,1) - (*R*d / *k*R , *G*d / *k*G , *B*d / *k*B , *A*d / *k*A ) |
| GL\_SRC\_ALPHA | (*A*? / *k*A , *A*? / *k*A , *A*? / *k*A , *A*? / *k*A ) |
| GL\_ONE\_MINUS\_SRC\_ALPHA | (1,1,1,1) - (*A*? / *k*A , *A*? / *k*A , *A*? / *k*A , *A*? / *k*A ) |
| GL\_DST\_ALPHA | (*A*d / *k*A , *A*d / *k*A , *A*d / *k*A , *A*d / *k*A ) |
| GL\_ONE\_MINUS\_DST\_ALPHA | (1,1,1,1) - (*A*d / *k*A , *A*d / *k*A , *A*d / *k*A , *A*d / *k*A ) |
| GL\_SRC\_ALPHA\_SATURATE | (*i,i,i,* 1) |

In the table,

*i* = min (*A*? , *k*A  - *A*d ) / *k*A

To determine the blended RGBA values of a pixel when drawing in RGBA mode, the system uses the following equations:

*R* (*d*) = min( *k*R , *R*? *s*R + *R*d *d*R )

*G* (*d*) = min( *k*G , *G*? *s*G + *G*d *d*G )

*B* (*d*) = min( *k*B *, B*? *s*B + *B*d *d*B )

*A* (*d*) = min( *k*A , *A*? *s*A + *A*d *d*A )

Despite the apparent precision of the above equations, blending arithmetic is not exactly specified, because blending operates with imprecise integer color values. However, a blend factor that should be equal to one is guaranteed not to modify its multiplicand, and a blend factor equal to zero reduces its multiplicand to zero. Thus, for example, when *sfactor* is GL\_SRC\_ALPHA, *dfactor* is GL\_ONE\_MINUS\_SRC\_ALPHA, and *A*? is equal to *k*A, the equations reduce to simple replacement:

*R*d = *R*?

*G*d = *G*?

Bd = *B*?

*A*d = *A*?

## Examples

Transparency is best implemented using **glBlendFunc**(GL\_SRC\_ALPHA, GL\_ONE\_MINUS\_SRC\_ALPHA) with primitives sorted from farthest to nearest. Note that this transparency calculation does not require the presence of alpha bitplanes in the framebuffer.

You can also use **glBlendFunc**(GL\_SRC\_ALPHA, GL\_ONE\_MINUS\_SRC\_ALPHA) for rendering antialiased points and lines in arbitrary order.

To optimize polygon antialiasing, use **glBlendFunc**(GL\_SRC\_ALPHA\_SATURATE, GL\_ONE) with polygons sorted from nearest to farthest. (See the GL\_POLYGON\_SMOOTH argument in [**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable) for information on polygon antialiasing.) Destination alpha bitplanes, which must be present for this blend function to operate correctly, store the accumulated coverage.

Incoming (source) alpha is a material opacity, ranging from 1.0 (*K*A ), representing complete opacity, to 0.0 (0), representing complete transparency.

When you enable more than one color buffer for drawing, each enabled buffer is blended separately, and the contents of the buffer is used for destination color. (See [**glDrawBuffer**](https://learn.microsoft.com/windows/win32/opengl/gldrawbuffer).)

Blending affects only RGBA rendering. It is ignored by color-index renderers.

The following functions retrieve information related to **glBlendFunc**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_BLEND\_SRC

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_BLEND\_DST

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument GL\_BLEND

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Gl.h |
| Library<br> | Opengl32.lib |
| DLL<br> | Opengl32.dll |

## See also

[**glAlphaFunc**](https://learn.microsoft.com/windows/win32/opengl/glalphafunc)

[**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin)

[**glClear**](https://learn.microsoft.com/windows/win32/opengl/glclear)

[**glDisable**](https://learn.microsoft.com/windows/win32/opengl/gldisable)

[**glDrawBuffer**](https://learn.microsoft.com/windows/win32/opengl/gldrawbuffer)

[**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled)

[**glLogicOp**](https://learn.microsoft.com/windows/win32/opengl/gllogicop)

[**glStencilFunc**](https://learn.microsoft.com/windows/win32/opengl/glstencilfunc)

