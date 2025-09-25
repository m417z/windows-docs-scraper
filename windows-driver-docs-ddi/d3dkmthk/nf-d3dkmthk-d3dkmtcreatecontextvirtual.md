# D3DKMTCreateContextVirtual function

## Description

The **D3DKMTCreateContextVirtual** function creates a kernel mode device context that supports virtual addressing.

## Parameters

### `unnamedParam1`

*pData* [in]

A pointer to a [D3DKMT_CREATECONTEXTVIRTUAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createcontextvirtual) structure that describes the kernel-mode device context.

## Return value

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The device context was successfully created.|
|STATUS_DEVICE_REMOVED|The graphics adapter was stopped or the display device was reset.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|
|STATUS_NO_MEMORY|D3DKMTCreateContextVirtual could not complete because of insufficient memory.|

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_CREATECONTEXTVIRTUAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createcontextvirtual)