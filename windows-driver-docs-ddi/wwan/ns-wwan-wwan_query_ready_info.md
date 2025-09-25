## Description

The **WWAN_QUERY_READY_INFO** structure represents the SIM slot ID that is associated with an [OID_WWAN_READY_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-ready-info) query request.

## Members

### `SlotId`

A ULONG value that specifies the intended SIM slot of the operation. For single SIM device, this value is 0. For a dual SIM device, this value is [0..1].

## Remarks

## See also

[**NDIS_WWAN_QUERY_READY_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-ndis_wwan_query_ready_info)

[OID_WWAN_READY_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-ready-info)