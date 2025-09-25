## Description

The **D3DKMTDestroySynchronizationObject** function destroys a kernel-mode synchronization object.

## Parameters

### `unnamedParam1` [in]

Pointer to a [**D3DKMT_DESTROYSYNCHRONIZATIONOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroysynchronizationobject) structure that contains the handle to the synchronization object to destroy.

## Return value

**D3DKMTDestroySynchronizationObject** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The kernel-mode overlay object was successfully destroyed. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## See also

[**D3DKMT_DESTROYSYNCHRONIZATIONOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroysynchronizationobject)