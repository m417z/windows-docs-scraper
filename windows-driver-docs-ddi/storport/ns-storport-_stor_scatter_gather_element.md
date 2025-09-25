# _STOR_SCATTER_GATHER_ELEMENT structure

## Description

The STOR_SCATTER_GATHER_ELEMENT structure is used with [STOR_SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_scatter_gather_list) to build a list of scatter/gather elements.

## Members

### `PhysicalAddress`

Contains the physical address of the scatter/gather element.

### `Length`

Contains the length in bytes of this scatter/gather element.

### `Reserved`

Reserved.

## Remarks

Miniport drivers used with the Storport driver retrieve an array of these structures using [StorPortGetScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetscattergatherlist).

## See also

[STOR_SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_scatter_gather_list)

[StorPortGetScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetscattergatherlist)