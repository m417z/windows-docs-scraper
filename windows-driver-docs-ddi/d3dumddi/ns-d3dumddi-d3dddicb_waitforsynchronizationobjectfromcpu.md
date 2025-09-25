# D3DDDICB_WAITFORSYNCHRONIZATIONOBJECTFROMCPU structure

## Description

**D3DDDICB_WAITFORSYNCHRONIZATIONOBJECTFROMCPU** is used with [pfnWaitForSynchronizationObjectFromCpuCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_waitforsynchronizationobjectfromcpucb) to wait for a monitored fence to reach a certain value.

## Members

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

| **Value** | **Meaning** |
|:--|:--|
| **WaitAny** <br>FALSE|The wait condition is considered to be satisfied when all input synchronization objects are signaled to the corresponding input fence values or greater. |
| **WaitAny** <br>TRUE|The wait condition is considered to be satisfied when any of the input synchronization objects is signaled to the corresponding input fence value or greater. |

## See also

[pfnWaitForSynchronizationObjectFromCpuCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_waitforsynchronizationobjectfromcpucb)