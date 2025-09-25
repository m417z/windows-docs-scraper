# WSD_HOST_METADATA structure

## Description

Provides metadata for all services hosted by a device.

## Members

### `Host`

Reference to a [WSD_SERVICE_METADATA](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_service_metadata) structure that describes the parent service or the device.

### `Hosted`

Reference to a [WSD_SERVICE_METADATA_LIST](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_service_metadata_list) structure that represents the singly linked list of services hosted by the parent service.