# WSD_OPERATION structure

## Description

Describes an operation as defined by WSDL in terms of one or two messages. This structure is populated by [generated code](https://learn.microsoft.com/windows/desktop/WsdApi/web-services-for-devices-code-generator).

## Members

### `RequestType`

Reference to a [WSDXML_TYPE](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_type) structure that specifies the request type of an incoming message.

### `ResponseType`

Reference to a [WSDXML_TYPE](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_type) structure that specifies the response type of an outgoing message.

### `RequestStubFunction`

Reference to a [WSD_STUB_FUNCTION](https://learn.microsoft.com/windows/desktop/api/wsdtypes/nc-wsdtypes-wsd_stub_function) function that specifies the address of a stub function which translates a generic SOAP message structure into a method call with a signature specific to the incoming message of the operation.