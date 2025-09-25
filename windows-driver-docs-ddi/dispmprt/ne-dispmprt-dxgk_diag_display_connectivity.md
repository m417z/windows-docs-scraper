# DXGK_DIAG_DISPLAY_CONNECTIVITY enumeration

## Description

**DXGK_DIAG_DISPLAY_CONNECTIVITY** provides the last status of the target to the operating system (OS) when it is gathering nonintrusive display diagnostic information.

## Constants

### `DXGK_DIAG_DISPLAY_CONNECTIVITY_UNINITIALIZED`

Reserved for OS use during diagnostic initialization.

### `DXGK_DIAG_DISPLAY_NOT_CONNECTED`

No monitor is connected on the given target.

### `DXGK_DIAG_DISPLAY_CONNECTED`

A monitor is connected on the given target.

## Remarks

The **DXGK_DIAG_BASIC_DISPLAY_TOPOLOGY** enumeration is a member of the [**DXGK_DISPLAYSTATE_NONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_nonintrusive) structure. It is used while gathering display diagnostic information via calls to [**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive).

A driver should return the last status (preferably the hardware status of whether the monitor is connected) and should not perform active detection. Active detection might change the state of display connectivity, which would trigger an OS path for handling a new display arrival during this diagnostic DDI. Note that the OS requests the driver for active detection when it is performing the recovery steps for black screens.

## See also

[**DXGK_DISPLAYSTATE_NONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_nonintrusive)

[**DXGKARG_GETDISPLAYSTATENONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_getdisplaystatenonintrusive)

[**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive)