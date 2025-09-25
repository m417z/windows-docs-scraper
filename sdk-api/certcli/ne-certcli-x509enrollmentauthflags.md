# X509EnrollmentAuthFlags enumeration

## Description

The **X509EnrollmentAuthFlags** enumeration specifies the authentication type.

## Constants

### `X509AuthNone:0`

Reserved.

### `X509AuthAnonymous:1`

Anonymous authentication.

### `X509AuthKerberos:2`

Kerberos authentication.

### `X509AuthUsername:4`

Plaintext user name and password authentication.

### `X509AuthCertificate:8`

A client authentication certificate (suitable for [Secure Sockets Layer protocol](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) client authentication) that is installed locally and that has an associated private key. This certificate is used by the server to verify the client's identity.