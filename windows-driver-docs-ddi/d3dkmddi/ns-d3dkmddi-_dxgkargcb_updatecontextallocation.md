# DXGKARGCB_UPDATECONTEXTALLOCATION structure

## Description

**DXGKARGCB_UPDATECONTEXTALLOCATION** contains the arguments used by the [**DXGKCB_UPDATECONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_updatecontextallocation) callback function, to update the contents of a context allocation.

## Members

### `hAllocation` [in]

Handle to the context allocation being updated. The allocation defines a physical adapter in a linked display adapter link.

### `pPrivateDriverData` [in]

Pointer to a private driver data buffer to be passed to the [**DXGKCB_UPDATECONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_updatecontextallocation) paging operation.

### `PrivateDriverDataSize` [in]

The size of the driver private data, in bytes.

## See also

[**DXGKCB_UPDATECONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_updatecontextallocation)