# _WWAN_DEVICE_SLOT_MAPPING_INFO structure

## Description

The WWAN_DEVICE_SLOT_MAPPING_INFO structure represents the executor-to-slot mapping relationship in the MB device.

## Members

### `SlotMapListHeader`

[WWAN_LIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header) has a new structure, **WwanStructSlotIndex**, which represents the slot index the *i-th* executor is mapped to (where 0 <= i <= (Number of mappings -1)).

## See also

[NDIS_STATUS_WWAN_DEVICE_SLOT_MAPPING_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-device-slot-mappings)

[NDIS_WWAN_DEVICE_SLOT_MAPPING_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_device_slot_mapping_info)

[NDIS_WWAN_SET_DEVICE_SLOT_MAPPING_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_set_device_slot_mapping_info)

[OID_WWAN_DEVICE_SLOT_MAPPING_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-device-slot-mappings)