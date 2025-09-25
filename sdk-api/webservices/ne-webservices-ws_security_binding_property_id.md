# WS_SECURITY_BINDING_PROPERTY_ID enumeration

## Description

Identifies the properties used to specify security
binding settings. Security binding settings are present
in [security bindings](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_binding) that are used, in turn, in a [security description](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_description).

This enumeration is used within the [WS_SECURITY_BINDING_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_binding_property) structure, which in turn is used in a [WS_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_binding) structure. Not all values are applicable to all security bindings. Please see the individual descriptions for a list of security bindings that support the respective property.

Note that the related enum [WS_SECURITY_TOKEN_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_token_property_id) defines the keys for extracting fields from a security token instance.
Thus, [WS_SECURITY_BINDING_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_binding_property) enables specifying security binding
settings at channel / listener creation time to influence how a
security token is created and used, whereas **WS_SECURITY_TOKEN_PROPERTY_ID** enables extracting fields out of a security token -- typically a
security token from a received message when the channel and security
are 'live'.

## Constants

### `WS_SECURITY_BINDING_PROPERTY_REQUIRE_SSL_CLIENT_CERT:1`

A **BOOL** that specifies whether a client certificate should be demanded when using SSL. The
default is **FALSE**.

This setting may be specified in the security binding properties of a
server-side [WS_SSL_TRANSPORT_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_ssl_transport_security_binding).

### `WS_SECURITY_BINDING_PROPERTY_WINDOWS_INTEGRATED_AUTH_PACKAGE:2`

A [WS_WINDOWS_INTEGRATED_AUTH_PACKAGE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_windows_integrated_auth_package) value that specifies the specific SSP package (among Kerberos, NTLM, SPNEGO) to be used
when performing Windows Integrated Authentication. The default is **WS_WINDOWS_INTEGRATED_AUTH_PACKAGE_SPNEGO**.

This setting may be specified in the security binding properties of [WS_TCP_SSPI_TRANSPORT_SECURITY_BINDING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_namedpipe_sspi_transport_security_binding) and [WS_NAMEDPIPE_SSPI_TRANSPORT_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_namedpipe_sspi_transport_security_binding).

### `WS_SECURITY_BINDING_PROPERTY_REQUIRE_SERVER_AUTH:3`

A **BOOL** that specifies whether server authentication is mandatory. Currently, this setting
is applicable only when using Windows Integrated Authentication based
security. Setting this to **FALSE** is strongly
discouraged since, without server authentication, a malicious party
masquerading as the server cannot be detected.

The default is **TRUE** when used with [WS_TCP_SSPI_TRANSPORT_SECURITY_BINDING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_namedpipe_sspi_transport_security_binding) and **FALSE** when used with [WS_NAMEDPIPE_SSPI_TRANSPORT_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_namedpipe_sspi_transport_security_binding)

If a protocol that does not do server authentication (such as NTLM) is
to be allowed, this property must be set to
**FALSE**.

This setting may be specified only in the security binding properties
of a client-side [WS_TCP_SSPI_TRANSPORT_SECURITY_BINDING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_namedpipe_sspi_transport_security_binding) and [WS_NAMEDPIPE_SSPI_TRANSPORT_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_namedpipe_sspi_transport_security_binding).

### `WS_SECURITY_BINDING_PROPERTY_ALLOW_ANONYMOUS_CLIENTS:4`

A **BOOL** that specifies
whether the server should allow clients authenticated anonymously
using Windows Integrated Authentication based security. The default
is **FALSE**.

This setting may be specified only in the security binding properties
of a server-side [WS_TCP_SSPI_TRANSPORT_SECURITY_BINDING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_namedpipe_sspi_transport_security_binding) and [WS_NAMEDPIPE_SSPI_TRANSPORT_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_namedpipe_sspi_transport_security_binding).

### `WS_SECURITY_BINDING_PROPERTY_ALLOWED_IMPERSONATION_LEVEL:5`

A [SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/win32/api/winnt/ne-winnt-security_impersonation_level) value that specifies the impersonation level the client wants to allow when using Windows
Integrated Authentication to communicate with a service. The default impersonation level is **SecurityIdentification**.

This setting may be specified in the security binding properties
of [WS_TCP_SSPI_TRANSPORT_SECURITY_BINDING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_namedpipe_sspi_transport_security_binding), [WS_NAMEDPIPE_SSPI_TRANSPORT_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_namedpipe_sspi_transport_security_binding), and [WS_KERBEROS_APREQ_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_kerberos_apreq_message_security_binding).

### `WS_SECURITY_BINDING_PROPERTY_HTTP_HEADER_AUTH_SCHEME:6`

 A **ULONG** that specifies the HTTP header authentication mode to use. The value specified must be a combination of one or more of
[WS_HTTP_HEADER_AUTH_SCHEME_NONE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_node_type), **WS_HTTP_HEADER_AUTH_SCHEME_BASIC**,
**WS_HTTP_HEADER_AUTH_SCHEME_DIGEST**, **WS_HTTP_HEADER_AUTH_SCHEME_NTLM** or
**WS_HTTP_HEADER_AUTH_SCHEME_NEGOTIATE**. When setting this property on a binding used to communicate
with an HTTP proxy server, only one scheme should be set, and **WS_HTTP_HEADER_AUTH_SCHEME_NONE**
may not be used.

Alternatively, this property may be set to [WS_HTTP_HEADER_AUTH_SCHEME_PASSPORT](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_node_type).
**WS_HTTP_HEADER_AUTH_SCHEME_PASSPORT** must not be combined with any other value and cannot be used to
authenticate to an HTTP proxy server.

[WS_HTTP_HEADER_AUTH_SCHEME_NONE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_node_type) is only supported on the client. Setting it by itself disables HTTP header authentication.
Setting it in conjunction with other schemes allows the client to fall back to no header authentication when the server does not require it.
Otherwise, if the client specifies multiple authentication schemes and the server requires no authentication the request will fail.

When setting a single authentication scheme, the client will perform the request with that scheme set. If multiple schemes are set,
the client will first probe the server for the supported schemes by sending an unauthenticated blank request. Should the client
and server share more than one supported scheme, the client will prioritize schemes in the following order and pick the first mutually
supported one:

* [WS_HTTP_HEADER_AUTH_SCHEME_NEGOTIATE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_node_type)
* [WS_HTTP_HEADER_AUTH_SCHEME_NTLM](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_node_type)
* [WS_HTTP_HEADER_AUTH_SCHEME_DIGEST](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_node_type)
* [WS_HTTP_HEADER_AUTH_SCHEME_BASIC](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_node_type)

When the scheme is set to [WS_HTTP_HEADER_AUTH_SCHEME_NEGOTIATE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_node_type) and Kerberos authentication is negotiated, the Server Principal Name (SPN)
used is derived from the server's DNS name. Even when present [WS_ENDPOINT_IDENTITY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_endpoint_identity) is ignored. In order for authentication
to succeed, the server must be able to decrypt Kerberos tickets for that SPN.

When the scheme is set to [WS_HTTP_HEADER_AUTH_SCHEME_DIGEST](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_string_windows_integrated_auth_credential) or **WS_HTTP_HEADER_AUTH_SCHEME_BASIC**, then the [WS_STRING_WINDOWS_INTEGRATED_AUTH_CREDENTIAL](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_string_windows_integrated_auth_credential) must be used as credential type.

Note: Using "localhost", "127.0.0.1" or similar ways to refer to the local machine as server address may cause failures when using
[WS_HTTP_HEADER_AUTH_SCHEME_NTLM](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_node_type) or **WS_HTTP_HEADER_AUTH_SCHEME_NEGOTIATE**. It is recommended to use the machine name instead.

This setting may be specified in the security binding properties of [WS_HTTP_HEADER_AUTH_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_http_header_auth_security_binding).
The default is [WS_HTTP_HEADER_AUTH_SCHEME_NEGOTIATE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_node_type).

### `WS_SECURITY_BINDING_PROPERTY_HTTP_HEADER_AUTH_TARGET:7`

A [WS_HTTP_HEADER_AUTH_TARGET](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_http_header_auth_target) value that specifies the HTTP header authentication target to use. This property can be specified
on the client side to indicate whether the http header authentication security binding
is for the target server or the proxy server. Default value is **WS_HTTP_HEADER_AUTH_TARGET_SERVICE**.

This setting may be specified in the security binding properties of [WS_HTTP_HEADER_AUTH_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_http_header_auth_security_binding).

### `WS_SECURITY_BINDING_PROPERTY_HTTP_HEADER_AUTH_BASIC_REALM:8`

A [WS_STRING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_string) is used as the realm with the basic HTTP header
authentication scheme.

This setting may be specified in the security binding properties of a
server side [WS_HTTP_HEADER_AUTH_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_http_header_auth_security_binding).

### `WS_SECURITY_BINDING_PROPERTY_HTTP_HEADER_AUTH_DIGEST_REALM:9`

A [WS_STRING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_string) used as the realm with the digest HTTP
header authentication scheme.

This setting may be specified in the security binding properties of a
server side [WS_HTTP_HEADER_AUTH_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_http_header_auth_security_binding).

### `WS_SECURITY_BINDING_PROPERTY_HTTP_HEADER_AUTH_DIGEST_DOMAIN:10`

A [WS_STRING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_string) used as the domain name with the digest
HTTP header authentication scheme.

This setting may be specified in the security binding properties of a
server side [WS_HTTP_HEADER_AUTH_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_http_header_auth_security_binding).

### `WS_SECURITY_BINDING_PROPERTY_SECURITY_CONTEXT_KEY_SIZE:11`

A **ULONG** that specifies the key size (in bits) of the security token to be requested from an
issuer. If unspecified, the issuer decides the size. May be used with the [WS_SECURITY_CONTEXT_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_context_message_security_binding).

### `WS_SECURITY_BINDING_PROPERTY_SECURITY_CONTEXT_KEY_ENTROPY_MODE:12`

