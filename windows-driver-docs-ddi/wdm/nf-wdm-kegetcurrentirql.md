# KeGetCurrentIrql function

## Description

The **KeGetCurrentIrql** routine returns the current IRQL. For information about IRQLs, see [Managing Hardware Priorities](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-hardware-priorities).

## Return value

**KeGetCurrentIrql** returns the current IRQL.

## See also

[KeAcquireSpinLockAtDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlockatdpclevel)

[KeLowerIrql](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kelowerirql)

[KeRaiseIrql](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keraiseirql)

[Managing Hardware Priorities](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-hardware-priorities)