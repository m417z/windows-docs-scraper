# RtwqCancelWorkItem function

## Description

Attempts to cancel an asynchronous operation that was scheduled with [RtwqScheduleWorkItem](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqscheduleworkitem).

## Parameters

### `Key` [in]

The key that was received in the *key* parameter of the [RtwqScheduleWorkItem](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqscheduleworkitem).

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Because work items are asynchronous, the work-item callback might still be invoked after **RtwqCancelWorkItem** is called.