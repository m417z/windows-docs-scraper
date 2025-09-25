## Description

The *DxBobNextField* callback function bobs the next field of interleaved data.

## Parameters

### `unnamedParam1`

Points to the miniport driver's device extension.

### `unnamedParam2`

Points to a [DDBOBNEXTFIELDINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddbobnextfieldinfo) structure that contains the bob information for the surface.

### `unnamedParam3`

Reserved for system use.

## Return value

*DxBobNextField* returns DX_OK if it succeeds; otherwise, it returns one of the following error values:

[DXERR_GENERIC](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw)

[DXERR_OUTOFCAPS](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw)

[DXERR_UNSUPPORTED](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw)

## Remarks

When data is interleaved, the driver's [DdFlip](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_flip) function is called every other frame. This is insufficient for bob because it must be notified after every V-sync. The driver's *DxBobNextField* function is called when a V-sync does not cause a flip.

## See also

[DDBOBNEXTFIELDINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddbobnextfieldinfo)

[DdFlip](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_flip)