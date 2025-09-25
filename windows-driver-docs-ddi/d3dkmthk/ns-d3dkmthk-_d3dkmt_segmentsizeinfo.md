# _D3DKMT_SEGMENTSIZEINFO structure

## Description

The D3DKMT_SEGMENTSIZEINFO structure describes the size, in bytes, of memory and aperture segments.

## Members

### `DedicatedVideoMemorySize` [out]

The size, in bytes, of memory that is dedicated from video memory.

### `DedicatedSystemMemorySize` [out]

The size, in bytes, of memory that is dedicated from system memory.

### `SharedSystemMemorySize` [out]

The size, in bytes, of memory from system memory that can be shared by many users.

## See also

[D3DKMTQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo)

[D3DKMT_QUERYADAPTERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryadapterinfo)