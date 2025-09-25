# TmIsTransactionActive function

## Description

The **TmIsTransactionActive** routine indicates whether a specified transaction is in its active state.

## Parameters

### `Transaction` [in]

A pointer to a [transaction object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-objects). To obtain this pointer, your component must call [ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle) and supply the object handle that a previous call to [ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction) or [ZwOpenTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransaction) provided.

## Return value

**TmIsTransactionActive** returns **TRUE** if the specified transaction is in its active state. Otherwise, the routine returns **FALSE**.

## Remarks

When a transaction is created, it enters its active state and remains in that state until the [pre-prepare/prepare/commit sequence](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-commit-operations) begins.

For more information about **TmIsTransactionActive**, and for information about when to use KTM's **Tm*Xxx*** routines instead of **Zw*Xxx*** routines, see [Using TmXxx Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-tmxxx-routines).

## See also

[ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle)

[ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction)

[ZwOpenTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransaction)