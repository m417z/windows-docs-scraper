# GetLengthSid function

## Description

The **GetLengthSid** function returns the length, in bytes, of a valid [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID).

## Parameters

### `pSid` [in]

A pointer to the
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure whose length is returned. The structure is assumed to be valid.

## Return value

If the [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure is valid, the return value is the length, in bytes, of the **SID** structure.

If the [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure is not valid, the return value is undefined. Before calling **GetLengthSid**, pass the SID to the
[IsValidSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidsid) function to verify that the SID is valid.

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[GetSidLengthRequired](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidlengthrequired)

[GetSidSubAuthorityCount](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidsubauthoritycount)

[IsValidSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidsid)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)