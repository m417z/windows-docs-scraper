# MFASYNCRESULT structure overview

## Description

Contains data that is needed to implement the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface.

## Members

### `overlapped`

An **OVERLAPPED** structure. This structure is used internally to queue the work item. Fill this member with zeros.

### `pCallback`

Pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface. This interface is implemented by the caller of the asynchronous method. This member can be **NULL**. If this member is **NULL**, the **hEvent** member must be a valid event handle.

### `hrStatusResult`

The status code returned when this structure is used with an I/O completion port. You can also use this member to hold the status code for the asynchronous operation, returned by [IMFAsyncResult::GetStatus](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasyncresult-getstatus).

### `dwBytesTransferred`

The number of bytes transferred when this structure is used with an I/O completion port. This member is used internally by the work queue. Set this member to zero.

### `hEvent`

Event handle. If **pCallback** is **NULL**, set this member to a valid event handle. The event is signaled when the work item is dispatched. Otherwise, set this member to **NULL**.

### `IMFAsyncResult`

## Remarks

Any custom implementation of the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface must inherit this structure. For more information, see [Custom Asynchronous Result Objects](https://learn.microsoft.com/windows/desktop/medfound/custom-asynchronous-result-objects).

## See also

[Custom Asynchronous Result Objects](https://learn.microsoft.com/windows/desktop/medfound/custom-asynchronous-result-objects)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)