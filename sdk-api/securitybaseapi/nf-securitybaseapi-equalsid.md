# EqualSid function

## Description

The **EqualSid** function tests two [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) values for equality. Two SIDs must match exactly to be considered equal.

## Parameters

### `pSid1` [in]

A pointer to the first
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure to compare. This structure is assumed to be valid.

### `pSid2` [in]

A pointer to the second [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure to compare. This structure is assumed to be valid.

## Return value

If the
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structures are equal, the return value is nonzero.

If the [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structures are not equal, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If either [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure is not valid, the return value is undefined.

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[EqualPrefixSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-equalprefixsid)

[IsValidSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidsid)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)