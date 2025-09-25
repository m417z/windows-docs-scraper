# WS_KERBEROS_APREQ_MESSAGE_SECURITY_BINDING structure

## Description

The security binding subtype for specifying the use of the Kerberos
AP_REQ ticket as a direct (i.e., without establishing a session)
security token with WS-Security.

Only one instance of this binding may be present in a [security description](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_description).

This security binding is not supported with the [WS_NAMEDPIPE_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

With this security binding, the following security binding properties may be specified:

* [WS_SECURITY_BINDING_PROPERTY_ALLOWED_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id) (client side only)
* [WS_SECURITY_BINDING_PROPERTY_ALLOW_ANONYMOUS_CLIENTS](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id) (server side only)

In Windows Vista and above on the client side, using this binding with HTTP will result in the message being sent using chunked transfer.

## Members

### `binding`

The base type from which this security binding subtype and all other security binding subtypes derive.

### `bindingUsage`

How the security token corresponding to this security binding should
be attached to a message.

Only [WS_SUPPORTING_MESSAGE_SECURITY_USAGE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_security_usage) is supported. With this usage, this security binding provides client authentication, but not message protection (such as signing, encryption, replay detection). Consequently, this binding is generally used together with another security binding such as the [WS_SSL_TRANSPORT_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_ssl_transport_security_binding) that provides a protected channel.

To use this binding on HTTP without SSL, the security description property **WS_SECURITY_PROPERTY_TRANSPORT_PROTECTION_LEVEL** must be explicitly set to **WS_PROTECTION_LEVEL_NONE**. This is not supported on the client or on TCP.

### `clientCredential`

The Windows Integrated Authentication credential to be used to obtain
the Kerberos ticket. This field is required on the client side, but
must be **NULL** on the server side.