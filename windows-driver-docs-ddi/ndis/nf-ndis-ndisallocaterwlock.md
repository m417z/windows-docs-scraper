# NdisAllocateRWLock function

## Description

The
**NdisAllocateRWLock** function allocates a read/write lock variable of type
[NDIS_RW_LOCK_EX](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff567279(v=vs.85)).

## Parameters

### `NdisHandle`

A handle returned from one of the following functions:

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)
[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver)
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)
[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)
**Windows 8 and Windows Server 2012 and later:** If the read/write lock is being allocated in [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) before any NDIS handle is available, the caller may pass a NULL value for this parameter.

## Return value

**NdisAllocateRWLock** returns a pointer to an
[NDIS_RW_LOCK_EX](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff567279(v=vs.85)) structure if one can be allocated; otherwise it returns **NULL**.

## Remarks

NDIS drivers call the
**NdisAllocateRWLock** function to allocate an
[NDIS_RW_LOCK_EX](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff567279(v=vs.85)) structure that controls
read/write access to resources that are shared among driver threads. Drivers use a read/write lock for
resources that are frequently accessed for reading and infrequently accessed for writing.

Each lock that a driver allocates can do one of the following:

* Protect a discrete set of shared resources from concurrent write and read access by driver threads
  that run at IRQL <= DISPATCH_LEVEL.
* Expose a discrete set of shared resources to concurrent read access by driver threads that run at
  IRQL <= DISPATCH_LEVEL.

The [NDIS_RW_LOCK_EX](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff567279(v=vs.85)) pointer that
**NdisAllocateRWLock** returns is a required parameter for all other read/write lock functions.

An [NDIS_RW_LOCK_EX](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff567279(v=vs.85)) is not fair. That is, a processor waiting to acquire the lock for exclusive access may be starved by processors that hold the lock for read access. Therefore, do not use an **NDIS_RW_LOCK_EX** in situations where the majority of accesses will be for write access. If the majority of accesses will need write access, it is more efficient to simply use a kernel spin lock. For more information about spin locks, see [Introduction to Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-spin-locks).

In situations where there are many acquisitions for read access on more than one processor, the [NDIS_RW_LOCK_EX](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff567279(v=vs.85)) typically performs better than a kernel spin lock. Use **NDIS_RW_LOCK_EX** when you expect many read accesses per second distributed across more than one processor.

An [NDIS_RW_LOCK_EX](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff567279(v=vs.85)) structure defines attributes that limit write access to shared resources to one
non-ISR driver thread at a time. The **NDIS_RW_LOCK_EX** structure can allow multiple non-ISR driver threads
to have concurrent read access to the associated resources. Such read access is not permitted during a
write access.

To modify the protected resources, a driver thread must obtain a write lock with the
[NdisAcquireRWLockWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirerwlockwrite) function. To
simply read those resources, a driver thread must obtain a read-only lock with the
[NdisAcquireRWLockRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirerwlockread) function. Read
access does not require interlocked operations or contention for spin locks. Read-only access helps
maintain good operating system and driver performance.

After the resource access is complete, the driver calls the
[NdisReleaseRWLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreleaserwlock) function.

A driver must call the
[NdisFreeRWLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreerwlock) function to free the
[NDIS_RW_LOCK_EX](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff567279(v=vs.85)) structure that it allocated with the
**NdisAllocateRWLock** function.

You can use the **!ndiskd.ndisrwlock** debugger extension to inspect an [NDIS_RW_LOCK_EX](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff567279(v=vs.85)), see how many readers it has, and see who its current writer is. For more information, see [NDIS Extensions (Ndiskd.dll)](https://learn.microsoft.com/windows-hardware/drivers/debugger/ndis-extensions--ndiskd-dll-).

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[Introduction to Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-spin-locks)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS Extensions (Ndiskd.dll)](https://learn.microsoft.com/windows-hardware/drivers/debugger/ndis-extensions--ndiskd-dll-)

[NDIS_RW_LOCK_EX](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff567279(v=vs.85))

[NdisAcquireRWLockRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirerwlockread)

[NdisAcquireRWLockWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirerwlockwrite)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)

[NdisFreeRWLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreerwlock)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver)

[NdisReleaseRWLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreleaserwlock)