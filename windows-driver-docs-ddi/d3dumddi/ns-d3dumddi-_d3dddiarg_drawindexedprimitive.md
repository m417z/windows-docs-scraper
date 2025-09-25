# _D3DDDIARG_DRAWINDEXEDPRIMITIVE structure

## Description

The D3DDDIARG_DRAWINDEXEDPRIMITIVE structure describes an indexed primitive to draw.

## Members

### `PrimitiveType` [in]

A D3DPRIMITIVETYPE-typed value that indicates the type of primitive to draw. This member can be one of the following values: D3DPT_POINTLIST, D3DPT_LINELIST, D3DPT_LINESTRIP, D3DPT_TRIANGLELIST, D3DPT_TRIANGLESTRIP, or D3DPT_TRIANGLEFAN. For more information about D3DPRIMITIVETYPE, see the Microsoft Windows SDK documentation.

### `BaseVertexIndex` [in]

The number that should be added to each index that is referenced by the various primitives to determine the actual index of the vertex elements in each vertex stream.

### `MinIndex` [in]

The minimum index of a range of vertices that are potentially accessed by the primitives to be drawn and, therefore, which vertices should be processed.

### `NumVertices` [in]

The number of vertices in a range that are potentially accessed by the primitives to be drawn and, therefore, which vertices should be processed.

### `StartIndex` [in]

The first index in the index buffer from which indices are read to draw the primitives.

### `PrimitiveCount` [in]

The number of triangles, lines, or points to draw for the given primitive.

## Remarks

The Microsoft Direct3D runtime does not transform the index data before passing a pointer to the description of the index data in the *pData* parameter in a call to the user-mode display driver's [DrawIndexedPrimitive](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawindexedprimitive) function.

## See also

[DrawIndexedPrimitive](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawindexedprimitive)