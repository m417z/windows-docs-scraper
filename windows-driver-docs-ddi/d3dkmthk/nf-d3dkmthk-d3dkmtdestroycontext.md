# D3DKMTDestroyContext function

## Description

The **D3DKMTDestroyContext** function releases a kernel-mode device context.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_DESTROYCONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroycontext) structure that contains the handle to the kernel-mode device context.

## Return value

**D3DKMTDestroyContext** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The device context was successfully released. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_DESTROYCONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroycontext)