# D3DKMTCreatePagingQueue function

## Description

**D3DKMTCreatePagingQueue** is used to create a device paging queue that can be used to synchronize with video memory management operations for the device, such as making the device resource resident.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_CREATEPAGINGQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createpagingqueue) structure that describes the operation.

## Return value

Returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The operation was performed successfully.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_CREATEPAGINGQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createpagingqueue)