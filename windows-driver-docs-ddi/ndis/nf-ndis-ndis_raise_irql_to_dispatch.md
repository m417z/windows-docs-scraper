# NDIS_RAISE_IRQL_TO_DISPATCH macro

## Description

The **NDIS_RAISE_IRQL_TO_DISPATCH** macro raises the current IRQL to DISPATCH_LEVEL on the current processor.

## Parameters

### `_pIrql_`

A pointer to a KIRQL-type variable where **NDIS_RAISE_IRQL_TO_DISPATCH** stores the original (that is, unraised) IRQL value. You should use this original IRQL value in a subsequent call to the [**NDIS_LOWER_IRQL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_lower_irql) macro.

## Remarks

NDIS network drivers should use the **NDIS_RAISE_IRQL_TO_DISPATCH** macro to raise the current IRQL.

If the current IRQL is greater than DISPATCH_LEVEL, a bugcheck occurs. Otherwise, the macro sets the current IRQL to DISPATCH_LEVEL.

**NDIS_RAISE_IRQL_TO_DISPATCH** is an NDIS wrapper for the [**KeRaiseIrql**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keraiseirql) routine.

The caller should call the [**NDIS_LOWER_IRQL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_lower_irql) macro to restore the original IRQL as soon as possible.

## See also

[**KeRaiseIrql**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keraiseirql)

[**NDIS_LOWER_IRQL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_lower_irql)