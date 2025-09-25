# GetSidLengthRequired function

## Description

The **GetSidLengthRequired** function returns the length, in bytes, of the buffer required to store a SID with a specified number of subauthorities.

## Parameters

### `nSubAuthorityCount` [in]

Specifies the number of subauthorities to be stored in the
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure.

## Return value

The return value is the length, in bytes, of the buffer required to store the [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure. This function cannot fail.

## Remarks

The [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure specified in *nSubAuthorityCount* uses a 32-bit RID value. For applications that require longer RID values, use
[CreateWellKnownSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createwellknownsid) and related functions.

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[AllocateAndInitializeSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-allocateandinitializesid)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[CreateWellKnownSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createwellknownsid)

[GetLengthSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getlengthsid)

[GetSidIdentifierAuthority](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsididentifierauthority)

[GetSidSubAuthority](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidsubauthority)

[GetSidSubAuthorityCount](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidsubauthoritycount)

[InitializeSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-initializesid)

[IsValidSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidsid)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)