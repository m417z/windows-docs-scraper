# PPP_CCP_INFO structure

## Description

The
**PPP_CCP_INFO** structure contains information that describes the results of a Compression Control Protocol (CCP) negotiation.

## Members

### `dwError`

Specifies an error if the negotiation is unsuccessful.

### `dwCompressionAlgorithm`

Specifies the compression algorithm used by the local computer. The following table shows the possible values for this member.

| Value | Meaning |
| --- | --- |
| **RASCCPCA_MPPC** | Microsoft Point-to-Point Compression (MPPC) Protocol |
| **RASCCPCA_STAC** | STAC option 4 |

### `dwOptions`

Specifies the compression options on the local computer. The following options are supported.

| Option | Meaning |
| --- | --- |
| **PPP_CCP_COMPRESSION** | Compression without encryption. |
| **PPP_CCP_HISTORYLESS** | Microsoft Point-to-Point Encryption (MPPE) in stateless mode. The session key is changed after every packet. This mode improves performance on high latency networks, or networks that experience significant packet loss. |
| **PPP_CCP_ENCRYPTION40BITOLD** | MPPE using 40-bit keys. |
| **PPP_CCP_ENCRYPTION40BIT** | MPPE using 40-bit keys. |
| **PPP_CCP_ENCRYPTION56BIT** | MPPE using 56-bit keys. |
| **PPP_CCP_ENCRYPTION128BIT** | MPPE using 128-bit keys. |

### `dwRemoteCompressionAlgorithm`

Specifies the compression algorithm used by the remote computer. The following table shows the possible values for this member.

| Value | Meaning |
| --- | --- |
| **RASCCPCA_MPPC** | Microsoft Point-to-Point Compression (MPPC) Protocol |
| **RASCCPCA_STAC** | STAC option 4 |

### `dwRemoteOptions`

Specifies the compression options on the remote computer. The following options are supported.

| Option | Meaning |
| --- | --- |
| **PPP_CCP_COMPRESSION** | Compression without encryption. |
| **PPP_CCP_HISTORYLESS** | Microsoft Point-to-Point Encryption (MPPE) in stateless mode. The session key is changed after every packet. This mode improves performance on high latency networks, or networks that experience significant packet loss. |
| **PPP_CCP_ENCRYPTION40BITOLD** | MPPE using 40-bit keys. |
| **PPP_CCP_ENCRYPTION40BIT** | MPPE using 40-bit keys. |
| **PPP_CCP_ENCRYPTION56BIT** | MPPE using 56-bit keys. |
| **PPP_CCP_ENCRYPTION128BIT** | MPPE using 128-bit keys. |

## See also

[PPP_LCP_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_lcp_info)