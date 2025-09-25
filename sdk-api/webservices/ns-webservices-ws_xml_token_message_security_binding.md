# WS_XML_TOKEN_MESSAGE_SECURITY_BINDING structure

## Description

The security binding subtype for specifying the use of a security
token that is already available to the application in XML form. The
security token that is supplied by the application in this binding is
presented to a service in a WS-Security header according to the
bindingUsage specified. This security binding may be included in a
[security description](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_description) only on the
client side.

This security binding is not supported with the [WS_NAMEDPIPE_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

Although this binding can be used with any token available in XML
form, this is commonly used in [federation
scenarios](https://learn.microsoft.com/windows/desktop/wsw/federation). For example, a client side token provider such as
CardSpace may be used to get a token from a security token service,
and that token may then be presented to a Web Service using this
security binding.

Security note: As with other security tokens and credentials, the
application is in charge of the risk assessment decision to disclose a
given XML token (supplied by the application in a
[security description](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_description)) to a given
server (supplied by the application when
[opening the channel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsopenchannel)). In particular, the
application should consider the threat that the server might use the
XML token it receives from the client, in turn, to pretend to be the
client to a 3rd party. For this threat, the following mitigations
exist: (A) the server authentication process makes sure that the
message (and hence the token) is sent only to a server that can speak
for the address specified by the client application; (B) keyless
(bearer) tokens are typically usable only at one server (e.g.,
contoso.com gains little from passing on a contoso.com
username/password token to another site -- the application security
design should make sure this property holds); (C) symmetric keyed
tokens are unusable at any server that doesn't share the same
symmetric key; (D) asymmetric keyed tokens will sign the timestamp and
the 'To' header, limiting their applicability to the intended 'To' for
a narrow time duration.

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

### `xmlToken`

The XML security token to be used. This token may be created using [WsCreateXmlSecurityToken](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatexmlsecuritytoken) or obtained from a security token
service using [WsRequestSecurityToken](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsrequestsecuritytoken). When this binding is
used for creating a channel, a copy of the supplied token is made and
kept for internal use -- the application continues to own the supplied
token and is responsible for deleting it with [WsFreeSecurityToken](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreesecuritytoken) any time after the channel creation call
returns.