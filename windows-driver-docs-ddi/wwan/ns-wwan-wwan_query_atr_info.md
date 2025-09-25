## Description

The **WWAN_QUERY_ATR_INFO** structure represents the SIM slot ID that is associated with an [OID_WWAN_UICC_ATR](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-atr) query request.

## Members

### `SlotId`

A ULONG value that specifies the intended SIM slot of the operation. For a single SIM device, this value is 0. For a dual SIM device, this value is [0..1].

## Remarks

## See also

[**NDIS_WWAN_QUERY_ATR_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-ndis_wwan_query_atr_info)

[OID_WWAN_UICC_ATR](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-atr)