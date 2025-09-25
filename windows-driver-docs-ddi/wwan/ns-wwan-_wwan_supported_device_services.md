# _WWAN_SUPPORTED_DEVICE_SERVICES structure

## Description

The WWAN_SUPPORTED_DEVICE_SERVICES structure describes information about device services supported by the miniport driver.

## Members

### `uMaxCommandDataSize`

The maximum size, in bytes, of data that can be associated with a device service command.

### `uMaxSessionDataSize`

The maximum size, in bytes, of data that can be associated with a device service session.

### `uMaxSessionCount`

The maximum number of device service sessions supported by the miniport driver.

### `ListHeader`

A formatted WWAN_LIST_HEADER object that represents a list of supported device services and the number of services in the list.

This member points to the list of the [WWAN_DEVICE_SERVICE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_service_entry) by using the WWAN_LIST_HEADER structure.

## See also

[NDIS_WWAN_SUPPORTED_DEVICE_SERVICES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_supported_device_services)

[WWAN_DEVICE_SERVICE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_service_entry)

[WWAN_LIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header)