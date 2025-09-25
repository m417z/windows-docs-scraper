# D3DKMTWaitForSynchronizationObjectFromGpu function

## Description

**D3DKMTWaitForSynchronizationObjectFromGpu** waits for a monitored fence to reach a certain value before processing subsequent context commands.

> [!NOTE]
> For Windows Display Driver Model (WDDM) v2 drivers, existing [D3DKMTWaitForSynchronizationObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtwaitforsynchronizationobject) and [D3DKMTWaitForSynchronizationObject2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtwaitforsynchronizationobject2) callbacks are deprecated and will eventually be removed.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_WAITFORSYNCHRONIZATIONOBJECTFROMGPU](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_waitforsynchronizationobjectfromgpu) structure that describes the operation.

## Return value

Returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The operation was performed successfully. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## Remarks

This function semantics are similar to existing [D3DKMTWaitForSynchronizationObject2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtwaitforsynchronizationobject2) call, except that this function also supports monitored fence objects and an array of monitored fence values to wait for.

## See also

[D3DKMTWaitForSynchronizationObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtwaitforsynchronizationobject)

[D3DKMTWaitForSynchronizationObject2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtwaitforsynchronizationobject2)

[D3DKMT_WAITFORSYNCHRONIZATIONOBJECTFROMGPU](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_waitforsynchronizationobjectfromgpu)