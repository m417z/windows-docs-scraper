# GetPrivateObjectSecurity function

## Description

The **GetPrivateObjectSecurity** function retrieves information from a private object's [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Parameters

### `ObjectDescriptor` [in]

A pointer to a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure. This is the security descriptor to be queried.

### `SecurityInformation` [in]

A set of bit flags that indicate the parts of the security descriptor to retrieve. This parameter can be a combination of the
[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) bit flags.

### `ResultantDescriptor` [out, optional]

A pointer to a buffer that receives a copy of the requested information from the specified security descriptor. The
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure is returned in [self-relative](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) format.

### `DescriptorLength` [in]

Specifies the size, in bytes, of the buffer pointed to by the *ResultantDescriptor* parameter.

### `ReturnLength` [out]

A pointer to a variable the function sets to zero if the descriptor is copied successfully. If the buffer is too small for the security descriptor, this variable receives the number of bytes required. If this variable's value is greater than the value of the *DescriptorLength* parameter when the function returns, the function returns **FALSE** and none of the security descriptor is copied to the buffer.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function is intended for use by resource managers only. To implement the standard access control semantics for updating security descriptors, a resource manager should verify that the following conditions are met before calling **GetPrivateObjectSecurity**:

* If the object's owner is being set, the calling [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) must have either WRITE_OWNER permission or be the object's owner.
* If the object's [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) is being set, the calling process must have either WRITE_DAC permission or be the object's owner.
* If the object's [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) is being set, the SE_SECURITY_NAME privilege must be enabled for the calling process.

If the preceding conditions are not met, a call to this function does not fail, however, standard access policy is not enforced.

## See also

[Client/Server Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[Client/Server Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)

[CreatePrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createprivateobjectsecurity)

[DestroyPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-destroyprivateobjectsecurity)

[GetFileSecurity](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfilesecuritya)

[GetKernelObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getkernelobjectsecurity)

[GetUserObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getuserobjectsecurity)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information)

[SetPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setprivateobjectsecurity)