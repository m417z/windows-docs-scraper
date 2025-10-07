# glDisable function

The [**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable) and **glDisable** functions enable or disable OpenGL capabilities.

## Parameters

*cap*

A symbolic constant indicating an OpenGL capability.

For discussion of the values *cap* can take, see the following Remarks section.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *cap* was not one of the values listed in the preceding Remarks section.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The [**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable) and **glDisable** functions enable and disable various OpenGL graphics capabilities. Use [**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) or [**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) to determine the current setting of any capability.

Both [**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable) and **glDisable** take a single argument, *cap*, which can assume one of the following values:

| Value | Meaning |
|-----------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| GL\_ALPHA\_TEST | If enabled, do alpha testing. See [**glAlphaFunc**](https://learn.microsoft.com/windows/win32/opengl/glalphafunc). |
| GL\_AUTO\_NORMAL | If enabled, compute surface normal vectors analytically when either GL\_MAP2\_VERTEX\_3 or GL\_MAP2\_VERTEX\_4 has generated vertices. See [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2). |
| GL\_BLEND | If enabled, blend the incoming RGBA color values with the values in the color buffers. See [**glBlendFunc**](https://learn.microsoft.com/windows/win32/opengl/glblendfunc). |
| GL\_CLIP\_PLANE*i* | If enabled, clip geometry against user-defined clipping plane *i*. See [**glClipPlane**](https://learn.microsoft.com/windows/win32/opengl/glclipplane). |
| GL\_COLOR\_LOGIC\_OP | If enabled, apply the current logical operation to the incoming RGBA color and color buffer values. See [**glLogicOp**](https://learn.microsoft.com/windows/win32/opengl/gllogicop). |
| GL\_COLOR\_MATERIAL | If enabled, have one or more material parameters track the current color. See [**glColorMaterial**](https://learn.microsoft.com/windows/win32/opengl/glcolormaterial). |
| GL\_CULL\_FACE | If enabled, cull polygons based on their winding in window coordinates. See [**glCullFace**](https://learn.microsoft.com/windows/win32/opengl/glcullface). |
| GL\_DEPTH\_TEST | If enabled, do depth comparisons and update the depth buffer. See [**glDepthFunc**](https://learn.microsoft.com/windows/win32/opengl/gldepthfunc) and [**glDepthRange**](https://learn.microsoft.com/windows/win32/opengl/gldepthrange). |
| GL\_DITHER | If enabled, dither color components or indexes before they are written to the color buffer. |
| GL\_FOG | If enabled, blend a fog color into the post-texturing color. See [**glFog**](https://learn.microsoft.com/windows/win32/opengl/glfog). |
| GL\_INDEX\_LOGIC\_OP | If enabled, apply the current logical operation to the incoming index and color buffer indices. See [**glLogicOp**](https://learn.microsoft.com/windows/win32/opengl/gllogicop). |
| GL\_LIGHT*i* | If enabled, include light *i* in the evaluation of the lighting equation. See [**glLightModel**](https://learn.microsoft.com/windows/win32/opengl/gllightmodel-functions) and [**glLight**](https://learn.microsoft.com/windows/win32/opengl/gllight-functions). |
| GL\_LIGHTING | If enabled, use the current lighting parameters to compute the vertex color or index. If disabled, associate the current color or index with each vertex. See [**glMaterial**](https://learn.microsoft.com/windows/win32/opengl/glmaterial-functions), **glLightModel**, and **glLight**. |
| GL\_LINE\_SMOOTH | If enabled, draw lines with correct filtering. If disabled, draw aliased lines. See [**glLineWidth**](https://learn.microsoft.com/windows/win32/opengl/gllinewidth). |
| GL\_LINE\_STIPPLE | If enabled, use the current line stipple pattern when drawing lines. See [**glLineStipple**](https://learn.microsoft.com/windows/win32/opengl/gllinestipple). |
| GL\_LOGIC\_OP | If enabled, apply the currently selected logical operation to the incoming and color-buffer indexes. See [**glLogicOp**](https://learn.microsoft.com/windows/win32/opengl/gllogicop). |
| GL\_MAP1\_COLOR\_4 | If enabled, calls to [**glEvalCoord1**](https://learn.microsoft.com/windows/win32/opengl/glevalcoord-functions), [**glEvalMesh1**](https://learn.microsoft.com/windows/win32/opengl/glevalmesh-functions), and [**glEvalPoint1**](https://learn.microsoft.com/windows/win32/opengl/glevalpoint) generate RGBA values. See also [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1). |
| GL\_MAP1\_INDEX | If enabled, calls to **glEvalCoord1**, **glEvalMesh1**, and **glEvalPoint1** generate color indexes. See also **glMap1**. |
| GL\_MAP1\_NORMAL | If enabled, calls to [**glEvalCoord1**](https://learn.microsoft.com/windows/win32/opengl/glevalcoord-functions), [**glEvalMesh1**](https://learn.microsoft.com/windows/win32/opengl/glevalmesh-functions), and [**glEvalPoint1**](https://learn.microsoft.com/windows/win32/opengl/glevalpoint) generate normals. See also [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1). |
| GL\_MAP1\_TEXTURE\_COORD\_1 | If enabled, calls to **glEvalCoord1**, **glEvalMesh1**, and **glEvalPoint1** generate *s* texture coordinates. See also **glMap1**. |
| GL\_MAP1\_TEXTURE\_COORD\_2 | If enabled, calls to [**glEvalCoord1**](https://learn.microsoft.com/windows/win32/opengl/glevalcoord-functions), [**glEvalMesh1**](https://learn.microsoft.com/windows/win32/opengl/glevalmesh-functions), and [**glEvalPoint1**](https://learn.microsoft.com/windows/win32/opengl/glevalpoint) generate *s* and *t* texture coordinates. See also [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1). |
| GL\_MAP1\_TEXTURE\_COORD\_3 | If enabled, calls to **glEvalCoord1**, **glEvalMesh1**, and **glEvalPoint1** generate *s*, *t*, and *r* texture coordinates. See also **glMap1**. |
| GL\_MAP1\_TEXTURE\_COORD\_4 | If enabled, calls to [glEvalCoord1](https://learn.microsoft.com/windows/win32/opengl/glevalcoord-functions), [glEvalMesh1](https://learn.microsoft.com/windows/win32/opengl/glevalmesh-functions), and [**glEvalPoint1**](https://learn.microsoft.com/windows/win32/opengl/glevalpoint) generate *s*, *t*, *r*, and *q* texture coordinates. See also [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1). |
| GL\_MAP1\_VERTEX\_3 | If enabled, calls to **glEvalCoord1**, **glEvalMesh1**, and **glEvalPoint1** generate *x*, *y*, and *z* vertex coordinates. See also **glMap1**. |
| GL\_MAP1\_VERTEX\_4 | If enabled, calls to [**glEvalCoord1**](https://learn.microsoft.com/windows/win32/opengl/glevalcoord-functions), [**glEvalMesh1**](https://learn.microsoft.com/windows/win32/opengl/glevalmesh-functions), and [**glEvalPoint1**](https://learn.microsoft.com/windows/win32/opengl/glevalpoint) generate homogeneous *x*, *y*, *z*, and *w* vertex coordinates. See also [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1). |
| GL\_MAP2\_COLOR\_4 | If enabled, calls to [**glEvalCoord2**](https://learn.microsoft.com/windows/win32/opengl/glevalcoord-functions), [**glEvalMesh2**](https://learn.microsoft.com/windows/win32/opengl/glevalmesh-functions), and [**glEvalPoint2**](https://learn.microsoft.com/windows/win32/opengl/glevalpoint) generate RGBA values. See also [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2). |
| GL\_MAP2\_INDEX | If enabled, calls to **glEvalCoord2**, **glEvalMesh2**, and **glEvalPoint2** generate color indexes. See also **glMap2**. |
| GL\_MAP2\_NORMAL | If enabled, calls to [**glEvalCoord2**](https://learn.microsoft.com/windows/win32/opengl/glevalcoord-functions), [**glEvalMesh2**](https://learn.microsoft.com/windows/win32/opengl/glevalmesh-functions), and [**glEvalPoint2**](https://learn.microsoft.com/windows/win32/opengl/glevalpoint) generate normals. See also [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2). |
| GL\_MAP2\_TEXTURE\_COORD\_1 | If enabled, calls to **glEvalCoord2**, **glEvalMesh2**, and **glEvalPoint2** generate *s* texture coordinates. See also **glMap2**. |
| GL\_MAP2\_TEXTURE\_COORD\_2 | If enabled, calls to [**glEvalCoord2**](https://learn.microsoft.com/windows/win32/opengl/glevalcoord-functions), [**glEvalMesh2**](https://learn.microsoft.com/windows/win32/opengl/glevalmesh-functions), and [**glEvalPoint2**](https://learn.microsoft.com/windows/win32/opengl/glevalpoint) generate *s* and *t* texture coordinates. See also [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2). |
| GL\_MAP2\_TEXTURE\_COORD\_3 | If enabled, calls to **glEvalCoord2**, **glEvalMesh2**, and **glEvalPoint2** generate *s*, *t*, and *r* texture coordinates. See also **glMap2**. |
| GL\_MAP2\_TEXTURE\_COORD\_4 | If enabled, calls to [**glEvalCoord2**](https://learn.microsoft.com/windows/win32/opengl/glevalcoord-functions), [**glEvalMesh2**](https://learn.microsoft.com/windows/win32/opengl/glevalmesh-functions), and [**glEvalPoint2**](https://learn.microsoft.com/windows/win32/opengl/glevalpoint) generate *s*, *t*, *r*, and *q* texture coordinates. See also [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2). |
| GL\_MAP2\_VERTEX\_3 | If enabled, calls to **glEvalCoord2**, **glEvalMesh2**, and **glEvalPoint2** generate *x*, *y*, and *z* vertex coordinates. See also **glMap2**. |
| GL\_MAP2\_VERTEX\_4 | If enabled, calls to [**glEvalCoord2**](https://learn.microsoft.com/windows/win32/opengl/glevalcoord-functions), [**glEvalMesh2**](https://learn.microsoft.com/windows/win32/opengl/glevalmesh-functions), and [**glEvalPoint2**](https://learn.microsoft.com/windows/win32/opengl/glevalpoint) generate homogeneous *x*, *y*, *z*, and *w* vertex coordinates. See also [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2). |
| GL\_NORMALIZE | If enabled, normal vectors specified with **glNormal** are scaled to unit length after transformation. See [**glNormal**](https://learn.microsoft.com/windows/win32/opengl/glnormal-functions). |
| GL\_POINT\_SMOOTH | If enabled, draw points with proper filtering. If disabled, draw aliased points. See [**glPointSize**](https://learn.microsoft.com/windows/win32/opengl/glpointsize). |
| GL\_POLYGON\_OFFSET\_FILL | If enabled, and if the polygon is rendered in GL\_FILL mode, an offset is added to depth values of a polygon's fragments before the depth comparison is performed. See [**glPolygonOffset**](https://learn.microsoft.com/windows/win32/opengl/glpolygonoffset)**.** |
| GL\_POLYGON\_OFFSET\_LINE | If enabled, and if the polygon is rendered in GL\_LINE mode, an offset is added to depth values of a polygon's fragments before the depth comparison is performed. See **glPolygonOffset**. |
| GL\_POLYGON\_OFFSET\_POINT | If enabled, an offset is added to depth values of a polygon's fragments before the depth comparison is performed, if the polygon is rendered in GL\_POINT mode. See [**glPolygonOffset**](https://learn.microsoft.com/windows/win32/opengl/glpolygonoffset). |
| GL\_POLYGON\_SMOOTH | If enabled, draw polygons with proper filtering. If disabled, draw aliased polygons. See [**glPolygonMode**](https://learn.microsoft.com/windows/win32/opengl/glpolygonmode). |
| GL\_POLYGON\_STIPPLE | If enabled, use the current polygon stipple pattern when rendering polygons. See [**glPolygonStipple**](https://learn.microsoft.com/windows/win32/opengl/glpolygonstipple). |
| GL\_SCISSOR\_TEST | If enabled, discard fragments that are outside the scissor rectangle. See [**glScissor**](https://learn.microsoft.com/windows/win32/opengl/glscissor). |
| GL\_STENCIL\_TEST | If enabled, do stencil testing and update the stencil buffer. See [**glStencilFunc**](https://learn.microsoft.com/windows/win32/opengl/glstencilfunc) and [**glStencilOp**](https://learn.microsoft.com/windows/win32/opengl/glstencilop). |
| GL\_TEXTURE\_1D | If enabled, one-dimensional texturing is performed (unless two-dimensional texturing is also enabled). See [**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d). |
| GL\_TEXTURE\_2D | If enabled, two-dimensional texturing is performed. See [**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d). |
| GL\_TEXTURE\_GEN\_Q | If enabled, the *q* texture coordinate is computed using the texture-generation function defined with [**glTexGen**](https://learn.microsoft.com/windows/win32/opengl/gltexgen-functions). Otherwise, the current *q* texture coordinate is used. |
| GL\_TEXTURE\_GEN\_R | If enabled, the *r* texture coordinate is computed using the texture generation function defined with [**glTexGen**](https://learn.microsoft.com/windows/win32/opengl/gltexgen-functions). If disabled, the current *r* texture coordinate is used. |
| GL\_TEXTURE\_GEN\_S | If enabled, the *s* texture coordinate is computed using the texture generation function defined with **glTexGen**. If disabled, the current *s* texture coordinate is used. |
| GL\_TEXTURE\_GEN\_T | If enabled, the *t* texture coordinate is computed using the texture generation function defined with [**glTexGen**](https://learn.microsoft.com/windows/win32/opengl/gltexgen-functions). If disabled, the current *t* texture coordinate is used. |

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

[**glArrayElement**](https://learn.microsoft.com/windows/win32/opengl/glarrayelement)

[**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin)

[**glBlendFunc**](https://learn.microsoft.com/windows/win32/opengl/glblendfunc)

[**glClipPlane**](https://learn.microsoft.com/windows/win32/opengl/glclipplane)

[**glColorMaterial**](https://learn.microsoft.com/windows/win32/opengl/glcolormaterial)

[**glColorPointer**](https://learn.microsoft.com/windows/win32/opengl/glcolorpointer)

[**glCullFace**](https://learn.microsoft.com/windows/win32/opengl/glcullface)

[**glDepthFunc**](https://learn.microsoft.com/windows/win32/opengl/gldepthfunc)

[**glDepthRange**](https://learn.microsoft.com/windows/win32/opengl/gldepthrange)

[**glDrawArrays**](https://learn.microsoft.com/windows/win32/opengl/gldrawarrays)

[**glEdgeFlagPointer**](https://learn.microsoft.com/windows/win32/opengl/gledgeflagpointer)

[**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glEvalCoord1**](https://learn.microsoft.com/windows/win32/opengl/glevalcoord-functions)

[**glEvalMesh1**](https://learn.microsoft.com/windows/win32/opengl/glevalmesh-functions)

[**glEvalPoint1**](https://learn.microsoft.com/windows/win32/opengl/glevalpoint)

[**glFog**](https://learn.microsoft.com/windows/win32/opengl/glfog)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glIndexPointer**](https://learn.microsoft.com/windows/win32/opengl/glindexpointer)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled)

[**glLight**](https://learn.microsoft.com/windows/win32/opengl/gllight-functions)

[**glLightModel**](https://learn.microsoft.com/windows/win32/opengl/gllightmodel-functions)

[**glLineWidth**](https://learn.microsoft.com/windows/win32/opengl/gllinewidth)

[**glLineStipple**](https://learn.microsoft.com/windows/win32/opengl/gllinestipple)

[**glLogicOp**](https://learn.microsoft.com/windows/win32/opengl/gllogicop)

[**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1)

[**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2)

[**glMaterial**](https://learn.microsoft.com/windows/win32/opengl/glmaterial-functions)

[**glNormal**](https://learn.microsoft.com/windows/win32/opengl/glnormal-functions)

[**glNormalPointer**](https://learn.microsoft.com/windows/win32/opengl/glnormalpointer)

[**glPointSize**](https://learn.microsoft.com/windows/win32/opengl/glpointsize)

[**glPolygonMode**](https://learn.microsoft.com/windows/win32/opengl/glpolygonmode)

[**glPolygonStipple**](https://learn.microsoft.com/windows/win32/opengl/glpolygonstipple)

[**glScissor**](https://learn.microsoft.com/windows/win32/opengl/glscissor)

[**glStencilFunc**](https://learn.microsoft.com/windows/win32/opengl/glstencilfunc)

[**glStencilOp**](https://learn.microsoft.com/windows/win32/opengl/glstencilop)

[**glTexCoordPointer**](https://learn.microsoft.com/windows/win32/opengl/gltexcoordpointer)

[**glTexGen**](https://learn.microsoft.com/windows/win32/opengl/gltexgen-functions)

[**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d)

[**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d)

