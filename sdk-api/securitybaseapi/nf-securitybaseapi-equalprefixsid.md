# EqualPrefixSid function

## Description

The **EqualPrefixSid** function tests two [security-identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) prefix values for equality. A SID prefix is the entire SID except for the last subauthority value.

## Parameters

### `pSid1` [in]

A pointer to the first
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure to compare. This structure is assumed to be valid.

### `pSid2` [in]

A pointer to the second [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure to compare. This structure is assumed to be valid.

## Return value

If the SID prefixes are equal, the return value is nonzero.

If the SID prefixes are not equal, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **EqualPrefixSid** function enables a server application in one domain to verify an attempt by a user to log on to another domain. For example, if a user attempts to log on to RemoteDomain from a workstation in LocalDomain, the server for LocalDomain can request the SIDs for the user and the user's groups from RemoteDomain. The domain controller for RemoteDomain responds with the relevant SIDs.

All SIDs for a specified domain have the same prefix. When the server receives the user's SIDs, the server can call the **EqualPrefixSid** function for each SID, comparing the user or group SID against the SID for RemoteDomain. If any of the SID prefixes are not equal, the server refuses the logon attempt.

It is advisable to modify the SID for a domain before comparing it with a group or user SID. If the SID for RemoteDomain is S-1–1234–8, each group or user SID for that domain has S-1–1234–8 as its prefix. To compare the SIDs by using the **EqualPrefixSid** function, an application copies the domain SID and adds any subauthority ([RID](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly)) value to the copy, thereby creating a SID in the form S-1–1234–8–0. The application then uses the modified domain SID as a template against which the group and user SIDs are compared.

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[CopySid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-copysid)

[EqualSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-equalsid)

[IsValidSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidsid)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)