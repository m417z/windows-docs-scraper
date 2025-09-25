# SetPrivateObjectSecurity function

## Description

The **SetPrivateObjectSecurity** function modifies a private object's [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

To specify whether the protected server supports automatic inheritance of [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs), use the
[SetPrivateObjectSecurityEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setprivateobjectsecurityex) function.

## Parameters

### `SecurityInformation` [in]

Indicates the parts of the security descriptor to set. This value can be a combination of the
[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) bit flags.

### `ModificationDescriptor` [in]

A pointer to a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure. The parts of this security descriptor indicated by the *SecurityInformation* parameter are applied to the *ObjectsSecurityDescriptor* security descriptor.

### `ObjectsSecurityDescriptor` [in, out]

A pointer to a pointer to a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure. This security descriptor must be in [self-relative](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) form. **The memory for the security descriptor must be allocated from the process heap (GetProcessHeap) with the HeapAlloc function.**

On input, this is the current security descriptor of the private object. The function modifies it to produce the new security descriptor. If necessary, the **SetPrivateObjectSecurity** function allocates additional memory to produce a larger security descriptor.

### `GenericMapping` [in]

A pointer to a
[GENERIC_MAPPING](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-generic_mapping) structure that specifies the specific and standard access rights that correspond to each of the generic access rights.

### `Token` [in, optional]

A handle to the [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) for the client on whose behalf the private object's security is being modified. This parameter is required to ensure that the client has provided a legitimate value for a new owner [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID). The token must be open for TOKEN_QUERY access.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function is intended for use by resource managers only. To implement the standard access control semantics for updating security descriptors, a resource manager should verify that the following conditions are met before calling **SetPrivateObjectSecurity**:

* If the object's owner is being set, the calling [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) must have either WRITE_OWNER permission or be the object's owner.
* If the object's [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) is being set, the calling process must have either WRITE_DAC permission or be the object's owner.
* If the object's [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) is being set, the SE_SECURITY_NAME privilege must be enabled for the calling process.

If the preceding conditions are not met, a call to this function does not fail; however, standard access policy is not enforced.

The process calling this function should not be impersonating a client because clients do not typically have appropriate privileges required for underlying token operations.

## See also

[Client/Server Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[Client/Server Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)

[CreatePrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createprivateobjectsecurity)

[DestroyPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-destroyprivateobjectsecurity)

[GENERIC_MAPPING](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-generic_mapping)

[GetPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getprivateobjectsecurity)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information)

[SetFileSecurity](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setfilesecuritya)

[SetKernelObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setkernelobjectsecurity)

[SetPrivateObjectSecurityEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setprivateobjectsecurityex)

[SetUserObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setuserobjectsecurity)