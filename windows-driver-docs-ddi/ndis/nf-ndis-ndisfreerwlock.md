# NdisFreeRWLock function

## Description

The
**NdisFreeRWLock** function frees a read/write lock that was previously allocated with the
[NdisAllocateRWLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocaterwlock) function.

## Parameters

### `Lock` [in]

A pointer to an opaque
[NDIS_RW_LOCK_EX](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff567279(v=vs.85)) variable that represents a
lock. The caller can use this lock to gain write or read access to resources that are shared among
non-ISR driver threads.

## Remarks

NDIS drivers call the
**NdisFreeRWLock** function to free the
[NDIS_RW_LOCK_EX](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff567279(v=vs.85)) structure and any associated
resources that were previously allocated with the
[NdisAllocateRWLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocaterwlock) function.

A driver must call the
[NdisReleaseRWLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreleaserwlock) function to release a
read/write lock before it calls the
**NdisFreeRWLock** function.

## See also

[NDIS_RW_LOCK_EX](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff567279(v=vs.85))

[NdisAllocateRWLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocaterwlock)

[NdisReleaseRWLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreleaserwlock)