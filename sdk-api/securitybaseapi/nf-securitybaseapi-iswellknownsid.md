# IsWellKnownSid function

## Description

The **IsWellKnownSid** function compares a SID to a well-known SID and returns **TRUE** if they match.

## Parameters

### `pSid` [in]

A pointer to the [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) to test.

### `WellKnownSidType` [in]

Member of the
[WELL_KNOWN_SID_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-well_known_sid_type) enumeration to compare with the SID at *pSid*.

## Return value

Returns **TRUE** if the SID at *pSid* matches the well-known SID indicated by *WellKnownSidType*.

Otherwise, returns **FALSE**.

## See also

[CreateWellKnownSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createwellknownsid)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)

[WELL_KNOWN_SID_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-well_known_sid_type)