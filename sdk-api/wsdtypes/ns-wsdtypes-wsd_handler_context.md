# WSD_HANDLER_CONTEXT structure

## Description

Specifies the context for handling incoming messages.

## Members

### `Handler`

[PSWD_SOAP_MESSAGE_HANDLER](https://learn.microsoft.com/windows/desktop/api/wsdtypes/nc-wsdtypes-pwsd_soap_message_handler) function that specifies the incoming message handler.

### `PVoid`

The value supplied by the *pVoidContext* parameter of the IWSDSession::AddPort, IWSDSession::RegisterForIncomingRequests, or IWSDSession::RegisterForIncomingResponse methods.

### `Unknown`

The value supplied by the *unknownContext* parameter of the IWSDSession::AddPort, IWSDSession::RegisterForIncomingRequests, or IWSDSession::RegisterForIncomingResponse methods.