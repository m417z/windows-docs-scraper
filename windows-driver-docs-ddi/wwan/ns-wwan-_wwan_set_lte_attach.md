# _WWAN_SET_LTE_ATTACH structure

## Description

The **WWAN_SET_LTE_ATTACH** structure describes default LTE attach contexts a miniport driver should set for the inserted SIM's provider (MCC/MNC pair).

## Members

### `SetContextArray`

An array of [**WWAN_SET_CONTEXT_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_context_v2) structures that each represent an LTE attach context to set.

## Remarks

This structure is used in the [**NDIS_WWAN_SET_LTE_ATTACH_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_set_lte_attach_context) structure, which is used in the payload of an [OID_WWAN_LTE_ATTACH_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-lte-attach-config) Set request. If this structure does not contain exactly three contexts, one each for home, partner, and non-partner roaming conditions, the miniport driver should reject the request.

## See also

[MB LTE Attach Operations](https://learn.microsoft.com/windows-hardware/drivers/network/mb-lte-attach-operations)

[**NDIS_WWAN_SET_LTE_ATTACH_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_set_lte_attach_context)

[**WWAN_SET_CONTEXT_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_context_v2)