## Description

The *DxLock* callback function is called when a client of the video miniport driver wants access to the frame buffer.

## Parameters

### `unnamedParam1`
Points to the miniport driver's device extension.

### `unnamedParam2`
Points to a [DDLOCKININFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddlockininfo) structure that contains the surface information for the lock.

### `unnamedParam3`
Points to a [DDLOCKOUTINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddlockoutinfo) structure that contains the surface in the frame buffer.

## Return value

*DxLock* returns DX_OK if it succeeds; otherwise, it returns one of the following error values:

## Remarks

The [DDLOCKININFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddlockininfo) and [DDLOCKOUTINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddlockoutinfo) structures contain surface information.

## See also

[DDLOCKININFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddlockininfo)

[DDLOCKOUTINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddlockoutinfo)