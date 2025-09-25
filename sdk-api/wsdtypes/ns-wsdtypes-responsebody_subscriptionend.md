# RESPONSEBODY_SubscriptionEnd structure

## Description

Represents a WS-Eventing SubscriptionEnd response message.

## Members

### `SubscriptionManager`

Reference to a [WSD_ENDPOINT_REFERENCE](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_endpoint_reference) structure that represents the endpoint reference of the subscription manager.

### `Status`

A string that describes the reason the subscription ended.

| Value | Meaning |
| --- | --- |
| **http://schemas.xmlsoap.org/ws/2004/08/eventing/SourceShuttingDown** | The event source is shutting down. |
| **http://schemas.xmlsoap.org/ws/2004/08/eventing/SourceCancelling** | The event source canceled the subscription for another reason. |
| **http://schemas.xmlsoap.org/ws/2004/08/eventing/DeliveryFailure** | The event source ended the subscription because the delivery of notifications failed. |

### `Reason`

Reference to a [WSD_LOCALIZED_STRING](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_localized_string) that contains a human-readable explanation of the reason the subscription ended.

### `Any`

Reference to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that specifies extension content allowed by the XML **ANY** keyword.