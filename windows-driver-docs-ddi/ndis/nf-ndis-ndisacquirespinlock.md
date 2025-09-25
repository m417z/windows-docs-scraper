# NdisAcquireSpinLock macro

## Description

The
**NdisAcquireSpinLock** function acquires a spin lock so the caller gains exclusive access to the
resources, shared among driver functions, that the spin lock protects.

## Parameters

### `_SpinLock` [in]

Pointer to an opaque spin lock, already initialized by the caller.

## Remarks

The driver must initialize a variable of type NDIS_SPIN_LOCK with
[NdisAllocateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatespinlock) before it calls
any other
**Ndis*Xxx*SpinLock** function. The driver must provide resident storage for the spin lock(s) it uses.

After acquiring a spin lock with
**NdisAcquireSpinLock**, the caller must release that lock with a call to
[NdisReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreleasespinlock). A driver must
call
**NdisReleaseSpinLock** following each call to
**NdisAcquireSpinLock**. Otherwise, a deadlock occurs, hanging the driver.

A spin lock acquired with
**NdisAcquireSpinLock** must be released with
**NdisReleaseSpinLock**. A spin lock acquired with
[NdisDprAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdpracquirespinlock) must be
released with
[NdisDprReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdprreleasespinlock).

A driver should never hold a spin lock for an extended period (more than a few instructions). Holding
a spin lock for longer than 25 microseconds degrades both system and driver performance.

A miniport driver cannot use a spin lock to protect resources that its other functions share with the
[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr) and/or
[MiniportDisableInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_disable_interrupt) functions. Instead, a miniport driver must call
**NdisMSynchronizeWithInterruptEx** so that its
[MiniportSynchronizeInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_synchronize_interrupt) function accesses such shared resources at the same DIRQL at which its
*MiniportInterrupt* and/or
*MiniportDisableInterruptEx* functions do.

For more information about acquiring and releasing NDIS spin locks, see
[Synchronization
and Notification in Network Drivers](https://learn.microsoft.com/windows-hardware/drivers/network/synchronization-and-notification-in-network-drivers).

## See also

[MiniportDisableInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_disable_interrupt)

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr)

[MiniportSynchronizeInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_synchronize_interrupt)

[NdisAllocateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatespinlock)

[NdisDprAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdpracquirespinlock)

[NdisMSynchronizeWithInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsynchronizewithinterruptex)

[NdisReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreleasespinlock)