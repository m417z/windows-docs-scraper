## Description

The **KeReleaseSpinLock** routine releases a spin lock and restores the original IRQL at which the caller was running.

## Parameters

### `SpinLock`

Pointer to a KSPIN_LOCK spin lock for which the caller provides the storage.

### `NewIrql`

Specifies the KIRQL value saved from the preceding call to [**KeAcquireSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock).

## Remarks

This call is a reciprocal to **KeAcquireSpinLock**. The input *NewIrql* value must be the *OldIrql* returned by **KeAcquireSpinLock**.

For more information about spin locks, see [Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/spin-locks).

Callers of this routine are running at IRQL = DISPATCH_LEVEL. On return from **KeReleaseSpinLock**, IRQL is restored to the *NewIrql* value.

## See also

- **[KeAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock)**
- **[KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock)**
- [Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/spin-locks)