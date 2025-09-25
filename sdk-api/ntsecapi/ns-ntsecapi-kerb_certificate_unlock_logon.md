# KERB_CERTIFICATE_UNLOCK_LOGON structure

## Description

The **KERB_CERTIFICATE_UNLOCK_LOGON** structure contains information used to unlock a workstation that has been locked during an interactive smart card [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly).

It is passed as the *AuthenticationInformation* parameter to the
[LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser) function when using the [Kerberos](https://learn.microsoft.com/windows/desktop/SecAuthN/kerberos-ssp-ap) security package to unlock a logon session.

## Members

### `Logon`

A [KERB_CERTIFICATE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_certificate_logon) structure that contains information about the logon session to unlock.

The **MessageType** member of the [KERB_CERTIFICATE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_certificate_logon) structure must be set to **KerbCertificateUnlockLogon**.

### `LogonId`

A [LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid) structure that identifies the logon session to unlock. This member is set by [Winlogon](https://learn.microsoft.com/windows/desktop/SecAuthN/winlogon).

## See also

[KERB_CERTIFICATE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_certificate_logon)

[KERB_SMARTCARD_CSP_INFO](https://learn.microsoft.com/windows/desktop/SecAuthN/kerb-smartcard-csp-info)

[LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser)