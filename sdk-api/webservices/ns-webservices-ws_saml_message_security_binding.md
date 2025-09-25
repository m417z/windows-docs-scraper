# WS_SAML_MESSAGE_SECURITY_BINDING structure

## Description

The security binding subtype for specifying the use of a SAML
assertion as a message security token. The SAML token is expected to
be presented to a service in a WS-Security header according to the
bindingUsage specified. This security binding may be included in a
[security description](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_description) only on the
server side.

Only one instance of this binding may be present in a [security description](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_description).

This security binding is not supported with the [WS_NAMEDPIPE_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

For a [federated security](https://learn.microsoft.com/windows/desktop/wsw/federation) scenario that
involves getting a security token from an issuer and then presenting
it to a service, one may use [WsRequestSecurityToken](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_token_message_security_binding) together with the [WS_XML_TOKEN_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_token_message_security_binding) on
the client side, and this binding on the server side.

The extent of validation performed on the received SAML depends on the
authenticator specified. If additional validation is required, the
application may get the received SAML assertion using
[WsGetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmessageproperty) with the key [WS_MESSAGE_PROPERTY_SAML_ASSERTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_property_id)
and do further processing.

With this security binding, no security binding properties may be specified:

## Members

### `binding`

The base type from which this security binding subtype and all other security binding subtypes derive.

### `bindingUsage`

How the security token corresponding to this security binding should be bound to a message.
Only [WS_SUPPORTING_MESSAGE_SECURITY_USAGE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_security_usage) is

supported. With this usage, this security binding provides client
authentication, but not message protection (such as signing,
encryption, replay detection). Thus, this binding must be used
together with another security binding such as the [WS_SSL_TRANSPORT_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_ssl_transport_security_binding) that provides a protected
channel.

To use this binding on HTTP without SSL, the security description property **WS_SECURITY_PROPERTY_TRANSPORT_PROTECTION_LEVEL** must be explicitly set to **WS_PROTECTION_LEVEL_NONE**. This is not supported on the client or on TCP.

### `authenticator`

The authenticator for validating incoming SAML tokens. This field is
required.