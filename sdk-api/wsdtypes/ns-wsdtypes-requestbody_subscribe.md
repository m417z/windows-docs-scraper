# REQUESTBODY_Subscribe structure

## Description

Represents a WS-Eventing Subscribe request message.

## Members

### `EndTo`

Reference to a [WSD_ENDPOINT_REFERENCE](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_endpoint_reference) structure that represents the endpoint reference of the event recipient.

### `Delivery`

Reference to a [WSD_EVENTING_DELIVERY_MODE](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_eventing_delivery_mode) structure that specifies the delivery mode. Only push delivery is supported.

### `Expires`

Reference to a [WSD_EVENTING_EXPIRES](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_eventing_expires) structure that specifies when the subscription will expire.

### `Filter`

Reference to a [WSD_EVENTING_FILTER](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_eventing_filter) structure that specifies a boolean expression used for event filtering.

### `Any`

Reference to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that specifies extension content allowed by the XML **ANY** keyword.