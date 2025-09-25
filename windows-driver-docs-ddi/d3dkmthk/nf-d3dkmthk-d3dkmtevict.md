# D3DKMTEvict function

## Description

**D3DKMTEvict** is used to decrement the allocation residency reference count. Once this count reaches zero, it will remove the allocation from the device residency list.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_EVICT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_evict) structure that describes the operation.

## Return value

Returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The operation was performed successfully.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

This function might also return other **NTSTATUS** values.

## Remarks

Once the eviction request is queued, it is illegal to access the underlying allocation as the allocation may be evicted at anytime from there on at the operating system discretion.

## See also

[D3DKMT_EVICT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_evict)