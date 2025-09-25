# WS_TCP_SSPI_USERNAME_SECURITY_CONTEXT_BINDING_TEMPLATE structure

## Description

Security template information to be filled in by application.
Associated with [WS_TCP_SSPI_USERNAME_SECURITY_CONTEXT_BINDING_TEMPLATE_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_binding_template_type).

## Members

### `channelProperties`

Application provided additional channel properties for both bootstrap channel and service channel
that cannot be represented in policy.

### `securityProperties`

Application provided additional security properties for the bootstrap channel
that cannot be represented in policy.

### `sspiTransportSecurityBinding`

Application provided SSPI transport security information for both bootstrap channel and service
channel that cannot be represented in policy.

### `usernameMessageSecurityBinding`

Application provided username binding information for the bootstrap channel that cannot be represented in policy.

### `securityContextSecurityBinding`

Application provided security context message binding information for the service channel that cannot be represented in policy.