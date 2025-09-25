# QueryServiceObjectSecurity function

## Description

The **QueryServiceObjectSecurity** function retrieves a copy of the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) associated with a service object. You can also use the [GetNamedSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getnamedsecurityinfoa) function to retrieve a security descriptor.

## Parameters

### `hService` [in]

A handle to the service control manager or the service. Handles to the service control manager are returned by the
[OpenSCManager](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openscmanagera) function, and handles to a service are returned by either the
[OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea) or
[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea) function. The handle must have the READ_CONTROL access right.

### `dwSecurityInformation` [in]

A set of
bit flags that indicate the type of security information to retrieve. This parameter can be a combination of the
[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) bit flags, with the exception that this function does not support the **LABEL_SECURITY_INFORMATION** value.

### `lpSecurityDescriptor` [out, optional]

A pointer to a buffer that receives a copy of the security descriptor of the specified service object. The calling process must have the appropriate access to view the specified aspects of the security descriptor of the object. The
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure is returned in [self-relative](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) format.

### `cbBufSize` [in]

The size of the buffer pointed to by the *lpSecurityDescriptor* parameter, in bytes. The largest size allowed is 8 kilobytes.

### `pcbBytesNeeded` [out]

A pointer to a variable that receives the number of bytes needed to return the requested security descriptor information, if the function fails.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error codes may be set by the service control manager. Other error codes may be set by the registry functions that are called by the service control manager.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The specified handle was not opened with READ_CONTROL access, or the calling process is not the owner of the object. |
| **ERROR_INVALID_HANDLE** | The specified handle is not valid. |
| **ERROR_INSUFFICIENT_BUFFER** | The security descriptor information is too large for the *lpSecurityDescriptor* buffer. The number of bytes required to get all the information is returned in the *pcbBytesNeeded* parameter. Nothing is written to the *lpSecurityDescriptor* buffer. |
| **ERROR_INVALID_PARAMETER** | The specified security information is not valid. |

## Remarks

When a service is created, the service control manager assigns a default security descriptor to the service object. To retrieve a copy of the security descriptor for a service object, call the **QueryServiceObjectSecurity** function. To change the security descriptor, call the
[SetServiceObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setserviceobjectsecurity) function. For a description of the default security descriptor for a service object, see
[Service Security and Access Rights](https://learn.microsoft.com/windows/desktop/Services/service-security-and-access-rights).

To read the owner, group, or DACL from the security descriptor of the service object, the calling process must have been granted READ_CONTROL access when the handle was opened. To get READ_CONTROL access, the caller must be the owner of the object or the DACL of the object must grant the access.

To read the SACL from the security descriptor, the calling process must have been granted ACCESS_SYSTEM_SECURITY access when the handle was opened. The correct way to get this access is to enable the SE_SECURITY_NAME privilege in the caller's current token, open the handle for ACCESS_SYSTEM_SECURITY access, and then disable the privilege.

## See also

[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea)

[GetNamedSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getnamedsecurityinfoa)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SetServiceObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setserviceobjectsecurity)