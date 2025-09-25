# _D3DDDIARG_SETINDICES structure

## Description

The D3DDDIARG_SETINDICES structure describes parameters for setting the current index buffer.

## Members

### `hIndexBuffer` [in]

A handle to the surface that is associated with the index buffer.

### `Stride` [in]

The size, in bytes, of the indices that are contained in the index buffer. The value of this member is 2 if the indices are 16-bit quantities or 4 if the indices are 32-bit quantities.

## See also

[SetIndices](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setindices)

[SetStreamSourceUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setstreamsourceum)