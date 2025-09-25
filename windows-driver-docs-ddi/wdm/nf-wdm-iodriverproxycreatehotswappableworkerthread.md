## Description

The **IoDriverProxyCreateHotSwappableWorkerThread** function creates a hot-swappable worker thread that provides a "spin waiting" worker thread compatible with Driver Hot-Swap. This function is particularly useful for handling infinite loops and long-running operations in drivers that need to remain hot-swappable.

## Parameters

### `DriverProxyExtension`

[in] A pointer to the DriverProxy extension that the endpoints are registered to. The worker routine specified in **WorkerStartContext** must be a registered endpoint wrapper.

### `ThreadHandle`

[out] A pointer to a variable that receives the handle to the created thread.

### `DesiredAccess`

[in] The [desired access rights](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) for the thread handle.

### `ObjectAttributes`

[in, optional] A pointer to an [*OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that specifies attributes for the thread object. This parameter can be NULL.

### `ProcessHandle`

[in, optional] A handle to the process in which the thread is created. If NULL, the thread is created in the current process.

### `ClientId`

[out, optional] A pointer to the [**CLIENT_ID**](https://learn.microsoft.com/openspecs/windows_protocols/ms-tsts/a11e7129-685b-4535-8d37-21d4596ac057) structure of the created thread. This parameter can be NULL.

### `WorkerStartContext`

[in] A pointer to a [**DRIVER_PROXY_HOTSWAP_WORKER_ROUTINE_START_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-driver_proxy_hotswap_worker_routine_start_context) structure that contains the configuration for the worker thread, including the worker routine and event objects to wait on.

## Return value

**IoDriverProxyCreateHotSwappableWorkerThread** returns one of the following NTSTATUS values:

| Return code | Description |
|-------------|-------------|
| **STATUS_SUCCESS** | The hot-swappable worker thread was successfully created. |
| **STATUS_NOT_SUPPORTED** | DriverProxy functionality is not available on the current system. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are invalid, such as a NULL worker routine or an invalid event count. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient memory was available to create the thread context or supporting structures. |

## Remarks

This function creates a specialized worker thread that integrates with the DriverProxy system, allowing the worker routine to be hot-swapped while the thread continues running. This is particularly useful for drivers that need to perform continuous background operations that should persist across driver updates.

The worker routine specified in **WorkerStartContext** must be a registered endpoint wrapper obtained through the DriverProxy registration process. This requirement enables the hot-swappable functionality, allowing drivers to update their worker logic without stopping long-running background operations.

The worker thread operates in a loop, waiting on the specified events and calling the worker routine when events are signaled. The worker routine can indicate whether the thread should continue running or terminate.

The function makes a copy of the **WorkerStartContext** structure, so the caller can safely discard the original structure after the function returns. The function must be called at PASSIVE_LEVEL as it performs memory allocation and thread creation.

## See also

[**DRIVER_PROXY_HOTSWAP_WORKER_ROUTINE_START_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-driver_proxy_hotswap_worker_routine_start_context)

[**DRIVER_PROXY_HOTSWAP_WORKER_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_proxy_hotswap_worker_routine)

[**IoRegisterDriverProxyEndpoints**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdriverproxyendpoints)
[**PsCreateSystemThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pscreatesystemthread)