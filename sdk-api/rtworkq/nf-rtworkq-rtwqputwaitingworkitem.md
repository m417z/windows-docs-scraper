# RtwqPutWaitingWorkItem function

## Description

Queues a work item that waits for an event to be signaled.

## Parameters

### `hEvent` [in]

A handle to an event object, such as an event or timer. To create an event object, call [CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) or [CreateEventEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventexa).

### `lPriority` [in]

The priority of the work item. Work items are performed in order of priority.

### `result` [in]

A pointer to the [IRtwqAsyncResult](https://learn.microsoft.com/windows/desktop/api/rtworkq/nn-rtworkq-irtwqasyncresult) interface of an asynchronous result object. To create the result object, call [RtwqCreateAsyncResult](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqcreateasyncresult).

### `key` [out, optional]

Receives a key that can be used to cancel the wait. To cancel the wait, call [RtwqCancelWorkItem](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqcancelworkitem) and pass this key in the *Key* parameter. This parameter can be **NULL**.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.