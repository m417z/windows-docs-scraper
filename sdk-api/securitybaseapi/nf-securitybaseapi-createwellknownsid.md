# CreateWellKnownSid function

## Description

The **CreateWellKnownSid** function creates a SID for predefined aliases.

## Parameters

### `WellKnownSidType` [in]

Member of the [WELL_KNOWN_SID_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-well_known_sid_type) enumeration that specifies what the SID will identify.

### `DomainSid` [in, optional]

A pointer to a SID that identifies the domain to use when creating the SID. Pass **NULL** to use the local computer.

### `pSid` [out, optional]

A pointer to memory where **CreateWellKnownSid** will store the new SID.

### `cbSid` [in, out]

A pointer to a **DWORD** that contains the number of bytes available at *pSid*. The **CreateWellKnownSid** function stores the number of bytes actually used at this location.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[EqualDomainSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-equaldomainsid)

[GetWindowsAccountDomainSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getwindowsaccountdomainsid)

[IsWellKnownSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-iswellknownsid)

[WELL_KNOWN_SID_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-well_known_sid_type)