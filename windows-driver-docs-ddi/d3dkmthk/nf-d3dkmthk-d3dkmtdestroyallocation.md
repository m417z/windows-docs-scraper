# D3DKMTDestroyAllocation function

## Description

The **D3DKMTDestroyAllocation** function releases a resource, a list of allocations, or both.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_DESTROYALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroyallocation) structure that contains information for releasing allocations.

## Return value

**D3DKMTDestroyAllocation** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | Allocations were successfully released. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_DESTROYALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroyallocation)