# D3D11DDIARG_STREAM_OUTPUT_DECLARATION_ENTRY structure

## Description

The D3D11DDIARG_STREAM_OUTPUT_DECLARATION_ENTRY structure describes a portion of the stream output for a geometry shader.

## Members

### `Stream` [in]

The stream to output from, which is a value between zero and the maximum number of streams that are specified by the driver.

### `OutputSlot` [in]

The number of the slot for the portion of the stream output.

### `RegisterIndex` [in]

The number of the register for the portion of the stream output.

### `RegisterMask` [in]

The xyzw register mask for the portion of the stream output. That is, the four least significant bits (LSBs) of the mask represent xyzw respectively.