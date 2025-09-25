# PPP_LCP_INFO structure

## Description

The
**PPP_LCP_INFO** structure contains information that describes the results of a PPP Link Control Protocol (LCP) negotiation.

## Members

### `dwError`

Specifies the error that occurred if the negotiation was unsuccessful.

### `dwAuthenticationProtocol`

Specifies the authentication protocol used to authenticate the local computer. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PPP_LCP_PAP** | Password Authentication Protocol |
| **PPP_LCP_SPAP** | Shiva Password Authentication Protocol |
| **PPP_LCP_CHAP** | Challenge Handshake Authentication Protocol |
| **PPP_LCP_EAP** | Extensible Authentication Protocol |

### `dwAuthenticationData`

Specifies additional information about the authentication protocol specified by the **dwAuthenticationProtocol** member. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PPP_LCP_CHAP_MD5** | MD5 CHAP |
| **PPP_LCP_CHAP_MS** | Microsoft CHAP |
| **PPP_LCP_CHAP_MSV2** | Microsoft CHAP version 2 |

### `dwRemoteAuthenticationProtocol`

Specifies the authentication protocol used to authenticate the remote computer. See the **dwAuthenticationProtocol** member for a list of possible values.

### `dwRemoteAuthenticationData`

Specifies additional information about the authentication protocol specified by **dwRemoteAuthenticationProtocol**. See the **dwAuthenticationData** member for a list of possible values.

### `dwTerminateReason`

Specifies the reason the connection was terminated by the local computer. This member always has a value of zero.

### `dwRemoteTerminateReason`

Specifies the reason the connection was terminated by the remote computer. This member always has a value of zero.

### `dwOptions`

Specifies information about LCP options in use by the local computer. This member is a combination of the following flags.

| Flag | Meaning |
| --- | --- |
| **PPP_LCP_MULTILINK_FRAMING** | The connection is using multilink |
| **RASLCPO_PFC** | Protocol Field Compression (see [RFC 1172](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-request-for-comments)) |
| **RASLCPO_ACFC** | Address and Control Field Compression (see [RFC 1172](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-request-for-comments)) |
| **RASLCPO_SSHF** | Short Sequence Number Header Format (see [RFC 1990](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-request-for-comments)) |
| **RASLCPO_DES_56** | DES 56-bit encryption |
| **RASLCPO_3_DES** | Triple DES Encryption |

### `dwRemoteOptions`

Specifies information about LCP options in use by the remote computer. This member is a combination of the following flags.

| Flag | Meaning |
| --- | --- |
| **PPP_LCP_MULTILINK_FRAMING** | The connection is using multilink. |
| **RASLCPO_PFC** | Protocol Field Compression (see [RFC 1172](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-request-for-comments)) |
| **RASLCPO_ACFC** | Address and Control Field Compression (see [RFC 1172](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-request-for-comments)) |
| **RASLCPO_SSHF** | Short Sequence Number Header Format (see [RFC 1990](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-request-for-comments)) |
| **RASLCPO_DES_56** | DES 56-bit encryption |
| **RASLCPO_3_DES** | Triple DES Encryption |

### `dwEapTypeId`

Specifies the type identifier of the Extensible Authentication Protocol (EAP) used to authenticate the local computer. The value of this member is valid only if **dwAuthenticationProtocol** is PPP_LCP_EAP.

### `dwRemoteEapTypeId`

Specifies the type identifier of the Extensible Authentication Protocol (EAP) used to authenticate the remote computer. The value of this member is valid only if **dwRemoteAuthenticationProtocol** is PPP_LCP_EAP.

## See also

[PPP_CCP_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_ccp_info)