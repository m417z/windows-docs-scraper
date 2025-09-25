# ExReleaseSpinLockShared function

## Description

The **ExReleaseSpinLockShared** routine releases ownership of a [spin lock](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-spin-locks) that the caller previously acquired for shared access, and restores the IRQL to its original value.

## Parameters

### `SpinLock` [in, out]

A pointer to the spin lock to release. The caller must own this spin lock for shared access.

### `OldIrql` [in]

The interrupt request level (IRQL) to restore. Set this parameter to the KIRQL value that was returned by the [ExAcquireSpinLockShared](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirespinlockshared) call that acquired the spin lock.

## Remarks

This routine must be called only for a spin lock that is owned by the caller.

On entry to this routine, the caller must be running at IRQL = DISPATCH_LEVEL. Before exiting, **ExReleaseSpinLockShared** restores the IRQL to the value specified by the *OldIrql* parameter.

The caller should hold the spin lock only briefly before releasing it. For more information, see [Introduction to Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-spin-locks).

## See also

- [ExAcquireSpinLockShared](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirespinlockshared)