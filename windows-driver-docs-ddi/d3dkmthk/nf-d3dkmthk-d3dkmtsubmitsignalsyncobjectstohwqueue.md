# D3DKMTSubmitSignalSyncObjectsToHwQueue function

## Description

Used to submit a signal to the hardware queue.

## Parameters

### `unnamedParam1` [in]

A [D3DKMT_SUBMITSIGNALSYNCOBJECTSTOHWQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_submitsignalsyncobjectstohwqueue) structure holding the information needed to submit a signal to the hardware queue.

## Return value

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The device context was called successfully. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_SUBMITSIGNALSYNCOBJECTSTOHWQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_submitsignalsyncobjectstohwqueue)