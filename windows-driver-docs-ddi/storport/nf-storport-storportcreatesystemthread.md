## Description

**StorPortCreateSystemThread** creates a system thread and supplies a pointer to a context for the thread.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport's hardware device extension.

### `StartRoutine` [in]

Pointer to the entry point for the newly created system thread. This parameter is a function pointer to a [**STOR_THREAD_START_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-stor_thread_start_routine) callback that receives a single argument, which is the **StartContext** parameter value.

### `StartContext` [in/optional]

Pointer to a single argument that is passed to the thread when it begins execution.

### `Priority` [in/optional]

Pointer to a [**STOR_THREAD_PRIORITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-stor_thread_priority) enum value that specifies the thread priority.

### `ThreadContext` [out/optional]

Pointer to a variable that will receive the thread context.

## Return value

**StorPortCreateSystemThread** returns one of the following values:

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_SUCCESS | A system thread has been successfully created. |
| STOR_STATUS_INVALID_PARAMETER | One or more of the provided parameters are invalid. |
| STOR_STATUS_UNSUCCESSFUL | Returned for other internal system reasons. |

## Remarks

Miniport drivers that create device-dedicated threads call **StorPortCreateSystemThread**, either when they initialize or when I/O requests begin to come in to the driver's *Dispatch* routines. For example, a driver might create such a thread when it receives an asynchronous device control request.

The thread continues to run until either the system is shut down or the thread terminates itself by calling [**StorPortTerminateSystemThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportterminatesystemthread).

Thread priority can be changed by calling [**StorPortSetPriorityThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetprioritythread). A miniport should specify a thread priority value that avoids run-time priority inversions. See [Device-dedicated Threads](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-dedicated-threads) for more information.

For a given adapter, the maximum system threads that a miniport can create is the maximum logical processor count in the system.

## See also

[**STOR_THREAD_PRIORITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-stor_thread_priority)

[**STOR_THREAD_START_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-stor_thread_start_routine)

[**StorPortSetPriorityThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetprioritythread)

[**StorPortTerminateSystemThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportterminatesystemthread)