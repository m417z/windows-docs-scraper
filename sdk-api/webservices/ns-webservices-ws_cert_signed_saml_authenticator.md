# WS_CERT_SIGNED_SAML_AUTHENTICATOR structure

## Description

The type for specifying a SAML token authenticator based on an array
of expected issuer certificates. When an authenticator of this type
is used, an incoming SAML token will be accepted if only if it has a
valid XML signature created with any one of the specified X.509
certificates. Thus, the specified X.509 certificates represent a
'allow list' of trusted SAML issuers.

No revocation or chain trust checks are done by the runtime on the
specified certificates: so, it is up to the application to make sure
that the certificates are valid before they are specified in this
structure.

As indicated above, the validation of the received SAML is limited to
making sure that it was signed correctly by one of the specified
certificates. The application may then extract the SAML assertion
using [WsGetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmessageproperty) with the key
[WS_MESSAGE_PROPERTY_SAML_ASSERTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_property_id) and do
additional validator or processing.

## Members

### `authenticator`

The base type from which this type and all other SAML authenticator
types derive.

### `trustedIssuerCerts`

The array of acceptable SAML issuers, identified by their X.509
certificates. This field is required.

The certificate handles are duplicated and the copies are kept for
internal use. The application continues to own the certificate
handles supplied here and is responsible for freeing them anytime
after the listener creation call that uses this structure returns.

### `trustedIssuerCertCount`

The count of X.509 certificates specified in trustedIssuerCerts.

### `decryptionCert`

The certificate for decrypting incoming SAML tokens.

The certificate handle is duplicated and the copy is kept for internal
use. The application continues to own the certificate handle supplied
here and is responsible for freeing it anytime after the listener
creation call that uses this structure returns.

### `_CERT_CONTEXT`

### `samlValidator`

An optional callback to enable the application to additional
validation on the SAML assertion if the signature validation passes.

### `samlValidatorCallbackState`

The state to be passed back when invoking the samlValidator callback.