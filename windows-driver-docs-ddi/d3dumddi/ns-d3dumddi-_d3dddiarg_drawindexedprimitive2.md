# _D3DDDIARG_DRAWINDEXEDPRIMITIVE2 structure

## Description

The D3DDDIARG_DRAWINDEXEDPRIMITIVE2 structure describes an indexed primitive to draw.

## Members

### `PrimitiveType` [in]

A D3DPRIMITIVETYPE-typed value that indicates the type of primitive to draw. This member can be one of the following values: D3DPT_POINTLIST, D3DPT_LINELIST, D3DPT_LINESTRIP, D3DPT_TRIANGLELIST, D3DPT_TRIANGLESTRIP, or D3DPT_TRIANGLEFAN. For more information about D3DPRIMITIVETYPE, see the Microsoft Windows SDK documentation.

### `BaseVertexOffset` [in]

The offset that should be added to each vertex in vertex stream 0 by the various primitives to determine the actual vertex in vertex stream 0. This offset could be negative, but when an index is added to the offset, the result is positive.

### `MinIndex` [in]

The minimum index of a range of vertices that are potentially accessed by the primitives to be drawn and, therefore, which vertices should be processed.

### `NumVertices` [in]

The number of vertices in a range that are potentially accessed by the primitives to be drawn and, therefore, which vertices should be processed.

### `StartIndexOffset` [in]

The offset of the first index in the index buffer from which indices are read to draw the primitives.

### `PrimitiveCount` [in]

The number of triangles, lines, or points to draw for the given primitive.

## Remarks

The Microsoft Direct3D runtime transforms the index data before passing a pointer to the description of the index data in the *pData* parameter in a call to the user-mode display driver's [DrawIndexedPrimitive2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawindexedprimitive2) function.

When the runtime specifies triangle-edge flags in the value that is pointed to by the *pFlagBuffer* parameter in the [DrawIndexedPrimitive2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawindexedprimitive2) call, the runtime also specifies to draw only one triangle (that is, the runtime specifies the D3DPT_TRIANGLELIST value in the **PrimitiveType** member and 0x00000001 in the **PrimitiveCount** member of D3DDDIARG_DRAWINDEXEDPRIMITIVE2 that is pointed to by the *pData* parameter in the **DrawIndexedPrimitive2** call).

## See also

[DrawIndexedPrimitive2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawindexedprimitive2)