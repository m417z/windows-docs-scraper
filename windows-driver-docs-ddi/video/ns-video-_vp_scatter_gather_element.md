# _VP_SCATTER_GATHER_ELEMENT structure

## Description

The VP_SCATTER_GATHER_ELEMENT structure is used to store information about a single scatter/gather element.

## Members

### `Address`

Specifies the logical address of one scatter/gather element.

### `Length`

Specifies the length, in bytes, of the scatter/gather element.

### `Reserved`

Reserved for system use.

## Remarks

This structure is available in Windows XP and later.

A VP_SCATTER_GATHER_ELEMENT structure is one element of the [VP_SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_vp_scatter_gather_list) structure's array member.

## See also

[VP_SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_vp_scatter_gather_list)