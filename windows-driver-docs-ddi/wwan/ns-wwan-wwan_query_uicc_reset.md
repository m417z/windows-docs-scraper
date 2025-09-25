## Description

The **WWAN_QUERY_UICC_RESET** structure represents the SIM slot ID that is associated with an [OID_WWAN_UICC_RESET](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-reset) query request.

## Members

### `SlotId`

A ULONG value that specifies the intended SIM slot of the operation. For a single SIM device, this value is 0. For a dual SIM device, this value is [0..1].

## Remarks

## See also

[OID_WWAN_UICC_RESET](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-reset)