# WS_SECURITY_CONTEXT_MESSAGE_SECURITY_BINDING structure

## Description

The security binding subtype for specifying the use of a security context
token negotiated between the client and server using
WS-SecureConversation. This security binding may be used only with
message security. It is used to establish a message-level security
context. Another set of one or more security bindings, specified in the
bootstrapSecurityDescription field, is used to the bootstrap the context.

Only one instance of this binding may be present in a [security description](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_description).
This security binding is not supported with the [WS_NAMEDPIPE_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

When this binding is used, the channel must complete the receive of at least one
message before it can be used to send messages.

With this security binding, the following security binding properties may be specified:

* [WS_SECURITY_BINDING_PROPERTY_SECURITY_CONTEXT_KEY_SIZE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id)
* [WS_SECURITY_BINDING_PROPERTY_SECURITY_CONTEXT_KEY_ENTROPY_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id)
* [WS_SECURITY_BINDING_PROPERTY_MESSAGE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id)
* [WS_SECURITY_BINDING_PROPERTY_SECURE_CONVERSATION_VERSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id)
* [WS_SECURITY_BINDING_PROPERTY_SECURITY_CONTEXT_SUPPORT_RENEW](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id)
* [WS_SECURITY_BINDING_PROPERTY_SECURITY_CONTEXT_RENEWAL_INTERVAL](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id)
* [WS_SECURITY_BINDING_PROPERTY_SECURITY_CONTEXT_ROLLOVER_INTERVAL](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id)

## Members

### `binding`

The base type from which this security binding subtype and all other security binding subtypes derive.

### `bindingUsage`

How the security token corresponding to this security binding should
be attached to a message.

Currently, only [WS_SUPPORTING_MESSAGE_SECURITY_USAGE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_security_usage) is
supported. With this usage, this security binding provides client
authentication, but not message protection (such as signing, encryption,
replay detection). Thus, this binding must be used together with
another security binding such as the [WS_SSL_TRANSPORT_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_ssl_transport_security_binding)
that provides a protected channel.

To use this binding on HTTP without SSL, the security description property **WS_SECURITY_PROPERTY_TRANSPORT_PROTECTION_LEVEL** must be explicitly set to **WS_PROTECTION_LEVEL_NONE**. This is not supported on the client or on TCP.

### `bootstrapSecurityDescription`

The security description for used to obtain the security context token.