## Description

The **ExAcquireSpinLockExclusive** routine acquires a [spin lock](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-spin-locks) for exclusive access by the caller, and raises the IRQL to DISPATCH_LEVEL.

## Parameters

### `SpinLock`

[in, out] A pointer to the spin lock to acquire for exclusive access. The caller must not already own this spin lock.

## Return value

**ExAcquireSpinLockExclusive** returns the previous IRQL value. For more information, see Remarks.

## Remarks

On entry to this routine, the caller must be running at IRQL \<= DISPATCH_LEVEL. This routine raises the IRQL to DISPATCH_LEVEL and returns the original (on-entry) IRQL value.

To release the spin lock, call the [**ExReleaseSpinLockExclusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleasespinlockexclusive) routine. **ExReleaseSpinLockExclusive** restores the IRQL to the original value that it had on entry to **ExAcquireSpinLockExclusive**.

A spin lock is a 32-bit variable of type EX_SPIN_LOCK. The driver must allocate the storage for the spin lock and initialize the spin lock to zero. This storage must be located in nonpaged system-space memory.

The caller should hold the spin lock only briefly before releasing it. For more information, see [Introduction to Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-spin-locks).

Recursive acquisition of a spin lock causes deadlock and is not allowed.

## See also

[**ExReleaseSpinLockExclusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleasespinlockexclusive)