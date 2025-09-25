## Description

The **WWAN_SET_UICC_TERMINAL_CAPABILITY** structure represents the terminal capabilities of the host and SIM slot ID associated with an [OID_WWAN_UICC_TERMINAL_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-terminal-capability) set request.

## Members

### `SlotId`

A ULONG value that identifies the SIM slot of the operation. For single SIM devices this value is 0. For dual SIM devices this value is [0..1].

### `CapabilityListHeader`

A [**WWAN_LIST_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header) object that represents a list of terminal capability objects.

## Remarks

## See also

[OID_WWAN_UICC_TERMINAL_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-terminal-capability)

[NDIS_STATUS_WWAN_UICC_TERMINAL_CAPABILITY_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-uicc-terminal-capability-info)