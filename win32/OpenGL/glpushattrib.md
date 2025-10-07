# glPushAttrib function

Pushes the attribute stack.

## Parameters

*mask*

A mask that indicates which attributes to save. The symbolic mask constants and their associated OpenGL state are as follows (the indented paragraphs list which attributes are saved):

GL\_ACCUM\_BUFFER\_BIT

Accumulation buffer clear value

GL\_COLOR\_BUFFER\_BIT

GL\_ALPHA\_TEST enable bit

Alpha test function and reference value

GL\_BLEND enable bit

Blending source and destination functions

GL\_DITHER enable bit

GL\_DRAW\_BUFFER setting

GL\_LOGIC\_OP enable bit

Logic op function

Color-mode and index-mode clear values

Color-mode and index-mode writemasks

GL\_CURRENT\_BIT

Current RGBA color

Current color index

Current normal vector

Current texture coordinates

Current raster position GL\_CURRENT\_RASTER\_POSITION\_VALID flag

RGBA color associated with current raster position

Color index associated with current raster position

Texture coordinates associated with current raster position

GL\_EDGE\_FLAG flag

GL\_DEPTH\_BUFFER\_BIT

GL\_DEPTH\_TEST enable bit

Depth buffer test function

Depth buffer clear value

GL\_DEPTH\_WRITEMASK enable bit

GL\_ENABLE\_BIT

GL\_ALPHA\_TEST flag

GL\_AUTO\_NORMAL flag

GL\_BLEND flag

Enable bits for the user-definable clipping planes

GL\_COLOR\_MATERIAL

GL\_CULL\_FACE flag

GL\_DEPTH\_TEST flag

GL\_DITHER flag

GL\_FOG flag

GL\_LIGHT*i* where 0 <= *i* < GL\_MAX\_LIGHTS

GL\_LIGHTING flag

GL\_LINE\_SMOOTH flag

GL\_LINE\_STIPPLE flag

GL\_COLOR\_LOGIC\_OP flag

GL\_INDEX\_LOGIC\_OP flag

GL\_MAP1\_x where x is a map type

GL\_MAP2\_x where x is a map type

GL\_NORMALIZE flag

GL\_POINT\_SMOOTH flag

GL\_POLYGON\_OFFSET\_LINE flag

GL\_POLYGON\_OFFSET\_FILL flag

GL\_POLYGON\_OFFSET\_POINT flag

GL\_POLYGON\_SMOOTH flag

GL\_POLYGON\_STIPPLE flag

GL\_SCISSOR\_TEST flag

GL\_STENCIL\_TEST flag

GL\_TEXTURE\_1D flag

GL\_TEXTURE\_2D flag

Flags GL\_TEXTURE\_GEN\_x where x is S, T, R, or Q

GL\_EVAL\_BIT

GL\_MAP1\_x enable bits, where x is a map type

GL\_MAP2\_x enable bits, where x is a map type

1-D grid endpoints and divisions

2-D grid endpoints and divisions

GL\_AUTO\_NORMAL enable bit

GL\_FOG\_BIT

GL\_FOG enable flag

Fog color

Fog density

Linear fog start

Linear fog end

Fog index

GL\_FOG\_MODE value

GL\_HINT\_BIT

GL\_PERSPECTIVE\_CORRECTION\_HINT setting

GL\_POINT\_SMOOTH\_HINT setting

GL\_LINE\_SMOOTH\_HINT setting

GL\_POLYGON\_SMOOTH\_HINT setting

GL\_FOG\_HINT setting

GL\_LIGHTING\_BIT

GL\_COLOR\_MATERIAL enable bit

GL\_COLOR\_MATERIAL\_FACE value

Color material parameters that are tracking the current color

Ambient scene color

GL\_LIGHT\_MODEL\_LOCAL\_VIEWER value

GL\_LIGHT\_MODEL\_TWO\_SIDE setting

GL\_LIGHTING enable bit

Enable bit for each light

Ambient, diffuse, and specular intensity for each light

Direction, position, exponent, and cutoff angle for each light

Constant, linear, and quadratic attenuation factors for each light

Ambient, diffuse, specular, and emissive color for each material

Ambient, diffuse, and specular color indexes for each material

Specular exponent for each material GL\_SHADE\_MODEL setting

GL\_LINE\_BIT

GL\_LINE\_SMOOTH flag

GL\_LINE\_STIPPLE enable bit

Line stipple pattern and repeat counter

Line width

GL\_LIST\_BIT

GL\_LIST\_BASE setting

GL\_PIXEL\_MODE\_BIT

GL\_RED\_BIAS and GL\_RED\_SCALE settings

GL\_GREEN\_BIAS and GL\_GREEN\_SCALE values

GL\_BLUE\_BIAS and GL\_BLUE\_SCALE

