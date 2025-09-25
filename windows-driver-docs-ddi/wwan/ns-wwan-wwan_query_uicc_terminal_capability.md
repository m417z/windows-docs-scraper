## Description

The **WWAN_QUERY_UICC_TERMINAL_CAPABILITY** structure represents the SIM slot ID that is associated with an [OID_WWAN_UICC_TERMINAL_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-terminal-capability) query request.

## Members

### `SlotId`

A ULONG value that specifies the intended SIM slot of the operation. For a single SIM device, this value is 0. For a dual SIM device, this value is [0..1].

## Remarks

## See also

[OID_WWAN_UICC_TERMINAL_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-terminal-capability)

[**NDIS_WWAN_QUERY_UICC_TERMINAL_CAPABILITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-ndis_wwan_query_uicc_terminal_capability)