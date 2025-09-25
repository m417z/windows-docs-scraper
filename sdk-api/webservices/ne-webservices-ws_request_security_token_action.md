# WS_REQUEST_SECURITY_TOKEN_ACTION enumeration

## Description

Defines which set of actions to use when negotiating security tokens using WS-Trust.

## Constants

### `WS_REQUEST_SECURITY_TOKEN_ACTION_ISSUE:1`

Use the "request" action defined in WS-Trust.

### `WS_REQUEST_SECURITY_TOKEN_ACTION_NEW_CONTEXT:2`

Use the "request" action defined in WS-SecureConversation.

### `WS_REQUEST_SECURITY_TOKEN_ACTION_RENEW_CONTEXT:3`

Use the "renew" action defined in WS-SecureConversation. Requires [WS_REQUEST_SECURITY_TOKEN_PROPERTY_EXISTING_TOKEN](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_request_security_token_property_id).