# KeTestSpinLock function

## Description

The **KeTestSpinLock** routine tests for the availability of a spin lock.

## Parameters

### `SpinLock` [in]

A pointer to a spin lock. The spin lock must have been initialized by calling [KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock).

## Return value

**KeTestSpinLock** returns **FALSE** if the spin lock is currently being held. Otherwise, it returns **TRUE**.

## Remarks

This routine enables the caller that is running at a low IRQL to test the spin lock. If **KeTestSpinLock** returns **TRUE**, the caller can try to acquire the spin lock with a high probability of immediate success.

This routine neither raises nor lowers the IRQL, and it never acquires the spin lock.

For more information about spin locks, see [Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/spin-locks).

## See also

[KeAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock)

[KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock)

[KeReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlock)