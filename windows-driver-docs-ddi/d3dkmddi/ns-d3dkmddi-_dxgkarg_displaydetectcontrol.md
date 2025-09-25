# _DXGKARG_DISPLAYDETECTCONTROL structure

## Description

Used to hold the arguments for [DXGKDDI_DISPLAYDETECTCONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_displaydetectcontrol).

## Members

### `TargetId` [in]

The identifier of a display adapter's video present target. Ignored if the type is not DXGK_DDCT_POLLONE, or when DXGK_DDCT_POLLALL is specified.

### `Type` [in]

Detection action type requested.

### `NonDestructiveOnly` [in]

Used only for polling the types of requests.

If TRUE, the driver should attempt to poll the specified target(s) without causing any visual artifacts.
If FALSE, the driver should perform any action necessary to detect the status of the specified target(s) even if it would cause visual artifacts on the target(s) in question or other targets.

### `Reserved`

This value is reserved for system use.