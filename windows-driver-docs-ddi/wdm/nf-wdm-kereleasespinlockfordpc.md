# KeReleaseSpinLockForDpc function

## Description

The **KeReleaseSpinLockForDpc** routine releases a spin lock that was acquired by calling [KeAcquireSpinLockForDpc](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551923(v=vs.85)).

## Parameters

### `SpinLock` [in, out]

Pointer to the spin lock that **KeAcquireSpinLockForDpc** acquired.

### `OldIrql` [in]

Specifies the IRQL that was current when the spin lock was acquired. Specify the value returned by **KeAcquireSpinLockForDpc**.

## Remarks

For more information about spin locks, see [Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/spin-locks).

If *OldIrql* = PASSIVE_LEVEL, **KeReleaseSpinLockForDpc** lowers the current IRQL to PASSIVE_LEVEL. If *OldIrql* = DISPATCH_LEVEL, **KeReleaseSpinLockForDpc** does not change the current IRQL.

## See also

[KeAcquireSpinLockForDpc](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551923(v=vs.85))