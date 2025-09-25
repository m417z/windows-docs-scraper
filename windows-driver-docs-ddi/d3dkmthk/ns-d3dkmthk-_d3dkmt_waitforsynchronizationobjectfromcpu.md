# _D3DKMT_WAITFORSYNCHRONIZATIONOBJECTFROMCPU structure

## Description

**D3DKMT_WAITFORSYNCHRONIZATIONOBJECTFROMCPU** is used with [D3DKMTWaitForSynchronizationObjectFromCpu](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtwaitforsynchronizationobjectfromcpu) to wait for a monitored fence to reach a certain value.

## Members

### `hDevice` [in]

The device handle to wait on.

### `ObjectCount` [in]

The number of synchronization objects in the **ObjectHandleArray** and fence values in the **FenceValueArray**.

### `ObjectHandleArray` [in]

An array of kernel-mode handles to the synchronization events to wait for.

### `FenceValueArray` [in]

An array of 64-bit monitored fence values to wait for, each corresponding to an object in the **ObjectHandleArray**.

### `hAsyncEvent` [in]

When not **NULL**, specifies the event to be signaled when the wait condition is satisfied. When **NULL**, the call will not return until the wait condition is satisfied.

### `Flags` [in]

A [D3DDDI_WAITFORSYNCHRONIZATIONOBJECTFROMCPU_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_waitforsynchronizationobjectfromcpu_flags) structure describing the operation.

|Value|Meaning|
|--- |--- |
|WaitAny
FALSE|The wait condition is considered to be satisfied when all input synchronization objects are signaled to the corresponding input fence values or greater.|
|WaitAny
TRUE|The wait condition is considered to be satisfied when any of the input synchronization objects is signaled to the corresponding input fence value or greater.|

## See also

[D3DDDI_WAITFORSYNCHRONIZATIONOBJECTFROMCPU_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_waitforsynchronizationobjectfromcpu_flags)

[D3DKMTWaitForSynchronizationObjectFromCpu](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtwaitforsynchronizationobjectfromcpu)