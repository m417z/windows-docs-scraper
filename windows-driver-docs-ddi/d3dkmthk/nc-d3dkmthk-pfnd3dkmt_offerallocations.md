# PFND3DKMT_OFFERALLOCATIONS callback function

## Description

Offers video memory allocations for reuse.

## Parameters

### `unnamedParam1` [in]

*pData*

A pointer to a [D3DKMT_OFFERALLOCATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_offerallocations) structure that defines memory allocations that the driver offers for reuse.

## Return value

Returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The allocations were successfully offered.|
|STATUS_DEVICE_REMOVED|The graphics adapter was stopped or the display device was reset.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

## See also

[D3DKMTReclaimAllocations](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtreclaimallocations)

[D3DKMT_OFFERALLOCATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_offerallocations)