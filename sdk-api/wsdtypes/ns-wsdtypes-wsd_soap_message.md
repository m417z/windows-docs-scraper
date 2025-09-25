# WSD_SOAP_MESSAGE structure

## Description

The contents of a WSD SOAP message. This structure is used for [Probe](https://learn.microsoft.com/windows/desktop/WsdApi/probe-message) messages, ProbeMatch messages, [Resolve](https://learn.microsoft.com/windows/desktop/WsdApi/resolve-message) messages, and ResolveMatch messages, among others.

## Members

### `Header`

A [WSD_SOAP_HEADER](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_soap_header) structure that specifies the header of the SOAP message.

### `Body`

The body of the SOAP message.

### `BodyType`

Reference to a [WSDXML_TYPE](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_type) structure that specifies the type of the SOAP message body.

## See also

[Discovery and Metadata Exchange Messages](https://learn.microsoft.com/windows/desktop/WsdApi/discovery-and-metadata-exchange-message-patterns)