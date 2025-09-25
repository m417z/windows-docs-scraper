# GetSidIdentifierAuthority function

## Description

The **GetSidIdentifierAuthority** function returns a pointer to the
[SID_IDENTIFIER_AUTHORITY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_identifier_authority) structure in a specified [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID).

## Parameters

### `pSid` [in]

A pointer to the
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure for which a pointer to the
[SID_IDENTIFIER_AUTHORITY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_identifier_authority) structure is returned.

This function does not handle [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structures that are not valid. Call the [IsValidSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidsid) function to verify that the **SID** structure is valid before you call this function.

## Return value

If the function succeeds, the return value is a pointer to the [SID_IDENTIFIER_AUTHORITY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_identifier_authority) structure for the specified
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure.

If the function fails, the return value is undefined. The function fails if the [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure pointed to by the *pSid* parameter is not valid. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function uses a 32-bit RID value. For applications that require a larger RID value, use
[CreateWellKnownSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createwellknownsid) and related functions.

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[CreateWellKnownSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createwellknownsid)

[GetLengthSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getlengthsid)

[GetSidLengthRequired](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidlengthrequired)

[GetSidSubAuthority](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidsubauthority)

[GetSidSubAuthorityCount](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidsubauthoritycount)

[IsValidSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidsid)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)

[SID_IDENTIFIER_AUTHORITY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_identifier_authority)