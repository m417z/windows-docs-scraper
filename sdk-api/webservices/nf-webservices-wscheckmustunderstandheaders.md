# WsCheckMustUnderstandHeaders function

## Description

Verifies that the specified headers were understood by the receiver.

**Note** This function should be called after all headers have been read for a received
message.

## Parameters

### `message` [in]

Pointer to the [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message) structure containing the headers to be understood.

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure where additional error information is stored if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_OPERATION** | The message is not in the correct state. For more information, see the Remarks section. |
| **WS_E_INVALID_FORMAT** | The validation failed, or the message was not correctly formed. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

Because the set of headers is extensible, it is necessary to determine whether a message has been sufficiently understood to be processed. Therefore, the sender can use this function to indicate which headers must be understood, which headers can be treated as optional or informational.

Standard addressing headers, such as the ones defined in [WS_HEADER_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_header_type), are automatically assumed to be understood, even if they are never read by calling [WsGetHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetheader).

Custom, application-defined headers that are read by [WsGetCustomHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetcustomheader) are also assumed to be understood. Calling **WsGetCustomHeader** will automatically mark the particular header as understood.

For any other header processed by the application, the application must explicitly mark the header as understood by calling [WsMarkHeaderAsUnderstood](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsmarkheaderasunderstood). Otherwise, the header is considered to not be understood.

This function should be called after all headers have been read for a received message. An exception to having to call this function is the case of an intermediary that forwards the message to another node without changing its identity (message ID), since the final node will do the check.

The function will fail if any of the specified headers were not understood. If an error object is supplied to the function, it will be populated with information that can be used to send a fault (see [WsCreateFaultFromError](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatefaultfromerror)).

The message must be in the WS_MESSAGE_STATE_READING state.