# RtwqAllocateWorkQueue function

## Description

Creates a new work queue.

## Parameters

### `WorkQueueType` [in]

A member of the [RTWQ_WORKQUEUE_TYPE](https://learn.microsoft.com/windows/desktop/api/rtworkq/ne-rtworkq-rtwq_workqueue_type) enumeration, specifying the type of work queue to create.

| Value | Meaning |
| --- | --- |
| **RTWQ_MULTITHREADED_WORKQUEUE** | Create a multithreaded work queue. Generally, applications should not create private multithreaded queues. Use the platform multithreaded queues instead. |
| **RTWQ_STANDARD_WORKQUEUE** | Create a work queue without a message loop. Using this flag is equivalent to calling **RtwqAllocateWorkQueue**. |
| **RTWQ_WINDOW_WORKQUEUE** | Create a work queue with a message loop. The thread that dispatches the work items for this queue will also call [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) and [DispatchMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dispatchmessage). Use this option if your callback performs any actions that require a message loop. |

### `workQueueId` [out]

Receives an identifier for the work queue that was created.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.