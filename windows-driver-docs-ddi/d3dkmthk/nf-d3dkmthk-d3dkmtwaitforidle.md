# D3DKMTWaitForIdle function

## Description

The **D3DKMTWaitForIdle** function waits for a display device to be idle.

## Parameters

### `D3DKMT_WAITFORIDLE`

*pData* [in]

A pointer to a [D3DKMT_WAITFORIDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_waitforidle) structure that specifies the display device to wait for.

## Return value

**D3DKMTWaitForIdle** returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The wait for the display device successfully occurred.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

This function might also return other NTSTATUS values.

## See also

[D3DKMT_WAITFORIDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_waitforidle)