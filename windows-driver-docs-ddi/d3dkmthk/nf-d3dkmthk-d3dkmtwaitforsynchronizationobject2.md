# D3DKMTWaitForSynchronizationObject2 function

## Description

The **D3DKMTWaitForSynchronizationObject2** function inserts a wait for the specified synchronization objects in the specified context stream.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_WAITFORSYNCHRONIZATIONOBJECT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_waitforsynchronizationobject2) structure that describes the synchronization objects and context stream that the wait is set up for.

## Return value

**D3DKMTWaitForSynchronizationObject2** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The wait was successfully set up. |
| STATUS_DEVICE_REMOVED | The graphics adapter was stopped or the display context was reset. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_WAITFORSYNCHRONIZATIONOBJECT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_waitforsynchronizationobject2)