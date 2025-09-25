# NDIS_LOWER_IRQL macro

## Description

The NDIS_LOWER_IRQL macro sets the IRQL on the current processor to the specified value.

## Parameters

### `_OldIrql_`

The original (that is, unraised) IRQL value from before the driver called the [**NDIS_RAISE_IRQL_TO_DISPATCH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_raise_irql_to_dispatch) macro. **NDIS_LOWER_IRQL** sets the IRQL to this value.

### `_CurIrql_`

The current IRQL value that is active before the call to **NDIS_LOWER_IRQL**.

## Remarks

NDIS network drivers should use the **NDIS_LOWER_IRQL** macro to restore the IRQL setting that existed before a call to the [**NDIS_RAISE_IRQL_TO_DISPATCH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_raise_irql_to_dispatch) macro.

If the value that the *\_OldIrql\_* parameter specifies is not equal to the current IRQL, the **NDIS_LOWER_IRQL** macro attempts to lower the IRQL to the value that the *\_OldIrql\_* parameter specifies.

It is a fatal error to call **NDIS_LOWER_IRQL** and use a value for *\_OldIrql\_* that was not returned from an immediately preceding call to the [**NDIS_RAISE_IRQL_TO_DISPATCH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_raise_irql_to_dispatch) macro.

**NDIS_LOWER_IRQL** is an NDIS wrapper for the [**KeLowerIrql**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kelowerirql) routine.

## See also

[**KeLowerIrql**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kelowerirql)

[**NDIS_RAISE_IRQL_TO_DISPATCH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_raise_irql_to_dispatch)