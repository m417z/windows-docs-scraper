# NdisDprAcquireSpinLock macro

## Description

The
**NdisDprAcquireSpinLock** function acquires a spin lock so the caller can synchronize access to
resources shared among non-ISR driver functions in a multiprocessor-safe way.

## Parameters

### `_SpinLock` [in]

Pointer to an opaque spin lock, already initialized by the caller.

## Remarks

The miniport driver must initialize a variable of type NDIS_SPIN_LOCK with
[NdisAllocateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatespinlock) before it calls
any other
**Ndis..SpinLock** function. The driver must provide resident storage for the spin lock(s) it uses.

**NdisDprAcquireSpinLock** is an optimized version of
[NdisAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirespinlock) that a miniport
driver can call only while running at IRQL = DISPATCH_LEVEL.

After acquiring a spin lock with
**NdisDprAcquireSpinLock**, the caller must release that lock with a call to
[NdisDprReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdprreleasespinlock). A miniport
driver must call
**NdisDprReleaseSpinLock** following each call to
**NdisDprAcquireSpinLock**. Otherwise, a deadlock occurs, hanging the driver.

A spin lock acquired with
**NdisDprAcquireSpinLock** must be released with
**NdisDprReleaseSpinLock**. A spin lock acquired with
**NdisAcquireSpinLock** must be released with
**NdisReleaseSpinLock**.

A driver should never hold a spin lock for an extended period (more than a few instructions). Holding
a spin lock for longer than 25 microseconds degrades both system and driver performance.

A miniport driver cannot use a spin lock to protect resources that its other functions share with the
[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr) and/or
[MiniportDisableInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_disable_interrupt) functions. Instead, a miniport driver must call
[NdisMSynchronizeWithInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsynchronizewithinterruptex) so that its
[MiniportSynchronizeInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_synchronize_interrupt) function accesses such shared resources at the same DIRQL at which its
*MiniportInterrupt* and/or
*MiniportDisableInterruptEx* functions do.

For more information about acquiring and releasing NDIS spin locks, see
[Synchronization
and Notification in Network Drivers](https://learn.microsoft.com/windows-hardware/drivers/network/synchronization-and-notification-in-network-drivers).

## See also

[MiniportDisableInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_disable_interrupt)

[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr)

[MiniportSynchronizeInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_synchronize_interrupt)

[NdisAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirespinlock)

[NdisAllocateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatespinlock)

[NdisDprReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdprreleasespinlock)

[NdisMSynchronizeWithInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsynchronizewithinterruptex)

[NetTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_timer_function)