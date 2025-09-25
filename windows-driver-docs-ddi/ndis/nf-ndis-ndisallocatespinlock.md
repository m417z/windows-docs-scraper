# NdisAllocateSpinLock function

## Description

The
**NdisAllocateSpinLock** function initializes a variable of type NDIS_SPIN_LOCK, used to synchronize
access to resources shared among non-ISR driver functions.

## Parameters

### `SpinLock` [out]

Pointer to an opaque variable that represents a spin lock.

## Remarks

Before a driver calls
[NdisAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirespinlock),
[NdisDprAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdpracquirespinlock), or any of
the
**NdisInterlocked*Xxx*** functions, it must call
**NdisAllocateSpinLock** to initialize the spin lock passed as a required parameter to these
**Ndis*Xxx*** functions. The caller must provide nonpaged storage for the variable at
*SpinLock* .

After calling
**NdisAllocateSpinLock**, the driver can call
**NdisAcquireSpinLock** to obtain exclusive use of the resource(s) the spin lock protects. When
resource access is complete, the driver calls
[NdisReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreleasespinlock) so that other
driver functions can access the resource(s) protected by that spin lock.

As a general rule, to improve performance a driver should use different locks to protect different
critical sections. Thus, a driver might initialize more than one spin lock with
**NdisAllocateSpinLock**.

Each spin lock that a driver allocates protects a discrete set of shared resources from simultaneous
access by driver functions that run at IRQL <= DISPATCH_LEVEL. For example, a driver that maintains an
internal queue of packets might initialize one spin lock to protect its queue and another to protect a
set of state variables that several driver functions, not including the
[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr) or
[MiniportDisableInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_disable_interrupt) function, access while the driver is processing packets.

**NdisAcquireSpinLock** raises the IRQL to DISPATCH_LEVEL and stores the old IRQL in the spin lock.
Releasing the spin lock sets the IRQL to the value stored in the spin lock. Because NDIS sometimes enters
drivers at PASSIVE_LEVEL, problems can arise with the following code:

```
NdisAcquireSpinLock(A);
NdisAcquireSpinLock(B);
NdisReleaseSpinLock(A);
NdisReleaseSpinLock(B);
```

A driver should not access spin locks in this sequence for the following reasons:

* Between
  **NdisReleaseSpinLock**(A) and
  **NdisReleaseSpinLock**(B) the code is running at PASSIVE_LEVEL instead of DISPATCH_LEVEL and is
  subject to inappropriate interruption.
* After
  **NdisReleaseSpinLock**(B) the code is running at DISPATCH_LEVEL which could cause the caller to
  fault at much later time with an IRQL_NOT_LESS_OR_EQUAL stop error.

A driver should
never use two spin locks to protect the same (sub)set of resources because nested spin lock
acquisitions so frequently cause deadlocks. Even if a driver could be designed to prevent deadlocks,
nested spin lock acquisitions have an adverse effect on driver performance and I/O throughput.

A miniport driver cannot use a spin lock to protect resources that its non-ISR functions share with
its
[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr) or
[MiniportDisableInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_disable_interrupt) function. To access resources shared with a
*MiniportInterrupt* or
*MiniportDisableInterruptEx* function, a miniport driver must call
[NdisMSynchronizeWithInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsynchronizewithinterruptex) to have its
[MiniportSynchronizeInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_synchronize_interrupt) function access those resources at DIRQL.

When a driver no longer requires resource protection, for example, when a NIC is being removed and the
driver is releasing the resources it allocated for that NIC, the driver calls
[NdisFreeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreespinlock).

Freeing a spin lock and releasing a spin lock are potentially confusing.
**NdisFreeSpinLock** clears the memory at
*SpinLock* so it no longer represents a spin lock. Releasing an acquired spin lock with
[NdisReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreleasespinlock) simply allows
another thread of execution to acquire that spin lock.

For more information about acquiring and releasing NDIS spin locks, see
[Synchronization
and Notification in Network Drivers](https://learn.microsoft.com/windows-hardware/drivers/network/synchronization-and-notification-in-network-drivers).

Callers of
**NdisAllocateSpinLock** can run at any IRQL. Usually a caller is running at IRQL = PASSIVE_LEVEL
during initialization.

## See also

[DriverEntry of NDIS Protocol
Drivers](https://learn.microsoft.com/previous-versions/windows/embedded/gg156036(v=winembedded.80))

[MiniportDisableInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_disable_interrupt)

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr)

[NdisAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirespinlock)

[NdisDprAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdpracquirespinlock)

[NdisDprReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdprreleasespinlock)

[NdisFreeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreespinlock)

[NdisInterlockedAddUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedaddulong)

[NdisInterlockedInsertHeadList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedinsertheadlist)

[NdisInterlockedInsertTailList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedinserttaillist)

[NdisInterlockedRemoveHeadList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedremoveheadlist)

[NdisMSynchronizeWithInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsynchronizewithinterruptex)

[NdisReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreleasespinlock)

[NetTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_timer_function)