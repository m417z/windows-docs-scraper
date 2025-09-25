# MFAllocateWorkQueueEx function

## Description

Creates a new work queue. This function extends the capabilities of the [MFAllocateWorkQueue](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfallocateworkqueue) function by making it possible to create a work queue that has a message loop.

## Parameters

### `WorkQueueType` [in]

A member of the [MFASYNC_WORKQUEUE_TYPE](https://learn.microsoft.com/windows/desktop/api/mfapi/ne-mfapi-mfasync_workqueue_type) enumeration, specifying the type of work queue to create.

| Value | Meaning |
| --- | --- |
| **MF_MULTITHREADED_WORKQUEUE** | Create a multithreaded work queue. Generally, applications should not create private multithreaded queues. Use the platform multithreaded queues instead. For more information, see [Work Queue and Threading Improvements](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-work-queue-and-threading-improvements). |
| **MF_STANDARD_WORKQUEUE** | Create a work queue without a message loop. Using this flag is equivalent to calling [MFAllocateWorkQueue](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfallocateworkqueue). |
| **MF_WINDOW_WORKQUEUE** | Create a work queue with a message loop. The thread that dispatches the work items for this queue will also call [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) and [DispatchMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dispatchmessage). Use this option if your callback performs any actions that require a message loop. |

### `pdwWorkQueue` [out]

Receives an identifier for the work queue that was created.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |
| **E_FAIL** | The application exceeded the maximum number of work queues. |
| **E_INVALIDARG** | Invalid argument. |
| **MF_E_SHUTDOWN** | The application did not call [MFStartup](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfstartup), or the application has already called [MFShutdown](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfshutdown). |

## Remarks

When you are done using the work queue, call [MFUnlockWorkQueue](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfunlockworkqueue).

The [MFAllocateWorkQueue](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfallocateworkqueue) function is equivalent to calling **MFAllocateWorkQueueEx** with the value MF_STANDARD_WORKQUEUE for the *WorkQueueType* parameter.

This function is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[MFPutWorkItem](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfputworkitem)

[MFPutWorkItemEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfputworkitemex)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)