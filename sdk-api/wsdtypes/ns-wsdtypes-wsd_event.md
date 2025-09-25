# WSD_EVENT structure

## Description

Provides an internal representation of a SOAP message.

## Members

### `Hr`

The result code of the event.

### `EventType`

The event type.

### `DispatchTag`

Pointer to the protocol string when dispatch by tags is required.

### `HandlerContext`

Reference to a [WSD_HANDLER_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_handler_context) structure that specifies the handler context.

### `Soap`

Reference to a [WSD_SOAP_MESSAGE](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_soap_message) structure that describes the event.

### `Operation`

Reference to a [WSD_OPERATION](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_operation) structure that specifies the operation performed.

### `MessageParameters`

Message transmission parameters.