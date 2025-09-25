# WS_SECURITY_TOKEN_REFERENCE_MODE enumeration

## Description

With message and mixed-mode security bindings, the mechanism to use to
refer to a security token from signatures, encrypted items and derived
tokens. The security runtime can use the right reference on its own
most of the time, and this needs to be explicitly set only when a
specific reference mechanism is required, typically for interop with
another platform that supports only that reference form.

## Constants

### `WS_SECURITY_TOKEN_REFERENCE_MODE_LOCAL_ID:1`

The id of the serialized security token is used to refer to it. This
reference mechanism can be used only when the security token is
serialized in the same message as the item (such as a signature) that
needs to refer to the security token.

### `WS_SECURITY_TOKEN_REFERENCE_MODE_XML_BUFFER:2`

An opaque XML buffer that is used as a token reference (for example, as in a custom token).

### `WS_SECURITY_TOKEN_REFERENCE_MODE_CERT_THUMBPRINT:3`

The thumbprint of a certificate is used to refer to it.

### `WS_SECURITY_TOKEN_REFERENCE_MODE_SECURITY_CONTEXT_ID:4`

The context-id is used to refer to a security context token.

### `WS_SECURITY_TOKEN_REFERENCE_MODE_SAML_ASSERTION_ID:5`

The SAML assertion ID is used to refer to the SAML token.