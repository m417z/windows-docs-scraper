## Description

The **KeAcquireSpinLockRaiseToDpc** routine is a faster version of the [**KeAcquireSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock) routine.

## Parameters

### `SpinLock`

[in, out] Specifies the spin lock to acquire. The spin lock must already have been initialized by [**KeInitializeSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock).

## Return value

**KeAcquireSpinLockRaiseToDpc** returns the current IRQL at the time the routine is called. This value is passed to [**KeReleaseSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlock)) when the spin lock is released.

## Remarks

The effect of this routine is identical to that of [**KeAcquireSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock). In particular, the acquired spin lock is released by [**KeReleaseSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlock). For more information, see the reference page for **KeAcquireSpinLock**.

Drivers can try to acquire the spin lock without blocking by using [**KeTryToAcquireSpinLockAtDpcLevel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ketrytoacquirespinlockatdpclevel).

For more information about spin locks, see [Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-spin-locks).

## See also

[**KeAcquireInStackQueuedSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquireinstackqueuedspinlock)

[**KeAcquireSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock)

[**KeInitializeSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock)