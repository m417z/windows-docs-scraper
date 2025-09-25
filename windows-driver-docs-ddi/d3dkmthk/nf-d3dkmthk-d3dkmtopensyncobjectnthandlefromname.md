# D3DKMTOpenSyncObjectNtHandleFromName function

## Description

**D3DKMTOpenSyncObjectNtHandleFromName** opens an NT handle for a named shared monitored fence object, similar to what [D3DKMTOpenNtHandleFromName](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopennthandlefromname) does for shared allocations.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_OPENSYNCOBJECTNTHANDLEFROMNAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_opensyncobjectnthandlefromname) structure that describes the operation.

## Return value

Returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The operation was performed successfully.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

This function might also return other **NTSTATUS** values.

## See also

[D3DKMTOpenNtHandleFromName](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopennthandlefromname)