# GetSidSubAuthorityCount function

## Description

The **GetSidSubAuthorityCount** function returns a pointer to the member in a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) structure that contains the subauthority count.

## Parameters

### `pSid` [in]

A pointer to the
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure from which a pointer to the subauthority count is returned.

This function does not handle [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structures that are not valid. Call the [IsValidSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidsid) function to verify that the **SID** structure is valid before you call this function.

## Return value

If the function succeeds, the return value is a pointer to the subauthority count for the specified [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure.

If the function fails, the return value is undefined. The function fails if the specified [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure is not valid. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The SID structure specified in *pSid* uses a 32-bit value. For applications that require longer RID values, use
[CreateWellKnownSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createwellknownsid) and related functions.

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[CreateWellKnownSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createwellknownsid)

[GetLengthSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getlengthsid)

[GetSidIdentifierAuthority](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsididentifierauthority)

[GetSidLengthRequired](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidlengthrequired)

[GetSidSubAuthority](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidsubauthority)

[IsValidSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidsid)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)