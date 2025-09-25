## Description

The **KeAcquireSpinLock** routine acquires a spin lock so the caller can synchronize access to shared data in a multiprocessor-safe way by raising IRQL.

## Parameters

### `SpinLock`

Pointer to an initialized KSPIN_LOCK spin lock for which the caller provides the storage.

### `OldIrql`

Pointer to a KIRQL variable that is set to the current IRQL when this call occurs.

## Remarks

**KeAcquireSpinLock** first resets the IRQL to DISPATCH_LEVEL and then acquires the lock. The previous IRQL is written to *OldIrql* after the lock is acquired.

The *OldIrql* value must be specified when the spin lock is released with [**KeReleaseSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlock).

Most drivers use a local variable to store the old IRQL value. A driver can also use a shared memory location, such as a global variable, but the driver must not use the same location for two different locks. Otherwise, a race condition can occur.

Spin locks can cause serious problems if not used judiciously. In particular, no deadlock protection is performed and dispatching is disabled while the spin lock is held. Therefore:

- The code within a critical region guarded by a spin lock must neither be pageable nor make any references to pageable data.

- The code within a critical region guarded by a spin lock can neither call any external function that might access pageable data or raise an exception, nor can it generate any exceptions.

- The caller should release the spin lock with **KeReleaseSpinLock** as quickly as possible.

Attempting to acquire a spin lock recursively is guaranteed to cause a deadlock. For more information about spin locks, see [Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/spin-locks).

## See also

[**KeAcquireInStackQueuedSpinLock**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551899(v=vs.85))

[**KeAcquireSpinLockAtDpcLevel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlockatdpclevel)

[**KeInitializeSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock)

[**KeReleaseSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlock)

[Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/spin-locks)