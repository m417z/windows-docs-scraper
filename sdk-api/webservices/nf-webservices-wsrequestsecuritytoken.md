# WsRequestSecurityToken function

## Description

Get a security token from a security token service (STS) that acts as
the token issuer in a federation scenario.
This function is used on the client side, and performs the WS-Trust
based negotiation steps with the STS until the security token is
obtained or the negotiation process fails.

## Parameters

### `channel` [in]

The channel on which the negotiation to obtain the security token
should take place.

The supplied channel should have been [created](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel) with the appropriate [WS_SECURITY_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_description) to meet the security requirements of
the issuer, and then [opened](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsopenchannel) to the [WS_ENDPOINT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_endpoint_address) of the issuer. The caller is also
responsible for [closing](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsclosechannel) and [freeing](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreechannel) the channel after the completion of
this function.

Thus, the channel must be in state [WS_CHANNEL_STATE_OPEN](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_state) when this function is called. After a successful completion of this
function, the channel will be in state **WS_CHANNEL_STATE_OPEN**. After a failed completion, it will
either be in state **WS_CHANNEL_STATE_OPEN** or state **WS_CHANNEL_STATE_FAULTED**.

### `properties`

An optional group of settings to be used in the negotiation process
with the issuer.

### `propertyCount` [in]

The number of items in the properties array.

### `token`

The XML security token obtained. This is set upon successful
completion of the function call, and is unmodified if any failure
occurs during the execution of the function.

The returned security token may be used with [WS_XML_TOKEN_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_token_message_security_binding) if it is to be
presented to a service. The token must be freed using [WsFreeSecurityToken](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreesecuritytoken) when it is no longer needed.

### `asyncContext` [in, optional]

Information on how to invoke the function asynchronously, or **NULL** if invoking synchronously.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_S_ASYNC** | The asynchronous operation is still pending. |

## Remarks

Windows 7 and Windows Server 2008 R2: WWSAPI only supports [Ws-Trust](http://specs.xmlsoap.org/ws/2005/02/trust/WS-Trust.pdf) and [Ws-SecureConversation](http://specs.xmlsoap.org/ws/2005/02/sc/WS-SecureConversation.pdf) as defined by [Lightweight Web Services Security Profile (LWSSP)](https://learn.microsoft.com/openspecs/windows_protocols/ms-lwssp/376af2f8-f4fe-4577-bfd5-370ac12cac2e). For details regarding Microsoft's implementation please see the [MESSAGE Syntax](https://learn.microsoft.com/openspecs/windows_protocols/ms-lwssp/d4f0f509-e14a-47b5-81e8-ade06a51d1ed) section of LWSSP.