# WS_SECURITY_CONTEXT_SECURITY_BINDING_TEMPLATE structure

## Description

The security binding template for specifying the use of an application
supplied security context security binding. This security binding may
be used only with message security. So, it is used in conjunction with another transport
security binding that provides message protection. The security properties are
used to establish the secure conversation.

See also [WS_SECURITY_CONTEXT_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_context_message_security_binding)

## Members

### `securityContextMessageSecurityBinding`

Application provided security binding properties that cannot be represented in policy.

### `securityProperties`

Application provided additional security properties for the service channel
that cannot be represented in policy. Only policy specified security properties is used if no additional properties are specified here.