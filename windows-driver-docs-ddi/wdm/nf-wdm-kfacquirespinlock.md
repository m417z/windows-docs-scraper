## Description

The **KfAcquireSpinLock** routine acquires a spin lock so the caller can synchronize access to shared data in a multiprocessor-safe way by raising IRQL.

## Parameters

### `SpinLock`

Pointer to an initialized KSPIN_LOCK spin lock for which the caller provides the storage.

## Return value

## Remarks

For more information about spin locks, see [Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/spin-locks).

## See also

- **[KeAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock)**
- **[KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock)**
- **[KeReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlock)**
- **[KfReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kfreleasespinlock)**
- [Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/spin-locks)