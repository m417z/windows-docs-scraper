# DXGK_SYNC_LOCK_STYLE enumeration

## Description

Used in the call to [**DxgkDdiSetTimingsFromVidPn**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_settimingsfromvidpn) to describe the style of display synchronization to be applied.

## Constants

### `DXGK_SYNC_LOCK_STYLE_NONE`

Indicates that this path is not synchronized. If the *Input.SyncLockStyle* value of [**DXGK_SET_TIMING_PATH_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_set_timing_path_info) is set to this value, then the *Input.SyncLockGroup* should be set to zero.

### `DXGK_SYNC_LOCK_STYLE_IDENTICAL`

Indicates that this path is synchronized with other paths with the *Input.SyncLockGroup* set to the same non-zero value where all the paths have an identical target mode.

## Remarks

The sync styled defined for WDDM 2.4 - WDDM 2.6 do not allow the styles applied within a group to be mixed, since a path with **DXGK_SYNC_LOCK_STYLE_IDENTICAL** can only be synchronized with another path with **DXGK_SYNC_LOCK_STYLE_IDENTICAL**. However, in future releases, sync styles will support and potentially require different styles within a group.

## See also

[**DXGK_SET_TIMING_PATH_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_set_timing_path_info)