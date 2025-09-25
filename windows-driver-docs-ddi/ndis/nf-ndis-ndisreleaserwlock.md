# NdisReleaseRWLock function

## Description

The
**NdisReleaseRWLock** function releases a read/write lock that the caller uses to gain access to
resources that are shared between driver threads.

## Parameters

### `Lock` [in]

A pointer to an opaque
[NDIS_RW_LOCK_EX](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff567279(v=vs.85)) variable that represents a
lock. The caller can use this lock to gain write or read access to resources that are shared between
non-ISR driver threads.

### `LockState` [in]

A pointer to an opaque
[LOCK_STATE_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_lock_state_ex) variable that tracks the state
of the lock. This variable exists in the interval between the times that the caller obtains and releases
the lock. The caller must use a different variable of type LOCK_STATE_EX for each attempt that it makes
to obtain the lock from the same non-ISR driver thread.

## Remarks

NDIS drivers call the
**NdisReleaseRWLock** function to release a read/write lock that was previously obtained by calling the
[NdisAcquireRWLockRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirerwlockread) or
[NdisAcquireRWLockWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirerwlockwrite) function.

A driver must obtain a read/write lock before the driver can call
**NdisReleaseRWLock**. Each call to obtain a lock requires a reciprocal call to
**NdisReleaseRWLock**.

The acquisition of an [NDIS_RW_LOCK_EX](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff567279(v=vs.85)) is affinitized to the current processor. Drivers must call **NdisReleaseRWLock** on the same processor that made the corresponding call to [NdisAcquireRWLockRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirerwlockread) or [NdisAcquireRWLockWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirerwlockwrite).

**NdisReleaseRWLock** restores the original IRQL that was used by its caller before the lock was
obtained.

## See also

[LOCK_STATE_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_lock_state_ex)

[NDIS_RW_LOCK_EX](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff567279(v=vs.85))

[NdisAcquireRWLockRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirerwlockread)

[NdisAcquireRWLockWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirerwlockwrite)