# KeRaiseIrqlToDpcLevel function (ntddk.h)

## Description

The **KeRaiseIrqlToDpcLevel** routine raises the hardware priority to IRQL = DISPATCH_LEVEL, thereby masking off interrupts of equivalent or lower IRQL on the current processor.

## Return value

**KeRaiseIrqlToDpcLevel** returns the IRQL at which the call occurred.

## Remarks

Any caller of **KeRaiseIrqlToDpcLevel** should save the returned IRQL value. Every such caller must restore the original IRQL as quickly as possible by passing this returned IRQL in a subsequent call to [KeLowerIrql](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kelowerirql).

Callers of **KeRaiseIrqlToDpcLevel** must be running at IRQL <= DISPATCH_LEVEL. Otherwise, a call to this routine causes a bug check.

## See also

[KeGetCurrentIrql](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetcurrentirql)

[KeLowerIrql](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kelowerirql)

[KeRaiseIrql](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keraiseirql)