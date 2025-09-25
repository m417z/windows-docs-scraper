# WsEndReaderCanonicalization function

## Description

This function stops XML canonicalization started by a preceding [WsStartReaderCanonicalization](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsstartreadercanonicalization) function call.
Any remaining canonical bytes buffered by the reader will be written to the callback function.

## Parameters

### `reader` [in]

A pointer to the XML reader on which canonicalization should be stopped.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |

## Remarks

**WsEndReaderCanonicalization** must be called at the same depth at which [WsStartReaderCanonicalization](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsstartreadercanonicalization) was called.

It is not necessary to call **WsEndReaderCanonicalization** in order to call [WsFreeReader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreereader).