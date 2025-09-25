# _D3DDDICB_QUERYADAPTERINFO structure

## Description

The D3DDDICB_QUERYADAPTERINFO structure contains information that describes the graphics adapter.

## Members

### `pPrivateDriverData` [out]

A pointer to a buffer that the display miniport driver can fill with information about the graphics adapter.

### `PrivateDriverDataSize` [in/out]

The size, in bytes, of the buffer that **pPrivateDriverData** points to.

## See also

[pfnQueryAdapterInfoCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb)