# KzLowerIrql function

## Description

Restores the IRQL on the current processor to its original value. For information about IRQLs, see [Managing Hardware Priorities](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-hardware-priorities).

## Parameters

### `NewIrql` [in]

Specifies the IRQL that was returned from [KeRaiseIrql](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keraiseirql) or [KeRaiseIrqlToDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keraiseirqltodpclevel).

## Remarks

This function is same as the [**KeLowerIrql**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kelowerirql) function.

## See also