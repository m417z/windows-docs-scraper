# GetSecurityDescriptorDacl function

## Description

The **GetSecurityDescriptorDacl** function retrieves a pointer to the [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) in a specified [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Parameters

### `pSecurityDescriptor` [in]

A pointer to the
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure that contains the DACL. The function retrieves a pointer to it.

### `lpbDaclPresent` [out]

A pointer to a value that indicates the presence of a DACL in the specified security descriptor. If *lpbDaclPresent* is **TRUE**, the security descriptor contains a DACL, and the remaining output parameters in this function receive valid values. If *lpbDaclPresent* is **FALSE**, the security descriptor does not contain a DACL, and the remaining output parameters do not receive valid values.

A value of **TRUE** for *lpbDaclPresent* does not mean that *pDacl* is not **NULL**. That is, *lpbDaclPresent* can be **TRUE** while *pDacl* is **NULL**, meaning that a **NULL** DACL is in effect. A **NULL** DACL implicitly allows all access to an object and is not the same as an empty DACL. An empty DACL permits no access to an object. For information about creating a proper DACL, see [Creating a DACL](https://learn.microsoft.com/windows/desktop/SecBP/creating-a-dacl).

### `pDacl` [out]

A pointer to a pointer to an
[access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL). If a DACL exists, the function sets the pointer pointed to by *pDacl* to the address of the security descriptor's DACL. If a DACL does not exist, no value is stored.

If the function stores a **NULL** value in the pointer pointed to by *pDacl*, the security descriptor has a **NULL** DACL. A **NULL** DACL implicitly allows all access to an object.

If an application expects a non-**NULL** DACL but encounters a **NULL** DACL, the application should fail securely and not allow access.

### `lpbDaclDefaulted` [out]

A pointer to a flag set to the value of the SE_DACL_DEFAULTED flag in the
[SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-control) structure if a DACL exists for the security descriptor. If this flag is **TRUE**, the DACL was retrieved by a default mechanism; if **FALSE**, the DACL was explicitly specified by a user.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[GetSecurityDescriptorControl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorcontrol)

[GetSecurityDescriptorGroup](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorgroup)

[GetSecurityDescriptorLength](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorlength)

[GetSecurityDescriptorOwner](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorowner)

[GetSecurityDescriptorSacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorsacl)

[InitializeSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-initializesecuritydescriptor)

[IsValidSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidsecuritydescriptor)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-control)

[SetSecurityDescriptorDacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptordacl)