# RtwqSetDeadline function

## Description

Sets a deadline by which the work in a work queue must be completed.

## Parameters

### `workQueueId` [in]

The identifier for the work queue. The identifier is returned by the [RtwqAllocateWorkQueue](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqallocateworkqueue) function.

### `deadlineInHNS` [in]

 The deadline for the work in the queue to be completed, in hundred-nanosecond units. For example, if `deadlineInHNS` is 9600, that represents 9600 hundred-nanoseconds, which is equal to 960 microseconds, or 0.96 milliseconds.

### `pRequest` [in, out]

Receives a handle to the request that can be used to cancel the request by calling [RtwqCancelDeadline](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqcanceldeadline).

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Update a deadline by creating a new deadline and releasing the old one.

Cancel a deadline by calling [RtwqCancelDeadline](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqcanceldeadline).

## See also

[RtwqCancelDeadline](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqcanceldeadline)