# _D3DKMT_FREEGPUVIRTUALADDRESS structure

## Description

**D3DKMT_FREEGPUVIRTUALADDRESS** is used with [FreeGpuVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtfreegpuvirtualaddress) to release a range of graphics processing unit (GPU) virtual addresses that were previously reserved or mapped.

## Members

### `hAdapter`

Specifies the handle to the adapter.

### `BaseAddress`

Specifies the base virtual address, in bytes, of the range to free. Must be aligned to 4 KB.

### `Size`

Specifies the size, in bytes, of the range to free. Must be aligned to 4 KB.

## See also

[FreeGpuVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtfreegpuvirtualaddress)