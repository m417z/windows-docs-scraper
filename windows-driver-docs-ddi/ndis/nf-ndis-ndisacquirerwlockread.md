# NdisAcquireRWLockRead function

## Description

The
**NdisAcquireRWLockRead** function obtains a read lock that the caller uses for read access to resources
that are shared among driver threads.

## Parameters

### `Lock` [in]

A pointer to an opaque
[NDIS_RW_LOCK_EX](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff567279(v=vs.85)) variable that represents a
lock. The caller can use this lock to gain write or read access to resources that are shared between
non-ISR driver threads.

### `LockState` [out]

A pointer to an opaque
[LOCK_STATE_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_lock_state_ex) variable that tracks the state
of the lock. This variable exists in the interval between the times that the caller obtains and releases
the lock. The caller must use a different variable of type **LOCK_STATE_EX** for each attempt that it makes
to obtain the lock from the same non-ISR driver thread.

### `Flags` [in]

A **ULONG** value that contains lock flags. Set this parameter to **NDIS_RWL_AT_DISPATCH_LEVEL** if the
caller's current IRQL is **DISPATCH_LEVEL**. Otherwise, set this parameter to zero. For more information
about dispatch IRQL tracking, see
[Dispatch IRQL Tracking](https://learn.microsoft.com/windows-hardware/drivers/network/dispatch-irql-tracking).

**Note** If the caller knows the current IRQL is **DISPATCH_LEVEL**, set this parameter to **NDIS_RWL_AT_DISPATCH_LEVEL**. This flag makes the lock even more efficient by causing it to omit a check for the current IRQL. If the current IRQL is unknown, do not test the current IRQL with [KeGetCurrentIrql](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetcurrentirql) solely to determine whether to set this flag, as it is more efficient to allow the **NdisAcquireRWLockRead** function to test the IRQL itself.

## Remarks

NDIS drivers call the
**NdisAcquireRWLockRead** function to obtain read-only access to resources that are shared between
driver threads.

The driver must allocate a variable of type
[NDIS_RW_LOCK_EX](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff567279(v=vs.85)) with the
[NdisAllocateRWLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocaterwlock) function before the
driver calls the
**NdisAcquireRWLockRead** function.

After the driver calls
[NdisAllocateRWLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocaterwlock), it can call
[NdisAcquireRWLockWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirerwlockwrite) or
**NdisAcquireRWLockRead** to obtain either write or read access to the resource. Only one non-ISR
driver thread at a time can obtain write access to the resource. When one non-ISR thread has write
access, all read and write accesses by other non-ISR threads must wait until the write-access holder
releases the lock. However, if a non-ISR thread has read access, other non-ISR threads can concurrently
obtain read access.

The [NDIS_RW_LOCK_EX](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff567279(v=vs.85)) lock does not support promotion from read to write. Once a processor has acquired an **NDIS_RW_LOCK_EX** for read access (by calling **NdisAcquireRWLockRead**), the same processor must not attempt to acquire write access (by calling [NdisAcquireRWLockWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirerwlockwrite)) until the previous read access is released.

An [NDIS_RW_LOCK_EX](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff567279(v=vs.85)) read lock can be acquired recursively on the same processor. For each call to **NdisAcquireRWLockRead**, there must be a corresponding call to [NdisReleaseRWLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreleaserwlock). The lock is only released after the last call to **NdisReleaseRWLock**.

The driver cannot use a lock to protect resources from read or write access that its other functions
share with the
[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr) or
[MiniportDisableInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_disable_interrupt) function, or both. Instead, the driver must call
[NdisMSynchronizeWithInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsynchronizewithinterruptex) so that its
[MiniportSynchronizeInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_synchronize_interrupt) function accesses such shared resources at the same DIRQL that its
*MiniportInterrupt* or
*MiniportDisableInterruptEx* functions, or both do.

**NdisAcquireRWLockRead** always raises the IRQL to IRQL = **DISPATCH_LEVEL**.

## See also

[LOCK_STATE_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_lock_state_ex)

[MiniportDisableInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_disable_interrupt)

[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr)

[MiniportSynchronizeInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_synchronize_interrupt)

[NDIS_RW_LOCK_EX](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff567279(v=vs.85))

[NdisAcquireRWLockWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirerwlockwrite)

[NdisAllocateRWLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocaterwlock)

[NdisMSynchronizeWithInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsynchronizewithinterruptex)

[NdisReleaseRWLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreleaserwlock)