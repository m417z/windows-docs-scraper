# WS_SECURITY_CONTEXT_MESSAGE_SECURITY_BINDING_CONSTRAINT structure

## Description

A security binding constraint that corresponds to
the [WS_SECURITY_CONTEXT_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_context_message_security_binding).

## Members

### `bindingConstraint`

The base binding constraint that this binding constraint derives from.

The following binding constraints are supported at this point: [WS_SECURITY_BINDING_PROPERTY_SECURE_CONVERSATION_VERSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id)
and **WS_SECURITY_BINDING_PROPERTY_SECURITY_CONTEXT_KEY_ENTROPY_MODE**.
Currently only [WS_SECURE_CONVERSATION_VERSION_FEBRUARY_2005](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_secure_conversation_version) is supported in policy, so a binding constraint containing the
value **WS_SECURE_CONVERSATION_VERSION_FEBRUARY_2005** must be specified in
order for the policy to match.

### `bindingUsage`

This specifies how the security context token should be attached to a message.

### `bootstrapSecurityConstraint`

This specifies the bootstrap security used to establish the secure conversation context.