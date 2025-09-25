# _DXGK_MAPAPERTUREFLAGS structure

## Description

The DXGK_MAPAPERTUREFLAGS structure identifies the type of map-aperture-segment operation to set up in a call to the [DxgkDdiBuildPagingBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer) function.

## Members

### `CacheCoherent` [in]

A UINT value that specifies whether cache coherency is required for pages that are mapped in a call to [DxgkDdiBuildPagingBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer). If this member is set, the driver must ensure that cache coherency is enforced on the pages that are mapped. If this member is not set, cache coherency is not required for the pages that are mapped.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Reserved` [in]

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 31 bits (0xFFFFFFFE) of the 32-bit **Value** member to zeros.

### `Value` [in]

A member in the union that DXGK_MAPAPERTUREFLAGS contains that can hold a 32-bit value that identifies the type of map-aperture-segment-operation.

## See also

[DXGKARG_BUILDPAGINGBUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_buildpagingbuffer)

[DxgkDdiBuildPagingBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer)