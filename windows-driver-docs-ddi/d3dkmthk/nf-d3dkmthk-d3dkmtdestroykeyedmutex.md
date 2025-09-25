# D3DKMTDestroyKeyedMutex function

## Description

The **D3DKMTDestroyKeyedMutex** function destroys a keyed mutex object.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_DESTROYKEYEDMUTEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroykeyedmutex) structure that specifies the keyed mutex object to destroy.

## Return value

**D3DKMTDestroyKeyedMutex** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The keyed mutex object was successfully destroyed. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_DESTROYKEYEDMUTEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroykeyedmutex)