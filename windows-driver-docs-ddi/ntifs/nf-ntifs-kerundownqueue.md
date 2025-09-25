# KeRundownQueue function

## Description

The **KeRundownQueue** routine cleans up a queue object, flushing any queued entries.

## Parameters

### `Queue` [in, out]

Pointer to an initialized queue object for which the caller provides resident storage in nonpaged pool.

## Return value

If the queue is empty, **KeRundownQueue** returns **NULL**; otherwise, it returns the address of the first entry in the queue.

## Remarks

File systems call **KeRundownQueue** to discard all entries from a queue before freeing or reusing the queue object.

If the queue object is to be reused, the caller must call [**KeInitializeQueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-keinitializequeue) after calling **KeRundownQueue**, in order to reinitialize the queue object before reusing it.

**KeRundownQueue** returns no information about how many queued entries are discarded.

Starting in Windows 7, **KeRundownQueue** wakes any threads currently waiting on the queue object with STATUS_ABANDONED. After returning from this function, any future threads that try to wait on this queue will immediately fail with STATUS_ABANDONED.

Prior to Windows 7, **KeRundownQueue** did not wake waiting threads when the queue was rundown. To avoid the possibility of leaving threads waiting forever on these OS versions, **KeRundownQueue** should never be called for a queue if any threads are waiting on the queue object.

For more information about using driver-managed internal queues, see [Driver-Managed Queues](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#driver-managed-queues).

## See also

[**KeInitializeQueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-keinitializequeue)

[**KeRemoveQueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-keremovequeue)