# D3DKMTDestroyDCFromMemory function

## Description

The **D3DKMTDestroyDCFromMemory** function releases the display context.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_DESTROYDCFROMMEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroydcfrommemory) structure that contains handles to the display context and bitmap.

## Return value

**D3DKMTDestroyDCFromMemory** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The device context was successfully released. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_DESTROYDCFROMMEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroydcfrommemory)