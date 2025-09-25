# WS_REQUEST_SECURITY_TOKEN_PROPERTY_ID enumeration

## Description

Identifies the properties for requesting a security token from an issuer. It is used with [WsRequestSecurityToken](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsrequestsecuritytoken) as part of the [WS_REQUEST_SECURITY_TOKEN_PROPERTY*](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_request_security_token_property) parameter.

## Constants

### `WS_REQUEST_SECURITY_TOKEN_PROPERTY_APPLIES_TO:1`

A pointer to a [WS_ENDPOINT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_endpoint_address) structure containing the address of the service ('relying party') to whom the requested
token will be presented.
.

### `WS_REQUEST_SECURITY_TOKEN_PROPERTY_TRUST_VERSION:2`

A [WS_TRUST_VERSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_trust_version) value that specifies the version of WS-Trust to use.

If this property is not specified, it defaults to [WS_TRUST_VERSION_FEBRUARY_2005](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_trust_version).

### `WS_REQUEST_SECURITY_TOKEN_PROPERTY_SECURE_CONVERSATION_VERSION:3`

A [WS_SECURE_CONVERSATION_VERSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_secure_conversation_version) value that
specifies the version of WS-SecureConversation to use when [WS_REQUEST_SECURITY_TOKEN_ACTION_NEW_CONTEXT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_request_security_token_action)
or **WS_REQUEST_SECURITY_TOKEN_ACTION_RENEW_CONTEXT** are specified.

If this property is not specified, it defaults to [WS_SECURE_CONVERSATION_VERSION_FEBRUARY_2005](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_secure_conversation_version).

### `WS_REQUEST_SECURITY_TOKEN_PROPERTY_ISSUED_TOKEN_TYPE:4`

A pointer to a [WS_XML_STRING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_string) structure that specifies the type of the security token to be issued. If this property is not specified,
the corresponding element is not generated in the request security token message, and the
issuer is assumed to know the token type required.

### `WS_REQUEST_SECURITY_TOKEN_PROPERTY_REQUEST_ACTION:5`

A [WS_REQUEST_SECURITY_TOKEN_ACTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_request_security_token_action) value that specifies the action to be used with the request. The default is **WS_REQUEST_SECURITY_TOKEN_ACTION_ISSUE**.

### `WS_REQUEST_SECURITY_TOKEN_PROPERTY_EXISTING_TOKEN:6`

A pointer to a [WS_SECURITY_TOKEN](https://learn.microsoft.com/windows/desktop/wsw/ws-security-token) structure that,
if specified, instead of requesting a new token, the provided token is renewed by requesting a new token based on
the existing one. The old token becomes invalid if this operation succeeds.
Only supported with [WS_REQUEST_SECURITY_TOKEN_ACTION_RENEW_CONTEXT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_request_security_token_action).

### `WS_REQUEST_SECURITY_TOKEN_PROPERTY_ISSUED_TOKEN_KEY_TYPE:7`

A [WS_SECURITY_KEY_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_key_type) value that specifies the type of the cryptographic key to be requested for the
issued security token. This must be set to **WS_SECURITY_KEY_TYPE_NONE** or **WS_SECURITY_KEY_TYPE_SYMMETRIC**.

The value [WS_SECURITY_KEY_TYPE_NONE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_key_type) specifies a bearer token without
proof-of-possession keys. Such tokens will not produce a signature when used to secure a message.

If this property is not specified, the corresponding key type element is not emitted in token requests.
Not emitting the key type in token requests results in the implied default of symmetric keys for the
issued token, as defined in the WS-Trust specification.

### `WS_REQUEST_SECURITY_TOKEN_PROPERTY_ISSUED_TOKEN_KEY_SIZE:8`

A **ULONG** that specifies the size (in bits) of the cryptographic key to be requested
in the issued security token. This property may be specified only for
issued tokens with symmetric keys. If this property is not specified,
the corresponding key size element is not emitted in token requests.

### `WS_REQUEST_SECURITY_TOKEN_PROPERTY_ISSUED_TOKEN_KEY_ENTROPY:9`

A [WS_SECURITY_KEY_ENTROPY_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_key_entropy_mode) value that specifies how entropy is contributed to the cryptographic key of the
issued token. This property may be specified only for issued tokens
with symmetric keys. If this property is not specified, the mode **WS_SECURITY_KEY_ENTROPY_MODE_SERVER_ONLY** is used.

### `WS_REQUEST_SECURITY_TOKEN_PROPERTY_LOCAL_REQUEST_PARAMETERS:10`

A pointer to a [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer) that contains
the additional primary parameters to be included verbatim in request
security token messages. Each such parameter must be a top-level
element in the supplied XML buffer. If this property is not specified, such
parameters are not emitted. The buffer is serialized into the RequestSecurityToken element
when requesting a security token.

Unlike [WS_REQUEST_SECURITY_TOKEN_PROPERTY_SERVICE_REQUEST_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_request_security_token_property_id), local request
parameters are defined by the client as a means to add parameters to the token request.

### `WS_REQUEST_SECURITY_TOKEN_PROPERTY_SERVICE_REQUEST_PARAMETERS:11`

A pointer to a [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer) that contains
the service parameters to include in request security token
messages, supplied as an XML buffer. Each such parameter must be a
top-level element in the supplied XML buffer. If this is property not specified, such
parameters are not emitted.

If [WS_TRUST_VERSION_FEBRUARY_2005](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_trust_version) is specified this buffer is serialized
into the RequestSecurityToken element following the
[WS_REQUEST_SECURITY_TOKEN_PROPERTY_LOCAL_REQUEST_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_request_security_token_property_id).

If [WS_TRUST_VERSION_1_3](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_trust_version) is specified this buffer is serialized into the
RequestSecurityToken/SecondaryParameters element.

Service request parameters are instructions regarding how to issue a token. They are obtained from the service,
usually by means of metadata import. In that case, this parameter may be obtained
from the out.RequestSecurityTokenTemplate field of the [WS_ISSUED_TOKEN_MESSAGE_SECURITY_BINDING_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_issued_token_message_security_binding_constraint).

### `WS_REQUEST_SECURITY_TOKEN_PROPERTY_MESSAGE_PROPERTIES:12`

The set of [WS_MESSAGE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_properties) to be specified
while creating the two messages with [WsCreateMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatemessage) and are to
be used for the security token obtaining exchange. If this property
is not specified, the request and reply messages are created with the
default message properties.

### `WS_REQUEST_SECURITY_TOKEN_PROPERTY_BEARER_KEY_TYPE_VERSION:13`