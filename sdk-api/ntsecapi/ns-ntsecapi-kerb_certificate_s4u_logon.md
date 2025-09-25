# KERB_CERTIFICATE_S4U_LOGON structure

## Description

The **KERB_CERTIFICATE_S4U_LOGON** structure contains information about the certificate for a service for user (S4U) logon.

## Members

### `MessageType`

A value of the [KERB_LOGON_SUBMIT_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-kerb_logon_submit_type) enumeration that identifies the type of logon request being made. This member must be set to **KerbCertificateS4ULogon**.

### `Flags`

Flags that provide more information about the certificate logon.

| Value | Meaning |
| --- | --- |
| **KERB_CERTIFICATE_S4U_LOGON_FLAG_CHECK_DUPLICATES**<br><br>0x1 | The [Key Distribution Center](https://learn.microsoft.com/windows/desktop/SecAuthN/key-distribution-center) (KDC) checks for account mapping conflicts for the same certificate. |
| **KERB_CERTIFICATE_S4U_LOGON_FLAG_CHECK_LOGONHOURS**<br><br>0x2 | The KDC checks the length of time this account with this certificate has been logged on. |
| **KERB_CERTIFICATE_S4U_LOGON_FLAG_IF_NT_AUTH_POLICY_REQUIRED**<br><br>0x4 | The KDC checks to see if an authentication policy is set. |
| **KERB_CERTIFICATE_S4U_LOGON_FLAG_IDENTIFY**<br><br>0x8 | The KDC checks for identity only tokens instead of impersonation tokens. The request for the identity token must have the same value as the **KERB_S4U_LOGON_FLAG_IDENTIFY** flag in the [KERB_S4U_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_s4u_logon) structure.<br><br>**Windows Server 2008 R2, Windows 7, Windows Server 2008 and Windows Vista with SP2:** This flag is not available. |

### `UserPrincipalName`

The user principal name of the client to authenticate. The value of this member can be **NULL**. If the value is not **NULL**, the [LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser) function uses the value to locate the user name.

### `DomainName`

The domain name of the user to authenticate. The value of this member can be **NULL**. If the value is not **NULL**, the [LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser) function uses the value to locate the KDC. If the value is **NULL**, the **LsaLogonUser** function attempts to authenticate against the domain to which the computer is joined.

### `CertificateLength`

The length, in bytes, of the client certificate.

### `Certificate`

The certificate of the S4U logon.