# D3DKMTOpenSyncObjectFromNtHandle2 function

## Description

**D3DKMTOpenSyncObjectFromNtHandle2** opens a monitored fence object from an NT handle previously created by [D3DKMTShareObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtshareobjects).

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_OPENSYNCOBJECTFROMNTHANDLE2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_opensyncobjectfromnthandle2) structure that describes the operation.

## Return value

Returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The operation was performed successfully.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

This function might also return other **NTSTATUS** values.

## See also

[D3DKMTShareObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtshareobjects)

[D3DKMT_OPENSYNCOBJECTFROMNTHANDLE2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_opensyncobjectfromnthandle2)