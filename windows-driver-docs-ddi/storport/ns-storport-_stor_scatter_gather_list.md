# _STOR_SCATTER_GATHER_LIST structure

## Description

The STOR_SCATTER_GATHER_LIST structure is used in conjunction with the [StorPortGetScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetscattergatherlist) routine to retrieve the scatter/gather list for a SCSI request block (SRB).

## Members

### `NumberOfElements`

Contains the number of scatter/gather elements in the list.

### `Reserved`

Reserved.

### `List`

Contains the array of scatter/gather elements.

## Remarks

Miniport drivers that work with the Storport driver call the Storport support routine, [StorPortGetScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetscattergatherlist), to retrieve the scatter gather list for an SRB. **StorPortGetScatterGatherList** returns a structure of type STOR_SCATTER_GATHER_LIST. Each scatter/gather element is of type [STOR_SCATTER_GATHER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_scatter_gather_element).

## See also

[STOR_SCATTER_GATHER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_scatter_gather_element)

[StorPortGetScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetscattergatherlist)