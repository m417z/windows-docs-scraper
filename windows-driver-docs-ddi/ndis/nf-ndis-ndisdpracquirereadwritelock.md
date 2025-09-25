# NdisDprAcquireReadWriteLock function

## Description

The
[NdisDprAcquireReadWriteLock](https://learn.microsoft.com/previous-versions/hh205388(v=vs.85)) function acquires a lock that the caller uses for either write or read
access to the resources that are shared among driver threads.

**Note** The read-write lock interface is deprecated for NDIS 6.20 and later drivers, which should use [NdisAcquireRWLockRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirerwlockread) or [NdisAcquireRWLockWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirerwlockwrite) (setting **NDIS_RWL_AT_DISPATCH_LEVEL** in the *Flags* parameter) instead of [NdisDprAcquireReadWriteLock](https://learn.microsoft.com/previous-versions/hh205388(v=vs.85)).

## Parameters

### `Lock` [in, out]

A pointer to an opaque variable that represents a lock. The caller can use this lock to access
shared resources.

### `fWrite` [in]

A Boolean value. If the value is TRUE, this function is provided with write access to shared
resources; if the value is FALSE, this function is provided with read access.

### `LockState` [out]

A pointer to an opaque variable that tracks the state of the lock. This variable exists in the
interval between the time the caller acquires and releases the lock. The caller must use a different
variable of type [LOCK_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_lock_state) for each attempt that it makes to acquire the lock from the same non-ISR
driver thread.

## Remarks

The driver must initialize a variable of type [NDIS_RW_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_rw_lock) using the
[NdisInitializeReadWriteLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializereadwritelock) function before the driver calls any other
Ndis*Xxx*ReadWriteLock function. The driver must provide resident storage for the locks it uses.

After acquiring a lock by using
[NdisDprAcquireReadWriteLock](https://learn.microsoft.com/previous-versions/hh205388(v=vs.85)), the caller must release that lock by calling the
[NdisDprReleaseReadWriteLock](https://learn.microsoft.com/previous-versions/hh205389(v=vs.85)) function. To decrement the reference count of the lock, a driver must call
**NdisDprReleaseReadWriteLock** once for each call to
**NdisDprAcquireReadWriteLock**.

It is safe to use both [NdisDprAcquireReadWriteLock](https://learn.microsoft.com/previous-versions/hh205388(v=vs.85)) and **NdisDprAcquireReadWriteLock** on the same lock. However, calls must be balanced so that if the lock is acquired with **NdisDprAcquireReadWriteLock**, it must be released with [NdisDprReleaseReadWriteLock](https://learn.microsoft.com/previous-versions/hh205389(v=vs.85)). Likewise, if the lock is acquired with **NdisAcquireReadWriteLock**, it must be released with **NdisReleaseReadWriteLock**.

With some architectures, [NdisDprAcquireReadWriteLock](https://learn.microsoft.com/previous-versions/hh205388(v=vs.85)) performs faster than **NdisAcquireReadWriteLock**. Drivers can use **NdisDprAcquireReadWriteLock** rather than **NdisAcquireReadWriteLock** when it is certain that the current IRQL is already **DISPATCH_LEVEL**. However, it is not required. The overhead of calling the [KeGetCurrentIrql](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetcurrentirql) function is greater than the performance advantage of calling **NdisDprAcquireReadWriteLock** rather than **NdisAcquireReadWriteLock**.

To modify resources that are shared among driver threads, a driver thread must acquire a write lock.
To simply monitor those resources, a driver thread must acquire a read-only lock. Read access does not
require interlocked operations or contention for spin locks. Using read-only access helps to maintain
good operating system and driver performance.

A driver thread should never hold a write lock for more than 25 microseconds. Holding a write lock for
a prolonged period degrades both operating system and driver performance.

The driver cannot use a lock to protect resources from read or write access that its other functions
share with the
[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr) and/or
[MiniportDisableInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_disable_interrupt) functions. Instead, the driver must call
[NdisMSynchronizeWithInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsynchronizewithinterruptex) so that its
[MiniportSynchronizeInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_synchronize_interrupt) function accesses such shared resources at the same DIRQL at which its
*MiniportInterrupt* and/or
*MiniportDisableInterruptEx* functions do.

For more information about acquiring and releasing NDIS spin locks, see
[Synchronization
and Notification in Network Drivers](https://learn.microsoft.com/windows-hardware/drivers/network/synchronization-and-notification-in-network-drivers).

## See also

[LOCK_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_lock_state)

[MiniportDisableInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_disable_interrupt)

[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr)

[MiniportSynchronizeInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_synchronize_interrupt)

[NdisAcquireRWLockRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirerwlockread)

[NdisAcquireRWLockWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirerwlockwrite)

[NdisDprReleaseReadWriteLock](https://learn.microsoft.com/previous-versions/hh205389(v=vs.85))

[NdisInitializeReadWriteLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializereadwritelock)

[NdisMSynchronizeWithInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsynchronizewithinterruptex)