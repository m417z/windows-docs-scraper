# WSD_RESOLVE structure

## Description

Represents a [Resolve](https://learn.microsoft.com/windows/desktop/WsdApi/resolve-message) message.

## Members

### `EndpointReference`

Reference to a [WSD_ENDPOINT_REFERENCE](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_endpoint_reference) structure that specifies the endpoint to match.

### `Any`

Reference to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that specifies extension content allowed by the XML **ANY** keyword.

## See also

[Resolve Message](https://learn.microsoft.com/windows/desktop/WsdApi/resolve-message)

[WSD_RESOLVE_MATCH](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_resolve_match)

[WSD_RESOLVE_MATCHES](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_resolve_matches)