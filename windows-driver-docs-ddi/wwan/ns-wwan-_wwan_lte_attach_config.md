# _WWAN_LTE_ATTACH_CONFIG structure

## Description

The **WWAN_LTE_ATTACH_CONFIG** structure describes default LTE attach contexts for the inserted SIM's provider (MCC/MNC pair).

## Members

### `ElementCount`

A **ULONG** value that specifies the number of contexts in **LteContextArray**.

### `LteContextArray`

An array of [**WWAN_CONTEXT_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_context_v2) structures that each represent an LTE attach context.

## Remarks

This structure is used in the [**NDIS_WWAN_LTE_ATTACH_CONTEXTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_lte_attach_contexts) structure.

## See also

[MB LTE Attach Operations](https://learn.microsoft.com/windows-hardware/drivers/network/mb-lte-attach-operations)

[**NDIS_WWAN_LTE_ATTACH_CONTEXTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_lte_attach_contexts)

[**WWAN_CONTEXT_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_context_v2)