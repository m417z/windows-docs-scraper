# PPP_PROJECTION_INFO2 structure

## Description

Contains information obtained during Point-to-Point (PPP) negotiation for Secure Socket Tunneling Protocol (SSTP), Point-to-Point Tunneling Protocol (PPTP), and Layer 2 Tunneling Protocol (L2TP).

## Members

### `dwIPv4NegotiationError`

A value that specifies the result of PPP IPv4 Network control protocol negotiation. A value of 0 indicates IPv4 has been negotiated successfully. A nonzero value indicates failure, and also represents the fatal error that occurred during the control protocol negotiation.

### `wszAddress`

A null-terminated Unicode string that specifies the IPv4 address of the local client. This string has the form "a.b.c.d". The **wszAddress** member is valid only if dwIPv4NegotiationError is 0.

### `wszRemoteAddress`

An array that contains a Unicode string that specifies the IPv4 address of the remote server. This string has the form "a.b.c.d". The **wszRemoteAddress** member is valid only if the **dwIPv4NegotiationError** member is zero. If the address is not available, this member is an empty string.

### `dwIPv4Options`

A value that specifies IPCP options for the local client.

| Value | Meaning |
| --- | --- |
| **PPP_IPCP_VJ** | Indicates that IP datagrams sent by the local client are compressed using Van Jacobson compression. |

### `dwIPv4RemoteOptions`

A value that specifies IPCP options for the remote server.

| Value | Meaning |
| --- | --- |
| **PPP_IPCP_VJ** | Indicates that IP datagrams sent by the remote server (that is, received by the local computer) are compressed using Van Jacobson compression. |

### `IPv4SubInterfaceIndex`

A value that specifies the IPv4 subinterface index corresponding to the connection on the server.

### `dwIPv6NegotiationError`

A value that specifies the result of PPP IPv6 Network control protocol negotiation. A value of zero indicates Ipv6 has been negotiated successfully. A nonzero value indicates failure, and is the fatal error that occurred during the control protocol negotiation.

### `bInterfaceIdentifier`

An array that specifies the 64-bit IPv6 interface identifier of the client. The last 64 bits of a 128-bit IPv6 internet address are considered the interface identifier, which provides a strong level of uniqueness for the preceding 64 bits. The **bInterfaceIdentifier** member must not be 0 and is valid only if the **dwIPv6NegotiationError** member is 0.

### `bRemoteInterfaceIdentifier`

An array that specifies the 64-bit IPv6 interface identifier of the server. The last 64 bits of a 128-bit IPv6 internet address are considered the interface identifier, which provides a strong level of uniqueness for the preceding 64 bits. The **bInterfaceIdentifier** member must not be 0 and is valid only if the **dwIPv6NegotiationError** member is 0.

### `bPrefix`

A value that specifies the client interface IPv6 address prefix.

### `dwPrefixLength`

A value that specifies the length, in bits, of the **bPrefix** member.

### `IPv6SubInterfaceIndex`

A value that specifies the IPv6 subinterface index corresponding to the connection on the server.

### `dwLcpError`

A value that specifies the result of PPP LCP negotiation. A value of zero indicates LCP has been negotiated successfully. A nonzero value indicates failure and represents the fatal error that occurred during the control protocol negotiation.

### `dwAuthenticationProtocol`

A value that specifies the authentication protocol used to authenticate the local client. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PPP_LCP_PAP** | Password Authentication Protocol |
| **PPP_LCP_CHAP** | Challenge Handshake Authentication Protocol |
| **PPP_LCP_EAP** | Extensible Authentication Protocol |

### `dwAuthenticationData`

A value that specifies additional information about the authentication protocol specified by the **dwAuthenticationProtocol** member. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PPP_LCP_CHAP_MD5** | MD5 CHAP |
| **PPP_LCP_CHAP_MS** | Microsoft CHAP |
| **PPP_LCP_CHAP_MSV2** | Microsoft CHAP version 2 |

### `dwRemoteAuthenticationProtocol`

A value that specifies the authentication protocol used to authenticate the remote server. The **dwAuthenticationProtocol** member and the **dwRemoteAuthenticationProtocol** member will differ when demand dial uses different authentication protocols on the client and server. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PPP_LCP_PAP** | Password Authentication Protocol |
| **PPP_LCP_CHAP** | Challenge Handshake Authentication Protocol |
| **PPP_LCP_EAP** | Extensible Authentication Protocol |

### `dwRemoteAuthenticationData`

A value that specifies additional information about the authentication protocol specified by the **dwRemoteAuthenticationProtocol** member. The **dwAuthenticationData** member and the **dwRemoteAuthenticationData** member will differ when demand dial uses different authentication protocols on the client and server. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PPP_LCP_CHAP_MD5** | MD5 CHAP |
| **PPP_LCP_CHAP_MS** | Microsoft CHAP |
| **PPP_LCP_CHAP_MSV2** | Microsoft CHAP version 2 |

### `dwLcpTerminateReason`

Not Implemented. Must be 0.

### `dwLcpRemoteTerminateReason`

Not Implemented. Must be 0.

### `dwLcpOptions`

A value that specifies information about LCP options in use by the local client. This member is a combination of the following flags.

| Value | Meaning |
| --- | --- |
| **PPP_LCP_MULTILINK_FRAMING** | The connection is using multilink. |
| **PPP_LCP_PFC** | The connection is using Protocol Field Compression. |
| **PPP_LCP_ACFC** | The connection is using Address and Control Field Compression. |
| **PPP_LCP_SSHF** | The connection is using Short Sequence Number Header Format. |
| **PPP_LCP_DES_56** | The connection is using DES 56-bit encryption. |
| **PPP_LCP_3_DES** | The connection is using Triple DES Encryption. |
| **PPP_LCP_AES_128** | The connection is using 128-bit AES Encryption. |
| **PPP_LCP_AES_256** | The connection is using 256-bit AES Encryption. |

### `dwLcpRemoteOptions`

A value that specifies information about LCP options in use by the remote server. This member is a combination of the following flags.

| Value | Meaning |
| --- | --- |
| **PPP_LCP_MULTILINK_FRAMING** | The connection is using multilink. |
| **PPP_LCP_PFC** | The connection is using Protocol Field Compression. |
| **PPP_LCP_ACFC** | The connection is using Address and Control Field Compression. |
| **PPP_LCP_SSHF** | The connection is using Short Sequence Number Header Format. |
| **PPP_LCP_DES_56** | The connection is using DES 56-bit encryption. |
| **PPP_LCP_3_DES** | The connection is using Triple DES Encryption. |
| **PPP_LCP_AES_128** | The connection is using 128-bit AES Encryption. |
| **PPP_LCP_AES_256** | The connection is using 256-bit AES Encryption. |

### `dwEapTypeId`

A value that specifies the type identifier of the Extensible Authentication Protocol (EAP) used to authenticate the local client. The value of this member is valid only if the **dwAuthenticationProtocol** member is **PPP_LCP_EAP**.

### `dwEmbeddedEAPTypeId`

A value that specifies the type identifier of the inner EAP method used in the EAP authentication. The value of this member is valid only if the **dwEapTypeId** member is set to PEAP defined in IANA-EAP.

### `dwRemoteEapTypeId`

A value that specifies the type identifier of the Extensible Authentication Protocol (EAP) used to authenticate the remote server. The value of this member is valid only if the **dwRemoteAuthenticationProtocol** member is **PPP_LCP_EAP**.

### `dwCcpError`

A value that specifies the result of PPP CCP negotiation. A value of 0 indicates CCP has been negotiated successfully. A nonzero value indicates failure, and represents the fatal error that occurred during the control protocol negotiation.

### `dwCompressionAlgorithm`

A value that specifies the compression algorithm used by the local client. The following table shows the possible values for this member.

| Value | Meaning |
| --- | --- |
| **RASCCPCA_MPPC** | Microsoft Point-to-Point Compression (MPPC) Protocol. |
| **RASCCPCA_STAC** | STAC option 4. |

### `dwCcpOptions`

A value that specifies the compression types available on the local client. The following types are supported.

| Value | Meaning |
| --- | --- |
| **PPP_CCP_COMPRESSION** | Compression without encryption. |
| **PPP_CCP_HISTORYLESS** | Microsoft Point-to-Point Encryption (MPPE) in stateless mode. The session key is changed after every packet. This mode improves performance on high latency networks, or networks that experience significant packet loss. |
| **PPP_CCP_ENCRYPTION40BITOLD** | MPPE compression using 40-bit keys. |
| **PPP_CCP_ENCRYPTION40BIT** | MPPE compression using 40-bit keys. |
| **PPP_CCP_ENCRYPTION56BIT** | MPPE compression using 56-bit keys. |
| **PPP_CCP_ENCRYPTION128BIT** | MPPE compression using 128-bit keys. |

The last three options are used when a connection is made over Layer 2 Tunneling Protocol (L2TP), and the connection uses IPSec encryption.

### `dwRemoteCompressionAlgorithm`

A value that specifies the compression algorithm used by the remote server. The following algorithms are supported.

| Value | Meaning |
| --- | --- |
| **RASCCPCA_MPPC** | Microsoft Point-to-Point Compression (MPPC) Protocol. |
| **RASCCPCA_STAC** | STAC option 4. |

### `dwCcpRemoteOptions`

A value that specifies the compression types available on the remote server. The following types are supported.

| Value | Meaning |
| --- | --- |
| **PPP_CCP_COMPRESSION** | Compression without encryption. |
| **PPP_CCP_HISTORYLESS** | Microsoft Point-to-Point Encryption (MPPE) in stateless mode. The session key is changed after every packet. This mode improves performance on high latency networks, or networks that experience significant packet loss. |
| **PPP_CCP_ENCRYPTION40BITOLD** | MPPE compression using 40-bit keys. |
| **PPP_CCP_ENCRYPTION40BIT** | MPPE compression using 40-bit keys. |
| **PPP_CCP_ENCRYPTION56BIT** | MPPE compression using 56-bit keys. |
| **PPP_CCP_ENCRYPTION128BIT** | MPPE compression using 128-bit keys. |
| **ERROR_PPP_NOT_CONVERGING** | The remote computer and RRAS could not converge on address negotiation. |

The last three options are used when a connection is made over Layer 2 Tunneling Protocol (L2TP), and the connection uses IPSec encryption.