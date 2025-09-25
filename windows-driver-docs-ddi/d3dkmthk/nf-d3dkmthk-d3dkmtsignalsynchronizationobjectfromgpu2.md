# D3DKMTSignalSynchronizationObjectFromGpu2 function

## Description

**D3DKMTSignalSynchronizationObjectFromGpu2** is used to signal a monitored fence.When a particular graphics processing unit (GPU) engine is not capable of writing a new monitored fence value directly using its GPU virtual address, the driver needs to flush its command buffer and issue a signal from GPU packet using **D3DKMTSignalSynchronizationObjectFromGpu2**. For Windows Display Driver Model (WDDM) v2 drivers, existing [D3DKMTSignalSynchronizationObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsignalsynchronizationobject) and [D3DKMTSignalSynchronizationObject2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsignalsynchronizationobject2) callbacks are deprecated and will eventually be removed.

## Parameters

### `unnamedParam1` [in]

A [D3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMGPU2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_signalsynchronizationobjectfromgpu2) structure that provides the details of the requested operation.

## Return value

Returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The operation was performed successfully. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMTSignalSynchronizationObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsignalsynchronizationobject)

[D3DKMTSignalSynchronizationObject2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsignalsynchronizationobject2)

[D3DKMTSignalSynchronizationObjectFromGpu](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsignalsynchronizationobjectfromgpu)

[D3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMGPU2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_signalsynchronizationobjectfromgpu2)