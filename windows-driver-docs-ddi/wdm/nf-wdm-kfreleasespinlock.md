## Description

The **KfReleaseSpinLock** routine releases a spin lock and restores the original IRQL at which the caller was running.

## Parameters

### `SpinLock`

Pointer to a KSPIN_LOCK spin lock for which the caller provides the storage.

### `NewIrql`

Specifies the KIRQL value saved from the preceding call to **[KfAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kfacquirespinlock)**.

## Remarks

For more information about spin locks, see **[Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/spin-locks)**.

## See also

- **[KeAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock)**
- **[KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock)**
- **[KeReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlock)**
- **[KfAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kfacquirespinlock)**
- [Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/spin-locks)