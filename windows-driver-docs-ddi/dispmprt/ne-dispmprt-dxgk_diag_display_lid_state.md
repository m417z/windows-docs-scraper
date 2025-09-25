# DXGK_DIAG_DISPLAY_LID_STATE enumeration

## Description

**DXGK_DIAG_DISPLAY_LID_STATE** provides the lid state of the target to the operating system (OS) when it is gathering nonintrusive display diagnostic information.

## Constants

### `DXGK_DIAG_DISPLAY_LID_STATE_UNINITIALIZED`

Reserved for OS use during diagnostic initialization.

### `DXGK_DIAG_DISPLAY_LID_STATE_NOTAPPLICABLE`

Lid state is not applicable on this target. This would be the value used for most of the targets which are not internal displays.

### `DXGK_DIAG_DISPLAY_LID_STATE_OPEN`

The lid of the display is currently open, according to driver state.

### `DXGK_DIAG_DISPLAY_LID_STATE_CLOSE`

The lid of the display is currently closed, according to driver state.

### `DXGK_DIAG_DISPLAY_LID_STATE_UNKNOWN`

The driver does not know the current lid state. A driver should only use this value when it doesn't maintain/cache lid state internally.

## Remarks

The **DXGK_DIAG_DISPLAY_LID_STATE** enumeration is a member of the [**DXGK_DISPLAYSTATE_NONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_nonintrusive) structure. It is used while gathering display diagnostic information via calls to [**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive).

**DXGK_DIAG_DISPLAY_LID_STATE** is only applicable to form factors which have a lid. If the driver caches the current state of the lid (open or close) then we want to compare it against to OS state.

## See also

[**DXGK_DISPLAYSTATE_NONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_nonintrusive)

[**DXGKARG_GETDISPLAYSTATENONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_getdisplaystatenonintrusive)

[**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive)