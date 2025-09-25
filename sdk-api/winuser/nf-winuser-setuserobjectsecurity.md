# SetUserObjectSecurity function

## Description

The **SetUserObjectSecurity** function sets the security of a user object. This can be, for example, a window or a DDE conversation.

## Parameters

### `hObj` [in]

A handle to a user object for which security information is set.

### `pSIRequested` [in]

A pointer to a value that indicates the components of the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) to set. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **DACL_SECURITY_INFORMATION** | Sets the [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) of the object. The handle specified by *hObj* must have WRITE_DAC access, or the calling [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) must be the owner of the object. |
| **GROUP_SECURITY_INFORMATION** | Sets the primary group [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) of the object. |
| **OWNER_SECURITY_INFORMATION** | Sets the SID of the owner of the object. The handle specified by *hObj* must have WRITE_OWNER access, or the calling process must be the owner of the object or have the SE_TAKE_OWNERSHIP_NAME privilege enabled. |
| **SACL_SECURITY_INFORMATION** | Sets the [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) of the object. The handle specified by *hObj* must have ACCESS_SYSTEM_SECURITY access. <br><br>**To obtain ACCESS_SYSTEM_SECURITY access**<br><br>1. Enable the SE_SECURITY_NAME    [privilege](https://learn.microsoft.com/windows/desktop/SecAuthZ/privileges) in the current [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) of the caller. 2. Open the handle for ACCESS_SYSTEM_SECURITY access. 3. Disable the privilege. |

### `pSID` [in]

A pointer to a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure that contains the new security information.

This buffer must be aligned on a 4-byte boundary.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **SetUserObjectSecurity** function applies changes specified in a [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) to the security descriptor assigned to a user object. The security descriptor of the object must be in [self-relative](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) form. If necessary, this function allocates additional memory to increase the size of the security descriptor.

#### Examples

For an example that uses this function, see [Starting an Interactive Client Process](https://learn.microsoft.com/previous-versions/aa379608(v=vs.85)).

## See also

[GetUserObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getuserobjectsecurity)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information)

[SetFileSecurity](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setfilesecuritya)

[SetKernelObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setkernelobjectsecurity)

[SetPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setprivateobjectsecurity)