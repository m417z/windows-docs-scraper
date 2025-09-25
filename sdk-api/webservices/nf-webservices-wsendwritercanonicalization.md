# WsEndWriterCanonicalization function

## Description

This function stops XML canonicalization started by the preceding [WsStartWriterCanonicalization](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsstartwritercanonicalization) call.
Remaining canonical bytes buffered by the writer are written to the callback function.

## Parameters

### `writer` [in]

A pointer to a [WS_XML_WRITER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-writer) object on which canonicalization should be stopped.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |

## Remarks

**WsEndWriterCanonicalization** must be called at the same depth at
which [WsStartWriterCanonicalization](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsstartwritercanonicalization) was called.

It is not necessary to call **WsEndWriterCanonicalization** in order to call [WsFreeWriter](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreewriter).