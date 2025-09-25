# KeRaiseIrql macro

## Description

The **KeRaiseIrql** routine raises the hardware priority to the specified IRQL value, thereby masking off interrupts of equivalent or lower IRQL on the current processor. For information about IRQLs, see [Managing Hardware Priorities](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-hardware-priorities).

## Parameters

### `a` [in]

The **NewIrql** parameter specifies the new KIRQL value to which the hardware priority is to be raised.

### `b` [out]

The **OldIrql** parameter is a pointer to the storage for the original (unraised) KIRQL value to be used in a subsequent call to [KeLowerIrql](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kelowerirql).

## Syntax

```cpp
VOID KeRaiseIrql(
  _In_  KIRQL  NewIrql,
  _Out_ PKIRQL OldIrql
);
```

## Remarks

If the new IRQL is less than the current IRQL, a bug check occurs. Otherwise, the current IRQL is set to the specified value.

Callers of this routine can be running at any IRQL. Any caller should restore the original IRQL with [KeLowerIrql](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kelowerirql) as soon as possible.

A call to **KeLowerIrql** is valid if it specifies *NewIrql* <= *CurrentIrql*. A call to **KeRaiseIrql** is valid if the caller specifies *NewIrql* >= *CurrentIrql*.

## See also

[KeGetCurrentIrql](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetcurrentirql)

[KeLowerIrql](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kelowerirql~r1)