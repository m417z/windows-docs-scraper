# DXGK_DIAG_DISPLAY_HARDWARE_BANDWIDTH enumeration

The **DXGK_DIAG_DISPLAY_HARDWARE_BANDWIDTH** enum provides hardware bandwidth information during diagnostic data collection.

## Description

## Constants

### `DXGK_DIAG_DISPLAY_HARDWARE_BANDWIDTH_UNINITIALIZED`

Reserved for OS use during diagnostic initialization.

### `DXGK_DIAG_DISPLAY_HARDWARE_BANDWIDTH_SUFFICIENT`

The bandwidth required to drive the last set display mode on the given target is within the range of what the display hardware and monitor/link can support.

### `DXGK_DIAG_DISPLAY_HARDWARE_LINK_BANDWIDTH_LIMITED`

The bandwidth limitation is on the link or monitor end, and the link negotiation did not result in sufficient bandwidth. Do not set this field if the current target/monitor bus protocol cannot determine the bandwidth it supports.

### `DXGK_DIAG_DISPLAY_HARDWARE_SOC_BANDWIDTH_LIMITED`

The bandwidth limitation is on the display hardware side and silicon cannot support the currently needed bandwidth.

### `DXGK_DIAG_DISPLAY_HARDWARE_BANDWIDTH_ERROR`

This value should be used in rare cases where the driver has hit some error while doing any bandwidth calculations so that all other fields are still filled.

### `DXGK_DIAG_DISPLAY_HARDWARE_BANDWIDTH_UNKNOWN`

The driver could not calculate the bandwidth requirements for the given monitor/link and/or SOC. This value should be used in rare cases where the driver does not implement the calculation of bandwidth requirements.

## Remarks

The **DXGK_DIAG_DISPLAY_HARDWARE_BANDWIDTH** enumeration is a member of the [**DXGK_DISPLAYSTATE_INTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_intrusive) structure. It is used while gathering display diagnostic information via calls to [**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive).

DXGK_DIAG_DISPLAY_HARDWARE_BANDWIDTH tells the operating system whether the display hardware including the link (for example, displayport) has sufficient bandwidth to drive the display on the given target at the last set mode (resolution, refresh rate).

## See also

[**DXGK_DISPLAYSTATE_INTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_intrusive)

[**DXGKARG_GETDISPLAYSTATEINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_getdisplaystateintrusive)

[**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive)