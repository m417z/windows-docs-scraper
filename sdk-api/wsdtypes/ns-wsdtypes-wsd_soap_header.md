# WSD_SOAP_HEADER structure

## Description

Provides SOAP header data for the [WSD_SOAP_MESSAGE](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_soap_message) structure.

## Members

### `To`

The URI to which the SOAP message is addressed.

### `Action`

The action encoded by the SOAP message.

### `MessageID`

An identifier that distinguishes the message from others from the same sender.

### `RelatesTo`

In response messages, specifies the message ID of the matching request message.

### `ReplyTo`

In request messages, a reference to a [WSD_ENDPOINT_REFERENCE](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_endpoint_reference) structure that specifies to the endpoint to which responses should be sent.

### `From`

Reference to a [WSD_ENDPOINT_REFERENCE](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_endpoint_reference) structure that specifies the endpoint from which the SOAP message was sent.

### `FaultTo`

Reference to a [WSD_ENDPOINT_REFERENCE](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_endpoint_reference) structure that specifies to the endpoint to which fault messages should be sent.

### `AppSequence`

In discovery messages, a reference to a [WSD_APP_SEQUENCE](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_app_sequence) structure that helps the recipient determine the order in which messages were issued by the sender.

### `AnyHeaders`

Reference to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that specifies additional headers not encoded by the other members.