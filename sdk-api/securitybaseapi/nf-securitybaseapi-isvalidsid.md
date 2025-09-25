# IsValidSid function

## Description

The **IsValidSid** function validates a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) by verifying that the revision number is within a known range, and that the number of subauthorities is less than the maximum.

## Parameters

### `pSid` [in]

A pointer to the
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure to validate. This parameter cannot be **NULL**.

## Return value

If the [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure is valid, the return value is nonzero.

If the [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure is not valid, the return value is zero. There is no extended error information for this function; do not call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If *pSid* is **NULL**, the application will fail with an access violation.

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[GetLengthSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getlengthsid)

[GetSidIdentifierAuthority](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsididentifierauthority)

[GetSidLengthRequired](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidlengthrequired)

[GetSidSubAuthority](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidsubauthority)

[GetSidSubAuthorityCount](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidsubauthoritycount)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)