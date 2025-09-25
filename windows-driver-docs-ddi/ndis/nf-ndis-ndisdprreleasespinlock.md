# NdisDprReleaseSpinLock macro

## Description

The
**NdisDprReleaseSpinLock** function releases a spin lock acquired in the immediately preceding call to
the
[NdisDprAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdpracquirespinlock) function.

## Parameters

### `_SpinLock` [in]

Pointer to the acquired spin lock to be released.

## Remarks

Release of the spin lock allows another driver function to use the resources the lock protects after
that function acquires the spin lock.

A spin lock acquired with
**NdisDprAcquireSpinLock** must be released with
**NdisDprReleaseSpinLock**. A spin lock acquired with
[NdisAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirespinlock) must be released
with
[NdisReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreleasespinlock).

For more information about acquiring and releasing NDIS spin locks, see
[Synchronization
and Notification in Network Drivers](https://learn.microsoft.com/windows-hardware/drivers/network/synchronization-and-notification-in-network-drivers).

## See also

[NdisDprAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdpracquirespinlock)