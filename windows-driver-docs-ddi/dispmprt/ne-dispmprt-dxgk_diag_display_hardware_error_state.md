# DXGK_DIAG_DISPLAY_HARDWARE_ERROR_STATE enumeration

## Description

The **DXGK_DIAG_DISPLAY_HARDWARE_ERROR_STATE** enum provides hardware error state information during diagnostic data collection.

## Constants

### `DXGK_DIAG_DISPLAY_HARDWARE_ERROR_STATE_UNINITIALIZED`

Reserved for OS use during diagnostic initialization.

### `DXGK_DIAG_DISPLAY_HARDWARE_ERROR_NONE`

No display pipeline hardware error state was detected.

### `DXGK_DIAG_DISPLAY_HARDWARE_ERROR_SCANOUT_UNDERFLOW`

The display scan out pipeline is hitting underflows during scan out of the current frame.

### `DXGK_DIAG_DISPLAY_HARDWARE_ERROR_TDRNORECOVERY`

The display pipeline could not recover after a TDR.

### `DXGK_DIAG_DISPLAY_HARDWARE_ERROR_UNSPECIFIED`

The display hardware is in an error state that doesn't fall under any of the above categories.

## Remarks

The **DXGK_DIAG_DISPLAY_HARDWARE_ERROR_STATE** enumeration is a member of the [**DXGK_DISPLAYSTATE_INTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_intrusive) structure. It is used while gathering display diagnostic information via calls to [**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive).

**DXGK_DIAG_DISPLAY_HARDWARE_ERROR_STATE** informs the operating system whether the display hardware is in some kind of error state that might be causing issues with scan out or other display operations. For example, some black screens are caused right after the user hits TDRs. In such a situation, it is important that drivers notify the OS if after hitting TDR the display scan out pipeline hasn't recovered and there is no scan out going on.

## See also

[**DXGK_DISPLAYSTATE_INTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_intrusive)

[**DXGKARG_GETDISPLAYSTATEINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_getdisplaystateintrusive)

[**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive)