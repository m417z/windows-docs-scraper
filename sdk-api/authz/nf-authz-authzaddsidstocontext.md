# AuthzAddSidsToContext function

## Description

The **AuthzAddSidsToContext** function creates a copy of an existing context and appends a given set of [security identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIDs) and restricted SIDs.

## Parameters

### `hAuthzClientContext` [in]

An **AUTHZ_CLIENT_CONTEXT_HANDLE** structure to be copied as the basis for *NewClientContext*.

### `Sids` [in]

A pointer to a
[SID_AND_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_and_attributes) structure containing the SIDs and attributes to be added to the unrestricted part of the client context.

### `SidCount` [in]

The number of SIDs to be added.

### `RestrictedSids` [in]

A pointer to a [SID_AND_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_and_attributes) structure containing the SIDs and attributes to be added to the restricted part of the client context.

### `RestrictedSidCount` [in]

Number of restricted SIDs to be added.

### `phNewAuthzClientContext` [out]

A pointer to the created **AUTHZ_CLIENT_CONTEXT_HANDLE** structure containing input values for expiration time, identifier, flags, additional SIDs and restricted SIDs.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[SID_AND_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_and_attributes)