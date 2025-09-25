# RTWQ_WORKQUEUE_TYPE enumeration

## Description

Specifies the type of work queue for the [RtwqAllocateWorkQueue](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqallocateworkqueue) function to create.

## Constants

### `RTWQ_STANDARD_WORKQUEUE:0`

Create a work queue without a message loop.

### `RTWQ_WINDOW_WORKQUEUE:1`

Create a work queue with a message loop.

### `RTWQ_MULTITHREADED_WORKQUEUE:2`

Create a multithreaded work queue. This type of work queue uses a thread pool to dispatch work items. The caller is responsible for serializing the work items.