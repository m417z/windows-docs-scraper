# RESPONSEBODY_Subscribe structure

## Description

Represents a WS-Eventing Subscribe response message.

## Members

### `SubscriptionManager`

Reference to a [WSD_ENDPOINT_REFERENCE](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_endpoint_reference) structure that represents the endpoint reference of the subscription manager.

### `expires`

Reference to a [WSD_EVENTING_EXPIRES](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_eventing_expires) structure that specifies when the subscription expires.

### `any`

### `Any`

Reference to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that specifies extension content allowed by the XML **ANY** keyword.