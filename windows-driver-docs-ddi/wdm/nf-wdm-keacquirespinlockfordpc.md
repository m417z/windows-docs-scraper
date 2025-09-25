## Description

The **KeAcquireSpinLockForDpc** routine acquires a threaded DPC spin lock.

## Parameters

### `SpinLock`

[in, out] Pointer to the spin lock to acquire. You must have already initialized the spin lock by calling [**KeInitializeSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock).

## Return value

**KeAcquireSpinLockForDpc** returns the current IRQL at the time the routine is called. Pass this value to [**KeReleaseSpinLockForDpc**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlockfordpc) when you release the spin lock.

## Remarks

A [*CustomThreadedDpc*](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-threaded-dpcs) routine can call **KeAcquireSpinLockForDpc** to acquire a spin lock. If *CustomThreadedDpc* is executing at IRQL = PASSIVE\_LEVEL, **KeAcquireSpinLockForDpc** raises the current IRQL to DISPATCH\_LEVEL. If *CustomThreadedDpc* is already executing at IRQL = DISPATCH\_LEVEL, **KeAcquireSpinLockForDpc** does not change the current IRQL.

Call [**KeReleaseSpinLockForDpc**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlockfordpc) to release a spin lock acquired by **KeAcquireSpinLockForDpc**. Pass the return value from **KeAcquireSpinLockForDpc** to **KeReleaseSpinLockForDpc**.

For more information about spin locks, see [Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-spin-locks).

## See also

[*CustomThreadedDpc*](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-threaded-dpcs)

[**KeInitializeSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock)

[**KeReleaseSpinLockForDpc**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlockfordpc)