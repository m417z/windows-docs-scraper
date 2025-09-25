# _VP_SCATTER_GATHER_LIST structure

## Description

The VP_SCATTER_GATHER_LIST structure is a collection of one or more scatter/gather elements.

## Members

### `NumberOfElements`

Specifies the number of scatter/gather elements in the **Elements** array member.

### `Reserved`

Reserved for system use.

### `Elements`

Specifies the number of scatter/gather elements in the **Elements** array member.

## Remarks

This structure is available in Windows XP and later.

The video port driver aggregates scatter/gather information in a VP_SCATTER_GATHER_LIST structure, passing it to the miniport driver's [HwVidExecuteDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pexecute_dma) callback routine. The miniport driver uses this information when it sets up the video hardware for a DMA transfer.

## See also

[HwVidExecuteDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pexecute_dma)

[VP_SCATTER_GATHER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_vp_scatter_gather_element)