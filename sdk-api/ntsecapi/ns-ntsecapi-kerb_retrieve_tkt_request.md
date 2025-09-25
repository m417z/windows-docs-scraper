# KERB_RETRIEVE_TKT_REQUEST structure

## Description

The **KERB_RETRIEVE_TKT_REQUEST** structure contains information used to retrieve a ticket.

It is used by
[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage).The Kerberos ticket is defined in Internet [RFC 4120](http://www.ietf.org/rfc/rfc4120.txt). For more information, see [http://www.ietf.org](https://www.ietf.org/).

## Members

### `MessageType`

[KERB_PROTOCOL_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-kerb_protocol_message_type) value indicating the type of request being made. This member must be set to **KerbRetrieveEncodedTicketMessage**.

### `LogonId`

[LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid) structure containing the [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) identifier. This can be zero for the current user's logon session. If not zero, the caller must have the SeTcbPrivilege privilege set. If this fails, the [Kerberos](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) authentication package sets the *ProtocolStatus* parameter of [LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage) to STATUS_ACCESS_DENIED.

### `TargetName`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the name of the target service.

### `TicketFlags`

Contains flags specifying uses for the retrieved ticket. If **TicketFlags** is set to zero and if there is a matching ticket found in the cache, then that ticket will be returned, regardless of its flag values. If there is no match in the cache, a new ticket with the default flag values will be requested.

If this member is not set to zero, the returned ticket will not be cached.

### `CacheOptions`

Indicates options for searching the cache. Set this member to zero to indicate that the cache should be searched and if no ticket if found, a new ticket should be requested.

If this member is not set to zero, the returned ticket will not be cached.

**CacheOptions** can contain the following values.

| Value | Meaning |
| --- | --- |
| **KERB_RETRIEVE_TICKET_DONT_USE_CACHE**<br><br>1 | Always request a new ticket; do not search the cache. <br><br>If a ticket is obtained, the Kerberos authentication package returns STATUS_SUCCESS in the *ProtocolStatus* parameter of the [LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage) function. |
| **KERB_RETRIEVE_TICKET_USE_CREDHANDLE**<br><br>4 | Use the **CredentialsHandle** member instead of **LogonId** to identify the logon session. The credential handle is used as the client credential for which the ticket is retrieved<br><br>**Note** This option is not available for 32-bit Windows-based applications running on 64-bit Windows. |
| **KERB_RETRIEVE_TICKET_USE_CACHE_ONLY**<br><br>2 | Return only a previously cached ticket. <br><br>If such a ticket is not found, the Kerberos authentication package returns STATUS_OBJECT_NAME_NOT_FOUND in the *ProtocolStatus* parameter of the [LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage) function. |
| **KERB_RETRIEVE_TICKET_AS_KERB_CRED**<br><br>8 | Return the ticket as a Kerberos credential. The Kerberos ticket is defined in Internet [RFC 4120](http://www.ietf.org/rfc/rfc4120.txt) as KRB_CRED. For more information, see [http://www.ietf.org](https://www.ietf.org/). <br><br> |
| **KERB_RETRIEVE_TICKET_WITH_SEC_CRED**<br><br>10 | Not implemented. |
| **KERB_RETRIEVE_TICKET_CACHE_TICKET**<br><br>20 | Return the ticket that is currently in the cache. If the ticket is not in the cache, it is requested and then cached. This flag should not be used with the KERB_RETRIEVE_TICKET_DONT_USE_CACHE flag. <br><br>**Windows XP with SP1 and earlier and Windows Server 2003:** This option is not available. |
| **KERB_RETRIEVE_TICKET_MAX_LIFETIME**<br><br>40 | Return a fresh ticket with maximum allowed time by the policy. The ticker is cached afterwards. Use of this flag implies that KERB_RETRIEVE_TICKET_USE_CACHE_ONLY is not set and KERB_RETRIEVE_TICKET_CACHE_TICKET is set. <br><br>**Windows Vista, Windows Server 2008, Windows XP with SP1 and earlier and Windows Server 2003:** This option is not available. |

### `EncryptionType`

Specifies the type of encryption to use for the requested ticket. If this member is not set to zero, the returned ticket will not be cached.

This member can have one of the following values.

| Value | Meaning |
| --- | --- |
| **KERB_ETYPE_DES_CBC_CRC** | Use [DES](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) encryption in [cipher-block-chaining](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) mode with a CRC-32 checksum. |
| **KERB_ETYPE_DES_CBC_MD4** | Use DES encryption in cipher-block-chaining mode with a MD4 checksum. |
| **KERB_ETYPE_DES_CBC_MD5** | Use DES encryption in cipher-block-chaining mode with a MD5 checksum. |
| **KERB_ETYPE_NULL** | Use no encryption. |
| **KERB_ETYPE_RC4_HMAC_NT** | Use the RC4 [stream cipher](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) with a [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly)-based [Message Authentication Code](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) (MAC), as used by Windows. |
| **KERB_ETYPE_RC4_MD4** | Use the RC4 stream cipher with the MD4 hash function. |
| **>127** | Values greater than 127 are reserved for local values and may change without notice. |

### `CredentialsHandle`

An SSPI credentials handle used in place of a logon session identifier.