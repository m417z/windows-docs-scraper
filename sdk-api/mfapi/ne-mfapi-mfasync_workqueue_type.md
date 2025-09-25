# MFASYNC_WORKQUEUE_TYPE enumeration

## Description

Specifies the type of work queue for the [MFAllocateWorkQueueEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfallocateworkqueueex) function to create.

## Constants

### `MF_STANDARD_WORKQUEUE:0`

Create a work queue without a message loop.

### `MF_WINDOW_WORKQUEUE:1`

Create a work queue with a message loop.

### `MF_MULTITHREADED_WORKQUEUE:2`

Create a multithreaded work queue. This type of work queue uses a thread pool to dispatch work items. The caller is responsible for serializing the work items.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)