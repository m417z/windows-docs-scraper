# EqualDomainSid function

## Description

The **EqualDomainSid** function determines whether two SIDs are from the same domain.

## Parameters

### `pSid1` [in]

A pointer to one of the two SIDs to compare. This SID must be either an account domain SID or a BUILTIN SID.

### `pSid2` [in]

A pointer to one of the two SIDs to compare. This SID must be either an account domain SID or a BUILTIN SID.

### `pfEqual` [out]

A pointer to a BOOL that **EqualDomainSid** sets to **TRUE** if the domains of the two SIDs are equal or **FALSE** if they are not equal. This value cannot be **NULL**.

## Return value

If both SIDs are account domain SIDs and/or BUILTIN SIDs, the return value is nonzero. In addition, **pfEqual* is set to **TRUE** if the domains of the two SIDs are equal; otherwise **pfEqual* is set to **FALSE**.

If one or more of the SIDS is neither an account domain SID nor a BUILTIN SID, then the return value is **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). **GetLastError** returns ERROR_NON_DOMAIN_SID if either SID is not an account domain SID or BUILTIN SID.

## See also

[EqualPrefixSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-equalprefixsid)

[EqualSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-equalsid)