# KeReleaseInterruptSpinLock function

## Description

The **KeReleaseInterruptSpinLock** routine releases an interrupt spin lock acquired by [KeAcquireInterruptSpinLock](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551914(v=vs.85)).

## Parameters

### `Interrupt` [in, out]

Specifies the value of the *Interrupt* parameter passed to [KeAcquireInterruptSpinLock](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551914(v=vs.85)).

### `OldIrql` [in]

Specifies the IRQL value returned by **KeAcquireInterruptSpinLock**.

## Remarks

The **KeReleaseInterruptSpinLock** releases the interrupt spin lock, and lowers the IRQL value back to the *OldIrql* value.

## See also

[KeAcquireInterruptSpinLock](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551914(v=vs.85))

[KeSynchronizeExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesynchronizeexecution)