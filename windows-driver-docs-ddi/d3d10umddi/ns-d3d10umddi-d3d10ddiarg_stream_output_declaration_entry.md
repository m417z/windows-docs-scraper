# D3D10DDIARG_STREAM_OUTPUT_DECLARATION_ENTRY structure

## Description

The D3D10DDIARG_STREAM_OUTPUT_DECLARATION_ENTRY structure describes a portion of the stream output for a geometry shader.

## Members

### `OutputSlot` [in]

The number of the slot for the portion of the stream output.

### `RegisterIndex` [in]

The number of the register for the portion of the stream output.

### `RegisterMask` [in]

The xyzw register mask for the portion of the stream output. That is, the four least significant bits (LSBs) of the mask represent xyzw respectively.

## See also

[D3D10DDIARG_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_creategeometryshaderwithstreamoutput)