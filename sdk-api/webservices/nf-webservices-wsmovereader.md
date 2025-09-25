# WsMoveReader function

## Description

Moves the current position of the reader as specified by the *moveTo* parameter.
This function can only be used on a reader that is set to an XmlBuffer.

## Parameters

### `reader` [in]

A pointer to the **XML Reader** object with the position to move. The pointer must reference a valid [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) object and the referenced **Reader** value may not be **NULL**.

### `moveTo` [in]

This enumerator specifies direction or next position of the Reader relative to the current position.

### `found`

Indicates success or failure of the specified move.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |

## Remarks

If the found parameter is not **NULL**, then it will indicate there whether or not it could
move to the requested node and return NOERROR.

If the found parameter is **NULL**, and the requested node is not found, it will return **WS_E_INVALID_FORMAT**.
(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)

This function cannot be used while canonicalizing. If [WsStartReaderCanonicalization](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsstartreadercanonicalization) has
been called, then it will return **WS_E_INVALID_OPERATION**.