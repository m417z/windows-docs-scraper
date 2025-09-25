# AllocateAndInitializeSid function

## Description

The **AllocateAndInitializeSid** function allocates and initializes a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) with up to eight subauthorities.

## Parameters

### `pIdentifierAuthority` [in]

A pointer to a
[SID_IDENTIFIER_AUTHORITY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_identifier_authority) structure. This structure provides the top-level identifier authority value to set in the SID.

### `nSubAuthorityCount` [in]

Specifies the number of subauthorities to place in the SID. This parameter also identifies how many of the subauthority parameters have meaningful values. This parameter must contain a value from 1 to 8.

For example, a value of 3 indicates that the subauthority values specified by the *dwSubAuthority0*, *dwSubAuthority1*, and *dwSubAuthority2* parameters have meaningful values and to ignore the remainder.

### `nSubAuthority0` [in]

Subauthority value to place in the SID.

### `nSubAuthority1` [in]

Subauthority value to place in the SID.

### `nSubAuthority2` [in]

Subauthority value to place in the SID.

### `nSubAuthority3` [in]

Subauthority value to place in the SID.

### `nSubAuthority4` [in]

Subauthority value to place in the SID.

### `nSubAuthority5` [in]

Subauthority value to place in the SID.

### `nSubAuthority6` [in]

Subauthority value to place in the SID.

### `nSubAuthority7` [in]

Subauthority value to place in the SID.

### `pSid` [out]

A pointer to a variable that receives the pointer to the allocated and initialized
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A SID allocated with the **AllocateAndInitializeSid** function must be freed by using the [FreeSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-freesid) function.

This function creates a SID with a 32-bit RID value. For applications that require longer RID values, use
[CreateWellKnownSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createwellknownsid).

#### Examples

For an example that uses this function, see [Creating a Security Descriptor for a New Object](https://learn.microsoft.com/windows/desktop/SecAuthZ/creating-a-security-descriptor-for-a-new-object-in-c--) or [Taking Object Ownership](https://learn.microsoft.com/windows/desktop/SecAuthZ/taking-object-ownership-in-c--).

## See also

[Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[FreeSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-freesid)

[GetSidIdentifierAuthority](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsididentifierauthority)

[InitializeSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-initializesid)

[SID_IDENTIFIER_AUTHORITY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_identifier_authority)

[Well-known SIDs](https://learn.microsoft.com/windows/desktop/SecAuthZ/well-known-sids)