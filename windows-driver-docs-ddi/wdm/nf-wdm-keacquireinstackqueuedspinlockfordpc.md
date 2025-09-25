## Description

The **KeAcquireInStackQueuedSpinLockForDpc** routine acquires a queued spin lock for a threaded DPC.

## Parameters

### `SpinLock`

[in, out] Pointer to the spin lock to acquire as a queued spin lock. You must have already initialized the spin lock by calling [**KeInitializeSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock).

### `LockHandle`

[out] Pointer to a [**KLOCK\_QUEUE\_HANDLE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that receives the lock queue handle. Pass this value to the [**KeReleaseInStackQueuedSpinLockForDpc**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleaseinstackqueuedspinlockfordpc) routine when you release the queued spin lock.

## Remarks

A [*CustomThreadedDpc*](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-threaded-dpcs) routine can use **KeAcquireInStackQueuedSpinLockForDpc** to acquire a queued spin lock. If *CustomThreadedDpc* is executing at IRQL = PASSIVE\_LEVEL, **KeAcquireInStackQueuedSpinLockForDpc** raises the current IRQL to DISPATCH\_LEVEL. If *CustomThreadedDpc* is already executing at IRQL = DISPATCH\_LEVEL, **KeAcquireInStackQueuedSpinLockForDpc** does not change the current IRQL.

For more information about queued spin locks, see [Queued Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/queued-spin-locks).

Call **KeReleaseInStackQueuedSpinLockForDpc** to release the spin lock that **KeAcquireInStackQueuedSpinLockForDpc** acquired.

## See also

[*CustomThreadedDpc*](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-threaded-dpcs)

[**KLOCK\_QUEUE\_HANDLE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[**KeInitializeSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock)

[**KeReleaseInStackQueuedSpinLockForDpc**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleaseinstackqueuedspinlockfordpc)