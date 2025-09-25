# _D3DDDIARG_DRAWPRIMITIVE structure

## Description

The D3DDDIARG_DRAWPRIMITIVE structure describes a nonindexed primitive to draw.

## Members

### `PrimitiveType` [in]

A D3DPRIMITIVETYPE-typed value that indicates the type of primitive to draw. This member can be one of the following values: D3DPT_POINTLIST, D3DPT_LINELIST, D3DPT_LINESTRIP, D3DPT_TRIANGLELIST, D3DPT_TRIANGLESTRIP, or D3DPT_TRIANGLEFAN. For more information about D3DPRIMITIVETYPE, see the Microsoft Windows SDK documentation.

### `VStart` [in]

The index (into each active vertex stream) of the vertex elements to start drawing with. Vertex data should be read from the current vertex streams (those that are referenced by the current vertex shader).

### `PrimitiveCount` [in]

The number of triangles, lines, or points to draw for the given primitive.

## Remarks

The Microsoft Direct3D runtime does not transform the vertex data before passing a pointer to the description of the vertex data in the *pData* parameter in a call to the user-mode display driver's [DrawPrimitive](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawprimitive) function.

When the runtime specifies triangle-edge flags in the value that is pointed to by the *pFlagBuffer* parameter in the [DrawPrimitive](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawprimitive) call, the runtime also specifies to draw one or more triangles (that is, the runtime specifies the D3DPT_TRIANGLEFAN value in the **PrimitiveType** member and from 0x00000001 to 0xFFFFFFFF in the **PrimitiveCount** member of D3DDDIARG_DRAWPRIMITIVE that is pointed to by the *pData* parameter in the **DrawPrimitive** call).

## See also

[DrawPrimitive](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawprimitive)