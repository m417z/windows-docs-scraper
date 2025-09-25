# _NDIS_WWAN_SET_DEVICE_SLOT_MAPPING_INFO structure

## Description

The **NDIS_WWAN_SET_DEVICE_SLOT_MAPPING_INFO** structure sets the executor-to-slot mapping relationship of the MB device.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_SET_DEVICE_SLOT_MAPPINGS** structure.
The MB Service sets the header with the values that are shown in the following table when it sends the
data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SET_DEVICE_SLOT_MAPPING_INFO_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SET_DEVICE_SLOT_MAPPING_INFO) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `SetDeviceSlotMappingInfo`

A formatted [WWAN_DEVICE_SLOT_MAPPING_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_slot_mapping_info) structure that represents the executor-to-slot mapping relationship of the MB device.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_WWAN_DEVICE_SLOT_MAPPING_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-device-slot-mappings)

[WWAN_DEVICE_SLOT_MAPPING_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_slot_mapping_info)