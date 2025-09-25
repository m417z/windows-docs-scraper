# RtwqPutWorkItem function

## Description

Puts an asynchronous operation on a work queue.

## Parameters

### `dwQueue` [in]

The identifier for the work queue. This value can specify one of the standard work queues, or a work queue created by the app. To access to a work queue, call [RtwqLockSharedWorkQueue](https://learn.microsoft.com/windows/win32/api/rtworkq/nf-rtworkq-rtwqlocksharedworkqueue).

### `lPriority` [in]

The priority of the work item. Work items are performed in order of priority. This value should be -1, 0, or 1, where -1 is the lowest priority and 1 is the highest priority.

### `result` [in]

A pointer to the callback . The caller must implement this interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.