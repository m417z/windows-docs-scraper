# CopySid function

## Description

The **CopySid** function copies a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) to a buffer.

## Parameters

### `nDestinationSidLength` [in]

Specifies the length, in bytes, of the buffer receiving the copy of the SID.

### `pDestinationSid` [out]

A pointer to a buffer that receives a copy of the source
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure.

### `pSourceSid` [in]

A pointer to a [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure that the function copies to the buffer pointed to by the *pDestinationSid* parameter.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

An application can use the **CopySid** function to make a copy of a SID in an [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (for example, in a [TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure) to use in an access control entry ([ACE](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly)).

#### Examples

For an example that uses this function, see [Getting the Logon SID](https://learn.microsoft.com/previous-versions/aa446670(v=vs.85)).

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[AllocateAndInitializeSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-allocateandinitializesid)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[EqualSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-equalsid)

[GetLengthSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getlengthsid)

[GetSidIdentifierAuthority](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsididentifierauthority)

[GetSidLengthRequired](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidlengthrequired)

[GetSidSubAuthority](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidsubauthority)

[GetSidSubAuthorityCount](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidsubauthoritycount)

[InitializeSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-initializesid)

[IsValidSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidsid)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)