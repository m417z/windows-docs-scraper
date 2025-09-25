## Description

The **DRIVER_PROXY_HOTSWAP_WORKER_ROUTINE** callback defines a routine that runs in a hot-swappable worker thread created by [**IoDriverProxyCreateHotSwappableWorkerThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iodriverproxycreatehotswappableworkerthread).

## Parameters

### `WorkerContext`

[in] A pointer to driver-defined context information that was specified when the worker thread was created. This context is passed through from the **Context** field of the [**DRIVER_PROXY_HOTSWAP_WORKER_ROUTINE_START_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-driver_proxy_hotswap_worker_routine_start_context) structure.

### `WaitStatus`

[in] The status returned from the wait operation. This indicates why the worker thread was awakened. See [**KeWaitForMultipleObjects**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitformultipleobjects) for possible wait status values.

## Return value

**DRIVER_PROXY_HOTSWAP_WORKER_ROUTINE** returns one of the following values:

| Return value | Description |
|--------------|-------------|
| TRUE | The worker thread should continue running and wait again on the specified objects. |
| FALSE | The worker thread should terminate. |

## Remarks

This callback is invoked when the worker thread wakes up from waiting on kernel objects. The routine determines whether the thread should continue running or terminate.

This callback routine runs at PASSIVE_LEVEL in the context of a system worker thread created specifically for hot-swappable operations. The thread maintains the same IRQL throughout its execution (_IRQL_requires_same_).

The worker routine is called each time the thread wakes up from waiting on the kernel objects specified in the [**DRIVER_PROXY_HOTSWAP_WORKER_ROUTINE_START_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-driver_proxy_hotswap_worker_routine_start_context) structure. Based on the **WaitStatus** and the current state of the driver, the routine should decide whether to continue processing (return TRUE) or terminate the worker thread (return FALSE).

The worker thread infrastructure ensures that the thread can be safely terminated and recreated as part of driver hot-swap operations, maintaining system stability during runtime driver updates.

## See also

[**IoDriverProxyCreateHotSwappableWorkerThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iodriverproxycreatehotswappableworkerthread)

[**DRIVER_PROXY_HOTSWAP_WORKER_ROUTINE_START_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-driver_proxy_hotswap_worker_routine_start_context)