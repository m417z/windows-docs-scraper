# WsFreeMessage function

## Description

Releases the memory resource associated with a Message object.

## Parameters

### `message` [in]

A pointer to the **Message** object to release. The pointer must reference a valid [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message) object returned
by [WsCreateMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatemessage) or [WsCreateMessageForChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatemessageforchannel) and the referenced value may not be **NULL**.