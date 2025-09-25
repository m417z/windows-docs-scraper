# WS_MESSAGE_DONE_CALLBACK callback function

## Description

Notifies the caller that the message has completed its use of either the [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) structure that was supplied to [WsReadEnvelopeStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadenvelopestart) function, or of the [WS_XML_WRITER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-writer) structure supplied to the [WsWriteEnvelopeStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswriteenvelopestart) function.

## Parameters

### `doneCallbackState` [in]

A pointer to **state** information passed to the [WsReadEnvelopeStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadenvelopestart) or [WsWriteEnvelopeStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswriteenvelopestart) function.

This parameter can be used to specify a pointer to user-defined
data required by the callback.

## Remarks

This callback can be used as an indicator that the message object is no
longer using the reader or writer.

The callback is specified when [WsReadEnvelopeStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadenvelopestart) or
[WsWriteEnvelopeStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswriteenvelopestart) is called.

The callback should assume that it is invoked as a
[WS_SHORT_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_callback_model), since it will be invoked on the same
thread that calls [WsFreeMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreemessage) or [WsResetMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsresetmessage).