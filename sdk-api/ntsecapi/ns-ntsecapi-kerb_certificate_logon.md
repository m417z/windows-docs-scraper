# KERB_CERTIFICATE_LOGON structure

## Description

The **KERB_CERTIFICATE_LOGON** structure contains information about a smart card [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly).

It is passed as the *AuthenticationInformation* parameter to the
[LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser) function when the [Kerberos](https://learn.microsoft.com/windows/desktop/SecAuthN/kerberos-ssp-ap) security package performs an interactive smart card logon.

## Members

### `MessageType`

A member of the [KERB_LOGON_SUBMIT_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-kerb_logon_submit_type) enumeration that indicates how this structure is used. The member must be one of the following values.

| Value | Meaning |
| --- | --- |
| **KerbCertificateLogon**<br><br>13 | This structure is passed as the *AuthenticationInformation* parameter to the [LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser) function to perform an interactive smart card logon. |
| **KerbCertificateUnlockLogon**<br><br>15 | This structure is used as the **Logon** member of a [KERB_CERTIFICATE_UNLOCK_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_certificate_unlock_logon) structure. |

### `DomainName`

The domain name of the user to authenticate. The value of this member can be empty. If the value is not empty, [LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser) uses the value to locate the [Key Distribution Center](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) (KDC). If the value is empty, **LsaLogonUser** attempts to authenticate against the domain to which the computer is joined. The pointer is relative to the beginning of the structure and is not an absolute memory pointer.

### `UserName`

The user name of the user to authenticate. The value of this member can be empty. If the value is not empty, [LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser) uses the value to locate the user account to authenticate. The pointer is relative to the beginning of the structure and is not an absolute memory pointer.

### `Pin`

The PIN to use to authenticate the user. The **Length** member of this structure does not include the terminating null character of the PIN. The pointer is relative to the beginning of the structure and is not an absolute memory pointer.

The PIN can be protected by using the [CredProtect](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credprotecta) function.

### `Flags`

Optional flags that control the behavior of the authentication. The following values are defined.

| Value | Meaning |
| --- | --- |
| **KERB_CERTIFICATE_LOGON_FLAG_CHECK_DUPLICATES**<br><br>0x1 | The KDC checks the certificate for multiple account mappings. |
| **KERB_CERTIFICATE_LOGON_FLAG_USE_CERTIFICATE_INFO**<br><br>0x2 | The KDC uses the certificate information for authentication.<br><br>**Windows Server 2008 R2, Windows 7, Windows Server 2008 and Windows Vista:** This flag is not available. |

### `CspDataLength`

The length, in characters, of the **CspData** member.

### `CspData`

A pointer to a [KERB_SMARTCARD_CSP_INFO](https://learn.microsoft.com/windows/desktop/SecAuthN/kerb-smartcard-csp-info) structure that contains information about the smart card [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) ) or a pointer to a marshaled [KERB_CERTIFICATE_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_certificate_info) structure when updating certificate credentials.

## Remarks

This structure, along with the data pointed to by the **DomainName**, **UserName**, **Pin**, and **CspData** members, is contained in a single block of contiguous memory. When this structure is serialized, the offsets specified by each of these members must be multiples of two.

The pointers stored in the members of **UNICODE_STRING** type are relative to the beginning of the structure and are not absolute memory pointers.

## See also

[KERB_CERTIFICATE_UNLOCK_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_certificate_unlock_logon)

[KERB_SMARTCARD_CSP_INFO](https://learn.microsoft.com/windows/desktop/SecAuthN/kerb-smartcard-csp-info)

[LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser)