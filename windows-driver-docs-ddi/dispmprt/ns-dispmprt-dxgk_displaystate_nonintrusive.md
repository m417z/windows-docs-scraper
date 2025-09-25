# DXGK_DISPLAYSTATE_NONINTRUSIVE structure

## Description

The **DXGK_DISPLAYSTATE_NONINTRUSIVE** structure holds display state during nonintrusive diagnostic data collection.

## Members

### `VidPnTargetId`

Integer value that identifies a particular video present source.

### `DisplayConnectivity`

A [**DXGK_DIAG_DISPLAY_CONNECTIVITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_display_connectivity) value.

### `DisplayLidState`

A [**DXGK_DIAG_DISPLAY_LID_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_display_lid_state) value.

### `DisplayTopology`

A [**DXGK_DIAG_BASIC_DISPLAY_TOPOLOGY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_basic_display_topology) value.

### `DisplayLinkState`

A [**DXGK_DIAG_DISPLAY_LINK_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_display_link_state) value.

### `DisplayModeSet`

A [**DXGK_DIAG_DISPLAY_MODE_SET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_display_mode_set) value.

### `ReturnSubStatus`

A [**DXGK_DIAG_GETDISPLAYSTATE_SUBSTATUS_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_getdisplaystate_substatus_flags) value.

## Remarks

A pointer to an array of pointers to **DXGK_DISPLAYSTATE_NONINTRUSIVE** structures is contained in the [**DXGKARG_GETDISPLAYSTATENONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_getdisplaystatenonintrusive) structure, which is passed in calls to [**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive) during nonintrusive diagnostic data collection.

## See also

[**DXGK_DIAG_DISPLAY_CONNECTIVITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_display_connectivity)

[**DXGK_DIAG_DISPLAY_LID_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_display_lid_state)

[**DXGK_DIAG_DISPLAY_LINK_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_display_link_state)

[**DXGK_DIAG_DISPLAY_MODE_SET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_display_mode_set)

[**DXGK_DIAG_BASIC_DISPLAY_TOPOLOGY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_basic_display_topology)

[**DXGKARG_GETDISPLAYSTATENONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_getdisplaystatenonintrusive)

[**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive)