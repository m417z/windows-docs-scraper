# WSD_ENDPOINT_REFERENCE structure

## Description

Represents a WS-Addressing endpoint reference.

## Members

### `Address`

The endpoint address.

### `ReferenceProperties`

[WSD_REFERENCE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_reference_properties) structure that specifies additional data used to uniquely identify the endpoint.

### `ReferenceParameters`

[WSD_REFERENCE_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_reference_parameters) structure that specifies additional opaque data used by the endpoint.

### `PortType`

Reference to a [WSDXML_NAME](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_name) structure that specifies the port type of the service at the referenced endpoint.

### `ServiceName`

Reference to a [WSDXML_NAME](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_name) structure that specifies the service name of the service at the referenced endpoint.

### `Any`

Reference to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that specifies extension content allowed by the XML **ANY** keyword.