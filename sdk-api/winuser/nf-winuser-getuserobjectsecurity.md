# GetUserObjectSecurity function

## Description

The **GetUserObjectSecurity** function retrieves security information for the specified user object.

## Parameters

### `hObj` [in]

A handle to the user object for which to return security information.

### `pSIRequested` [in]

A pointer to a
[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) value that specifies the security information being requested.

### `pSID` [in, out, optional]

A pointer to a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure in [self-relative](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) format that contains the requested information when the function returns. This buffer must be aligned on a 4-byte boundary.

### `nLength` [in]

The length, in bytes, of the buffer pointed to by the *pSD* parameter.

### `lpnLengthNeeded` [out]

A pointer to a variable to receive the number of bytes required to store the complete [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). If this variable's value is greater than the value of the *nLength* parameter when the function returns, the function returns **FALSE** and none of the security descriptor is copied to the buffer. Otherwise, the entire security descriptor is copied.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To read the owner, group, or [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) from the user object's security descriptor, the calling [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) must have been granted READ_CONTROL access when the handle was opened.

To read the [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) from the security descriptor, the calling process must have been granted ACCESS_SYSTEM_SECURITY access when the handle was opened. The correct way to get this access is to enable the SE_SECURITY_NAME privilege in the caller's current token, open the handle for ACCESS_SYSTEM_SECURITY access, and then disable the privilege.

#### Examples

For an example that uses this function, see [Starting an Interactive Client Process](https://learn.microsoft.com/previous-versions/aa379608(v=vs.85)).

## See also

[CreatePrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createprivateobjectsecurity)

[GetKernelObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getkernelobjectsecurity)

[GetPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getprivateobjectsecurity)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information)

[SetUserObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setuserobjectsecurity)