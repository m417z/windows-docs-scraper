# RtwqScheduleWorkItem function

## Description

Schedules an asynchronous operation to be completed after a specified interval.

## Parameters

### `result` [in]

A pointer to the callback. The caller must implement this interface.

### `Timeout` [in]

Time-out interval, in milliseconds. Set this parameter to a negative value. The callback is invoked after *−Timeout* milliseconds. For example, if *Timeout* is −5000, the callback is invoked after 5000 milliseconds.

### `key` [out, optional]

Receives a key that can be used to cancel the timer. To cancel the wait, call [RtwqCancelWorkItem](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqcancelworkitem) and pass this key in the *Key* parameter.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.