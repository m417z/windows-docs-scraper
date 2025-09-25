# DXGK_DIAG_DISPLAY_MODE_SET enumeration

## Description

**DXGK_DIAG_DISPLAY_MODE_SET** provides a driver's last mode set state to the operating system (OS) when it is gathering nonintrusive display diagnostic information.

## Constants

### `DXGK_DIAG_DISPLAY_MODE_SET_UNINITIALIZED`

Reserved for OS use during diagnostic initialization.

### `DXGK_DIAG_DISPLAY_MODE_SET_NO`

The driver did not complete the last mode set successfully.

### `DXGK_DIAG_DISPLAY_MODE_SET_YES`

The driver completed the last mode set successfully.

## Remarks

The **DXGK_DIAG_DISPLAY_MODE_SET** enumeration is a member of the [**DXGK_DISPLAYSTATE_NONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_nonintrusive) structure. It is used while gathering display diagnostic information via calls to [**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive).

While the OS tracks whether the last Set mode call succeeded, **DXGK_DIAG_DISPLAY_MODE_SET** provides the driver's state regarding mode set on a given target to compare against the OS state. For the OS, a mode set operation mainly consists of a SetTimings DDI call. However, for drivers, a mode set usually means multiple internal operations to set the hardware timings correctly. The OS can use **DXGK_DIAG_DISPLAY_MODE_SET** to determine the overall driver state for mode set and if it is considered successful.

## See also

[**DXGK_DISPLAYSTATE_NONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_nonintrusive)

[**DXGKARG_GETDISPLAYSTATENONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_getdisplaystatenonintrusive)

[**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive)