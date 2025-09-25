## Description

**DXGKARG_QUERYDIRTYBITDATA** is an input/output parameter for [**DxgkDdiQueryDirtyBitData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_querydirtybitdata) to use to query dirty bitplane data.

## Members

### `MemoryBasis`

[in] Handle to the collection of ranges of physical memory pages to query the modified status of. This handle was previously created by a call to [**DxgkDdiCreateMemoryBasis**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_creatememorybasis).

### `SubrangeIndex`

[in] If a subrange is indicated (see SubrangeSize below), then this data represents which range in the memory basis to query from.

### `SubrangeOffset`

[in] If **SubrangeSize** isn't 0, then **SubrangeOffset** represents an optional offset into the subrange chosen from which to query the current dirty bitplane. This value is an offset in bytes and is always a multiple of the bitplane page size.

### `SubrangeSize`

[in] Specifies the range of the memory basis to query. When **SubrangeSize** is 0, the driver should query the entire memory basis. When a non-zero size is specified, the driver should query a single range of the memory basis, where **SubrangeIndex** and **SubrangeOffset** provide the starting index of the physical interval to query. **SubrangeSize** is in bytes and is always a multiple of the bitplane page size.

### `Buffer`

[out] A buffer in which to write the resulting bitplane data.

### `BufferSize`

[out] The size of the bit plane buffer, in bytes. The size is guaranteed to be large enough to fit one bit per page within the specified subrange, which is at least ```Size/DXGK_DIRTY_BIT_TRACKING_SEGMENT_CAPS::PageSize/8``` (rounded up) bytes. If a single subrange is queried, **BufferSize** represents **SubrangeSize**, whereas if the entire memory basis is referenced, **BufferSize** is the sum of all **SizeInBytes** of the ranges in the basis.

### `Flags`

[in] One or more [**DXGKARG_QUERYDIRTYBITDATAFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-dxgkarg_querydirtybitdataflags) values specifying additional behavior for the call.

## Remarks

For more information, see [Dirty bit tracking](https://learn.microsoft.com/windows-hardware/drivers/display/dirty-bit-tracking).

## See also

[**DXGKARG_QUERYDIRTYBITDATAFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-dxgkarg_querydirtybitdataflags)

[**DxgkDdiCreateMemoryBasis**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_creatememorybasis)

[**DxgkDdiQueryDirtyBitData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_querydirtybitdata)