# glIsEnabled function

The **gllsEnabled** function tests whether a capability is enabled.

## Parameters

*cap*

A symbolic constant indicating an OpenGL capability. The following capabilities are accepted.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_ALPHA\_TEST** | See [**glAlphaFunc**](https://learn.microsoft.com/windows/win32/opengl/glalphafunc)<br> |
| **GL\_AUTO\_NORMAL** | See [**glEvalCoord**](https://learn.microsoft.com/windows/win32/opengl/glevalcoord-functions)<br> |
| **GL\_BLEND** | See [**glBlendFunc**](https://learn.microsoft.com/windows/win32/opengl/glblendfunc)<br> |
| **GL\_CLIP\_PLANE *i*** | See [**glClipPlane**](https://learn.microsoft.com/windows/win32/opengl/glclipplane)<br> |
| **GL\_COLOR\_ARRAY** | See [**glColorPointer**](https://learn.microsoft.com/windows/win32/opengl/glcolorpointer)<br> |
| **GL\_COLOR\_LOGIC\_OP** | See [**glLogicOp**](https://learn.microsoft.com/windows/win32/opengl/gllogicop)<br> |
| **GL\_COLOR\_MATERIAL** | See [**glColorMaterial**](https://learn.microsoft.com/windows/win32/opengl/glcolormaterial)<br> |
| **GL\_CULL\_FACE** | See [**glCullFace**](https://learn.microsoft.com/windows/win32/opengl/glcullface)<br> |
| **GL\_DEPTH\_TEST** | See [**glDepthFunc**](https://learn.microsoft.com/windows/win32/opengl/gldepthfunc) and [**glDepthRange**](https://learn.microsoft.com/windows/win32/opengl/gldepthrange)<br> |
| **GL\_DITHER** | See [**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable)<br> |
| **GL\_FOG** | See [**glFog**](https://learn.microsoft.com/windows/win32/opengl/glfog)<br> |
| **GL\_INDEX\_ARRAY** | See [**glIndexPointer**](https://learn.microsoft.com/windows/win32/opengl/glindexpointer)<br> |
| **GL\_INDEX\_LOGIC\_OP** | See [**glLogicOp**](https://learn.microsoft.com/windows/win32/opengl/gllogicop)<br> |
| **GL\_LIGHT *i*** | See [**glLightModel**](https://learn.microsoft.com/windows/win32/opengl/gllightmodel-functions) and [**glLight**](https://learn.microsoft.com/windows/win32/opengl/gllight-functions)<br> |
| **GL\_LIGHTING** | See [**glMaterial**](https://learn.microsoft.com/windows/win32/opengl/glmaterial-functions), [**glLightModel**](https://learn.microsoft.com/windows/win32/opengl/gllightmodel-functions), and [**glLight**](https://learn.microsoft.com/windows/win32/opengl/gllight-functions)<br> |
| **GL\_LINE\_SMOOTH** | See [**glLineWidth**](https://learn.microsoft.com/windows/win32/opengl/gllinewidth)<br> |
| **GL\_LINE\_STIPPLE** | See [**glLineStipple**](https://learn.microsoft.com/windows/win32/opengl/gllinestipple)<br> |
| **GL\_MAP1\_COLOR\_4** | See [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1)<br> |
| **GL\_MAP1\_INDEX** | See [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1)<br> |
| **GL\_MAP1\_NORMAL** | See [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1)<br> |
| **GL\_MAP1\_TEXTURE\_COORD\_1** | See [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1)<br> |
| **GL\_MAP1\_TEXTURE\_COORD\_2** | See [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1)<br> |
| **GL\_MAP1\_TEXTURE\_COORD\_3** | See [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1)<br> |
| **GL\_MAP1\_TEXTURE\_COORD\_4** | See [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1)<br> |
| **GL\_MAP1\_VERTEX\_3** | See [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1)<br> |
| **GL\_MAP1\_VERTEX\_4** | See [**glMap1**](https://learn.microsoft.com/windows/win32/opengl/glmap1)<br> |
| **GL\_MAP2\_COLOR\_4** | See [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2)<br> |
| **GL\_MAP2\_INDEX** | See [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2)<br> |
| **GL\_MAP2\_NORMAL** | See [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2)<br> |
| **GL\_MAP2\_TEXTURE\_COORD\_1** | See [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2)<br> |
| **GL\_MAP2\_TEXTURE\_COORD\_2** | See [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2)<br> |
| **GL\_MAP2\_TEXTURE\_COORD\_3** | See [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2)<br> |
| **GL\_MAP2\_TEXTURE\_COORD\_4** | See [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2)<br> |
| **GL\_MAP2\_VERTEX\_3** | See [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2)<br> |
| **GL\_MAP2\_VERTEX\_4** | See [**glMap2**](https://learn.microsoft.com/windows/win32/opengl/glmap2)<br> |
| **GL\_NORMAL\_ARRAY** | See [**glNormalPointer**](https://learn.microsoft.com/windows/win32/opengl/glnormalpointer)<br> |
| **GL\_NORMALIZE** | See [**glNormal**](https://learn.microsoft.com/windows/win32/opengl/glnormal-functions)<br> |
| **GL\_POINT\_SMOOTH** | See [**glPointSize**](https://learn.microsoft.com/windows/win32/opengl/glpointsize)<br> |
| **GL\_POLYGON\_OFFSET\_FILL** | See [**glPolygonOffset**](https://learn.microsoft.com/windows/win32/opengl/glpolygonoffset)<br> |
| **GL\_POLYGON\_OFFSET\_LINE** | See [**glPolygonOffset**](https://learn.microsoft.com/windows/win32/opengl/glpolygonoffset)<br> |
| **GL\_POLYGON\_OFFSET\_POINT** | See [**glPolygonOffset**](https://learn.microsoft.com/windows/win32/opengl/glpolygonoffset)<br> |
| **GL\_POLYGON\_SMOOTH** | See [**glPolygonMode**](https://learn.microsoft.com/windows/win32/opengl/glpolygonmode)<br> |
| **GL\_POLYGON\_STIPPLE** | See [**glPolygonStipple**](https://learn.microsoft.com/windows/win32/opengl/glpolygonstipple)<br> |
| **GL\_SCISSOR\_TEST** | See [**glScissor**](https://learn.microsoft.com/windows/win32/opengl/glscissor)<br> |
| **GL\_STENCIL\_TEST** | See [**glStencilFunc**](https://learn.microsoft.com/windows/win32/opengl/glstencilfunc) and [**glStencilOp**](https://learn.microsoft.com/windows/win32/opengl/glstencilop)<br> |
| **GL\_TEXTURE\_1D** | See [**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d)<br> |
| **GL\_TEXTURE\_2D** | See [**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d)<br> |
| **GL\_TEXTURE\_COORD\_ARRAY** | See [**glTexCoordPointer**](https://learn.microsoft.com/windows/win32/opengl/gltexcoordpointer)<br> |
| **GL\_TEXTURE\_GEN\_Q** | See [**glTexGen**](https://learn.microsoft.com/windows/win32/opengl/gltexgen-functions)<br> |
| **GL\_TEXTURE\_GEN\_R** | See [**glTexGen**](https://learn.microsoft.com/windows/win32/opengl/gltexgen-functions)<br> |
| **GL\_TEXTURE\_GEN\_S** | See [**glTexGen**](https://learn.microsoft.com/windows/win32/opengl/gltexgen-functions)<br> |
| **GL\_TEXTURE\_GEN\_T** | See [**glTexGen**](https://learn.microsoft.com/windows/win32/opengl/gltexgen-functions)<br> |
| **GL\_VERTEX\_ARRAY** | See [**glVertexPointer**](https://learn.microsoft.com/windows/win32/opengl/glvertexpointer)<br> |

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *cap* was not an accepted value.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **gllsEnabled** function returns GL\_TRUE if *cap* is an enabled capability and returns GL\_FALSE otherwise.

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

[**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

