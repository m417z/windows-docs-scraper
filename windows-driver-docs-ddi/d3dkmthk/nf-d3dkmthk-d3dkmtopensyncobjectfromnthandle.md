# D3DKMTOpenSyncObjectFromNtHandle function

## Description

Maps an NT process handle to a graphics processing unit (GPU) synchronization object.

## Parameters

### `unnamedParam1`

*pObject* [in, out]

A pointer to a [D3DKMT_OPENSYNCOBJECTFROMNTHANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_opensyncobjectfromnthandle) structure that describes information that is required to perform the mapping.

## Return value

Returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The mapping was performed successfully.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

This function might also return other NTSTATUS values.

## See also

[D3DKMT_OPENSYNCOBJECTFROMNTHANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_opensyncobjectfromnthandle)