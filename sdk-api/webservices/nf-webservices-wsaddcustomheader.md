# WsAddCustomHeader function

## Description

Adds the specified application-defined header to the [message](https://learn.microsoft.com/windows/desktop/wsw/message).

## Parameters

### `message` [in]

The message to which to add the header.

The message can be in any state except **WS_MESSAGE_STATE_EMPTY** (see the [WS_MESSAGE_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state) enumeration..

### `headerDescription` [in]

The [WS_ELEMENT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_element_description) structure that describes the header.

### `writeOption` [in]

Whether the header element is required, and how the value is allocated.
For more information, see the [WS_WRITE_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_write_option) enumeration.

### `value` [in, ref]

The header value to serialize. For more information, see the [WS_WRITE_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_write_option) enumeration.

### `valueSize` [in]

The size of the value being serialized, in bytes.

### `headerAttributes` [in]

The values of the SOAP attributes for the header.

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | There are multiple instances of the same type of header present in the message. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_INVALIDARG** | One or more of the parameters are incorrect. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

The **WsAddCustomHeader** function is designed handle types of headers that are targeted at
the final receiver. Headers targeted at another receiver are ignored.

If you are replacing a header, call the [WsRemoveCustomHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsremovecustomheader) function to remove
the existing instances of the header before calling **WsAddCustomHeader**.