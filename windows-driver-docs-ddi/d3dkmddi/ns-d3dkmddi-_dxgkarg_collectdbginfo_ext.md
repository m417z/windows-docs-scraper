# _DXGKARG_COLLECTDBGINFO_EXT structure

## Description

The DXGKARG_COLLECTDBGINFO_EXT structure describes extension information for a debug report.

## Members

### `BucketingKey` [out]

The optional integer key for Microsoft Online Crash Analysis (OCA) bucketing (that is, the categorizing of minidumps).

### `CurrentDmaBufferOffset` [out]

The optional execution offset into the current DMA buffer. The operating system uses the offset to optimize DMA data collection.

### `Reserved2`

Reserved for future use.

### `Reserved3`

Reserved for future use.

### `Reserved4`

Reserved for future use.

### `Reserved5`

Reserved for future use.

### `Reserved6`

Reserved for future use.

### `Reserved7`

Reserved for future use.

## See also

[DXGKARG_COLLECTDBGINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_collectdbginfo)

[DxgkDdiCollectDbgInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_collectdbginfo)