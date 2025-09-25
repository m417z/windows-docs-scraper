# LSA_TOKEN_INFORMATION_TYPE enumeration

## Description

The **LSA_TOKEN_INFORMATION_TYPE** enumeration specifies the levels of information that can be included in a logon token.

When the LSA calls either
[LsaApLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_logon_user),
[LsaApLogonUserEx](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_logon_user_ex), or
[LsaApLogonUserEx2](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_logon_user_ex2) the [authentication package](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) is expected to return one of the following enumeration values to indicate the type of token information structure returned.

## Constants

### `LsaTokenInformationNull`

The token information is stored in an
[LSA_TOKEN_INFORMATION_NULL](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_token_information_null) structure.

This token information type is used for anonymous logons or **null** sessions, where a token is needed but the client's identity is unknown.

For example, a non-authenticated network circuit (such as a domain controller's **null** session) can be given **NULL** information. In this case, an anonymous token is generated for the logon. An anonymous token does not permit access to protected system resources, but does allow access to unprotected system resources.

### `LsaTokenInformationV1`

The token information is stored in a
[LSA_TOKEN_INFORMATION_V1](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa378721(v=vs.85)) structure. This structure contains information that an authentication package can place in a Version 1 Windows token object. A Version 1 Windows token object stores all the information needed to build a token and is used in most logon cases. The LSA creates the token object, and returns a handle to that token object to the caller of
[LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser).

### `LsaTokenInformationV2`

### `LsaTokenInformationV3`