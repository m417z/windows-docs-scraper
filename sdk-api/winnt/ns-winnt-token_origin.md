# TOKEN_ORIGIN structure

## Description

The **TOKEN_ORIGIN** structure contains information about the origin of the logon session. This structure is used by the [GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation) function.

## Members

### `OriginatingLogonSession`

[Locally unique identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LUID) for the [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly). If the token passed to [GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation) resulted from a logon using explicit credentials, such as passing name, domain, and password to the [LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera) function, then this member will contain the ID of the *logon session* that created it. If the token resulted from network authentication, such as a call to [AcceptSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext), or a call to **LogonUser** with *dwLogonType* set to LOGON32_LOGON_NETWORK or LOGON32_LOGON_NETWORK_CLEARTEXT, then this member will be zero.

## See also

[GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation)