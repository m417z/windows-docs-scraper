# glGetIntegerv function

The **glGetIntegerv** function returns the value or values of a selected parameter.

## Parameters

*pname*

The parameter value to be returned. The following symbolic constants are accepted.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**GL\_ACCUM\_ALPHA\_BITS**

| The *params* parameter returns one value: the number of alpha bitplanes in the accumulation buffer.<br> |
|

**GL\_ACCUM\_BLUE\_BITS**

| The *params* parameter returns one value: the number of blue bitplanes in the accumulation buffer.<br> |
|

**GL\_ACCUM\_CLEAR\_VALUE**

| The *params* parameter returns four values: the red, green, blue, and alpha values used to clear the accumulation buffer. Integer values, if requested, are linearly mapped from the internal floating-point representation such that 1.0 returns the most positive representable integer value, and -1.0 returns the most negative representable integer value. See [**glClearAccum**](https://learn.microsoft.com/windows/win32/opengl/glclearaccum).<br> |
|

**GL\_ACCUM\_GREEN\_BITS**

| The *params* parameter returns one value: the number of green bitplanes in the accumulation buffer.<br> |
|

**GL\_ACCUM\_RED\_BITS**

| The *params* parameter returns one value: the number of red bitplanes in the accumulation buffer.<br> |
|

**GL\_ALPHA\_BIAS**

| The *params* parameter returns one value: the alpha bias factor used during pixel transfers. See [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer).<br> |
|

**GL\_ALPHA\_BITS**

| The *params* parameter returns one value: the number of alpha bitplanes in each color buffer.<br> |
|

**GL\_ALPHA\_SCALE**

| The *params* parameter returns one value: the alpha scale factor used during pixel transfers. See [glPixelTransfer](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer).<br> |
|

**GL\_ALPHA\_TEST**

| The *params* parameter returns a single Boolean value indicating whether alpha testing of fragments is enabled. See [**glAlphaFunc**](https://learn.microsoft.com/windows/win32/opengl/glalphafunc).<br> |
|

**GL\_ALPHA\_TEST\_FUNC**

| The *params* parameter returns one value: the symbolic name of the alpha test function. See [**glAlphaFunc**](https://learn.microsoft.com/windows/win32/opengl/glalphafunc).<br> |
|

**GL\_ALPHA\_TEST\_REF**

| The *params* parameter returns one value: the reference value for the alpha test. See [**glAlphaFunc**](https://learn.microsoft.com/windows/win32/opengl/glalphafunc). An integer value, if requested, is linearly mapped from the internal floating-point representation such that 1.0 returns the most positive representable integer value, and -1.0 returns the most negative representable integer value.<br> |
|

**GL\_ATTRIB\_STACK\_DEPTH**

| The *params* parameter returns one value: the depth of the attribute stack. If the stack is empty, zero is returned. See [**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib).<br> |
|

**GL\_AUTO\_NORMAL**

| The *params* parameter returns a single Boolean value indicating whether 2-D map evaluation automatically generates surface normals. See [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2).<br> |
|

**GL\_AUX\_BUFFERS**

| The *params* parameter returns one value: the number of auxiliary color buffers.<br> |
|

**GL\_BLEND**

| The *params* parameter returns a single Boolean value indicating whether blending is enabled. See [**glBlendFunc**](https://learn.microsoft.com/windows/win32/opengl/glblendfunc).<br> |
|

**GL\_BLEND\_DST**

| The *params* parameter returns one value: the symbolic constant identifying the destination blend function. See [**glBlendFunc**](https://learn.microsoft.com/windows/win32/opengl/glblendfunc).<br> |
|

**GL\_BLEND\_SRC**

| The *params* parameter returns one value: the symbolic constant identifying the source blend function. See [**glBlendFunc**](https://learn.microsoft.com/windows/win32/opengl/glblendfunc).<br> |
|

**GL\_BLUE\_BIAS**

| The *params* parameter returns one value: the blue bias factor used during pixel transfers. See [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer).<br> |
|

**GL\_BLUE\_BITS**

| The *params* parameter returns one value: the number of blue bitplanes in each color buffer.<br> |
|

**GL\_BLUE\_SCALE**

| The *params* parameter returns one value: the blue scale factor used during pixel transfers. See [glPixelTransfer](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer).<br> |
|

**GL\_CLIENT\_ATTRIB\_STACK\_DEPTH**

| The *params* parameter returns one value indicating the depth of the attribute stack. The initial value is zero. See [**glPushClientAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushclientattrib).<br> |
|

**GL\_CLIP\_PLANE*i***

| The *params* parameter returns a single Boolean value indicating whether the specified clipping plane is enabled. See [**glClipPlane**](https://learn.microsoft.com/windows/win32/opengl/glclipplane).<br> |
|

**GL\_COLOR\_ARRAY**

| The *params* parameter returns a single Boolean value indicating whether the specified color array is defined. See [**glColorPointer**](https://learn.microsoft.com/windows/win32/opengl/glcolorpointer).<br> |
|

**GL\_COLOR\_ARRAY\_SIZE**

| The *params* parameter returns one value, the number of components per color in the color array. See [**glColorPointer**](https://learn.microsoft.com/windows/win32/opengl/glcolorpointer).<br> |
|

**GL\_COLOR\_ARRAY\_STRIDE**

| The *params* parameter returns one value, the byte offset between consecutive colors in the color array. See [**glColorPointer**](https://learn.microsoft.com/windows/win32/opengl/glcolorpointer).<br> |
|

**GL\_COLOR\_ARRAY\_TYPE**

| The *params* parameter returns one value, the data type of each component in the color array. See [**glColorPointer**](https://learn.microsoft.com/windows/win32/opengl/glcolorpointer).<br> |
|

**GL\_COLOR\_CLEAR\_VALUE**

| The *params* parameter returns four values: the red, green, blue, and alpha values used to clear the color buffers. Integer values, if requested, are linearly mapped from the internal floating-point representation such that 1.0 returns the most positive representable integer value, and -1.0 returns the most negative representable integer value. See [**glClearColor**](https://learn.microsoft.com/windows/win32/opengl/glclearcolor).<br> |
|

**GL\_COLOR\_LOGIC\_OP**

| The *params* parameter returns a single Boolean value indicating whether a fragment's RGBA color values are merged into the framebuffer using a logical operation. See [**glLogicOp**](https://learn.microsoft.com/windows/win32/opengl/gllogicop).<br> |
|

**GL\_COLOR\_MATERIAL**

| The *params* parameter returns a single Boolean value indicating whether one or more material parameters are tracking the current color. See [**glColorMaterial**](https://learn.microsoft.com/windows/win32/opengl/glcolormaterial).<br> |
|

**GL\_COLOR\_MATERIAL\_FACE**

| The *params* parameter returns one value: a symbolic constant indicating which materials have a parameter that is tracking the current color. See [**glColorMaterial**](https://learn.microsoft.com/windows/win32/opengl/glcolormaterial).<br> |
|

**GL\_COLOR\_MATERIAL\_PARAMETER**

| The *params* parameter returns one value: a symbolic constant indicating which material parameters are tracking the current color. See [**glColorMaterial**](https://learn.microsoft.com/windows/win32/opengl/glcolormaterial).<br> |
|

**GL\_COLOR\_WRITEMASK**

| The *params* parameter returns four Boolean values: the red, green, blue, and alpha write enables for the color buffers. See [**glColorMask**](https://learn.microsoft.com/windows/win32/opengl/glcolormask).<br> |
|

**GL\_CULL\_FACE**

| The *params* parameter returns a single Boolean value indicating whether polygon culling is enabled. See [**glCullFace**](https://learn.microsoft.com/windows/win32/opengl/glcullface).<br> |
|

**GL\_CULL\_FACE\_MODE**

| The *params* parameter returns one value: a symbolic constant indicating which polygon faces are to be culled. See [**glCullFace**](https://learn.microsoft.com/windows/win32/opengl/glcullface).<br> |
|

**GL\_CURRENT\_COLOR**

| The *params* parameter returns four values: the red, green, blue, and alpha values of the current color. Integer values, if requested, are linearly mapped from the internal floating-point representation such that 1.0 returns the most positive representable integer value, and -1.0 returns the most negative representable integer value. See [**glColor**](https://learn.microsoft.com/windows/win32/opengl/glcolor-functions).<br> |
|

**GL\_CURRENT\_INDEX**

| The *params* parameter returns one value: the current color index. See [**glIndex**](https://learn.microsoft.com/windows/win32/opengl/glindex-functions).<br> |
|

**GL\_CURRENT\_NORMAL**

| The *params* parameter returns three values: the *x*, *y*, and *z* values of the current normal. Integer values, if requested, are linearly mapped from the internal floating-point representation such that 1.0 returns the most positive representable integer value, and -1.0 returns the most negative representable integer value. See [**glNormal**](https://learn.microsoft.com/windows/win32/opengl/glnormal-functions).<br> |
|

**GL\_CURRENT\_RASTER\_COLOR**

| The *params* parameter returns four values: the red, green, blue, and alpha values of the current raster position. Integer values, if requested, are linearly mapped from the internal floating-point representation such that 1.0 returns the most positive representable integer value, and -1.0 returns the most negative representable integer value. See [**glRasterPos**](https://learn.microsoft.com/windows/win32/opengl/glrasterpos-functions).<br> |
|

**GL\_CURRENT\_RASTER\_DISTANCE**

| The *params* parameter returns one value: the distance from the eye to the current raster position. See [**glRasterPos**](https://learn.microsoft.com/windows/win32/opengl/glrasterpos-functions).<br> |
|

**GL\_CURRENT\_RASTER\_INDEX**

| The *params* parameter returns one value: the color index of the current raster position. See [**glRasterPos**](https://learn.microsoft.com/windows/win32/opengl/glrasterpos-functions).<br> |
|

**GL\_CURRENT\_RASTER\_POSITION**

| The *params* parameter returns four values: the *x*, *y*, *z*, and *w* components of the current raster position. The *x*, *y*, and *z* components are in window coordinates, and *w* is in clip coordinates. See [glRasterPos](https://learn.microsoft.com/windows/win32/opengl/glrasterpos-functions).<br> |
|

**GL\_CURRENT\_RASTER\_POSITION\_VALID**

| The *params* parameter returns a single Boolean value indicating whether the current raster position is valid. See [**glRasterPos**](https://learn.microsoft.com/windows/win32/opengl/glrasterpos-functions).<br> |
|

**GL\_CURRENT\_RASTER\_TEXTURE\_COORDS**

| The *params* parameter returns four values: the *s*, *t*, *r*, and *q* current raster texture coordinates. See [**glRasterPos**](https://learn.microsoft.com/windows/win32/opengl/glrasterpos-functions) and [**glTexCoord**](https://learn.microsoft.com/windows/win32/opengl/gltexcoord-functions).<br> |
|

**GL\_CURRENT\_TEXTURE\_COORDS**

| The *params* parameter returns four values: the *s*, *t*, *r*, and *q* current texture coordinates. See [**glTexCoord**](https://learn.microsoft.com/windows/win32/opengl/gltexcoord-functions).<br> |
|

**GL\_DEPTH\_BIAS**

| The *params* parameter returns one value: the depth bias factor used during pixel transfers. See [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer).<br> |
|

**GL\_DEPTH\_BITS**

| The *params* parameter returns one value: the number of bitplanes in the depth buffer.<br> |
|

**GL\_DEPTH\_CLEAR\_VALUE**

| The *params* parameter returns one value: the value that is used to clear the depth buffer. Integer values, if requested, are linearly mapped from the internal floating-point representation such that 1.0 returns the most positive representable integer value, and -1.0 returns the most negative representable integer value. See [**glClearDepth**](https://learn.microsoft.com/windows/win32/opengl/glcleardepth).<br> |
|

**GL\_DEPTH\_FUNC**

| The *params* parameter returns one value: the symbolic constant that indicates the depth comparison function. See [**glDepthFunc**](https://learn.microsoft.com/windows/win32/opengl/gldepthfunc).<br> |
|

**GL\_DEPTH\_RANGE**

| The *params* parameter returns two values: the near and far mapping limits for the depth buffer. Integer values, if requested, are linearly mapped from the internal floating-point representation such that 1.0 returns the most positive representable integer value, and -1.0 returns the most negative representable integer value. See [**glDepthRange**](https://learn.microsoft.com/windows/win32/opengl/gldepthrange).<br> |
|

**GL\_DEPTH\_SCALE**

| The *params* parameter returns one value: the depth scale factor used during pixel transfers. See [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer).<br> |
|

**GL\_DEPTH\_TEST**

| The *params* parameter returns a single Boolean value indicating whether depth testing of fragments is enabled. See [**glDepthFunc**](https://learn.microsoft.com/windows/win32/opengl/gldepthfunc) and [**glDepthRange**](https://learn.microsoft.com/windows/win32/opengl/gldepthrange).<br> |
|

**GL\_DEPTH\_WRITEMASK**

| The *params* parameter returns a single Boolean value indicating if the depth buffer is enabled for writing. See [**glDepthMask**](https://learn.microsoft.com/windows/win32/opengl/gldepthmask).<br> |
|

**GL\_DITHER**

| The *params* parameter returns a single Boolean value indicating whether dithering of fragment colors and indexes is enabled.<br> |
|

**GL\_DOUBLEBUFFER**

| The *params* parameter returns a single Boolean value indicating whether double buffering is supported.<br> |
|

**GL\_DRAW\_BUFFER**

| The *params* parameter returns one value: a symbolic constant indicating which buffers are being drawn to. See [**glDrawBuffer**](https://learn.microsoft.com/windows/win32/opengl/gldrawbuffer).<br> |
|

**GL\_EDGE\_FLAG**

| The *params* parameter returns a single Boolean value indicating whether the current edge flag is true or false. See [glEdgeFlag](https://learn.microsoft.com/windows/win32/opengl/gledgeflag-functions).<br> |
|

**GL\_EDGE\_FLAG\_ARRAY**

| The *params* parameter returns a single Boolean value indicating whether the edge flag array is enabled. See [**glEdgeFlagPointer**](https://learn.microsoft.com/windows/win32/opengl/gledgeflagpointer).<br> |
|

**GL\_EDGE\_FLAG\_ARRAY\_STRIDE**

| The *params* parameter returns one value, the byte offset between consecutive edge flags in the edge flag array. See [**glEdgeFlagPointer**](https://learn.microsoft.com/windows/win32/opengl/gledgeflagpointer).<br> |
|

**GL\_FOG**

| The *params* parameter returns a single Boolean value indicating whether fogging is enabled. See [**glFog**](https://learn.microsoft.com/windows/win32/opengl/glfog).<br> |
|

**GL\_FOG\_COLOR**

| The *params* parameter returns four values: the red, green, blue, and alpha components of the fog color. Integer values, if requested, are linearly mapped from the internal floating-point representation such that 1.0 returns the most positive representable integer value, and -1.0 returns the most negative representable integer value. See [**glFog**](https://learn.microsoft.com/windows/win32/opengl/glfog).<br> |
|

**GL\_FOG\_DENSITY**

| The *params* parameter returns one value: the fog density parameter. See [glFog](https://learn.microsoft.com/windows/win32/opengl/glfog).<br> |
|

**GL\_FOG\_END**

| The *params* parameter returns one value: the end factor for the linear fog equation. See [**glFog**](https://learn.microsoft.com/windows/win32/opengl/glfog).<br> |
|

**GL\_FOG\_HINT**

| The *params* parameter returns one value: a symbolic constant indicating the mode of the fog hint. See [**glHint**](https://learn.microsoft.com/windows/win32/opengl/glhint).<br> |
|

**GL\_FOG\_INDEX**

| The *params* parameter returns one value: the fog color index. See [**glFog**](https://learn.microsoft.com/windows/win32/opengl/glfog).<br> |
|

**GL\_FOG\_MODE**

| The *params* parameter returns one value: a symbolic constant indicating which fog equation is selected. See [**glFog**](https://learn.microsoft.com/windows/win32/opengl/glfog).<br> |
|

**GL\_FOG\_START**

| The *params* parameter returns one value: the start factor for the linear fog equation. See [**glFog**](https://learn.microsoft.com/windows/win32/opengl/glfog).<br> |
|

**GL\_FRONT\_FACE**

| The *params* parameter returns one value: a symbolic constant indicating whether clockwise or counterclockwise polygon winding is treated as front-facing. See [**glFrontFace**](https://learn.microsoft.com/windows/win32/opengl/glfrontface).<br> |
|

**GL\_GREEN\_BIAS**

| The *params* parameter returns one value: the green bias factor used during pixel transfers.<br> |
|

**GL\_GREEN\_BITS**

| The *params* parameter returns one value: the number of green bitplanes in each color buffer.<br> |
|

**GL\_GREEN\_SCALE**

| The *params* parameter returns one value: the green scale factor used during pixel transfers. See [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer).<br> |
|

**GL\_INDEX\_ARRAY**

| The *params* parameter returns a single Boolean value indicating whether the color index array is enabled. See [**glIndexPointer**](https://learn.microsoft.com/windows/win32/opengl/glindexpointer).<br> |
|

**GL\_INDEX\_ARRAY\_STRIDE**

| The *params* parameter returns one value, the byte offset between consecutive color indexes in the color index array. See [**glIndexPointer**](https://learn.microsoft.com/windows/win32/opengl/glindexpointer).<br> |
|

**GL\_INDEX\_ARRAY\_TYPE**

| The *params* parameter returns one value, the data type of indexes in the color index array. The initial value is GL\_FLOAT. See [**glIndexPointer**](https://learn.microsoft.com/windows/win32/opengl/glindexpointer).<br> |
|

**GL\_INDEX\_BITS**

| The *params* parameter returns one value: the number of bitplanes in each color-index buffer.<br> |
|

**GL\_INDEX\_CLEAR\_VALUE**

| The *params* parameter returns one value: the color index used to clear the color-index buffers. See [**glClearIndex**](https://learn.microsoft.com/windows/win32/opengl/glclearindex).<br> |
|

**GL\_INDEX\_LOGIC\_OP**

| The *params* parameter returns a single Boolean value indicating whether a fragment's index values are merged into the framebuffer using a logical operation. See [**glLogicOp**](https://learn.microsoft.com/windows/win32/opengl/gllogicop).<br> |
|

**GL\_INDEX\_MODE**

| The *params* parameter returns a single Boolean value indicating whether OpenGL is in color-index mode (TRUE) or RGBA mode (FALSE).<br> |
|

**GL\_INDEX\_OFFSET**

| The *params* parameter returns one value: the offset added to color and stencil indexes during pixel transfers. See [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer).<br> |
|

**GL\_INDEX\_SHIFT**

| The *params* parameter returns one value: the amount that color and stencil indexes are shifted during pixel transfers. See [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer).<br> |
|

**GL\_INDEX\_WRITEMASK**

| The *params* parameter returns one value: a mask indicating which bitplanes of each color-index buffer can be written. See [**glIndexMask**](https://learn.microsoft.com/windows/win32/opengl/glindexmask).<br> |
|

**GL\_LIGHT*i***

| The *params* parameter returns a single Boolean value indicating whether the specified light is enabled. See [**glLight**](https://learn.microsoft.com/windows/win32/opengl/gllight-functions) and [**glLightModel**](https://learn.microsoft.com/windows/win32/opengl/gllightmodel-functions).<br> |
|

**GL\_LIGHTING**

| The *params* parameter returns a single Boolean value indicating whether lighting is enabled. See [**glLightModel**](https://learn.microsoft.com/windows/win32/opengl/gllightmodel-functions).<br> |
|

**GL\_LIGHT\_MODEL\_AMBIENT**

| The *params* parameter returns four values: the red, green, blue, and alpha components of the ambient intensity of the entire scene. Integer values, if requested, are linearly mapped from the internal floating-point representation such that 1.0 returns the most positive representable integer value, and -1.0 returns the most negative representable integer value. See [**glLightModel**](https://learn.microsoft.com/windows/win32/opengl/gllightmodel-functions).<br> |
|

**GL\_LIGHT\_MODEL\_LOCAL\_VIEWER**

| The *params* parameter returns a single Boolean value indicating whether specular reflection calculations treat the viewer as being local to the scene. See [**glLightModel**](https://learn.microsoft.com/windows/win32/opengl/gllightmodel-functions).<br> |
|

**GL\_LIGHT\_MODEL\_TWO\_SIDE**

| The *params* parameter returns a single Boolean value indicating whether separate materials are used to compute lighting for front-facing and back-facing polygons. See [**glLightModel**](https://learn.microsoft.com/windows/win32/opengl/gllightmodel-functions).<br> |
|

**GL\_LINE\_SMOOTH**

| The *params* parameter returns a single Boolean value indicating whether antialiasing of lines is enabled. See [**glLineWidth**](https://learn.microsoft.com/windows/win32/opengl/gllinewidth).<br> |
|

**GL\_LINE\_SMOOTH\_HINT**

| The *params* parameter returns one value: a symbolic constant indicating the mode of the line antialiasing hint. See [**glHint**](https://learn.microsoft.com/windows/win32/opengl/glhint).<br> |
|

**GL\_LINE\_STIPPLE**

| The *params* parameter returns a single Boolean value indicating whether stippling of lines is enabled. See [**glLineStipple**](https://learn.microsoft.com/windows/win32/opengl/gllinestipple).<br> |
|

**GL\_LINE\_STIPPLE\_PATTERN**

| The *params* parameter returns one value: the 16-bit line stipple pattern. See [**glLineStipple**](https://learn.microsoft.com/windows/win32/opengl/gllinestipple).<br> |
|

**GL\_LINE\_STIPPLE\_REPEAT**

| The *params* parameter returns one value: the line stipple repeat factor. See [**glLineStipple**](https://learn.microsoft.com/windows/win32/opengl/gllinestipple).<br> |
|

**GL\_LINE\_WIDTH**

| The *params* parameter returns one value: the line width as specified with [**glLineWidth**](https://learn.microsoft.com/windows/win32/opengl/gllinewidth).<br> |
|

**GL\_LINE\_WIDTH\_GRANULARITY**

| The *params* parameter returns one value: the width difference between adjacent supported widths for antialiased lines. See [**glLineWidth**](https://learn.microsoft.com/windows/win32/opengl/gllinewidth).<br> |
|

**GL\_LINE\_WIDTH\_RANGE**

| The *params* parameter returns two values: the smallest and largest supported widths for antialiased lines. See [**glLineWidth**](https://learn.microsoft.com/windows/win32/opengl/gllinewidth).<br> |
|

**GL\_LIST\_BASE**

| The *params* parameter returns one value: the base offset added to all names in arrays presented to [**glCallLists**](https://learn.microsoft.com/windows/win32/opengl/glcalllists). See [**glListBase**](https://learn.microsoft.com/windows/win32/opengl/gllistbase).<br> |
|

**GL\_LIST\_INDEX**

| The *params* parameter returns one value: the name of the display list currently under construction. Zero is returned if no display list is currently under construction. See [**glNewList**](https://learn.microsoft.com/windows/win32/opengl/glnewlist).<br> |
|

**GL\_LIST\_MODE**

| The *params* parameter returns one value: a symbolic constant indicating the construction mode of the display list currently being constructed. See [**glNewList**](https://learn.microsoft.com/windows/win32/opengl/glnewlist).<br> |
|

**GL\_LOGIC\_OP**

| The *params* parameter returns a single Boolean value indicating whether fragment indexes are merged into the framebuffer using a logical operation. See [**glLogicOp**](https://learn.microsoft.com/windows/win32/opengl/gllogicop).<br> |
|

**GL\_LOGIC\_OP\_MODE**

| The *params* parameter returns one value: a symbolic constant indicating the selected logic operational mode. See [**glLogicOp**](https://learn.microsoft.com/windows/win32/opengl/gllogicop).<br> |
|

**GL\_MAP1\_COLOR\_4**

| The *params* parameter returns a single Boolean value indicating whether 1-D evaluation generates colors. See [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1).<br> |
|

**GL\_MAP1\_GRID\_DOMAIN**

| The *params* parameter returns two values: the endpoints of the 1-D maps grid domain. See [glMapGrid](https://learn.microsoft.com/windows/win32/opengl/glmapgrid-functions).<br> |
|

**GL\_MAP1\_GRID\_SEGMENTS**

| The *params* parameter returns one value: the number of partitions in the 1-D maps grid domain. See [glMapGrid](https://learn.microsoft.com/windows/win32/opengl/glmapgrid-functions).<br> |
|

**GL\_MAP1\_INDEX**

| The *params* parameter returns a single Boolean value indicating whether 1-D evaluation generates color indexes. See [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1).<br> |
|

**GL\_MAP1\_NORMAL**

| The *params* parameter returns a single Boolean value indicating whether 1-D evaluation generates normals. See [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1).<br> |
|

**GL\_MAP1\_TEXTURE\_COORD\_1**

| The *params* parameter returns a single Boolean value indicating whether 1-D evaluation generates 1-D texture coordinates. See [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1).<br> |
|

**GL\_MAP1\_TEXTURE\_COORD\_2**

| The *params* parameter returns a single Boolean value indicating whether 1-D evaluation generates 2-D texture coordinates. See [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1).<br> |
|

**GL\_MAP1\_TEXTURE\_COORD\_3**

| The *params* parameter returns a single Boolean value indicating whether 1-D evaluation generates 3-D texture coordinates. See [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1).<br> |
|

**GL\_MAP1\_TEXTURE\_COORD\_4**

| The *params* parameter returns a single Boolean value indicating whether 1-D evaluation generates 4-D texture coordinates. See [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1).<br> |
|

**GL\_MAP1\_VERTEX\_3**

| The *params* parameter returns a single Boolean value indicating whether 1-D evaluation generates 3-D vertex coordinates. See [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1).<br> |
|

**GL\_MAP1\_VERTEX\_4**

| The *params* parameter returns a single Boolean value indicating whether 1-D evaluation generates 4-D vertex coordinates. See [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1).<br> |
|

**GL\_MAP2\_COLOR\_4**

| The *params* parameter returns a single Boolean value indicating whether 2-D evaluation generates colors. See [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2).<br> |
|

**GL\_MAP2\_GRID\_DOMAIN**

| The *params* parameter returns four values: the endpoints of the 2-D maps *i* and *j* grid domains. See [glMapGrid](https://learn.microsoft.com/windows/win32/opengl/glmapgrid-functions).<br> |
|

**GL\_MAP2\_GRID\_SEGMENTS**

| The *params* parameter returns two values: the number of partitions in the 2-D maps *i* and *j* grid domains. See [glMapGrid](https://learn.microsoft.com/windows/win32/opengl/glmapgrid-functions).<br> |
|

**GL\_MAP2\_INDEX**

| The *params* parameter returns a single Boolean value indicating whether 2-D evaluation generates color indexes. See [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2).<br> |
|

**GL\_MAP2\_NORMAL**

| The *params* parameter returns a single Boolean value indicating whether 2-D evaluation generates normals. See [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2).<br> |
|

**GL\_MAP2\_TEXTURE\_COORD\_1**

| The *params* parameter returns a single Boolean value indicating whether 2-D evaluation generates 1-D texture coordinates. See [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2).<br> |
|

**GL\_MAP2\_TEXTURE\_COORD\_2**

| The *params* parameter returns a single Boolean value indicating whether 2-D evaluation generates 2-D texture coordinates. See [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2).<br> |
|

**GL\_MAP2\_TEXTURE\_COORD\_3**

| The *params* parameter returns a single Boolean value indicating whether 2-D evaluation generates 3-D texture coordinates. See [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2).<br> |
|

**GL\_MAP2\_TEXTURE\_COORD\_4**

| The *params* parameter returns a single Boolean value indicating whether 2-D evaluation generates 4-D texture coordinates. See [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2).<br> |
|

**GL\_MAP2\_VERTEX\_3**

| The *params* parameter returns a single Boolean value indicating whether 2-D evaluation generates 3-D vertex coordinates. See [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2).<br> |
|

**GL\_MAP2\_VERTEX\_4**

| The *params* parameter returns a single Boolean value indicating whether 2-D evaluation generates 4-D vertex coordinates. See [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2).<br> |
|

**GL\_MAP\_COLOR**

| The *params* parameter returns a single Boolean value indicating whether colors and color indexes are to be replaced by table lookup during pixel transfers. See [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer).<br> |
|

**GL\_MAP\_STENCIL**

| The *params* parameter returns a single Boolean value indicating whether stencil indexes are to be replaced by table lookup during pixel transfers. See [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer).<br> |
|

**GL\_MATRIX\_MODE**

| The *params* parameter returns one value: a symbolic constant indicating which matrix stack is currently the target of all matrix operations. See [**glMatrixMode**](https://learn.microsoft.com/windows/win32/opengl/glmatrixmode).<br> |
|

**GL\_MAX\_CLIENT\_ATTRIB\_STACK\_DEPTH**

| The *params* parameter returns one value indicating the maximum supported depth of the client attribute stack. See [**glPushClientAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushclientattrib).<br> |
|

**GL\_MAX\_ATTRIB\_STACK\_DEPTH**

| The *params* parameter returns one value: the maximum supported depth of the attribute stack. See [**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib).<br> |
|

**GL\_MAX\_CLIP\_PLANES**

| The *params* parameter returns one value: the maximum number of application-defined clipping planes. See [**glClipPlane**](https://learn.microsoft.com/windows/win32/opengl/glclipplane).<br> |
|

**GL\_MAX\_EVAL\_ORDER**

| The *params* parameter returns one value: the maximum equation order supported by 1-D and 2-D evaluators. See [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1) and [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2).<br> |
|

**GL\_MAX\_LIGHTS**

| The *params* parameter returns one value: the maximum number of lights. See [glLight](https://learn.microsoft.com/windows/win32/opengl/gllight-functions).<br> |
|

**GL\_MAX\_LIST\_NESTING**

| The *params* parameter returns one value: the maximum recursion depth allowed during display-list traversal. See [**glCallList**](https://learn.microsoft.com/windows/win32/opengl/glcalllist).<br> |
|

**GL\_MAX\_MODELVIEW\_STACK\_DEPTH**

| The *params* parameter returns one value: the maximum supported depth of the modelview matrix stack. See [**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix).<br> |
|

**GL\_MAX\_NAME\_STACK\_DEPTH**

| The *params* parameter returns one value: the maximum supported depth of the selection name stack. See [**glPushName**](https://learn.microsoft.com/windows/win32/opengl/glpushname).<br> |
|

**GL\_MAX\_PIXEL\_MAP\_TABLE**

| The *params* parameter returns one value: the maximum supported size of a [**glPixelMap**](https://learn.microsoft.com/windows/win32/opengl/glpixelmap) lookup table.<br> |
|

**GL\_MAX\_PROJECTION\_STACK\_DEPTH**

| The *params* parameter returns one value: the maximum supported depth of the projection matrix stack. See [**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix).<br> |
|

**GL\_MAX\_TEXTURE\_SIZE**

| The *params* parameter returns one value: the maximum width or height of any texture image (without borders). See [**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d) and [**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d).<br> |
|

**GL\_MAX\_TEXTURE\_STACK\_DEPTH**

| The *params* parameter returns one value: the maximum supported depth of the texture matrix stack. See [**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix).<br> |
|

**GL\_MAX\_VIEWPORT\_DIMS**

| The *params* parameter returns two values: the maximum supported width and height of the viewport. See [**glViewport**](https://learn.microsoft.com/windows/win32/opengl/glviewport).<br> |
|

**GL\_MODELVIEW\_MATRIX**

| The *params* parameter returns 16 values: the modelview matrix on the top of the modelview matrix stack. See [**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix).<br> |
|

**GL\_MODELVIEW\_STACK\_DEPTH**

| The *params* parameter returns one value: the number of matrices on the modelview matrix stack. See [**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix).<br> |
|

**GL\_NAME\_STACK\_DEPTH**

| The *params* parameter returns one value: the number of names on the selection name stack. See [**glPushName**](https://learn.microsoft.com/windows/win32/opengl/glpushname).<br> |
|

**GL\_NORMAL\_ARRAY**

| The *params* parameter returns a single Boolean value, indicating whether the normal array is enabled. See [**glNormalPointer**](https://learn.microsoft.com/windows/win32/opengl/glnormalpointer).<br> |
|

**GL\_NORMAL\_ARRAY\_STRIDE**

| The *params* parameter returns one value, the byte offset between consecutive normals in the normal array. See [**glNormalPointer**](https://learn.microsoft.com/windows/win32/opengl/glnormalpointer).<br> |
|

**GL\_NORMAL\_ARRAY\_TYPE**

| The *params* parameter returns one value, the data type of each coordinate in the normal array. See [**glNormalPointer**](https://learn.microsoft.com/windows/win32/opengl/glnormalpointer).<br> |
|

**GL\_NORMALIZE**

| The *params* parameter returns a single Boolean value indicating whether normals are automatically scaled to unit length after they have been transformed to eye coordinates. See [glNormal](https://learn.microsoft.com/windows/win32/opengl/glnormal-functions).<br> |
|

**GL\_PACK\_ALIGNMENT**

| The *params* parameter returns one value: the byte alignment used for writing pixel data to memory. See [glPixelStore](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions).<br> |
|

**GL\_PACK\_LSB\_FIRST**

| The *params* parameter returns a single Boolean value indicating whether single-bit pixels being written to memory are written first to the least significant bit of each unsigned byte. See [glPixelStore](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions).<br> |
|

**GL\_PACK\_ROW\_LENGTH**

| The *params* parameter returns one value: the row length used for writing pixel data to memory. See [glPixelStore](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions).<br> |
|

**GL\_PACK\_SKIP\_PIXELS**

| The *params* parameter returns one value: the number of pixel locations skipped before the first pixel is written into memory. See [glPixelStore](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions).<br> |
|

**GL\_PACK\_SKIP\_ROWS**

| The *params* parameter returns one value: the number of rows of pixel locations skipped before the first pixel is written into memory. See [glPixelStore](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions).<br> |
|

**GL\_PACK\_SWAP\_BYTES**

| The *params* parameter returns a single Boolean value indicating whether the bytes of 2-byte and 4-byte pixel indexes and components are swapped before being written to memory. See [glPixelStore](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions).<br> |
|

**GL\_PERSPECTIVE\_CORRECTION\_HINT**

| The *params* parameter returns one value: a symbolic constant indicating the mode of the perspective correction hint. See [**glHint**](https://learn.microsoft.com/windows/win32/opengl/glhint).<br> |
|

**GL\_PIXEL\_MAP\_A\_TO\_A\_SIZE**

| The *params* parameter returns one value: the size of the alpha-to-alpha pixel-translation table. See [**glPixelMap**](https://learn.microsoft.com/windows/win32/opengl/glpixelmap).<br> |
|

**GL\_PIXEL\_MAP\_B\_TO\_B\_SIZE**

| The *params* parameter returns one value: the size of the blue-to-blue pixel-translation table. See [**glPixelMap**](https://learn.microsoft.com/windows/win32/opengl/glpixelmap).<br> |
|

**GL\_PIXEL\_MAP\_G\_TO\_G\_SIZE**

| The *params* parameter returns one value: the size of the green-to-green pixel-translation table. See [**glPixelMap**](https://learn.microsoft.com/windows/win32/opengl/glpixelmap).<br> |
|

**GL\_PIXEL\_MAP\_I\_TO\_A\_SIZE**

| The *params* parameter returns one value: the size of the index-to-alpha pixel translation table. See [**glPixelMap**](https://learn.microsoft.com/windows/win32/opengl/glpixelmap).<br> |
|

**GL\_PIXEL\_MAP\_I\_TO\_B\_SIZE**

| The *params* parameter returns one value: the size of the index-to-blue pixel translation table. See [**glPixelMap**](https://learn.microsoft.com/windows/win32/opengl/glpixelmap).<br> |
|

**GL\_PIXEL\_MAP\_I\_TO\_G\_SIZE**

| The *params* parameter returns one value: the size of the index-to-green pixel-translation table. See [**glPixelMap**](https://learn.microsoft.com/windows/win32/opengl/glpixelmap).<br> |
|

**GL\_PIXEL\_MAP\_I\_TO\_I\_SIZE**

| The *params* parameter returns one value: the size of the index-to-index pixel-translation table. See [**glPixelMap**](https://learn.microsoft.com/windows/win32/opengl/glpixelmap).<br> |
|

**GL\_PIXEL\_MAP\_I\_TO\_R\_SIZE**

| The *params* parameter returns one value: the size of the index-to-red pixel-translation table. See [**glPixelMap**](https://learn.microsoft.com/windows/win32/opengl/glpixelmap).<br> |
|

**GL\_PIXEL\_MAP\_R\_TO\_R\_SIZE**

| The *params* parameter returns one value: the size of the red-to-red pixel-translation table. See [**glPixelMap**](https://learn.microsoft.com/windows/win32/opengl/glpixelmap).<br> |
|

**GL\_PIXEL\_MAP\_S\_TO\_S\_SIZE**

| The *params* parameter returns one value: the size of the stencil-to-stencil pixel translation table. See [**glPixelMap**](https://learn.microsoft.com/windows/win32/opengl/glpixelmap).<br> |
|

**GL\_POINT\_SIZE**

| The *params* parameter returns one value: the point size as specified by [**glPointSize**](https://learn.microsoft.com/windows/win32/opengl/glpointsize).<br> |
|

**GL\_POINT\_SIZE\_GRANULARITY**

| The *params* parameter returns one value: the size difference between adjacent supported sizes for antialiased points. See [**glPointSize**](https://learn.microsoft.com/windows/win32/opengl/glpointsize).<br> |
|

**GL\_POINT\_SIZE\_RANGE**

| The *params* parameter returns two values: the smallest and largest supported sizes for antialiased points. See [**glPointSize**](https://learn.microsoft.com/windows/win32/opengl/glpointsize).<br> |
|

**GL\_POINT\_SMOOTH**

| The *params* parameter returns a single Boolean value indicating whether antialiasing of points is enabled. See [**glPointSize**](https://learn.microsoft.com/windows/win32/opengl/glpointsize).<br> |
|

**GL\_POINT\_SMOOTH\_HINT**

| The *params* parameter returns one value: a symbolic constant indicating the mode of the point antialiasing hint. See [**glHint**](https://learn.microsoft.com/windows/win32/opengl/glhint).<br> |
|

**GL\_POLYGON\_MODE**

| The *params* parameter returns two values: symbolic constants indicating whether front-facing and back-facing polygons are rasterized as points, lines, or filled polygons. See [**glPolygonMode**](https://learn.microsoft.com/windows/win32/opengl/glpolygonmode).<br> |
|

**GL\_POLYGON\_OFFSET\_FACTOR**

| The *params* parameter returns one value, the scaling factor used to determine the variable offset that is added to the depth value of each fragment generated when a polygon is rasterized. See [**glPolygonOffset**](https://learn.microsoft.com/windows/win32/opengl/glpolygonoffset).<br> |
|

**GL\_POLYGON\_OFFSET\_UNITS**

| The *params* parameter returns one value. This value is multiplied by an implementation-specific value and then added to the depth value of each fragment generated when a polygon is rasterized. See [**glPolygonOffset**](https://learn.microsoft.com/windows/win32/opengl/glpolygonoffset).<br> |
|

**GL\_POLYGON\_OFFSET\_FILL**

| The *params* parameter returns a single Boolean value indicating whether polygon offset is enabled for polygons in fill mode. See [**glPolygonOffset**](https://learn.microsoft.com/windows/win32/opengl/glpolygonoffset).<br> |
|

**GL\_POLYGON\_OFFSET\_LINE**

| The *params* parameter returns a single Boolean value indicating whether polygon offset is enabled for polygons in line mode. See [**glPolygonOffset**](https://learn.microsoft.com/windows/win32/opengl/glpolygonoffset).<br> |
|

**GL\_POLYGON\_OFFSET\_POINT**

| The *params* parameter returns a single Boolean value indicating whether polygon offset is enabled for polygons in point mode. See [**glPolygonOffset**](https://learn.microsoft.com/windows/win32/opengl/glpolygonoffset).<br> |
|

**GL\_POLYGON\_SMOOTH**

| The *params* parameter returns a single Boolean value indicating whether antialiasing of polygons is enabled. See [**glPolygonMode**](https://learn.microsoft.com/windows/win32/opengl/glpolygonmode).<br> |
|

**GL\_POLYGON\_SMOOTH\_HINT**

| The *params* parameter returns one value: a symbolic constant indicating the mode of the polygon antialiasing hint. See [**glHint**](https://learn.microsoft.com/windows/win32/opengl/glhint).<br> |
|

**GL\_POLYGON\_STIPPLE**

| The *params* parameter returns a single Boolean value indicating whether stippling of polygons is enabled. See [**glPolygonStipple**](https://learn.microsoft.com/windows/win32/opengl/glpolygonstipple).<br> |
|

**GL\_PROJECTION\_MATRIX**

| The *params* parameter returns 16 values: the projection matrix on the top of the projection matrix stack. See [**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix).<br> |
|

**GL\_PROJECTION\_STACK\_DEPTH**

| The *params* parameter returns one value: the number of matrices on the projection matrix stack. See [**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix).<br> |
|

**GL\_READ\_BUFFER**

| The *params* parameter returns one value: a symbolic constant indicating which color buffer is selected for reading. See [**glReadPixels**](https://learn.microsoft.com/windows/win32/opengl/glreadpixels) and [**glAccum**](https://learn.microsoft.com/windows/win32/opengl/glaccum).<br> |
|

**GL\_RED\_BIAS**

| The *params* parameter returns one value: the red bias factor used during pixel transfers. See [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer).<br> |
|

**GL\_RED\_BITS**

| The *params* parameter returns one value: the number of red bitplanes in each color buffer.<br> |
|

**GL\_RED\_SCALE**

| The *params* parameter returns one value: the red scale factor used during pixel transfers. See [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer).<br> |
|

**GL\_RENDER\_MODE**

| The *params* parameter returns one value: a symbolic constant indicating whether OpenGL is in render, select, or feedback mode. See [**glRenderMode**](https://learn.microsoft.com/windows/win32/opengl/glrendermode).<br> |
|

**GL\_RGBA\_MODE**

| The *params* parameter returns a single Boolean value indicating whether OpenGL is in RGBA mode (TRUE) or color-index mode (FALSE). See [glColor](https://learn.microsoft.com/windows/win32/opengl/glcolor-functions).<br> |
|

**GL\_SCISSOR\_BOX**

| The *params* parameter returns four values: the *x* and *y* window coordinates of the scissor box, followed by its width and height. See [**glScissor**](https://learn.microsoft.com/windows/win32/opengl/glscissor).<br> |
|

**GL\_SCISSOR\_TEST**

| The *params* parameter returns a single Boolean value indicating whether scissoring is enabled. See [**glScissor**](https://learn.microsoft.com/windows/win32/opengl/glscissor).<br> |
|

**GL\_SHADE\_MODEL**

| The *params* parameter returns one value: a symbolic constant indicating whether the shading mode is flat or smooth. See [**glShadeModel**](https://learn.microsoft.com/windows/win32/opengl/glshademodel).<br> |
|

**GL\_STENCIL\_BITS**

| The *params* parameter returns one value: the number of bitplanes in the stencil buffer.<br> |
|

**GL\_STENCIL\_CLEAR\_VALUE**

| The *params* parameter returns one value: the index to which the stencil bitplanes are cleared. See [**glClearStencil**](https://learn.microsoft.com/windows/win32/opengl/glclearstencil).<br> |
|

**GL\_STENCIL\_FAIL**

| The *params* parameter returns one value: a symbolic constant indicating what action is taken when the stencil test fails. See [**glStencilOp**](https://learn.microsoft.com/windows/win32/opengl/glstencilop).<br> |
|

**GL\_STENCIL\_FUNC**

| The *params* parameter returns one value: a symbolic constant indicating what function is used to compare the stencil reference value with the stencil buffer value. See [**glStencilFunc**](https://learn.microsoft.com/windows/win32/opengl/glstencilfunc).<br> |
|

**GL\_STENCIL\_PASS\_DEPTH\_FAIL**

| The *params* parameter returns one value: a symbolic constant indicating what action is taken when the stencil test passes, but the depth test fails. See [**glStencilOp**](https://learn.microsoft.com/windows/win32/opengl/glstencilop).<br> |
|

**GL\_STENCIL\_PASS\_DEPTH\_PASS**

| The *params* parameter returns one value: a symbolic constant indicating what action is taken when the stencil test passes and the depth test passes. See [**glStencilOp**](https://learn.microsoft.com/windows/win32/opengl/glstencilop).<br> |
|

**GL\_STENCIL\_REF**

| The *params* parameter returns one value: the reference value that is compared with the contents of the stencil buffer. See [**glStencilFunc**](https://learn.microsoft.com/windows/win32/opengl/glstencilfunc).<br> |
|

**GL\_STENCIL\_TEST**

| The *params* parameter returns a single Boolean value indicating whether stencil testing of fragments is enabled. See [**glStencilFunc**](https://learn.microsoft.com/windows/win32/opengl/glstencilfunc) and [**glStencilOp**](https://learn.microsoft.com/windows/win32/opengl/glstencilop).<br> |
|

**GL\_STENCIL\_VALUE\_MASK**

| The *params* parameter returns one value: the mask that is used to mask both the stencil reference value and the stencil buffer value before they are compared. See [**glStencilFunc**](https://learn.microsoft.com/windows/win32/opengl/glstencilfunc).<br> |
|

**GL\_STENCIL\_WRITEMASK**

| The *params* parameter returns one value: the mask that controls writing of the stencil bitplanes. See [**glStencilMask**](https://learn.microsoft.com/windows/win32/opengl/glstencilmask).<br> |
|

**GL\_STEREO**

| The *params* parameter returns a single Boolean value indicating whether stereo buffers (left and right) are supported.<br> |
|

**GL\_SUBPIXEL\_BITS**

| The *params* parameter returns one value: an estimate of the number of bits of subpixel resolution that are used to position rasterized geometry in window coordinates.<br> |
|

**GL\_TEXTURE\_1D**

| The *params* parameter returns a single Boolean value indicating whether 1-D texture mapping is enabled. See [**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d).<br> |
|

**GL\_TEXTURE\_2D**

| The *params* parameter returns a single Boolean value indicating whether 2-D texture mapping is enabled. See [**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d).<br> |
|

**GL\_TEXTURE\_COORD\_ARRAY**

| The *params* parameter returns a single Boolean value indicating whether the texture coordinate array is enabled. See [**glTexCoordPointer**](https://learn.microsoft.com/windows/win32/opengl/gltexcoordpointer).<br> |
|

**GL\_TEXTURE\_COORD\_ARRAY\_SIZE**

| The *params* parameter returns one value, the number of coordinates per element in the texture coordinate array. See [**glTexCoordPointer**](https://learn.microsoft.com/windows/win32/opengl/gltexcoordpointer).<br> |
|

**GL\_TEXTURE\_COORD\_ARRAY\_STRIDE**

| The *params* parameter returns one value, the byte offset between consecutive elements in the texture coordinate array. See [**glTexCoordPointer**](https://learn.microsoft.com/windows/win32/opengl/gltexcoordpointer).<br> |
|

**GL\_TEXTURE\_COORD\_ARRAY\_TYPE**

| The *params* parameter params returns one value, the data type of the coordinates in the texture coordinate array. See [**glTexCoordPointer**](https://learn.microsoft.com/windows/win32/opengl/gltexcoordpointer).<br> |
|

**GL\_TEXTURE\_ENV\_COLOR**

| The *params* parameter returns four values: the red, green, blue, and alpha values of the texture environment color. Integer values, if requested, are linearly mapped from the internal floating-point representation such that 1.0 returns the most positive representable integer value, and 1.0 returns the most negative representable integer value. See [glTexEnv](https://learn.microsoft.com/windows/win32/opengl/gltexenv-functions).<br> |
|

**GL\_TEXTURE\_ENV\_MODE**

| The *params* parameter returns one value: a symbolic constant indicating which texture environment function is currently selected. See [glTexEnv](https://learn.microsoft.com/windows/win32/opengl/gltexenv-functions).<br> |
|

**GL\_TEXTURE\_GEN\_Q**

| The *params* parameter returns a single Boolean value indicating whether automatic generation of the Q texture coordinate is enabled. See [**glTexGen**](https://learn.microsoft.com/windows/win32/opengl/gltexgen-functions).<br> |
|

**GL\_TEXTURE\_GEN\_R**

| The *params* parameter returns a single Boolean value indicating whether automatic generation of the R texture coordinate is enabled. See [**glTexGen**](https://learn.microsoft.com/windows/win32/opengl/gltexgen-functions).<br> |
|

**GL\_TEXTURE\_GEN\_S**

| The *params* parameter returns a single Boolean value indicating whether automatic generation of the S texture coordinate is enabled. See [**glTexGen**](https://learn.microsoft.com/windows/win32/opengl/gltexgen-functions).<br> |
|

**GL\_TEXTURE\_GEN\_T**

| The *params* parameter returns a single Boolean value indicating whether automatic generation of the T texture coordinate is enabled. See [**glTexGen**](https://learn.microsoft.com/windows/win32/opengl/gltexgen-functions).<br> |
|

**GL\_TEXTURE\_MATRIX**

| The *params* parameter returns 16 values: the texture matrix on the top of the texture matrix stack. See [**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix).<br> |
|

**GL\_TEXTURE\_STACK\_DEPTH**

| The *params* parameter returns one value: the number of matrices on the texture matrix stack. See [**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix).<br> |
|

**GL\_UNPACK\_ALIGNMENT**

| The *params* parameter returns one value: the byte alignment used for reading pixel data from memory. See [glPixelStore](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions).<br> |
|

**GL\_UNPACK\_LSB\_FIRST**

| The *params* parameter returns a single Boolean value indicating whether single-bit pixels being read from memory are read first from the least significant bit of each unsigned byte. See [glPixelStore](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions).<br> |
|

**GL\_UNPACK\_ROW\_LENGTH**

| The *params* parameter returns one value: the row length used for reading pixel data from memory. See [glPixelStore](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions).<br> |
|

**GL\_UNPACK\_SKIP\_PIXELS**

| The *params* parameter returns one value: the number of pixel locations skipped before the first pixel is read from memory. See [glPixelStore](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions).<br> |
|

**GL\_UNPACK\_SKIP\_ROWS**

| The *params* parameter returns one value: the number of rows of pixel locations skipped before the first pixel is read from memory. See [glPixelStore](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions).<br> |
|

**GL\_UNPACK\_SWAP\_BYTES**

| The *params* parameter returns a single Boolean value indicating whether the bytes of 2-byte and 4-byte pixel indexes and components are swapped after being read from memory. See [glPixelStore](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions).<br> |
|

**GL\_VERTEX\_ARRAY**

| The *params* parameter returns a single Boolean value indicating whether the vertex array is enabled. See [**glVertexPointer**](https://learn.microsoft.com/windows/win32/opengl/glvertexpointer).<br> |
|

**GL\_VERTEX\_ARRAY\_SIZE**

| The *params* parameter returns one value, the number of coordinates per vertex in the vertex array. See [**glVertexPointer**](https://learn.microsoft.com/windows/win32/opengl/glvertexpointer).<br> |
|

**GL\_VERTEX\_ARRAY\_STRIDE**

| The *params* parameter returns one value, the byte offset between consecutive vertexes in the vertex array. See [**glVertexPointer**](https://learn.microsoft.com/windows/win32/opengl/glvertexpointer).<br> |
|

**GL\_VERTEX\_ARRAY\_TYPE**

| The *params* parameter returns one value, the data type of each coordinate in the vertex array. See [**glVertexPointer**](https://learn.microsoft.com/windows/win32/opengl/glvertexpointer).<br> |
|

**GL\_VIEWPORT**

| The *params* parameter returns four values: the *x* and *y* window coordinates of the viewport, followed by its width and height. See [**glViewport**](https://learn.microsoft.com/windows/win32/opengl/glviewport).<br> |
|

**GL\_ZOOM\_X**

| The *params* parameter returns one value: the *x* pixel zoom factor. See [**glPixelZoom**](https://learn.microsoft.com/windows/win32/opengl/glpixelzoom).<br> |
|

**GL\_ZOOM\_Y**

| The *params* parameter returns one value: the *y* pixel zoom factor. See [**glPixelZoom**](https://learn.microsoft.com/windows/win32/opengl/glpixelzoom).<br> |

*params*

Returns the value or values of the specified parameter.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *pname* was not an accepted value.<br> |
| **GL\_INVALID\_OPERATION** | **glGetIntegerv** was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

This function returns values for simple state variables in OpenGL. The *pname* parameter is a symbolic constant indicating the state variable to be returned, and *params* is a pointer to an array of the indicated type in which to place the returned data.

Type conversion is performed if *params* has a different type from the state variable value being requested. If you call [**glGetBooleanv**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv), a floating-point or integer value is converted to GL\_FALSE if and only if it is zero. Otherwise, it is converted to GL\_TRUE.

If you call **glGetIntegerv**, Boolean values are returned as GL\_TRUE or GL\_FALSE, and most floating-point values are rounded to the nearest integer value. Floating-point colors and normals, however, are returned with a linear mapping that maps 1.0 to the most positive representable integer value and 1.0 to the most negative representable integer value.

If you call [**glGetFloatv**](https://learn.microsoft.com/windows/win32/opengl/glgetfloatv) or [**glGetDoublev**](https://learn.microsoft.com/windows/win32/opengl/glgetdoublev), Boolean values are returned as GL\_TRUE or GL\_FALSE, and integer values are converted to floating-point values.

You can query many of the Boolean parameters more easily with [**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Gl.h |
| Library<br> | Opengl32.lib |
| DLL<br> | Opengl32.dll |

## See also

[**glAccum**](https://learn.microsoft.com/windows/win32/opengl/glaccum)

[**glAlphaFunc**](https://learn.microsoft.com/windows/win32/opengl/glalphafunc)

[**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin)

[**glBlendFunc**](https://learn.microsoft.com/windows/win32/opengl/glblendfunc)

[**glCallList**](https://learn.microsoft.com/windows/win32/opengl/glcalllist)

[**glClearAccum**](https://learn.microsoft.com/windows/win32/opengl/glclearaccum)

[**glClearColor**](https://learn.microsoft.com/windows/win32/opengl/glclearcolor)

[**glClearDepth**](https://learn.microsoft.com/windows/win32/opengl/glcleardepth)

[**glClearIndex**](https://learn.microsoft.com/windows/win32/opengl/glclearindex)

[**glClearStencil**](https://learn.microsoft.com/windows/win32/opengl/glclearstencil)

[**glClipPlane**](https://learn.microsoft.com/windows/win32/opengl/glclipplane)

[**glColor**](https://learn.microsoft.com/windows/win32/opengl/glcolor-functions)

[**glColorMask**](https://learn.microsoft.com/windows/win32/opengl/glcolormask)

[**glColorMaterial**](https://learn.microsoft.com/windows/win32/opengl/glcolormaterial)

[**glCullFace**](https://learn.microsoft.com/windows/win32/opengl/glcullface)

[**glDepthFunc**](https://learn.microsoft.com/windows/win32/opengl/gldepthfunc)

[**glDepthMask**](https://learn.microsoft.com/windows/win32/opengl/gldepthmask)

[**glDepthRange**](https://learn.microsoft.com/windows/win32/opengl/gldepthrange)

[**glDrawBuffer**](https://learn.microsoft.com/windows/win32/opengl/gldrawbuffer)

[**glEdgeFlag**](https://learn.microsoft.com/windows/win32/opengl/gledgeflag-functions)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glFog**](https://learn.microsoft.com/windows/win32/opengl/glfog)

[**glFrontFace**](https://learn.microsoft.com/windows/win32/opengl/glfrontface)

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

[**glHint**](https://learn.microsoft.com/windows/win32/opengl/glhint)

[**glIndex**](https://learn.microsoft.com/windows/win32/opengl/glindex-functions)

[**glIndexMask**](https://learn.microsoft.com/windows/win32/opengl/glindexmask)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled)

[**glLight**](https://learn.microsoft.com/windows/win32/opengl/gllight-functions)

[**glLightModel**](https://learn.microsoft.com/windows/win32/opengl/gllightmodel-functions)

[**glLineStipple**](https://learn.microsoft.com/windows/win32/opengl/gllinestipple)

[**glLineWidth**](https://learn.microsoft.com/windows/win32/opengl/gllinewidth)

[**glListBase**](https://learn.microsoft.com/windows/win32/opengl/gllistbase)

[**glLogicOp**](https://learn.microsoft.com/windows/win32/opengl/gllogicop)

[**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1)

[**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2)

[glMapGrid](https://learn.microsoft.com/windows/win32/opengl/glmapgrid-functions)

[**glMatrixMode**](https://learn.microsoft.com/windows/win32/opengl/glmatrixmode)

[**glNewList**](https://learn.microsoft.com/windows/win32/opengl/glnewlist)

[**glNormal**](https://learn.microsoft.com/windows/win32/opengl/glnormal-functions)

[**glPixelMap**](https://learn.microsoft.com/windows/win32/opengl/glpixelmap)

[glPixelStore](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions)

[**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer)

[**glPixelZoom**](https://learn.microsoft.com/windows/win32/opengl/glpixelzoom)

[**glPointSize**](https://learn.microsoft.com/windows/win32/opengl/glpointsize)

[**glPolygonMode**](https://learn.microsoft.com/windows/win32/opengl/glpolygonmode)

[**glPolygonStipple**](https://learn.microsoft.com/windows/win32/opengl/glpolygonstipple)

[**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib)

[**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix)

[**glPushName**](https://learn.microsoft.com/windows/win32/opengl/glpushname)

[**glRasterPos**](https://learn.microsoft.com/windows/win32/opengl/glrasterpos-functions)

[**glReadPixels**](https://learn.microsoft.com/windows/win32/opengl/glreadpixels)

[**glScissor**](https://learn.microsoft.com/windows/win32/opengl/glscissor)

[**glShadeModel**](https://learn.microsoft.com/windows/win32/opengl/glshademodel)

[**glStencilFunc**](https://learn.microsoft.com/windows/win32/opengl/glstencilfunc)

[**glStencilMask**](https://learn.microsoft.com/windows/win32/opengl/glstencilmask)

[**glStencilOp**](https://learn.microsoft.com/windows/win32/opengl/glstencilop)

[**glTexCoord**](https://learn.microsoft.com/windows/win32/opengl/gltexcoord-functions)

[**glTexEnv**](https://learn.microsoft.com/windows/win32/opengl/gltexenv-functions)

[**glTexGen**](https://learn.microsoft.com/windows/win32/opengl/gltexgen-functions)

[**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d)

[**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d)

[**glViewport**](https://learn.microsoft.com/windows/win32/opengl/glviewport)

