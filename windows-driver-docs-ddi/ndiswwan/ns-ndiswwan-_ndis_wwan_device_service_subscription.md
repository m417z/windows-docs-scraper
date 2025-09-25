# _NDIS_WWAN_DEVICE_SERVICE_SUBSCRIPTION structure

## Description

The NDIS_WWAN_DEVICE_SERVICE_SUBSCRIPTION structures encapsulates the data for NDIS_STATUS_WWAN_ DEVICE_SERVICE_SUBSCRIPTION.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_DEVICE_SERVICE_SUBSCRIPTION structure. The MB
Service sets the header with the values that are shown in the following table when it sends the data
structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_DEVICE_SERVICE_SUBSCRIPTION_REVISION_1 |
| Size | sizeof(NDIS_WWAN_DEVICE_SERVICE_SUBSCRIPTION) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of the device service subscription operation.

This can be any WWAN_STATUS code.

### `DeviceServiceListHeader`

A formatted WWAN_LIST_HEADER object that represents a list of device services and the number of services in the list. This is the list of device services for which the device would indicate NDIS_STATUS_WWAN_DEVICE_SERVICE_EVENT notifications.

This member points to the list of the GUIDs by using the WWAN_LIST_HEADER structure, and should contain 0 elements when indicated to mark completion of a set [OID_WWAN_SUBSCRIBE_DEVICE_SERVICE_EVENTS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-subscribe-device-service-events) request.

## See also

[OID_WWAN_SUBSCRIBE_DEVICE_SERVICE_EVENTS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-subscribe-device-service-events)

[WWAN_LIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header)