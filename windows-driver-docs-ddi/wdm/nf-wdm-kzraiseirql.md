# KzRaiseIrql function

## Description

Raises the hardware priority to the specified IRQL value, thereby masking off interrupts of equivalent or lower IRQL on the current processor. For information about IRQLs, see [Managing Hardware Priorities](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-hardware-priorities).

## Parameters

### `NewIrql` [in]

Specifies the new IRQL to which the hardware priority is to be raised.

## Return value

The original (unraised) IRQL value to be used in a subsequent call to [**KzLowerIrql**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kzlowerirql).

## Remarks

This function is same as the [**KeRaiseIrql**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keraiseirql) function.

## See also