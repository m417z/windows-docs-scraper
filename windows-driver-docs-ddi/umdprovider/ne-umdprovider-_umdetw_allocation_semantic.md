# _UMDETW_ALLOCATION_SEMANTIC enumeration

## Description

Indicates what a memory allocation is used for if the allocation is internal to the user-mode driver.

## Constants

### `UMDETW_ALLOCATION_SEMANTIC_NONE`

The allocation is created for a Direct3D resource.

### `UMDETW_ALLOCATION_SEMANTIC_DMA_BUFFER`

The allocation is used as a DMA buffer.

### `UMDETW_ALLOCATION_SEMANTIC_UPLOAD_STAGING`

The allocation is used as a staging allocation to upload and download data to and from video memory.

### `UMDETW_ALLOCATION_SEMANTIC_DOWNLOAD_STAGING`

The allocation is used exclusively as a staging allocation to download data from video memory.

### `UMDETW_ALLOCATION_SEMANTIC_CONTEXT_SAVE`

The allocation is used as a GPU context save area.

### `UMDETW_ALLOCATION_SEMANTIC_DRIVER_OTHER_MIN`

The driver can use this semantic value for its own internal purposes.

### `UMDETW_ALLOCATION_SEMANTIC_DRIVER_OTHER_MAX`

The driver can use this semantic value for its own internal purposes.

## See also

[UMDEtwLogMapAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/umdprovider/nf-umdprovider-umdetwlogmapallocation)

[UMDEtwLogUnmapAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/umdprovider/nf-umdprovider-umdetwlogunmapallocation)