## Description

The **KeAcquireInStackQueuedSpinLockAtDpcLevel** routine acquires a queued spin lock when the caller is already running at IRQL \>= DISPATCH\_LEVEL.

## Parameters

### `SpinLock`

[in, out] Specifies the spin lock to acquire. This parameter must have been initialized by a call to the [**KeInitializeSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock) routine.

### `LockHandle`

[out] Pointer to a caller-supplied [**KLOCK\_QUEUE\_HANDLE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that the routine can use to return the spin lock queue handle. To release the lock, the caller passes this value to the [**KeReleaseInStackQueuedSpinLockFromDpcLevel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleaseinstackqueuedspinlockfromdpclevel) routine.

## Remarks

For a driver running at IRQL \>= DISPATCH\_LEVEL, **KeAcquireInStackQueuedSpinLockAtDpcLevel** acquires a spin lock as a *queued spin lock*. For more information, see [Queued Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/queued-spin-locks). To release the spin lock, call the [**KeReleaseInStackQueuedSpinLockFromDpcLevel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleaseinstackqueuedspinlockfromdpclevel) routine.

Drivers that are already running at an IRQL \>= DISPATCH\_LEVEL can call this routine to acquire the queued spin lock more quickly. Otherwise, use the [**KeAcquireInStackQueuedSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquireinstackqueuedspinlock) routine to acquire the spin lock.

For a driver that is running at IRQL \> DISPATCH\_LEVEL, this routine acquires the lock without modifying the current IRQL. For a driver that is running at IRQL = DISPATCH\_LEVEL, this routine improves performance by acquiring the lock without first setting the IRQL to DISPATCH\_LEVEL, which, in this case, would be a redundant operation.

Like ordinary spin locks, queued spin locks must only be used in very special circumstances. For a description of when to use spin locks, see [**KeAcquireSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock).

Drivers must not combine calls to [**KeAcquireSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock) and **KeAcquireInStackQueuedSpinLock** on the same spin lock. A spin lock must always be acquired or released either as a queued spin lock, or as an ordinary spin lock.

## See also

[**KLOCK\_QUEUE\_HANDLE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[**KeAcquireSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock)

[**KeAcquireInStackQueuedSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquireinstackqueuedspinlock)

[**KeInitializeSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock)

[**KeReleaseInStackQueuedSpinLockFromDpcLevel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleaseinstackqueuedspinlockfromdpclevel)