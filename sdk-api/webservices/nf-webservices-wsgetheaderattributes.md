# WsGetHeaderAttributes function

## Description

This function populates a ULONG parameter with the [WS_HEADER_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_text_type) from the header element on which the reader is positioned. The
envelope version of the message is used to determine which attributes to return.

## Parameters

### `message` [in]

A pointer to a [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message) structure containing the message to query. This envelope version of the message is used to determine which attributes match.
The message can be in any state except [WS_MESSAGE_STATE_EMPTY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state).

### `reader` [in]

A pointer to the reader to query. This must be valid WS_XML_READER object returned from [WsCreateReader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatereader) and cannot be **NULL**.

### `headerAttributes` [out]

On success the value referenced by this pointer is set to the header attributes.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

The reader is assumed to point to a header element. Use the XML reader API's to position the reader appropriately.