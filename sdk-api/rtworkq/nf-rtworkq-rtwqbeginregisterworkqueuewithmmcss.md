# RtwqBeginRegisterWorkQueueWithMMCSS function

## Description

Associates a work queue with a Multimedia Class Scheduler Service (MMCSS) task.

## Parameters

### `workQueueId` [in]

The identifier of the work queue. For private work queues, the identifier is returned by the [RtwqAllocateWorkQueue](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqallocateworkqueue) function.

### `usageClass` [in]

The name of the MMCSS task.

### `dwTaskId` [in]

The unique task identifier. To obtain a new task identifier, set this value to zero.

### `lPriority` [in]

The base relative priority for the work-queue threads. For more information, see [AvSetMmThreadPriority](https://learn.microsoft.com/windows/desktop/api/avrt/nf-avrt-avsetmmthreadpriority).

### `doneCallback` [in]

A pointer to the [IRtwqAsyncCallback](https://learn.microsoft.com/windows/desktop/api/rtworkq/nn-rtworkq-irtwqasynccallback) interface of a callback object. The caller must implement this interface.

### `doneState` [in]

A pointer to the **IUnknown** interface of a state object, defined by the caller. This parameter can be **NULL**. You can use this object to hold state information. The object is returned to the caller when the callback is invoked.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.