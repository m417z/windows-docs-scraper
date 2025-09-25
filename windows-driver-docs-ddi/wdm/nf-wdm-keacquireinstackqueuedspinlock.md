## Description

The **KeAcquireInStackQueuedSpinLock** routine acquires a queued spin lock.

## Parameters

### `SpinLock`

[in, out] Specifies the spin lock to acquire. This parameter must have been initialized with [**KeInitializeSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock).

### `LockHandle`

[out] A pointer to a caller-supplied [**KLOCK_QUEUE_HANDLE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) variable that the routine can use to return the spin lock queue handle. The caller passes this value to [**KeReleaseInStackQueuedSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleaseinstackqueuedspinlock) when releasing the lock. Drivers should normally allocate the structure on the stack each time they acquire the lock. A driver should not use the same KLOCK_QUEUE_HANDLE from multiple calling sites.

## Remarks

**KeAcquireInStackQueuedSpinLock** acquires a spin lock as a *queued spin lock*. For more information, see [Queued Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/queued-spin-locks). The caller releases the spin lock by calling the [**KeReleaseInStackQueuedSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleaseinstackqueuedspinlock) routine.

Like ordinary spin locks, queued spin locks must only be used in very special circumstances. For a description of when to use spin locks, see [**KeAcquireSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock).

This routine raises the IRQL level to DISPATCH_LEVEL when acquiring the spin lock. If the caller is guaranteed to already be running at DISPATCH_LEVEL, it is more efficient to call [**KeAcquireInStackQueuedSpinLockAtDpcLevel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquireinstackqueuedspinlockatdpclevel).

The call to **KeReleaseInStackQueuedSpinLock** that releases the spin lock must occur at IRQL = DISPATCH_LEVEL. This call restores the original IRQL that the operating system saved at the beginning of the **KeAcquireInStackQueuedSpinLock** call. If a driver acquires multiple queued spin locks in series, it must release them in reverse order to properly restore the original IRQL.

Drivers must not combine calls to **KeAcquireSpinLock** and **KeAcquireInStackQueuedSpinLock** on the same spin lock. A spin lock must always be acquired or released as either a queued spin lock, or as an ordinary spin lock.

## See also

[**KLOCK_QUEUE_HANDLE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[**KeAcquireInStackQueuedSpinLockAtDpcLevel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquireinstackqueuedspinlockatdpclevel)

[**KeAcquireSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock)

[**KeInitializeSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock)

[**KeReleaseInStackQueuedSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleaseinstackqueuedspinlock)