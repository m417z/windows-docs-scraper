## Description

The **DXGKARG_CREATEMEMORYBASIS** structure is an input parameter for [**DxgkDdiCreateMemoryBasis**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_creatememorybasis) to use to create a memory basis.

## Members

### `SegmentId`

[in] The driver's segment ID.

### `RangeCount`

[in] The number of ranges that this memory basis includes; that is, the number of ranges in **Ranges**'s array.

### `Ranges[1]`

Array of [**DXGK_MEMORYRANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_memoryrange) structures that describe the details for each range of the basis, including **SegmentOffset** and **SizeInBytes**.

## Remarks

For more information, see [Dirty bit tracking](https://learn.microsoft.com/windows-hardware/drivers/display/dirty-bit-tracking).

## See also

[**DxgkDdiCreateMemoryBasis**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_creatememorybasis)