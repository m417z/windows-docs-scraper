# _D3DHAL_DP2OPERATION enumeration

## Description

The D3DHAL_DP2OPERATION enumerated type specifies the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) operation in the **bCommand** member of the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure. The enumerators of D3DHAL_DP2OPERATION can specify either primitive-rendering or nonprimitive-rendering operations. The enumerators of D3DHAL_DP2OPERATION can also specify that the driver returned responses to previously issued queries.

## Constants

### `D3DDP2OP_POINTS`

Draws a list of indexed or nonindexed points. Each list is specified by one or more [D3DHAL_DP2POINTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2points) structures.

### `D3DDP2OP_INDEXEDLINELIST`

Draws a list of lines, with each line specified by a pair of vertex indexes. The indexed line list is specified by one or more [D3DHAL_DP2INDEXEDLINELIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2indexedlinelist) structures.

### `D3DDP2OP_INDEXEDTRIANGLELIST`

Draws a list of triangles. Each triangle is specified by three indexes into the vertex buffer, one index per triangle vertex. The triangle list is specified by one or more [D3DHAL_DP2INDEXEDTRIANGLELIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2indexedtrianglelist) structures.

### `D3DDP2OP_RENDERSTATE`

Specifies a render state change that requires processing. The rendering state to change is specified by one or more [D3DHAL_DP2RENDERSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2renderstate) structures.

### `D3DDP2OP_LINELIST`

Draws a list of lines. Each line is specified by a pair of vertices. The vertices are processed in sequential order starting at an initial specified vertex index. The line list is specified by a [D3DHAL_DP2LINELIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2linelist) structure.

### `D3DDP2OP_LINESTRIP`

Draws a connected strip of lines defined by a sequence of vertices starting at an initial specified vertex index. The line strip is specified by a [D3DHAL_DP2LINESTRIP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2linestrip) structure.

### `D3DDP2OP_INDEXEDLINESTRIP`

Draws a connected strip of lines defined by a sequence of vertex indexes. Each line in the connected strip is specified by a [D3DHAL_DP2INDEXEDLINESTRIP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2indexedlinestrip) structure.

### `D3DDP2OP_TRIANGLELIST`

Draws a list of triangles. Each triangle is specified by three vertices that are processed starting at an initial specified vertex index. The triangles are processed in sequential order. The triangle list is specified by a [D3DHAL_DP2TRIANGLELIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2trianglelist) structure.

### `D3DDP2OP_TRIANGLESTRIP`

Draws a connected strip of triangles. Each triangle is specified by a sequence of vertices starting at an initial specified vertex index. The three most current vertices are used to draw each triangle. The triangle strip is specified by a [D3DHAL_DP2TRIANGLESTRIP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2trianglestrip) structure.

### `D3DDP2OP_INDEXEDTRIANGLESTRIP`

Draws a connected strip of triangles that are specified by a sequence of vertex indexes. The three most current vertex indexes are used to draw each triangle. Each triangle in the connected strip is specified by a [D3DHAL_DP2INDEXEDTRIANGLESTRIP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2indexedtrianglestrip) structure.

### `D3DDP2OP_TRIANGLEFAN`

Draws a triangle fan. The fan is specified by a sequence of vertices that start at an initial specified vertex index. The triangle fan is specified by a [D3DHAL_DP2TRIANGLEFAN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2trianglefan) structure.

### `D3DDP2OP_INDEXEDTRIANGLEFAN`

Draws a triangle fan. The triangle fan is specified by a sequence of vertex indexes. Each triangle in the fan is specified by a [D3DHAL_DP2INDEXEDTRIANGLEFAN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2indexedtrianglefan) structure.

### `D3DDP2OP_TRIANGLEFAN_IMM`

Draws a triangle fan. The fan is specified by a sequence of vertices stored in the command stream (immediate data). The **wPrimitiveCount** member of the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure specifies the number of triangles to render. The type and size of the vertices are specified by the **dwVertexType** member of the [D3DHAL_DRAWPRIMITIVES2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_drawprimitives2data) structure.

### `D3DDP2OP_LINELIST_IMM`

Draws a set of lines. Each line is specified by a pair of vertices stored in the command stream (immediate data). The **wPrimitiveCount** member of the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure specifies how many pairs of vertices follow. The type and size of the vertices are determined by the **dwVertexType** member of the [D3DHAL_DRAWPRIMITIVES2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_drawprimitives2data) structure.

### `D3DDP2OP_TEXTURESTAGESTATE`

Specifies a texture render state change that requires processing. The render state to change is specified by one or more [D3DHAL_DP2TEXTURESTAGESTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2texturestagestate) structures. The value in the **TSState** member specifies the texture state to be updated.

### `D3DDP2OP_INDEXEDTRIANGLELIST2`

Draws a list of triangles. Each triangle is specified by three indexes into the vertex buffer, one index per triangle vertex. The triangle list is specified by one or more [D3DHAL_DP2INDEXEDTRIANGLELIST2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2indexedtrianglelist2) structures.

### `D3DDP2OP_INDEXEDLINELIST2`

Draws a list of lines. Each line is specified by a pair of vertex indexes, with each offset from the beginning of the vertex buffer by a fixed amount. The indexed line list is specified by one or more [D3DHAL_DP2INDEXEDLINELIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2indexedlinelist) structures.

### `D3DDP2OP_VIEWPORTINFO`

Specifies the clipping rectangle that is used for guard-band clipping by guard-band aware drivers. The clipping rectangle (that is, the viewing rectangle) is specified by the [D3DHAL_DP2VIEWPORTINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2viewportinfo) structure.

### `D3DDP2OP_WINFO`

Specifies the w range for w buffering. This range is specified by one or more [D3DHAL_DP2WINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2winfo) structures.

### `D3DDP2OP_SETPALETTE`

Specifies that the palette is being set for a texture. See [D3DHAL_DP2SETPALETTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2setpalette).

### `D3DDP2OP_UPDATEPALETTE`

Specifies that a texture palette is to be updated. See [D3DHAL_DP2UPDATEPALETTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2updatepalette).

### `D3DDP2OP_ZRANGE`

Specifies the range of z values. See [D3DHAL_DP2ZRANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2zrange).

### `D3DDP2OP_SETMATERIAL`

Sets the properties for a material. D3DHAL_DP2SETMATERIAL is a D3DMATERIAL7 structure (described in the DirectX SDK documentation) that is used to set the material properties.

### `D3DDP2OP_SETLIGHT`

Specifies that a light is being set. See [D3DHAL_DP2SETLIGHT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2setlight).

### `D3DDP2OP_CREATELIGHT`

Creates a light. See [D3DHAL_DP2CREATELIGHT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2createlight).

### `D3DDP2OP_SETTRANSFORM`

Sets up a transform. See [D3DHAL_DP2SETTRANSFORM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2settransform).

### `D3DDP2OP_TEXBLT`

Specifies a blt operation from a source texture to a destination texture. It is used as a more efficient alternative to the DirectDraw [DdBlt](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_surfcb_blt) DDI. It is specified by one or more [D3DHAL_DP2TEXBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2texblt) structures. Because Direct3D drivers maintain all the state necessary to do a blt (for example, texture handles and blending modes), a blt can be accomplished with just the information in the D3DDP2OP_TEXBLT opcode. This new token signals the driver that a texture has to be transferred from system memory into local or nonlocal video memory.

### `D3DDP2OP_STATESET`

Specifies a state-set operation to perform. See [D3DHAL_DP2STATESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2stateset).

### `D3DDP2OP_SETPRIORITY`

Sets the priority of a managed texture. See [D3DHAL_DP2SETPRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2setpriority).

### `D3DDP2OP_SETRENDERTARGET`

Sets the render target. Direct3D drivers must respond to this opcode exactly the same as with the older *SetRenderTarget* callback. See [D3DHAL_DP2SETRENDERTARGET](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2setrendertarget).

### `D3DDP2OP_CLEAR`

Specifies a clear operation. Replaces the *Clear* and *Clear2* callbacks. See [D3DHAL_DP2CLEAR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2clear).

### `D3DDP2OP_SETTEXLOD`

Indicates that the level of detail (LOD) for MIP maps is being set. See [D3DHAL_DP2SETTEXLOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2settexlod).

### `D3DDP2OP_SETCLIPPLANE`

Specifies that a user-defined clip plane is being used. See [D3DHAL_DP2SETCLIPPLANE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2setclipplane).

### `D3DDP2OP_CREATEVERTEXSHADER`

### `D3DDP2OP_DELETEVERTEXSHADER`

### `D3DDP2OP_SETVERTEXSHADER`

### `D3DDP2OP_SETVERTEXSHADERCONST`

### `D3DDP2OP_SETSTREAMSOURCE`

### `D3DDP2OP_SETSTREAMSOURCEUM`

### `D3DDP2OP_SETINDICES`

### `D3DDP2OP_DRAWPRIMITIVE`

### `D3DDP2OP_DRAWINDEXEDPRIMITIVE`

### `D3DDP2OP_CREATEPIXELSHADER`

### `D3DDP2OP_DELETEPIXELSHADER`

### `D3DDP2OP_SETPIXELSHADER`

### `D3DDP2OP_SETPIXELSHADERCONST`

### `D3DDP2OP_CLIPPEDTRIANGLEFAN`

DirectX 8.0 and later versions only.This token is sent to the driver to draw transformed, clipped triangle fans. This token is a replacement for the DirectX 7.0 tokens that used inline vertices in the command stream. The triangle fans are specified by one or more [D3DHAL_CLIPPEDTRIANGLEFAN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_clippedtrianglefan) structures.

### `D3DDP2OP_DRAWPRIMITIVE2`

### `D3DDP2OP_DRAWINDEXEDPRIMITIVE2`

### `D3DDP2OP_DRAWRECTPATCH`

### `D3DDP2OP_DRAWTRIPATCH`

### `D3DDP2OP_VOLUMEBLT`

Supports optimal copying and updating of volume textures. This token is very similar to the existing D3DDP2OP_TEXBLT that copies and updates textures but has been extended to support subvolume (box) copying rather than simple rectangles.

### `D3DDP2OP_BUFFERBLT`

### `D3DDP2OP_MULTIPLYTRANSFORM`

DirectX 8.0 and later versions only. Multiplies a current transform. See [D3DHAL_DP2MULTIPLYTRANSFORM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2multiplytransform).

### `D3DDP2OP_ADDDIRTYRECT`

### `D3DDP2OP_ADDDIRTYBOX`

### `D3DDP2OP_CREATEVERTEXSHADERDECL`

### `D3DDP2OP_DELETEVERTEXSHADERDECL`

### `D3DDP2OP_SETVERTEXSHADERDECL`

### `D3DDP2OP_CREATEVERTEXSHADERFUNC`

### `D3DDP2OP_DELETEVERTEXSHADERFUNC`

### `D3DDP2OP_SETVERTEXSHADERFUNC`

### `D3DDP2OP_SETVERTEXSHADERCONSTI`

### `D3DDP2OP_SETSCISSORRECT`

### `D3DDP2OP_SETSTREAMSOURCE2`

### `D3DDP2OP_BLT`

### `D3DDP2OP_COLORFILL`

### `D3DDP2OP_SETVERTEXSHADERCONSTB`

### `D3DDP2OP_CREATEQUERY`

### `D3DDP2OP_SETRENDERTARGET2`

### `D3DDP2OP_SETDEPTHSTENCIL`

### `D3DDP2OP_RESPONSECONTINUE`

### `D3DDP2OP_RESPONSEQUERY`

### `D3DDP2OP_GENERATEMIPSUBLEVELS`

### `D3DDP2OP_DELETEQUERY`

### `D3DDP2OP_ISSUEQUERY`

### `D3DDP2OP_SETPIXELSHADERCONSTI`

### `D3DDP2OP_SETPIXELSHADERCONSTB`

### `D3DDP2OP_SETSTREAMSOURCEFREQ`

### `D3DDP2OP_SURFACEBLT`

### `D3DDP2OP_SETCONVOLUTIONKERNELMONO`

### `D3DDP2OP_COMPOSERECTS`

## Remarks

Note that because the D3DNTDP2OP_*XXX* enumerators are type defined as D3DDP2OP_*XXX* internally in the *Dx95type.h* file of the Windows Driver Kit (WDK), the shorter form is used here for clarity. Either form is valid on Windows 2000 and later implementations, but only the shorter form can be used on Windows 98/Me.

The D3DNTHAL_DP2OPERATION enumerated type is type defined as the D3DHAL_DP2OPERATION enumerated type in the *Dx95type.h* file. The later (shorter form) enumerated type is used here for clarity. Either form is valid on Windows 2000 and later implementations, but only the shorter form can be used on Windows 98/Me.