# D3DKMTUnlock2 function

## Description

The **D3DKMTUnlock2** function unlocks a list of allocations.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_UNLOCK2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_unlock2) structure that describes a list of allocations to unlock.

## Return value

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The allocations were successfully unlocked. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_UNLOCK2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_unlock2)