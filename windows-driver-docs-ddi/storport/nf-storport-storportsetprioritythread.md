## Description

**StorPortSetPriorityThread** sets the run-time priority of a miniport-created thread.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport's hardware device extension.

### `ThreadContext` [in]

Pointer to the thread context received in a prior call to [**StorPortCreateSystemThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportcreatesystemthread).

### `Priority` [in]

A [**STOR_THREAD_PRIORITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-stor_thread_priority) enum value that specifies the thread priority to set.

## Return value

**StorPortSetPriorityThread** returns one of the following values:

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_SUCCESS | The specified thread priority was set successfully. |
| STOR_STATUS_INVALID_IRQL | IRQL level must equal PASSIVE_LEVEL. |
| STOR_STATUS_INVALID_PARAMETER | One or more of the provided parameters are invalid. |
| STOR_STATUS_UNSUCCESSFUL | Returned for other internal system reasons. |

## Remarks

A miniport can call **StorPortSetPriorityThread** to change the priority of the thread specified by **ThreadContext**.

Threads, whatever their respective run-time priorities, are run at IRQL = PASSIVE_LEVEL. See [Thread Priorities](https://learn.microsoft.com/windows-hardware/drivers/kernel/thread-priorities) for more information.

A miniport should specify a thread priority value that avoids run-time priority inversions. See [Device-dedicated Threads](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-dedicated-threads) for more information.

## See also

[**STOR_THREAD_PRIORITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-stor_thread_priority)

[**StorPortCreateSystemThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportcreatesystemthread)