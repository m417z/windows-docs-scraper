# _D3DDDIARG_DRAWPRIMITIVE2 structure

## Description

The D3DDDIARG_DRAWPRIMITIVE2 structure describes a nonindexed primitive to draw.

## Members

### `PrimitiveType` [in]

A D3DPRIMITIVETYPE-typed value that indicates the type of primitive to draw. This member can be one of the following values: D3DPT_POINTLIST, D3DPT_LINELIST, D3DPT_LINESTRIP, D3DPT_TRIANGLELIST, D3DPT_TRIANGLESTRIP, or D3DPT_TRIANGLEFAN. For more information about D3DPRIMITIVETYPE, see the Microsoft Windows SDK documentation.

### `FirstVertexOffset` [in]

The offset, in bytes, in stream zero of the vertex data. This member differs from the **VStart** member of the [D3DDDIARG_DRAWPRIMITIVE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_drawprimitive) structure that is used with the [DrawPrimitive](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawprimitive) function. In **VStart**, the start of the vertex data in the vertex stream is specified by a vertex index rather than an actual byte offset.

### `PrimitiveCount` [in]

The number of triangles, lines, or points to draw for the given primitive.

## Remarks

The Microsoft Direct3D runtime transforms the vertex data before passing a pointer to the description of the vertex data in the *pData* parameter in a call to the user-mode display driver's [DrawPrimitive2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawprimitive2) function.

## See also

[D3DDDIARG_DRAWPRIMITIVE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_drawprimitive)

[DrawPrimitive2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawprimitive2)