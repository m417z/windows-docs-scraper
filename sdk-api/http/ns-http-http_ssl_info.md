# HTTP_SSL_INFO structure

## Description

The
**HTTP_SSL_INFO** structure contains data for a connection that uses Secure Sockets Layer (SSL), obtained through the SSL handshake.

## Members

### `ServerCertKeySize`

The size, in bytes, of the public key used to sign the server certificate.

### `ConnectionKeySize`

The size, in bytes, of the cipher key used to encrypt the current session.

### `ServerCertIssuerSize`

The size, in bytes, of the string pointed to by the **pServerCertIssuer** member not including the terminating null character.

### `ServerCertSubjectSize`

The size, in bytes, of the string pointed to by the **pServerCertSubject** member not including the terminating null character.

### `pServerCertIssuer`

A pointer to a null-terminated string of octets that specifies the name of the entity that issued the certificate.

### `pServerCertSubject`

A pointer to a null-terminated string of octets that specifies the name of the entity to which the certificate belongs.

### `pClientCertInfo`

A pointer to an
[HTTP_SSL_CLIENT_CERT_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_ssl_client_cert_info) structure that specifies the client certificate.

### `SslClientCertNegotiated`

If non-zero, indicates that the client certificate is already present locally.

## Remarks

An
**HTTP_SSL_INFO** structure can be pointed to by the **pSslInfo** member of an
[HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85)) structure.

## See also

[HTTP Server API Version 1.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-structures)

[HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85))

[HTTP_SSL_CLIENT_CERT_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_ssl_client_cert_info)