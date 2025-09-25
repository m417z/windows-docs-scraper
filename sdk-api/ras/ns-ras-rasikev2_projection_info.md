# RASIKEV2_PROJECTION_INFO structure

## Description

The
**RASIKEV2_PROJECTION_INFO** structure contains projection information obtained during Internet Key Exchange (IKE) negotiation.

## Members

### `dwIPv4NegotiationError`

A value that specifies the result of IPv4 negotiation. A value of zero indicates an IPv4 address has been assigned successfully. A nonzero value indicates failure, and is the fatal error that occurred during negotiation.

### `ipv4Address`

A [RASIPV4ADDR](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-data-types) structure that contains a null-terminated Unicode string that specifies the IPv4 address of the local client. This string has the form "a.b.c.d". **ipv4Address** is valid only if **dwIPv4NegotiationError** is zero.

### `ipv4ServerAddress`

A [RASIPV4ADDR](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-data-types) structure that contains a null-terminated Unicode string that specifies the IPv4 address of the remote server. This string has the form "a.b.c.d". **ipv4ServerAddress** is valid only if **dwIPv4NegotiationError** is zero. If the address is not available, this member is an empty string.

### `dwIPv6NegotiationError`

A value that specifies the result of IPv6 negotiation. A value of zero indicates an IPv6 address has been negotiated successfully. A nonzero value indicates failure, and is the fatal error that occurred during negotiation.

### `ipv6Address`

A [RASIPV6ADDR](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-data-types) structure that contains a null-terminated Unicode string that specifies the IPv6 address of the local client. **ipv6Address** is valid only if **dwIPv6NegotiationError** is zero.

### `ipv6ServerAddress`

A [RASIPV6ADDR](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-data-types) structure that contains a null-terminated Unicode string that specifies the IPv6 address of the remote server. **ipv6ServerAddress** is valid only if **dwIPv6NegotiationError** is zero. If the address is not available, this member is an empty string.

### `dwPrefixLength`

A value that specifies the length, in bits, of the IPv6 address prefix.

### `dwAuthenticationProtocol`

A value that specifies the authentication protocol used to authenticate the remote server. The following authentication protocols are supported:

| Value | Meaning |
| --- | --- |
| **RASIKEv2_AUTH_MACHINECERTIFICATES** | X.509 Public Key Infrastructure Certificate ([RFC 2459](https://www.ietf.org/rfc/rfc2459.txt)). |
| **RASIKEv2_AUTH_EAP** | Extensible Authentication Protocol. |

### `dwEapTypeId`

A value that specifies the type identifier of the Extensible Authentication Protocol (EAP) used to authenticate the local client. The value of this member is valid only if **dwAuthenticationProtocol** is **RASIKEv2_AUTH_EAP**.

### `dwFlags`

A bitmap of flags that can be any combination of the following values:

| Value | Meaning |
| --- | --- |
| **RASIKEv2_FLAGS_MOBIKESUPPORTED** | The client supports Mobile IKE (MOBIKE). |
| **RASIKEv2_FLAGS_BEHIND_NAT** | The client is behind Network Address Translation (NAT). |
| **RASIKEv2_FLAGS_SERVERBEHIND_NAT** | The server is behind Network Address Translation (NAT). |

### `dwEncryptionMethod`

A value that specifies the encryption method used in the connection. The following encryption methods are supported:

| Value | Meaning |
| --- | --- |
| **IPSEC_CIPHER_TYPE_3DES** | 3DES encryption. |
| **IPSEC_CIPHER_TYPE_AES_128** | AES-128 encryption. |
| **IPSEC_CIPHER_TYPE_AES_192** | AES-192 encryption. |
| **IPSEC_CIPHER_TYPE_AES_256** | AES-256 encryption. |

### `numIPv4ServerAddresses`

The number of available IPv4 addresses the server can switch to on the IKEv2 connection.

### `ipv4ServerAddresses`

A pointer to a [RASIPV4ADDR](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-data-types) structure that contains the available IPv4 addresses the server can switch to on the IKEv2 connection.

### `numIPv6ServerAddresses`

The number of available IPv6 addresses the server can switch to on the IKEv2 connection.

### `ipv6ServerAddresses`

A pointer to a [RASIPV6ADDR](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-data-types) structure that contains the available IPv6 addresses the server can switch to on the IKEv2 connection.

## See also

[RASPROJECTION_INFO_TYPE](https://learn.microsoft.com/windows/desktop/api/ras/ne-ras-rasprojection_info_type)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Structures](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-structures)