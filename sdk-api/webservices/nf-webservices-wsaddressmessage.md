# WsAddressMessage function

## Description

Addresses a [message](https://learn.microsoft.com/windows/desktop/wsw/message) to a specified [endpoint address](https://learn.microsoft.com/windows/desktop/wsw/endpoint-address).

## Parameters

### `message` [in]

Pointer to a [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message) structure representing the message to be addressed.

### `address` [in, optional]

Pointer to a [WS_ENDPOINT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_endpoint_address) structure containing the endpoint to which to address the message.

**Note** Passing **NULL** to this parameter indicates that no headers are added to the message. This provides
a way to set the [WS_MESSAGE_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_property_id) to **WS_MESSAGE_PROPERTY_IS_ADDRESSED**
without modifying the set of headers in the message.

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_OPERATION** | The message has already been addressed. (The **WS_MESSAGE_PROPERTY_IS_ADDRESSED** property indicates whether a message has already been addressed.) |
| **E_INVALIDARG** | One or more arguments are not valid. |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **Other Errors** | This function can return other errors not listed above. |

## Remarks

If you do not address a message by calling this function, the [channel](https://learn.microsoft.com/windows/desktop/wsw/channel) automatically addresses the message with the
[Endpoint Address](https://learn.microsoft.com/windows/desktop/wsw/endpoint-address) passed to [WsOpenChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsopenchannel).

This function marks the message as addressed by setting
the **WS_MESSAGE_PROPERTY_IS_ADDRESSED** property to **TRUE**.

This function fails
if the message has already been addressed and returns **WS_E_INVALID_OPERATION**.

If a non-**NULL**[WS_ENDPOINT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_endpoint_address) is passed
to the function, the function performs the following
additional steps:

* The header type is set to WS_TO_HEADER (see the [WS_HEADER_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_header_type) enumeration) and the address is set to the value of the **url** field of [WS_ENDPOINT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_endpoint_address). If the URL length
  is zero the [WS_ADDRESSING_VERSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_addressing_version)-specific
  representation for an anonymous URL is set for the message.
* Each header in the [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer) specified in the
  headers field of the [WS_ENDPOINT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_endpoint_address) is added to
  the message. No headers are added if the buffer is **NULL**.