A [WS_SECURITY_KEY_ENTROPY_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_key_entropy_mode) value that specifies how entropy contributes to the key in issued symmetric key
tokens. The default is **WS_SECURITY_KEY_ENTROPY_MODE_COMBINED**.
This setting may be specified in the security binding properties of the [WS_SECURITY_CONTEXT_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_context_message_security_binding) structure.

### `WS_SECURITY_BINDING_PROPERTY_MESSAGE_PROPERTIES:13`

The set of [WS_MESSAGE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_properties) to be specified
while [creating the two messages](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatemessage) to
be used for the security token obtaining exchange. If this property
is not specified, the request and reply messages are created with the
default message properties. This setting may be specified in the security binding properties of the [WS_SECURITY_CONTEXT_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_context_message_security_binding) structure.

### `WS_SECURITY_BINDING_PROPERTY_SECURITY_CONTEXT_MAX_PENDING_CONTEXTS:14`

A **ULONG** that specifies the maximum number of pending security contexts on the service that
have not been accepted by the application (or service model) as
channels. The default is 100. The setting may be specified in the security binding properties of the [WS_SECURITY_CONTEXT_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_context_message_security_binding) structure.

### `WS_SECURITY_BINDING_PROPERTY_SECURITY_CONTEXT_MAX_ACTIVE_CONTEXTS:15`

A **ULONG** that specifies the maximum number of active security contexts on the service. The default is 1000.
The setting may be specified in the security binding properties of the [WS_SECURITY_CONTEXT_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_context_message_security_binding) structure.

### `WS_SECURITY_BINDING_PROPERTY_SECURE_CONVERSATION_VERSION:16`

A [WS_SECURE_CONVERSATION_VERSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_secure_conversation_version) value that specifies the version of WS-SecureConversation to use. The default is **WS_SECURE_CONVERSATION_VERSION_FEBRUARY_2005**.
This setting may be specified in the security binding properties of the [WS_SECURITY_CONTEXT_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_context_message_security_binding) structure.

### `WS_SECURITY_BINDING_PROPERTY_SECURITY_CONTEXT_SUPPORT_RENEW:17`

A **BOOL** that specifies
whether or not to support the renew operation on established security contexts. On the client, if this is
set to **FALSE**, instead of renewing the existing security context a new context
will be established. On the server, all incoming renew messages will be
rejected. The default is **TRUE**.
This setting may be specified in the security binding properties of the [WS_SECURITY_CONTEXT_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_context_message_security_binding) structure.

### `WS_SECURITY_BINDING_PROPERTY_SECURITY_CONTEXT_RENEWAL_INTERVAL:18`

A [WS_TIMESPAN](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_timespan) structure that contains the interval before which a security context must be renewed. On the client it defaults to 10 hours
and denotes the time after which the session is proactively renewed. On the server it defaults to 15 hours
and denotes context lifetime. A server context must be renewed before that limit is reached.
This setting may be specified in the security binding properties of the
[WS_SECURITY_CONTEXT_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_context_message_security_binding) structure.

### `WS_SECURITY_BINDING_PROPERTY_SECURITY_CONTEXT_ROLLOVER_INTERVAL:19`

A [WS_TIMESPAN](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_timespan) structure that contains the time interval for which an old security context token should be accepted after a renewal. The default is 5 minutes.
This tolerance interval is provided to smoothly handle application messages during session renewal.
This setting may be specified in the security binding properties of the
[WS_SECURITY_CONTEXT_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_context_message_security_binding) structure.

### `WS_SECURITY_BINDING_PROPERTY_CERT_FAILURES_TO_IGNORE:20`

A **ULONG** that specifies a set of certificate verification failures that are ignored by the client so that communication with
the remote endpoint will succeed regardless.
Any combination of the values defined in [WS_CERT_FAILURE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_value_type) or 0 may be specified. The default is **WS_CERT_FAILURE_REVOCATION_OFFLINE**.
This setting may be specified in the security binding properties of the
[WS_SSL_TRANSPORT_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_ssl_transport_security_binding) structure on the client.

Ignoring certificate verification failures can expose the application to potential security vulnerabilities.
The use of this property should be carefully evaluated.

### `WS_SECURITY_BINDING_PROPERTY_DISABLE_CERT_REVOCATION_CHECK:21`

A **BOOL** that specifies the state of certificate revocation checking. When set to **TRUE**, certificate revocation checking is disabled. The default is **FALSE**.
This setting may be specified in the security binding properties of the
[WS_SSL_TRANSPORT_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_ssl_transport_security_binding) structure on the client.

Disabling certificate revocation checking can expose the application to potential security vulnerabilities.
The use of this property should be carefully evaluated.

### `WS_SECURITY_BINDING_PROPERTY_DISALLOWED_SECURE_PROTOCOLS:22`

### `WS_SECURITY_BINDING_PROPERTY_CERTIFICATE_VALIDATION_CALLBACK_CONTEXT:23`

A [WS_CERTIFICATE_VALIDATION_CALLBACK_CONTEXT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_certificate_validation_callback_context) structure that specifies a callback which will be invoked for each send request operation. This allows an application to validate the certificate associated with the connection of a request.