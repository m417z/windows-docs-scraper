# SetServiceObjectSecurity function

## Description

[**SetServiceObjectSecurity** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [SetNamedSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setnamedsecurityinfoa) function.]

The **SetServiceObjectSecurity** function sets the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of a service object.

## Parameters

### `hService` [in]

A handle to the service. This handle is returned by the
[OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea) or
[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea) function. The access required for this handle depends on the security information specified in the *dwSecurityInformation* parameter.

### `dwSecurityInformation` [in]

Specifies the components of the security descriptor to set. This parameter can be a combination of the following values. Note that flags not handled by **SetServiceObjectSecurity** will be silently ignored.

| Value | Meaning |
| --- | --- |
| **DACL_SECURITY_INFORMATION** | Sets the [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) of the object. The handle specified by *hService* must have WRITE_DAC access, or the calling [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) must be the owner of the object. |
| **GROUP_SECURITY_INFORMATION** | Sets the primary group [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) of the object. The handle specified by *hService* must have WRITE_OWNER access, or the calling process must be the owner of the object. |
| **OWNER_SECURITY_INFORMATION** | Sets the SID of the owner of the object. The handle specified by *hService* must have WRITE_OWNER access, or the calling process must be the owner of the object or have the SE_TAKE_OWNERSHIP_NAME privilege enabled. |
| **SACL_SECURITY_INFORMATION** | Sets the [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) of the object. The handle specified by *hService* must have ACCESS_SYSTEM_SECURITY access. <br><br>**To obtain ACCESS_SYSTEM_SECURITY access**<br><br>1. Enable the SE_SECURITY_NAME    [privilege](https://learn.microsoft.com/windows/desktop/SecAuthZ/privileges) in the current [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) of the caller. 2. Open the handle for ACCESS_SYSTEM_SECURITY access. 3. Disable the privilege. |

### `lpSecurityDescriptor` [in]

A pointer to a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure that contains the new security information.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error codes can be set by the service control manager. Other error codes can be set by the registry functions that are called by the service control manager.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The specified handle was not opened with the required access, or the calling process is not the owner of the object. |
| **ERROR_INVALID_HANDLE** | The specified handle is not valid. |
| **ERROR_INVALID_PARAMETER** | The specified security information or security descriptor is not valid. |
| **ERROR_SERVICE_MARKED_FOR_DELETE** | The specified service has been marked for deletion. |

## Remarks

The **SetServiceObjectSecurity** function sets the specified portions of the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of the service object based on the information specified in the *lpSecurityDescriptor* buffer. This function replaces any or all of the security information associated with the service object, according to the flags set in the *dwSecurityInformation* parameter and subject to the access rights of the calling [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

When a service is created, the service control manager assigns a default security descriptor to the service object. To retrieve a copy of the security descriptor for a service object, call the
[QueryServiceObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceobjectsecurity) function. For a description of the default security descriptor for a service object, see
[Service Security and Access Rights](https://learn.microsoft.com/windows/desktop/Services/service-security-and-access-rights).

Note that granting certain access to untrusted users (such as SERVICE_CHANGE_CONFIG or SERVICE_STOP) can allow them to interfere with the execution of your service and possibly allow them to run applications under the LocalSystem account.

## See also

[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea)

[QueryServiceObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceobjectsecurity)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)