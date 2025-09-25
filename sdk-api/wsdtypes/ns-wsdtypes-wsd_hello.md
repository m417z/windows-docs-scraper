# WSD_HELLO structure

## Description

Represents a [Hello](https://learn.microsoft.com/windows/desktop/WsdApi/hello-message) message.

## Members

### `EndpointReference`

Reference to a [WSD_ENDPOINT_REFERENCE](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_endpoint_reference) structure that specifies the endpoint announcing the Hello message.

### `Types`

Reference to a [WSD_NAME_LIST](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_name_list) structure that contains a list of WS-Discovery Types.

### `Scopes`

Reference to a [WSD_SCOPES](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_scopes) structure that contains a list of WS-Discovery Scopes.

### `XAddrs`

Reference to a [WSD_URI_LIST](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_uri_list) structure that contains a list of WS-Discovery XAddrs.

### `MetadataVersion`

The metadata version of this message.

### `Any`

Reference to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that specifies extension content allowed by the XML **ANY** keyword.

## See also

[Hello Message](https://learn.microsoft.com/windows/desktop/WsdApi/hello-message)