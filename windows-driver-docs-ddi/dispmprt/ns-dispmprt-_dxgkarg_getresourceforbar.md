# _DXGKARG_GETRESOURCEFORBAR structure

## Description

Arguments used to get the host partition base address of a single Virtual Function base address register (BAR).

## Members

### `VirtualFunctionIndex`

Zero-based offset of the Virtual Function from the first VF exposed by this Physical Function.

### `BarIndex`

Index to the bar to retrieve the resource for.

### `pResource`

Out variable that will be filled in with the resource information, specifically the base address. This is a CM_PARTIAL_RESOURCE_DESCRIPTOR. Valid types are CmResourceTypeMemory and CmResourceTypeMemoryLarge.

## Remarks

## See also