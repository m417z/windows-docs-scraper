# IKEV2_PROJECTION_INFO structure

## Description

The
**IKEV2_PROJECTION_INFO** structure contains information obtained during Internet Key Exchange (IKE) negotiation.

## Members

### `dwIPv4NegotiationError`

A value that specifies the result of IPv4 negotiation. A value of zero indicates an IPv4 address has been assigned successfully. A nonzero value indicates failure, and is the fatal error that occurred during negotiation.

### `wszAddress`

An array that contains a Unicode string that specifies the IPv4 address of the local client. This string has the form "a.b.c.d". **wszAddress** is valid only if **dwIPv4NegotiationError** is zero.

### `wszRemoteAddress`

An array that contains a Unicode string that specifies the IPv4 address of the remote server. This string has the form "a.b.c.d". **wszRemoteAddress** is valid only if **dwIPv4NegotiationError** is zero. If the address is not available, this member is an empty string.

### `IPv4SubInterfaceIndex`

A value that specifies the IPv4 subinterface index corresponding to the connection on the server.

### `dwIPv6NegotiationError`

A value that specifies the result of IPv6 negotiation. A value of zero indicates an IPv6 address has been negotiated successfully. A nonzero value indicates failure, and is the fatal error that occurred during negotiation.

### `bInterfaceIdentifier`

An array that specifies the 64-bit IPv6 interface identifier of the client. The last 64 bits of a 128-bit IPv6 internet address are considered the "interface identifier," which provides a strong level of uniqueness for the preceding 64-bits. **bInterfaceIdentifier** is valid only if **dwIPv6NegotiationError** is zero and must not be zero.

### `bRemoteInterfaceIdentifier`

An array that specifies the 64-bit IPv6 interface identifier of the server. The last 64 bits of a 128-bit IPv6 internet address are considered the "interface identifier," which provides a strong level of uniqueness for the preceding 64-bits. **bInterfaceIdentifier** is valid only if **dwIPv6NegotiationError** is zero and must not be zero.

### `bPrefix`

A value that specifies the client interface IPv6 address prefix.

### `dwPrefixLength`

A value that specifies the length, in bits, of **bPrefix**.

### `IPv6SubInterfaceIndex`

A value that specifies the IPv6 subinterface index corresponding to the connection on the server.

### `dwOptions`

Not used.

### `dwAuthenticationProtocol`

A value that specifies the authentication protocol used to authenticate the remote server. The following authentication protocols are supported:

| Value | Meaning |
| --- | --- |
| **MPRAPI_IKEV2_AUTH_USING_CERT** | X.509 Public Key Infrastructure Certificate ([RFC 2459](https://www.ietf.org/rfc/rfc2459.txt)) |
| **MPRAPI_IKEV2_AUTH_USING_EAP** | Extensible Authentication Protocol |

### `dwEapTypeId`

A value that specifies the type identifier of the Extensible Authentication Protocol (EAP) used to authenticate the local client. The value of this member is valid only if **dwAuthenticationProtocol** is **MPRAPI_IKEV2_AUTH_USING_EAP**.

### `dwCompressionAlgorithm`

Not used.

### `dwEncryptionMethod`

A value that specifies the encryption method used in the connection. The following encryption methods are supported:

| Value | Meaning |
| --- | --- |
| **IPSEC_CIPHER_TYPE_3DES** | 3DES encryption |
| **IPSEC_CIPHER_TYPE_AES_128** | AES-128 encryption |
| **IPSEC_CIPHER_TYPE_AES_192** | AES-192 encryption |
| **IPSEC_CIPHER_TYPE_AES_256** | AES-256 encryption |

## See also

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)

[Router Management Structures](https://learn.microsoft.com/windows/desktop/RRAS/router-management-structures)