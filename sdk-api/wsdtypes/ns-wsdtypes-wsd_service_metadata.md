# WSD_SERVICE_METADATA structure

## Description

Provides metadata regarding a service hosted by a device.

## Members

### `EndpointReference`

Reference to a [WSD_ENDPOINT_REFERENCE_LIST](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_endpoint_reference_list) structure that specifies the endpoints at which the service is available.

### `Types`

Reference to a [WSD_NAME_LIST](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_name_list) structure that contains a list of WS-Discovery Types.

### `ServiceId`

The URI of the service. This URI must be valid when a **WSD_SERVICE_METADATA** structure is passed to [IWSDDeviceHost::SetMetadata](https://learn.microsoft.com/windows/desktop/api/wsdhost/nf-wsdhost-iwsddevicehost-setmetadata). Applications are responsible for URI validation.

### `Any`

Reference to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that specifies extension content allowed by the XML **ANY** keyword.