GL\_ALPHA\_BIAS and GL\_ALPHA\_SCALE

GL\_DEPTH\_BIAS and GL\_DEPTH\_SCALE

GL\_INDEX\_OFFSET and GL\_INDEX\_SHIFT values

GL\_MAP\_COLOR and GL\_MAP\_STENCIL flags

GL\_ZOOM\_X and GL\_ZOOM\_Y factors

GL\_READ\_BUFFER setting

GL\_POINT\_BIT

GL\_POINT\_SMOOTH flag

Point size

GL\_POLYGON\_BIT

GL\_CULL\_FACE enable bit

GL\_CULL\_FACE\_MODE value

GL\_FRONT\_FACE indicator

GL\_POLYGON\_MODE setting

GL\_POLYGON\_SMOOTH flag

GL\_POLYGON\_STIPPLE enable bit

GL\_POLYGON\_OFFSET\_FILL flag

GL\_POLYGON\_OFFSET\_LINE flag

GL\_POLYGON\_OFFSET\_POINT flag

GL\_POLYGON\_OFFSET\_FACTOR

GL\_POLYGON\_OFFSET\_UNITS

GL\_POLYGON\_STIPPLE\_BIT

Polygon stipple image

GL\_SCISSOR\_BIT

GL\_SCISSOR\_TEST flag

Scissor box

GL\_STENCIL\_BUFFER\_BIT

GL\_STENCIL\_TEST enable bit

Stencil function and reference value

Stencil value mask

Stencil fail, pass, and depth buffer pass actions

Stencil buffer clear value

Stencil buffer writemask

GL\_TEXTURE\_BIT

Enable bits for the four texture coordinates

Border color for each texture image

Minification function for each texture image

Magnification function for each texture image

Texture coordinates and wrap mode for each texture image

Color and mode for each texture environment

Enable bits GL\_TEXTURE\_GEN\_*x*; *x* is S, T, R, and Q

GL\_TEXTURE\_GEN\_MODE setting for S, T, R, and Q

glTexGen plane equations for S, T, R, and Q

GL\_TRANSFORM\_BIT

Coefficients of the six clipping planes

Enable bits for the user-definable clipping planes

GL\_MATRIX\_MODE value

GL\_NORMALIZE flag

GL\_VIEWPORT\_BIT

Depth range (near and far)

Viewport origin and extent

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_STACK\_OVERFLOW** | The function was called while the attribute stack was full.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glPushAttrib** function takes one argument, a mask that indicates which groups of state variables to save on the attribute stack. Symbolic constants are used to set bits in the mask. The mask parameter is typically constructed by applying the logical **OR** operation to several of these constants. You can use the special mask GL\_ALL\_ATTRIB\_BITS to save all stackable states.

The [**glPopAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpopattrib) function restores the values of the state variables saved with the last **glPushAttrib** command. Those not saved are left unchanged.

It is an error to push attributes onto a full stack, or to pop attributes off an empty stack. In either case, the error flag is set and no other change is made to the OpenGL state.

Initially, the attribute stack is empty.

Not all values for the OpenGL state can be saved on the attribute stack. For example, you cannot save pixel pack and unpack state, render mode state, and select and feedback state.

The depth of the attribute stack depends on the implementation, but it must be at least 16.

The following functions retrieve information related to **glPushAttrib** and [**glPopAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpopattrib):

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_ATTRIB\_STACK\_DEPTH

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_MAX\_ATTRIB\_STACK\_DEPTH

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

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glGetClipPlane**](https://learn.microsoft.com/windows/win32/opengl/glgetclipplane)

[**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror)

[**glGetLight**](https://learn.microsoft.com/windows/win32/opengl/glgetlight)

[**glGetMap**](https://learn.microsoft.com/windows/win32/opengl/glgetmap)

[**glGetMaterial**](https://learn.microsoft.com/windows/win32/opengl/glgetmaterial)

[**glGetPixelMap**](https://learn.microsoft.com/windows/win32/opengl/glgetpixelmap)

[**glGetPolygonStipple**](https://learn.microsoft.com/windows/win32/opengl/glgetpolygonstipple)

[**glGetString**](https://learn.microsoft.com/windows/win32/opengl/glgetstring)

[**glGetTexEnv**](https://learn.microsoft.com/windows/win32/opengl/glgettexenv)

[**glGetTexGen**](https://learn.microsoft.com/windows/win32/opengl/glgettexgen)

[**glGetTexImage**](https://learn.microsoft.com/windows/win32/opengl/glgetteximage)

[**glGetTexLevelParameter**](https://learn.microsoft.com/windows/win32/opengl/glgettexlevelparameter)

[**glGetTexParameter**](https://learn.microsoft.com/windows/win32/opengl/glgettexparameter)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled)

