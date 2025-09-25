# WS_TCP_SSPI_USERNAME_BINDING_TEMPLATE structure

## Description

Username/password security template information to be filled in by application.
Associated with [WS_TCP_SSPI_USERNAME_BINDING_TEMPLATE_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_binding_template_type).

## Members

### `channelProperties`

Application provided additional channel properties that cannot be represented in policy.

### `securityProperties`

Application provided additional security properties that cannot be represented in policy.

### `sspiTransportSecurityBinding`

Application provided SSPI transport security information that cannot be represented
in policy.

### `usernameMessageSecurityBinding`

Application provided username/password authentication binding information
that cannot be represented in policy.