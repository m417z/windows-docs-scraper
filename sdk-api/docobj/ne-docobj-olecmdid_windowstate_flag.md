# OLECMDID_WINDOWSTATE_FLAG enumeration

## Description

Specifies the window state.

## Constants

### `OLECMDIDF_WINDOWSTATE_USERVISIBLE:0x00000001`

The window is visible.

### `OLECMDIDF_WINDOWSTATE_ENABLED:0x00000002`

The window has focus.

### `OLECMDIDF_WINDOWSTATE_USERVISIBLE_VALID:0x00010000`

The window is visible and valid.

### `OLECMDIDF_WINDOWSTATE_ENABLED_VALID:0x00020000`

The window has focus and is valid.

## Remarks

A value from this enumeration is passed as the *nCmdExecOpt* parameter to [IOleCommandTarget::Exec](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-exec) in conjunction with passing the OLECMDID_WINDOWSTATECHANGED value of the [OLECMDID](https://learn.microsoft.com/windows/desktop/api/docobj/ne-docobj-olecmdid) enumeration as the *nCmdID* parameter.

## See also

[OLECMDID](https://learn.microsoft.com/windows/desktop/api/docobj/ne-docobj-olecmdid)