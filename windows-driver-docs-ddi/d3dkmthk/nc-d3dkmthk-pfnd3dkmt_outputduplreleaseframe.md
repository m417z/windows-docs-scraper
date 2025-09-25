# PFND3DKMT_OUTPUTDUPLRELEASEFRAME callback function

## Description

Indicates that the driver has finished processing the duplicated desktop image.

## Parameters

### `unnamedParam1` [in, out]

*pData*

A pointer to a [D3DKMT_OUTPUTDUPL_RELEASE_FRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_outputdupl_release_frame) structure that defines the duplicated desktop image that is to be released.

## Return value

Returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function performed successfully.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|
|STATUS_NOT_FOUND|The context of the process could not be found.|

This function might also return other NTSTATUS values.

## See also

[D3DKMT_OUTPUTDUPL_RELEASE_FRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_outputdupl_release_frame)