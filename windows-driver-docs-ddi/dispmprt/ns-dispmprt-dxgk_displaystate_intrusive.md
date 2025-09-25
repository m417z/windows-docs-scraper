# DXGK_DISPLAYSTATE_INTRUSIVE structure

## Description

The **DXGK_DISPLAYSTATE_INTRUSIVE** structure holds display state during diagnostic data collection.

## Members

### `VidPnTargetId` [in]

Integer value that identifies a particular video present source.

### `MonitorState`

A [**DXGK_DIAG_MONITOR_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_monitor_state) value.

### `DisplayScanoutState`

A [**DXGK_DIAG_DISPLAY_SCANOUT_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_display_scanout_state) value.

### `DisplaySampledGamma`

A [**DXGK_DIAG_DISPLAY_SAMPLED_GAMMA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_diag_display_sampled_gamma) structure.

### `DisplayBufferContent`

A [**DXGK_DIAG_SCANOUT_BUFFER_CONTENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_diag_scanout_buffer_content) value.

### `DisplayErrorState`

A [**DXGK_DIAG_DISPLAY_HARDWARE_ERROR_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_display_hardware_error_state) value.

### `DisplayBandwidth`

A [**DXGK_DIAG_DISPLAY_HARDWARE_BANDWIDTH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_display_hardware_bandwidth) value.

### `ReturnSubStatus`

A [**DXGK_DIAG_GETDISPLAYSTATE_SUBSTATUS_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_getdisplaystate_substatus_flags) value.

## Remarks

A pointer to an array of pointers to **DXGK_DISPLAYSTATE_INTRUSIVE** structures is contained in the [**DXGKARG_GETDISPLAYSTATEINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_getdisplaystateintrusive) structure, which is passed in calls to [**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive) during diagnostic data collection.

## See also

[**DXGK_DIAG_DISPLAY_HARDWARE_BANDWIDTH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_display_hardware_bandwidth)

[**DXGK_DIAG_DISPLAY_HARDWARE_ERROR_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_display_hardware_error_state)

[**DXGK_DIAG_DISPLAY_SAMPLED_GAMMA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_diag_display_sampled_gamma)

[**DXGK_DIAG_DISPLAY_SCANOUT_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_display_scanout_state)

[**DXGK_DIAG_GETDISPLAYSTATE_SUBSTATUS_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_getdisplaystate_substatus_flags)

[**DXGK_DIAG_MONITOR_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_monitor_state)

[**DXGK_DIAG_SCANOUT_BUFFER_CONTENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_diag_scanout_buffer_content)

[**DXGKARG_GETDISPLAYSTATEINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_getdisplaystatenonintrusive)

[**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive)