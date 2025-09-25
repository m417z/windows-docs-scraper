## Description

The **DXGKARG_QUERYDIRTYBITDATAFLAGS** enumeration specifies flags for a call to [**DxgkDdiQueryDirtyBitData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_querydirtybitdata).

## Constants

### `DXGKARG_QUERYDIRTYBITDATAFLAGS_CLEARDATA:1`

Indicates that the driver should atomically clear the bitplane data during the request. Otherwise, the driver should return a copy of the data without clearing it.

## Remarks

For more information, see [Dirty bit tracking](https://learn.microsoft.com/windows-hardware/drivers/display/dirty-bit-tracking).

## See also

[**DXGKARG_QUERYDIRTYBITDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_querydirtybitdata)

[**DxgkDdiQueryDirtyBitData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_querydirtybitdata)