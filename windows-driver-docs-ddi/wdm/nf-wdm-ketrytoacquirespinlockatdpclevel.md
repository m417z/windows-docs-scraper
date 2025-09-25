# KeTryToAcquireSpinLockAtDpcLevel function

## Description

The **KeTryToAcquireSpinLockAtDpcLevel** routine attempts to acquire a spin lock at DISPATCH_LEVEL.

## Parameters

### `SpinLock` [in, out]

Specifies the spin lock to acquire. The spin lock must have already been initialized by [KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock).

## Return value

**KeTryToAcquireSpinLockAtDpcLevel** returns **TRUE** if the spin lock has been acquired, and **FALSE** if the spin lock is already being held and cannot be acquired.

## Remarks

If the specified spin lock is not busy, the **KeTryToAcquireSpinLockAtDpcLevel** routine acquires the spin lock (see [KeAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock) for details) and returns **TRUE**. If the spin lock has already been acquired, the routine immediately returns **FALSE**.

If the spin lock is acquired, the caller can release it by using the [KeReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlock) routine.

If you want the driver to block when it is unable to acquire the spin lock, use [KeAcquireSpinLockAtDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlockatdpclevel) instead.

For more information about spin locks, see [Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/spin-locks).

## See also

[KeAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock)

[KeAcquireSpinLockAtDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlockatdpclevel)

[KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock)

[KeReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlock)