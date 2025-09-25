# D3DKMTReclaimAllocations function

## Description

The **D3DKMTReclaimAllocations** function reclaims the video memory allocations specified in a [D3DKMT_RECLAIMALLOCATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_reclaimallocations) structure.

## Parameters

### `unnamedParam1` [in, out]

A pointer to a [D3DKMT_RECLAIMALLOCATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_reclaimallocations) structure that defines memory allocations to reclaim.

## Return value

Returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The allocations were successfully reclaimed. |
| STATUS_DEVICE_REMOVED | The graphics adapter was stopped or the display device was reset. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

## See also

[D3DKMTOfferAllocations](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtofferallocations)

[D3DKMT_RECLAIMALLOCATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_reclaimallocations)