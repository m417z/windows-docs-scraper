# _DXGK_DISCARDCONTENTFLAGS structure

## Description

The DXGK_DISCARDCONTENTFLAGS structure identifies the type of discard-content operation to set up in a call to the [DxgkDdiBuildPagingBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer) function.

## Members

### `AllocationIsIdle` [in]

A UINT value that specifies whether the allocation that is referenced in the call to [DxgkDdiBuildPagingBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer) is idle. If this member is not set, the driver should determine that the allocation is either currently busy or might become busy. If this member is set, the video memory manager guarantees that the allocation remains idle for the duration of the call to *DxgkDdiBuildPagingBuffer*.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Reserved` [in]

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 31 bits (0xFFFFFFFE) of the 32-bit **Value** member to zeros.

### `Value` [in]

A member in the union that DXGK_DISCARDCONTENTFLAGS contains that can hold a 32-bit value that identifies the discard-content-operation type.

## See also

[DXGKARG_BUILDPAGINGBUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_buildpagingbuffer)

[DxgkDdiBuildPagingBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer)