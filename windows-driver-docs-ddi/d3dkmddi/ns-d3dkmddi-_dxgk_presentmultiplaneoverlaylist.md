# _DXGK_PRESENTMULTIPLANEOVERLAYLIST structure

## Description

Specifies an overlay plane to display in a call to the [DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present) function.

## Members

### `LayerIndex`

The zero-based index of the overlay plane to display. The top plane (in the z-direction) has index zero. The planes' index values must be sequential from top to bottom.

### `Enabled`

Indicates whether the overlay plane specified by **LayerIndex** is enabled for display.

### `hDeviceSpecificAllocation`

A handle to the device-specific allocation that corresponds to the non device-specific allocation. The display miniport driver must set **hDeviceSpecificAllocation** to a handle value that it can use to refer to its private tracking structure for the allocation.

### `SegmentId` [in]

The identifier of a segment that data is read from.

### `Reserved`

This member is reserved and should be set to zero.

### `PhysicalAddress` [in]

A **PHYSICAL_ADDRESS** data type (which is defined as **LARGE_INTEGER**) that indicates the physical address, within the segment that **SegmentId** specifies, where the data is read.

## See also

[DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present)