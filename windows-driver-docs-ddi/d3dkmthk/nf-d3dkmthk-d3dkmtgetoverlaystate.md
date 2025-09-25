# D3DKMTGetOverlayState function

## Description

The **D3DKMTGetOverlayState** function retrieves the status about an overlay.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_GETOVERLAYSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getoverlaystate) structure that describes parameters to retrieve status about an overlay.

## Return value

**D3DKMTGetOverlayState** returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The status about an overlay was successfully retrieved.|
|STATUS_DEVICE_REMOVED|The graphics adapter was stopped or the display device was reset.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_GETOVERLAYSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getoverlaystate)