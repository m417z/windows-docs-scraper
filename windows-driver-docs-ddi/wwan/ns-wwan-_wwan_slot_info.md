# _WWAN_SLOT_INFO structure

## Description

The **WWAN_SLOT_INFO** structure represents the status of a specific SIM card slot on the modem.

## Members

### `SlotIndex`

The index of the slot being queried.

### `State`

The state of the slot being queried, a member of the [WWAN_UICCSLOT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_uiccslot_state) enumeration that represents a summary of both the slot and the card state.

## See also

[NDIS_STATUS_WWAN_SLOT_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-slot-info-status)

[NDIS_WWAN_SLOT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_slot_info)

[OID_WWAN_SLOT_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-slot-info-status)

[WWAN_UICCSLOT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_uiccslot_state)