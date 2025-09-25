# GetSidSubAuthority function

## Description

The **GetSidSubAuthority** function returns a pointer to a specified subauthority in a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID). The subauthority value is a [relative identifier](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) (RID).

## Parameters

### `pSid` [in]

A pointer to the
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure from which a pointer to a subauthority is to be returned.

This function does not handle [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structures that are not valid. Call the [IsValidSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidsid) function to verify that the **SID** structure is valid before you call this function.

### `nSubAuthority` [in]

Specifies an index value identifying the subauthority array element whose address the function will return. The function performs no validation tests on this value. An application can call the [GetSidSubAuthorityCount](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidsubauthoritycount) function to discover the range of acceptable values.

## Return value

If the function succeeds, the return value is a pointer to the specified [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) subauthority. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the function fails, the return value is undefined. The function fails if the specified [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure is not valid or if the index value specified by the *nSubAuthority* parameter is out of bounds.

## Remarks

The [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure specified in *pSid* uses a 32-bit RID value. For applications that require longer RID values, use
[CreateWellKnownSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createwellknownsid) and related functions.

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[CreateWellKnownSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createwellknownsid)

[GetLengthSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getlengthsid)

[GetSidIdentifierAuthority](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsididentifierauthority)

[GetSidLengthRequired](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidlengthrequired)

[GetSidSubAuthorityCount](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidsubauthoritycount)

[IsValidSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidsid)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)