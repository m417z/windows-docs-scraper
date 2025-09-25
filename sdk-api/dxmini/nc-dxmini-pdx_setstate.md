## Description

The *DxSetState* callback function is called when a client of the video miniport driver decides it wants to switch from bob mode to weave mode, and vice versa.

## Parameters

### `unnamedParam1`
Points to the miniport driver's device extension.

### `unnamedParam2`
Points to a [DDSETSTATEININFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddsetstateininfo) structure that contains the surface and VPE object information.

### `unnamedParam3`
Points to a [DDSETSTATEOUTINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddsetstateoutinfo) structure that contains the state information for the hardware video port.

## Return value

*DxSetState* returns DX_OK if it succeeds; otherwise, it returns one of the following error values:

## Remarks

The surface data passed contains the new state. If the new state is not supported, the video miniport driver should fail the call.

If the new state requires the device to revert from hardware autoflipping to software autoflipping, the video miniport driver should set members of the DDSETSTATEOUTINFO structure at *SetStateOutInfo* as follows:

* The **dwSoftwareAutoflip** member equal to 1.
* The **dwSurfaceIndex** member equal to the current position in the auto-flip list of the surface receiving hardware video port data.

## See also

[DDSETSTATEININFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddsetstateininfo)

[DDSETSTATEOUTINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddsetstateoutinfo)