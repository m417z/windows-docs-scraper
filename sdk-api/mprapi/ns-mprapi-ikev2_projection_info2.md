# IKEV2_PROJECTION_INFO2 structure

## Description

Contains information obtained during Internet Key Exchange (IKE) negotiation.

## Members

### `dwIPv4NegotiationError`

A value that specifies the result of IPv4 negotiation. A value of zero indicates an IPv4 address has been assigned successfully. A nonzero value indicates failure, and is the fatal error that occurred during negotiation.

### `wszAddress`

An null-terminated Unicode string that specifies the IPv4 address of the local client. The string has the form "a.b.c.d". The **wszAddress** member is valid only if the **dwIPv4NegotiationError** member is 0.

### `wszRemoteAddress`

A null-terminated Unicode string that specifies the IPv4 address of the remote server. This string has the form "a.b.c.d". The **wszRemoteAddress** member is valid only if the **dwIPv4NegotiationError** member is zero. If the address is not available, this member is an empty string.

### `IPv4SubInterfaceIndex`

A value that specifies the IPv4 subinterface index corresponding to the connection on the server.

### `dwIPv6NegotiationError`

A value that specifies the result of IPv6 negotiation. A value of 0 indicates an IPv6 address has been negotiated successfully. A nonzero value indicates failure, and is the fatal error that occurred during negotiation.

### `bInterfaceIdentifier`

An array that specifies the 64-bit IPv6 interface identifier of the client. The last 64-bits of a 128-bit IPv6 internet address are considered the interface identifier, which provides a strong level of uniqueness for the preceding 64-bits. The **bInterfaceIdentifier** member is valid only if the **dwIPv6NegotiationError** member is 0. The *bInterfaceIdentifier* member must not be 0.

### `bRemoteInterfaceIdentifier`

An array that specifies the 64-bit IPv6 interface identifier of the server. The last 64 bits of a 128-bit IPv6 internet address are considered the interface identifier, which provides a strong level of uniqueness for the preceding 64 bits. The **bInterfaceIdentifier** member must not be 0 and is valid only if the **dwIPv6NegotiationError** member is zero.

### `bPrefix`

A value that specifies the client interface IPv6 address prefix.

### `dwPrefixLength`

A value that specifies the length, in bits, of the **bPrefix** member.

### `IPv6SubInterfaceIndex`

A value that specifies the IPv6 subinterface index corresponding to the connection on the server.

### `dwOptions`

Not implemented.

### `dwAuthenticationProtocol`

A value that specifies the authentication protocol used to authenticate the remote server. The following authentication protocols are supported:

| Value | Meaning |
| --- | --- |
| **MPRAPI_IKEV2_AUTH_USING_CERT** | X.509 Public Key Infrastructure Certificate (described in RFC 2459) |
| **MPRAPI_IKEV2_AUTH_USING_EAP** | Extensible Authentication Protocol |

### `dwEapTypeId`

A value that specifies the type identifier of the Extensible Authentication Protocol (EAP) used to authenticate the local client. The value of this member is valid only if the **dwAuthenticationProtocol** member is **MPRAPI_IKEV2_AUTH_USING_EAP**.

### `dwEmbeddedEAPTypeId`

A value that specifies the type identifier of the inner EAP method used in the EAP authentication. The value of this member is valid only if the **dwEapTypeId** member is set to **PEAP** defined in IANA-EAP.

### `dwCompressionAlgorithm`

Not implemented.

### `dwEncryptionMethod`

A value that specifies the encryption method used in the connection. The following encryption methods are supported:

| Value | Meaning |
| --- | --- |
| **IPSEC_CIPHER_TYPE_3DES** | 3DES encryption |
| **IPSEC_CIPHER_TYPE_AES_128** | AES-128 encryption |
| **IPSEC_CIPHER_TYPE_AES_192** | AES-192 encryption |
| **IPSEC_CIPHER_TYPE_AES_256** | AES-256 encryption |