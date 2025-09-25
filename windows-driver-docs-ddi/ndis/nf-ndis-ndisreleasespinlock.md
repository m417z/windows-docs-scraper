# NdisReleaseSpinLock macro

## Description

The
**NdisReleaseSpinLock** function releases a spin lock that was acquired in a preceding call to the
[NdisAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirespinlock) function.

## Parameters

### `_SpinLock` [in]

Pointer to the acquired spin lock to be released.

## Remarks

A driver must initialize its spin lock with
[NdisAllocateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatespinlock) before it calls
any other
**Ndis..SpinLock** function to access the resources protected by that spin lock.

A driver must call
[NdisAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirespinlock) to acquire the
spin lock before it can call
**NdisReleaseSpinLock**. Each call to
**NdisAcquireSpinLock** requires a reciprocal call to
**NdisReleaseSpinLock** before the driver can call
**NdisAcquireSpinLock** again.

**NdisReleaseSpinLock** restores the original IRQL at which its caller was running before the call to
**NdisAcquireSpinLock**.

Any spin lock acquired with
**NdisAcquireSpinLock** must be released with
**NdisReleaseSpinLock**. Any spin lock acquired with
**NdisDprAcquireSpinLock** must be released with
**NdisDprReleaseSpinLock**.

For more information about acquiring and releasing NDIS spin locks, see
[Synchronization
and Notification in Network Drivers](https://learn.microsoft.com/windows-hardware/drivers/network/synchronization-and-notification-in-network-drivers).

## See also

[NdisAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirespinlock)

[NdisAllocateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatespinlock)

[NdisDprAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdpracquirespinlock)