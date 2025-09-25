# RASPPP_PROJECTION_INFO structure

## Description

The
**RASPPP_PROJECTION_INFO** structure contains information obtained during Point-to-Point (PPP) negotiation of Internet Protocol version 4 (IPv4) and IPv6 projection operations, and PPP Link Control Protocol (LCP)/multilink, and Compression Control Protocol (CCP) negotiation.

## Members

### `dwIPv4NegotiationError`

A value that specifies the result of PPP IPv4 network control protocol negotiation. A value of zero indicates Ipv4 has been negotiated successfully. A nonzero value indicates failure, and is the fatal error that occurred during the control protocol negotiation.

### `ipv4Address`

A [RASIPV4ADDR](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-data-types) that contains a null-terminated Unicode string that specifies the IPv4 address of the local client. This string has the form "a.b.c.d". **ipv4Address** is valid only if **dwIPv4NegotiationError** is zero.

### `ipv4ServerAddress`

A [RASIPV4ADDR](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-data-types) structure that contains a Unicode string that specifies the IPv4 address of the remote server. This string has the form "a.b.c.d". **ipv4ServerAddress** is valid only if **dwIPv4NegotiationError** is zero. If the address is not available, this member is an empty string.

### `dwIPv4Options`

A value that specifies Internet Protocol Control Protocol (IPCP) options for the local client.

| Value | Meaning |
| --- | --- |
| **RASIPO_VJ** | Indicates that IP datagrams sent by the local client are compressed using Van Jacobson compression. |

### `dwIPv4ServerOptions`

A value that specifies IPCP options for the remote server.

| Value | Meaning |
| --- | --- |
| **RASIPO_VJ** | Indicates that IP datagrams sent by the remote server (that is, received by the local computer) are compressed using Van Jacobson compression. |

### `dwIPv6NegotiationError`

A value that specifies the result of PPP IPv6 network control protocol negotiation. A value of zero indicates Ipv6 has been negotiated successfully. A nonzero value indicates failure, and is the fatal error that occurred during the control protocol negotiation.

### `bInterfaceIdentifier`

An array that specifies the 64-bit IPv6 interface identifier of the client. The last 64 bits of a 128-bit IPv6 internet address are considered the "interface identifier," which provides a strong level of uniqueness for the preceding 64-bits. **bInterfaceIdentifier** must not be zero and is valid only if **dwIPv6NegotiationError** is zero.

### `bServerInterfaceIdentifier`

An array that specifies the 64-bit IPv6 interface identifier of the server. The last 64 bits of a 128-bit IPv6 internet address are considered the "interface identifier," which provides a strong level of uniqueness for the preceding 64-bits. **bServerInterfaceIdentifier** must not be zero and is valid only if **dwIPv6NegotiationError** is zero.

### `fBundled`

A **BOOL** that is **TRUE** if the connection is composed of multiple links and **FALSE** otherwise.

### `fMultilink`

A **BOOL** that is **TRUE** if the connection supports multiple links and **FALSE** otherwise.

### `dwAuthenticationProtocol`

A value that specifies the authentication protocol used to authenticate the local client. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **RASLCPAP_PAP** | Password Authentication Protocol. |
| **RASLCPAP_SPAP** | Shiva Password Authentication Protocol. |
| **RASLCPAP_CHAP** | Challenge Handshake Authentication Protocol. |
| **RASLCPAP_EAP** | Extensible Authentication Protocol. |

### `dwAuthenticationData`

A value that specifies additional information about the authentication protocol specified by **dwAuthenticationProtocol**. **dwAuthenticationData** and **dwServerAuthenticationData** when different authentication protocols on the client and server. This member can be one of the following values:

| Value | Meaning |
| --- | --- |
| **RASLCPAD_CHAP_MD5** | MD5 CHAP. |
| **RASLCPAD_CHAP_MS** | Microsoft CHAP. |
| **RASLCPAD_CHAP_MSV2** | Microsoft CHAP version 2. |

### `dwServerAuthenticationProtocol`

A value that specifies the authentication protocol used to authenticate the remote server. This member can be one of the following values:

| Value | Meaning |
| --- | --- |
| **RASLCPAP_PAP** | Password Authentication Protocol. |
| **RASLCPAP_SPAP** | Shiva Password Authentication Protocol. |
| **RASLCPAP_CHAP** | Challenge Handshake Authentication Protocol. |
| **RASLCPAP_EAP** | Extensible Authentication Protocol. |

### `dwServerAuthenticationData`

A value that specifies additional information about the authentication protocol specified by **dwServerAuthenticationProtocol**. **dwAuthenticationData** and **dwServerAuthenticationData** when different authentication protocols on the client and server. This member can be one of the following values:

| Value | Meaning |
| --- | --- |
| **RASLCPAD_CHAP_MD5** | MD5 CHAP. |
| **RASLCPAD_CHAP_MS** | Microsoft CHAP. |
| **RASLCPAD_CHAP_MSV2** | Microsoft CHAP version 2. |

### `dwEapTypeId`

A value that specifies the type identifier of the Extensible Authentication Protocol (EAP) used to authenticate the local client. The value of this member is valid only if **dwAuthenticationProtocol** is **RASLCPAPP_EAP.**.

### `dwServerEapTypeId`

A value that specifies the type identifier of the Extensible Authentication Protocol (EAP) used to authenticate the remote server. The value of this member is valid only if **dwRemoteAuthenticationProtocol** is **RASLCPAPP_EAP.**.

### `dwLcpOptions`

A value that specifies information about LCP options in use by the local client. This member is a combination of the following flags:

| Value | Meaning |
| --- | --- |
| **RASLCPO_PFC** | The connection is using Protocol Field Compression ([RFC 1172](https://www.ietf.org/rfc/rfc1172.txt)). |
| **RASLCPO_ACFC** | The connection is using Address and Control Field Compression ([RFC 1172](https://www.ietf.org/rfc/rfc1172.txt)). |
| **RASLCPO_SSHF** | The connection is using Short Sequence Number Header Format (see RFC 1990). |
| **RASLCPO_DES_56** | The connection is using DES 56-bit encryption. |
| **RASLCPO_3_DES** | The connection is using Triple DES Encryption. |

### `dwLcpServerOptions`

A value that specifies information about LCP options in use by the remote server. This member is a combination of the following flags:

| Value | Meaning |
| --- | --- |
| **RASLCPO_PFC** | The connection is using Protocol Field Compression ([RFC 1172](https://www.ietf.org/rfc/rfc1172.txt)). |
| **RASLCPO_ACFC** | The connection is using Address and Control Field Compression ([RFC 1172](https://www.ietf.org/rfc/rfc1172.txt)). |
| **RASLCPO_SSHF** | The connection is using Short Sequence Number Header Format (see RFC 1990). |
| **RASLCPO_DES_56** | The connection is using DES 56-bit encryption. |
| **RASLCPO_3_DES** | The connection is using Triple DES Encryption. |

### `dwCcpError`

### `dwCcpCompressionAlgorithm`

A value that specifies the compression algorithm used by the local client. The following table shows the possible values for this member.

| Value | Meaning |
| --- | --- |
| **RASCCPCA_MPPC** | Microsoft Point-to-Point Compression (MPPC) Protocol ([RFC 2118](https://www.ietf.org/rfc/rfc2118.txt)). |
| **RASCCPCA_STAC** | STAC option 4 ([RFC 1974](https://www.ietf.org/rfc/rfc1974.txt)). |

### `dwCcpServerCompressionAlgorithm`

A value that specifies the compression algorithm used by the remote server. The following algorithms are supported:

| Value | Meaning |
| --- | --- |
| **RASCCPCA_MPPC** | Microsoft Point-to-Point Compression (MPPC) Protocol ( [RFC 2118](https://www.ietf.org/rfc/rfc2118.txt)). |
| **RASCCPCA_STAC** | STAC option 4 ( [RFC 1974](https://www.ietf.org/rfc/rfc1974.txt)). |

### `dwCcpOptions`

A value that specifies the compression types available on the local client. The following types are supported:

| Value | Meaning |
| --- | --- |
| **RASCCPO_COMPRESSION** | Compression without encryption. |
| **RASCCPO_HISTORYLESS** | Microsoft Point-to-Point Encryption (MPPE) in stateless mode. The session key is changed after every packet. This mode improves performance on high latency networks, or networks that experience significant packet loss. |
| **RASCCPO_ENCRYPTION40BITOLD** | MPPE compression using 40-bit keys. |
| **RASCCPO_ENCRYPTION40BIT** | MPPE compression using 40-bit keys. |
| **RASCCPO_ENCRYPTION56BIT** | MPPE compression using 56-bit keys. |
| **RASCCPO_ENCRYPTION128BIT** | MPPE compression using 128-bit keys. |

### `dwCcpServerOptions`

A value that specifies the compression types available on the remote server. The following types are supported:

| Value | Meaning |
| --- | --- |
| **RASCCPO_COMPRESSION** | Compression without encryption. |
| **RASCCPO_HISTORYLESS** | Microsoft Point-to-Point Encryption (MPPE) in stateless mode. The session key is changed after every packet. This mode improves performance on high latency networks, or networks that experience significant packet loss. |
| **RASCCPO_ENCRYPTION40BITOLD** | MPPE compression using 40-bit keys. |
| **RASCCPO_ENCRYPTION40BIT** | MPPE compression using 40-bit keys. |
| **RASCCPO_ENCRYPTION56BIT** | MPPE compression using 56-bit keys. |
| **RASCCPO_ENCRYPTION128BIT** | MPPE compression using 128-bit keys. |

## See also

[RasGetProjectionInfoEx](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetprojectioninfoex)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Structures](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-structures)