# SetSecurityDescriptorDacl function

## Description

The **SetSecurityDescriptorDacl** function sets information in a [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL). If a DACL is already present in the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly), the DACL is replaced.

## Parameters

### `pSecurityDescriptor` [in, out]

A pointer to the
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure to which the function adds the DACL. This security descriptor must be in [absolute](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) format, meaning that its members must be pointers to other structures, rather than offsets to contiguous data.

### `bDaclPresent` [in]

A flag that indicates the presence of a DACL in the security descriptor. If this parameter is **TRUE**, the function sets the SE_DACL_PRESENT flag in the
[SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-control) structure and uses the values in the *pDacl* and *bDaclDefaulted* parameters. If this parameter is **FALSE**, the function clears the SE_DACL_PRESENT flag, and *pDacl* and *bDaclDefaulted* are ignored.

### `pDacl` [in, optional]

A pointer to an
[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) structure that specifies the DACL for the security descriptor. If this parameter is **NULL**, a **NULL** DACL is assigned to the security descriptor, which allows all access to the object. The DACL is referenced by, not copied into, the security descriptor.

### `bDaclDefaulted` [in]

A flag that indicates the source of the DACL. If this flag is **TRUE**, the DACL has been retrieved by some default mechanism. If **FALSE**, the DACL has been explicitly specified by a user. The function stores this value in the SE_DACL_DEFAULTED flag of the [SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-control) structure. If this parameter is not specified, the SE_DACL_DEFAULTED flag is cleared.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

There is an important difference between an empty and a nonexistent DACL. When a DACL is empty, it contains no [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs); therefore, no access rights are explicitly granted. As a result, access to the object is implicitly denied.

When an object has no DACL (when the *pDacl* parameter is **NULL**), no protection is assigned to the object, and all access requests are granted. To help maintain security, restrict access by using a DACL.

There are three possible outcomes in different configurations of the *bDaclPresent* flag and the *pDacl* parameter:

* When the *pDacl* parameter points to a DACL and the *bDaclPresent* flag is **TRUE**, a DACL is specified and it must contain access-allowed ACEs to allow access to the object.
* When the *pDacl* parameter does not point to a DACL and the *bDaclPresent* flag is **TRUE**, a **NULL** DACL is specified. All access is allowed. You should not use a **NULL** DACL with an object because any user can change the DACL and owner of the security descriptor. This will interfere with use of the object.
* When the *pDacl* parameter does not point to a DACL and the *bDaclPresent* flag is **FALSE**, a DACL can be provided for the object through an inheritance or default mechanism.

#### Examples

For an example that uses this function, see [Creating a Security Descriptor for a New Object](https://learn.microsoft.com/windows/desktop/SecAuthZ/creating-a-security-descriptor-for-a-new-object-in-c--).

## See also

[GetSecurityDescriptorDacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptordacl)

[InitializeSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-initializesecuritydescriptor)

[IsValidSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidsecuritydescriptor)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-control)

[SetSecurityDescriptorGroup](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorgroup)

[SetSecurityDescriptorOwner](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorowner)

[SetSecurityDescriptorSacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorsacl)