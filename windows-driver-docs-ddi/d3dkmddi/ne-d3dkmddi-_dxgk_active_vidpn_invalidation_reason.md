# _DXGK_ACTIVE_VIDPN_INVALIDATION_REASON enumeration

## Description

The DXGK_ACTIVE_VIDPN_INVALIDATION_REASON enumeration is used to indicate the reason why an active VidPN is invalidated and a new VidPN is requested.

## Constants

### `DXGK_AVIR_UNINITIALIZED`

Indicates that a variable of type DXGK_ACTIVE_VIDPN_INVALIDATION_REASON has not yet been assigned a meaningful value.

### `DXGK_AVIR_HOTKEY`

Indicates that the user pressed a keyboard shortcut to change the set of monitors (or other display devices) being used to display the desktop.

### `DXGK_AVIR_USERMODE`

Indicates that a call to the [D3DKMTInvalidateActiveVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtinvalidateactivevidpn) function has been made in user mode.

## See also

[D3DKMTInvalidateActiveVidPN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtinvalidateactivevidpn)