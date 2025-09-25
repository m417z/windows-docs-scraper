# SECURITY_DESCRIPTOR structure

## Description

The **SECURITY_DESCRIPTOR** structure contains the security information associated with an object. Applications use this structure to set and query an object's security status.

Because the internal format of a [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) can vary, we recommend that applications not modify the **SECURITY_DESCRIPTOR** structure directly. For creating and manipulating a security descriptor, use the functions listed in See Also.

## Members

## Remarks

A security descriptor includes information that specifies the following components of an object's security:

* An owner [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID)
* A primary group SID
* A [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL)
* A [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL)
* Qualifiers for the preceding items

Several functions that use the **SECURITY_DESCRIPTOR** structure require that this structure be aligned on a valid pointer boundary in memory. These boundaries vary depending on the type of processor used. Memory allocation functions such as **malloc** and **LocalAlloc** return properly aligned pointers.

## See also

[GetSecurityDescriptorControl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorcontrol)

[GetSecurityDescriptorDacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptordacl)

[GetSecurityDescriptorGroup](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorgroup)

[GetSecurityDescriptorLength](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorlength)

[GetSecurityDescriptorOwner](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorowner)

[GetSecurityDescriptorRMControl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorrmcontrol)

[GetSecurityDescriptorSacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorsacl)

[InitializeSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-initializesecuritydescriptor)

[IsValidSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidsecuritydescriptor)

[SetSecurityDescriptorDacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptordacl)

[SetSecurityDescriptorGroup](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorgroup)

[SetSecurityDescriptorOwner](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorowner)

[SetSecurityDescriptorRMControl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorrmcontrol)

[SetSecurityDescriptorSacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorsacl)