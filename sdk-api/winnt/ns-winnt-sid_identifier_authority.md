# SID_IDENTIFIER_AUTHORITY structure

## Description

The **SID_IDENTIFIER_AUTHORITY** structure represents the top-level authority of a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID).

## Members

### `Value`

An array of 6 bytes specifying a SID's top-level authority.

## Remarks

The identifier authority value identifies the agency that issued the SID. The following identifier authorities are predefined.

| Identifier authority | Value |
| --- | --- |
| SECURITY_NULL_SID_AUTHORITY | 0 |
| SECURITY_WORLD_SID_AUTHORITY | 1 |
| SECURITY_LOCAL_SID_AUTHORITY | 2 |
| SECURITY_CREATOR_SID_AUTHORITY | 3 |
| SECURITY_NON_UNIQUE_AUTHORITY | 4 |
| SECURITY_NT_AUTHORITY | 5 |
| SECURITY_RESOURCE_MANAGER_AUTHORITY | 9 |

A SID must contain a top-level authority and at least one [relative identifier](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) (RID) value.

## See also

[AllocateAndInitializeSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-allocateandinitializesid)

[GetSidIdentifierAuthority](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsididentifierauthority)

[InitializeSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-initializesid)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)