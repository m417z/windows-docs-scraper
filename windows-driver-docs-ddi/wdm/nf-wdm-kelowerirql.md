# KeLowerIrql function

## Description

The **KeLowerIrql** routine restores the IRQL on the current processor to its original value. For information about IRQLs, see [Managing Hardware Priorities](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-hardware-priorities).

## Parameters

### `NewIrql` [in]

Specifies the IRQL that was returned from [KeRaiseIrql](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keraiseirql) or [KeRaiseIrqlToDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keraiseirqltodpclevel).

## Remarks

It is a fatal error to call **KeLowerIrql** using an input *NewIrql* that was not returned by the immediately preceding call to **KeRaiseIrql** or [KeRaiseIrqlToDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keraiseirqltodpclevel).

## See also

[KeGetCurrentIrql](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetcurrentirql)

[KeRaiseIrql](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keraiseirql)

[KeRaiseIrqlToDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keraiseirqltodpclevel)