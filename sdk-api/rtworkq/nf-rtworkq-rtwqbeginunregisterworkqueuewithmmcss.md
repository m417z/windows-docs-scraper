# RtwqBeginUnregisterWorkQueueWithMMCSS function

## Description

Unregisters a work queue from a Multimedia Class Scheduler Service (MMCSS) task.

## Parameters

### `workQueueId` [in]

The identifier of the work queue. For private work queues, the identifier is returned by the [RtwqAllocateWorkQueue](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqallocateworkqueue) function.

### `doneCallback` [in]

Pointer to the [IRtwqAsyncCallback](https://learn.microsoft.com/windows/desktop/api/rtworkq/nn-rtworkq-irtwqasynccallback) interface of a callback object. The caller must implement this interface.

### `doneState` [in]

Pointer to the **IUnknown** interface of a state object, defined by the caller. This parameter can be **NULL**. You can use this object to hold state information. The object is returned to the caller when the callback is invoked.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.