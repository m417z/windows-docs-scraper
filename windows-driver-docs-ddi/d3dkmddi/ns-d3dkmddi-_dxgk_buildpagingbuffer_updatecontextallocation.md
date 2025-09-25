# _DXGK_BUILDPAGINGBUFFER_UPDATECONTEXTALLOCATION structure

## Description

**DXGK_BUILDPAGINGBUFFER_UPDATECONTEXTALLOCATION** describes an operation used to update the content of a context or device allocation.

## Members

### `ContextAllocation`

A GPU virtual address in the paging process scratch area for the context allocation being updated.

### `ContextAllocationSize`

The size of the context allocation.

### `pDriverPrivateData`

A pointer to the driver-private data that was passed in the call to [DxgkCbUpdateContextAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_updatecontextallocation).

### `DriverPrivateDataSize`

The size of the driver-private data.

## See also

[DXGKARG_BUILDPAGINGBUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_buildpagingbuffer)

[DxgkCbUpdateContextAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_updatecontextallocation)