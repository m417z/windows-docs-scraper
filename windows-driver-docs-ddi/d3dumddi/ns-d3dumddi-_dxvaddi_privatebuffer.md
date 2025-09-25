# _DXVADDI_PRIVATEBUFFER structure

## Description

The DXVADDI_PRIVATEBUFFER structure describes a private buffer that a nonstandard decoder uses to perform a decode operation.

## Members

### `hResource` [in]

A handle to the resource that contains the private buffer for the decode operation.

### `SubResourceIndex` [in]

The index to the private buffer within the resource.

### `DataOffset` [in]

The offset to the relevant data, in bytes, from the beginning of the buffer.

### `DataSize` [in]

The size of the relevant data, in bytes.

## See also

[D3DDDIARG_DECODEEXTENSIONEXECUTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_decodeextensionexecute)