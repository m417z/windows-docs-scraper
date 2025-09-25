# WS_USERNAME_MESSAGE_SECURITY_BINDING structure

## Description

The security binding subtype for specifying the use of an application
supplied username / password pair as a direct (i.e., one-shot)
security token. This security binding may be used only with message
security. It provides client authentication, but not traffic signing
or encryption. So, it is used in conjunction with another transport
security or message security binding that provides message protection.

Only one instance of this binding may be present in a [security description](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_description).
This security binding is not supported with the [WS_NAMEDPIPE_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

With this security binding, no security binding properties may be specified.

## Members

### `binding`

The base type from which this security binding subtype and all other security binding subtypes derive.

### `bindingUsage`

How the security token corresponding to this security binding should be bound to a message.

Only [WS_SUPPORTING_MESSAGE_SECURITY_USAGE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_security_usage) is
supported. With this usage, this security binding provides client
authentication, but not message protection (such as signing, encryption,
replay detection). Thus, this binding must be used together with
another security binding such as the [WS_SSL_TRANSPORT_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_ssl_transport_security_binding)
that provides a protected channel.

To use this binding on HTTP without SSL, the security description property **WS_SECURITY_PROPERTY_TRANSPORT_PROTECTION_LEVEL** must be explicitly set to **WS_PROTECTION_LEVEL_NONE**. This is not supported on the client or on TCP.

### `clientCredential`

The username credential to be used with this security binding. This
must be specified when this security binding is used on the
client.

### `passwordValidator`

The validator to be used to check received username/password pairs.
This must be specified when this security binding is used on the
service.

### `passwordValidatorCallbackState`

The optional state to be passed in as an argument when the username validator is invoked.