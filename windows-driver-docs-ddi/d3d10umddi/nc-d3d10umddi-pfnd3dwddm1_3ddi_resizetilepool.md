# PFND3DWDDM1_3DDI_RESIZETILEPOOL callback function

## Description

Resizes a tile pool.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `hTilePool`

A handle to the tile pool to resize.

### `NewSizeInBytes`

The new size, in bytes, of the tile pool. The size must be a multiple of 64 KB or zero.

## Remarks

The driver can use the [**pfnSetErrorCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code, setting S_OK if successful; otherwise, returning one of the following:

|Return code|Description|
|--- |--- |
|E_INVALIDARG|The new tile pool size isn't a multiple of 64 KB or zero. The existing tile pool remains unchanged, which includes existing mappings.|
|E_OUTOFMEMORY|The driver had to allocate space for new page table mappings but ran out of memory. The existing tile pool remains unchanged, which includes existing mappings.|

The Direct3D runtime performs minimal validation of parameters, but it will fail the call if the new tile pool size isn't a multiple of the tile size, or zero.