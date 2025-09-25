## Description

The **ExAcquireSpinLockSharedAtDpcLevel** routine acquires a [spin lock](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-spin-locks) for shared access by a caller that is already running at IRQL \>= DISPATCH_LEVEL.

## Parameters

### `SpinLock`

[in, out] A pointer to the spin lock to acquire for shared access. The caller must not already own this spin lock.

## Remarks

On entry to this routine, the caller must be running at IRQL \>= DISPATCH_LEVEL. This routine does not change the IRQL.

To release the spin lock, the driver calls the [**ExReleaseSpinLockSharedFromDpcLevel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleasespinlocksharedfromdpclevel) routine.

A spin lock is a 32-bit variable of type EX_SPIN_LOCK. The driver must allocate the storage for the spin lock and initialize the spin lock to zero. This storage must be located in nonpaged system-space memory.

The caller should hold the spin lock only briefly before releasing it. For more information, see [Introduction to Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-spin-locks).

Recursive acquisition of a spin lock causes deadlock and is not allowed.

## See also

[**ExReleaseSpinLockSharedFromDpcLevel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleasespinlocksharedfromdpclevel)