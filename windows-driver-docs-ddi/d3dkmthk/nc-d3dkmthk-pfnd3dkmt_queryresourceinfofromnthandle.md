# PFND3DKMT_QUERYRESOURCEINFOFROMNTHANDLE callback function

## Description

Maps a global NT handle to resource information that is needed for a call to the [D3DKMTQueryResourceInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryresourceinfo) function.

## Parameters

### `unnamedParam1` [in, out]

*pData*

A pointer to a [D3DKMT_QUERYRESOURCEINFOFROMNTHANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryresourceinfofromnthandle) structure that describes information that is required to perform the mapping.

## Return value

Returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The mapping was performed successfully.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

This function might also return other NTSTATUS values.

## See also

[D3DKMTQueryResourceInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryresourceinfo)

[D3DKMT_QUERYRESOURCEINFOFROMNTHANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryresourceinfofromnthandle)