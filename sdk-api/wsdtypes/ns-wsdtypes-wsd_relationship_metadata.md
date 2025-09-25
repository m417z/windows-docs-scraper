# WSD_RELATIONSHIP_METADATA structure

## Description

Provides metadata about the relationship between two or more services.

## Members

### `Type`

A WS-Discovery Type.

### `Data`

Reference to a [WSD_HOST_METADATA](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_host_metadata) structure that contains metadata for all services hosted by a device.

### `Any`

Reference to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that specifies extension content allowed by the XML **ANY** keyword.