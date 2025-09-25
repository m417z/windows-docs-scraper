# PFND3DKMT_QUERYREMOTEVIDPNSOURCEFROMGDIDISPLAYNAME callback function

## Description

Maps a GDI display name to a remote video present network (VidPN) source ID that is needed for a call to the [D3DKMTOutputDuplPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtoutputduplpresent) function.

## Parameters

### `unnamedParam1` [in, out]

*pData*

A pointer to a [D3DKMT_QUERYREMOTEVIDPNSOURCEFROMGDIDISPLAYNAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryremotevidpnsourcefromgdidisplayname) structure that describes information that is required to perform the mapping.

## Return value

Returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The mapping was performed successfully.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

This function might also return other NTSTATUS values.

## See also

[D3DKMTOutputDuplPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtoutputduplpresent)

[D3DKMT_QUERYREMOTEVIDPNSOURCEFROMGDIDISPLAYNAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryremotevidpnsourcefromgdidisplayname)