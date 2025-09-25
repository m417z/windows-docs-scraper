# NdisDprReleaseReadWriteLock function

## Description

The
[NdisDprReleaseReadWriteLock](https://learn.microsoft.com/previous-versions/hh205389(v=vs.85)) function releases a lock that was acquired in a preceding call to
[NdisDprAcquireReadWriteLock](https://learn.microsoft.com/previous-versions/hh205388(v=vs.85)).

**Note** The read-write lock interface is deprecated for NDIS 6.20 and later drivers, which should use [NdisReleaseRWLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreleaserwlock) instead of [NdisDprReleaseReadWriteLock](https://learn.microsoft.com/previous-versions/hh205389(v=vs.85)).

## Parameters

### `Lock` [in, out]

A pointer to an [NDIS_RW_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_rw_lock) variable for the acquired lock to be released.

### `LockState`

A pointer to an opaque [LOCK_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_lock_state) variable that tracks the state of the lock. This variable exists
in the interval between the time the caller acquires and releases the lock.

## Remarks

A driver must initialize a lock before calling any other
Ndis*Xxx*ReadWriteLock function that is used to acquire or release read or write access to the
resources that are protected by that lock. The
[NdisInitializeReadWriteLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializereadwritelock) function is used to initialize a lock.

A driver must call the
[NdisDprAcquireReadWriteLock](https://learn.microsoft.com/previous-versions/hh205388(v=vs.85)) function
to acquire a lock before the driver can call
[NdisDprReleaseReadWriteLock](https://learn.microsoft.com/previous-versions/hh205389(v=vs.85)). Each call to
**NdisDprAcquireReadWriteLock** requires a reciprocal call to
**NdisDprReleaseReadWriteLock**.

## See also

[NdisDprAcquireReadWriteLock](https://learn.microsoft.com/previous-versions/hh205388(v=vs.85))

[NdisInitializeReadWriteLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializereadwritelock)

[NdisReleaseRWLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreleaserwlock)