# D3DKMTCheckSharedResourceAccess function

## Description

The **D3DKMTCheckSharedResourceAccess** function determines if a process can access a shared resource.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_CHECKSHAREDRESOURCEACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_checksharedresourceaccess) structure that specifies parameters to determine if a process can access a shared resource.

## Return value

**D3DKMTCheckSharedResourceAccess** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The shared resource can be accessed by the process. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_CHECKSHAREDRESOURCEACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_checksharedresourceaccess)