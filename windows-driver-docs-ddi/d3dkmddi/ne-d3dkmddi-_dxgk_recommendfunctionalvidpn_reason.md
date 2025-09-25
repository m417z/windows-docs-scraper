# _DXGK_RECOMMENDFUNCTIONALVIDPN_REASON enumeration

## Description

The DXGK_RECOMMENDFUNCTIONALVIDPN_REASON enumeration indicates the reason for calling the display miniport driver's [DxgkDdiRecommendFunctionalVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendfunctionalvidpn) function.

## Constants

### `DXGK_RFVR_UNINITIALIZED`

Indicates that a variable of type DXGK_RECOMMENDFUNCTIONALVIDPN_REASON has not yet been assigned a meaningful value.

### `DXGK_RFVR_HOTKEY`

Indicates that the VidPN manager is calling *DxgkDdiRecommendFunctionalVidPn* because the user pressed a hot key to request a change in the way the desktop is displayed on a collection of monitors (or other display devices).

### `DXGK_RFVR_USERMODE`

Indicates that a user-mode application initiated a call to *DxgkDdiRecommendFunctionalVidPn*.

### `DXGK_RFVR_FIRMWARE`

Value indicating that the OS is requesting the driver to describe a functional VidPn which reflects the display topology and timings which are currently set, as inherited from firmware during boot or resume from hibernation.

## Remarks

The **RequestReason** member of the [DXGKARG_RECOMMENDFUNCTIONALVIDPN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_recommendfunctionalvidpn) structure is a DXGK_RECOMMENDFUNCTIONALVIDPN_REASON value.

## See also

[DxgkDdiRecommendFunctionalVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendfunctionalvidpn)