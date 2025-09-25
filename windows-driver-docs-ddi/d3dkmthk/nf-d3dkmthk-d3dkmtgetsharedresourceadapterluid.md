# D3DKMTGetSharedResourceAdapterLuid function

## Description

Maps a shared resource to a locally unique identifier (LUID) that identifies the graphics adapter that the resource was created on.

## Parameters

### `unnamedParam1`

*pLuid* [in, out]

A pointer to a [D3DKMT_GETSHAREDRESOURCEADAPTERLUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getsharedresourceadapterluid) structure that describes a shared resource and the graphics adapter that the resource was created on.

## Return value

Returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The mapping was performed successfully.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_GETSHAREDRESOURCEADAPTERLUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getsharedresourceadapterluid)