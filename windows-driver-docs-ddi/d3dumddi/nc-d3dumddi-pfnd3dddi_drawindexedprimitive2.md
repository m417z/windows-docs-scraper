# PFND3DDDI_DRAWINDEXEDPRIMITIVE2 callback function

## Description

The **DrawIndexedPrimitive2** function draws indexed primitives that the Microsoft Direct3D runtime has transformed the index data in.

## Parameters

### `hDevice` [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_DRAWINDEXEDPRIMITIVE2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_drawindexedprimitive2) structure that describes the primitive to draw.

### `unnamedParam3`

*dwIndicesSize* [in]

The size, in bytes, of indexes in the buffer that *pIndexBuffer* points to. This size is 2 or 4 bytes.

### `unnamedParam4`

*pIndexBuffer* [in]

A pointer to a buffer of index data to be drawn.

### `unnamedParam5`

*pFlagBuffer* [in, optional]

A pointer to a 32-bit value that contains triangle-edge flags, which are used only during line-fill mode. The first three bits (0/1/2) of the 32-bit value specify how the three edges of the corresponding triangle are rendered. If a bit is set to 1, its associated triangle edge is rendered; otherwise, the edge is not rendered.

If the pointer is **NULL**, the user-mode display driver should use its fast path to draw primitives.

## Return value

**DrawIndexedPrimitive2** returns S_OK or an appropriate error result if the primitive is not successfully drawn.

## Remarks

Stream zero contains transform indices and is the only stream that should be accessed.

When the Microsoft Direct3D runtime specifies triangle-edge flags in the value that the *pFlagBuffer* parameter points to, the runtime also specifies to draw only one triangle (that is, the runtime specifies the D3DPT_TRIANGLELIST value in the **PrimitiveType** member and 0x00000001 in the **PrimitiveCount** member of the [D3DDDIARG_DRAWINDEXEDPRIMITIVE2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_drawindexedprimitive2) structure that the *pData* parameter points to).

## See also

[D3DDDIARG_DRAWINDEXEDPRIMITIVE2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_drawindexedprimitive2)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[DrawIndexedPrimitive](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawindexedprimitive)