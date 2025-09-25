# InitializeSid function

## Description

The **InitializeSid** function initializes a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID).

## Parameters

### `Sid` [out]

A pointer to a
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure to be initialized.

### `pIdentifierAuthority` [in]

A pointer to a
[SID_IDENTIFIER_AUTHORITY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_identifier_authority) structure to set in the [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure.

### `nSubAuthorityCount` [in]

Specifies the number of subauthorities to set in the [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid). Values of the subauthority must be set separately, as described in the following Remarks section.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Although the **InitializeSid** function sets the number of subauthorities for the SID, it does not set the subauthority values. This must be done separately, using functions such as [GetSidSubAuthority](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidsubauthority).

An application can use the [AllocateAndInitializeSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-allocateandinitializesid) function to initialize a SID and set its subauthority values.

This function uses a 32-bit RID value. For applications that require a larger RID value, use
[CreateWellKnownSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createwellknownsid).

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[AllocateAndInitializeSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-allocateandinitializesid)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[CreateWellKnownSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createwellknownsid)

[GetLengthSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getlengthsid)

[GetSidIdentifierAuthority](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsididentifierauthority)

[GetSidLengthRequired](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidlengthrequired)

[GetSidSubAuthority](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidsubauthority)

[GetSidSubAuthorityCount](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidsubauthoritycount)

[IsValidSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidsid)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)

[SID_IDENTIFIER_AUTHORITY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_identifier_authority)