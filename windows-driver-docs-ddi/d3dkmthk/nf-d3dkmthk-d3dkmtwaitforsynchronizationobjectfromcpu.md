# D3DKMTWaitForSynchronizationObjectFromCpu function

## Description

**D3DKMTWaitForSynchronizationObjectFromCpu** waits for a monitored fence to reach a certain value.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_WAITFORSYNCHRONIZATIONOBJECTFROMCPU](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_waitforsynchronizationobjectfromcpu) structure that describes the operation.

## Return value

Returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The operation was performed successfully. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_WAITFORSYNCHRONIZATIONOBJECTFROMCPU](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_waitforsynchronizationobjectfromcpu)