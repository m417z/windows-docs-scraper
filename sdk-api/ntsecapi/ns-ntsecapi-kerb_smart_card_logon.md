# KERB_SMART_CARD_LOGON structure

## Description

The **KERB_SMART_CARD_LOGON** structure contains information about a smart card [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly).

It is used by
[LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser) with the Kerberos security package using LOGON32_PROVIDER_WINNT50 or LOGON32_PROVIDER_DEFAULT.

## Members

### `MessageType`

[KERB_LOGON_SUBMIT_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-kerb_logon_submit_type) value identifying the type of logon request being made. This member must be set to **KerbInteractiveLogon**.

### `Pin`

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) that specifies the PIN associated with the smart card.

### `CspDataLength`

The length, in characters, of the **CspData** member.

### `CspData`

A pointer to a **KERB_SMARTCARD_CSP_INFO** structure that contains information about the smart card cryptographic service provider (CSP) or a pointer to a marshaled **KERB_CERTIFICATE_INFO** structure when updating certificate credentials.