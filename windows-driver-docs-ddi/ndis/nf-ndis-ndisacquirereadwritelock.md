# NdisAcquireReadWriteLock function

## Description

The
**NdisAcquireReadWriteLock** function acquires a lock that the caller uses for either write or read
access to the resources that are shared among driver threads.

**Note** The read-write lock interface is deprecated for NDIS 6.20 and later drivers, which should use [NdisAcquireRWLockRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirerwlockread) or [NdisAcquireRWLockWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirerwlockwrite) instead of **NdisAcquireReadWriteLock**.

## Parameters

### `Lock` [in, out]

A pointer to an opaque variable that represents a lock. The caller can use this lock to access
shared resources.

### `fWrite` [in]

A Boolean value. If the value is **TRUE**, this function is provided with write access to shared
resources; if the value is **FALSE**, this function is provided with read access.

### `LockState` [_out_]

**LockState**. A pointer to an opaque variable that tracks the state of the lock. This variable exists in the
interval between the time the caller acquires and releases the lock. The caller must use a different
variable of type [LOCK_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_lock_state) for each attempt that it makes to acquire the lock from the same non-ISR
driver thread.

## Remarks

The driver must initialize a variable of type [NDIS_RW_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_rw_lock) using the
[NdisInitializeReadWriteLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializereadwritelock) function before the driver calls any other
Ndis*Xxx*ReadWriteLock function. The driver must provide resident storage for the locks it uses.

After acquiring a lock by using
**NdisAcquireReadWriteLock**, the caller must release that lock by calling the
[NdisReleaseReadWriteLock](https://learn.microsoft.com/previous-versions/ff564521(v=vs.85)) function. To decrement the reference count of the lock, a driver must call
**NdisReleaseReadWriteLock** once for each call to
**NdisAcquireReadWriteLock**.

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

**NdisAcquireReadWriteLock** always raises the IRQL. For a write operation,
**NdisAcquireReadWriteLock** raises the IRQL by acquiring a spin lock. For a read operation,
**NdisAcquireReadWriteLock** explicitly raises the IRQL to IRQL = **DISPATCH_LEVEL**.

For more information about acquiring and releasing NDIS spin locks, see
[Synchronization
and Notification in Network Drivers](https://learn.microsoft.com/windows-hardware/drivers/network/synchronization-and-notification-in-network-drivers).

## See also

[MiniportDisableInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_disable_interrupt)

[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr)

[MiniportSynchronizeInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_synchronize_interrupt)

[NdisAcquireRWLockRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirerwlockread)

[NdisAcquireRWLockWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirerwlockwrite)

[NdisInitializeReadWriteLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializereadwritelock)

[NdisMSynchronizeWithInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsynchronizewithinterruptex)

[NdisReleaseReadWriteLock](https://learn.microsoft.com/previous-versions/ff564521(v=vs.85))