# D3DKMTGetScanLine function

## Description

The **D3DKMTGetScanLine** function determines whether the given video present source of a video present network (VidPN) is in vertical blanking mode and retrieves the current scan line.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_GETSCANLINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getscanline) structure that contains the vertical blanking status of a video present source.

## Return value

**D3DKMTGetScanLine** returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The vertical blanking status and scan line were successfully retrieved.|
|STATUS_DEVICE_REMOVED|The graphics adapter was stopped.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_GETSCANLINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getscanline)