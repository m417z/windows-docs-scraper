# PFND3DDDI_DRAWPRIMITIVE callback function

## Description

The **DrawPrimitive** function draws nonindexed primitives in which the Microsoft Direct3D runtime has not transformed the vertex data.

## Parameters

### `hDevice` [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_DRAWPRIMITIVE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_drawprimitive) structure that describes the primitive to draw.

### `unnamedParam3`

*pFlagBuffer* [in]

A pointer to a 32-bit value that contains triangle-edge flags, which are used only during line-fill mode. The first three bits (0/1/2) of the 32-bit value specify how the three edges of the corresponding triangles are rendered. If a bit is set to 1, its associated triangle edge is rendered; otherwise, the edge is not rendered.

If the pointer is **NULL**, the user-mode display driver should use its fast path to draw primitives.

## Return value

**DrawPrimitive** returns S_OK or an appropriate error result if the primitive is not successfully drawn.

## Remarks

When the Microsoft Direct3D runtime specifies triangle-edge flags in the value that the *pFlagBuffer* parameter points to, the runtime also specifies to draw one or more triangles (that is, the runtime specifies the D3DPT_TRIANGLEFAN value in the **PrimitiveType** member and from 0x00000001 to 0xFFFFFFFF in the **PrimitiveCount** member of the [D3DDDIARG_DRAWPRIMITIVE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_drawprimitive) structure that the *pData* parameter points to).

## See also

[D3DDDIARG_DRAWPRIMITIVE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_drawprimitive)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)