# D3DKMTReclaimAllocations2 function

## Description

**D3DKMTReclaimAllocations2** reclaims video memory allocations.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_RECLAIMALLOCATIONS2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_reclaimallocations2) structure that defines memory allocations to reclaim.

## Return value

Returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The allocations were successfully reclaimed.|
|STATUS_DEVICE_REMOVED|The graphics adapter was stopped or the display device was reset.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

## See also

[D3DKMT_RECLAIMALLOCATIONS2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_reclaimallocations2)