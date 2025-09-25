# _D3DDDICB_FREEGPUVIRTUALADDRESS structure

## Description

**D3DDDICB_FREEGPUVIRTUALADDRESS** is used with [pfnFreeGpuVirtualAddressCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_freegpuvirtualaddresscb) to release a range of graphics processing unit (GPU) virtual addresses that were previously reserved or mapped.

## Members

### `BaseAddress`

Specifies the base virtual address, in bytes, of the range to free. Must be aligned to 4 KB.

### `Size`

Specifies the size, in bytes, of the range to free. Must be aligned to 4 KB.

## See also

[pfnFreeGpuVirtualAddressCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_freegpuvirtualaddresscb)