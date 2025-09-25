# _NDIS_WWAN_SUPPORTED_DEVICE_SERVICES structure

## Description

The NDIS_WWAN_SUPPORTED_DEVICE_SERVICES structure describes a list of supported device services.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_SUPPORTED_DEVICE_SERVICES
structure. The MB Service sets the header with the values that are shown in the following table when it
sends the data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SUPPORTED_DEVICE_SERVICES_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SUPPORTED_DEVICE_SERVICES) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of the device services query operation.

### `DeviceServices`

This member points to the list of the [WWAN_SUPPORTED_DEVICE_SERVICES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_supported_device_services) structure that represents the list of supported device services and information about them by using the WWAN_LIST_HEADER structure

## See also

[WWAN_SUPPORTED_DEVICE_SERVICES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_supported_device_services)