## Description

The *DxGetPolarity* callback function returns the polarity (even or odd) of the current field being written by the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object.

## Parameters

### `unnamedParam1`

Points to the miniport driver's device extension.

### `unnamedParam2`

Points to a [DDGETPOLARITYININFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddgetpolarityininfo) structure that contains the VPE object from which to get the polarity information.

### `unnamedParam3`

Points to a [DDGETPOLARITYOUTINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddgetpolarityoutinfo) structure that contains the polarity information for the specified VPE object.

## Return value

*DxGetPolarity* returns DX_OK if it succeeds; otherwise, it returns one of the following error values:

## Remarks

The [DDGETPOLARITYININFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddgetpolarityininfo) and [DDGETPOLARITYOUTINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddgetpolarityoutinfo) structures contain VPE object information.

## See also

[DDGETPOLARITYININFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddgetpolarityininfo)

[DDGETPOLARITYOUTINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddgetpolarityoutinfo)