## Description

The **SecPkgContext_NegotiatedTlsExtensions** structure contains information about the (D)TLS extensions negotiated for the current (D)TLS connection.

## Members

### `ExtensionsCount`

The number of negotiated (D)TLS extensions.

### `Extensions`

A pointer to the array of 2-byte TLS extension IDs as defined in the [IANA (D)TLS extensions registry](https://www.iana.org/assignments/tls-extensiontype-values/tls-extensiontype-values.xhtml).

## Remarks

The list of (D)TLS extensions returned via this structure is not exhaustive. Depending on the type of the (D)TLS extension, it is not always possible to determine whether it has been negotiated with the peer. This structure generally reports negotiable (D)TLS extensions of interest to SSPI callers, such as: Certificate Status Request, Application Layer Protocol Negotiation, Secure Real-time Transport Protocol, Token Binding, Extended Master Secret, Renegotiation Info.

## See also

[IANA (D)TLS extensions registry](https://www.iana.org/assignments/tls-extensiontype-values/tls-extensiontype-values.xhtml)

[QueryContextAttributes (Schannel) function](https://learn.microsoft.com/windows/win32/secauthn/querycontextattributes--schannel)