# GetAce function

## Description

The **GetAce** function obtains a pointer to an [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE) in an [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL).

## Parameters

### `pAcl` [in]

A pointer to an
ACL that contains the ACE to be retrieved.

### `dwAceIndex` [in]

The index of the ACE to be retrieved. A value of zero corresponds to the first ACE in the ACL, a value of one to the second ACE, and so on.

### `pAce` [out]

A pointer to a pointer that the function sets to the address of the ACE.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[AddAccessAllowedAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessallowedace)

[AddAccessDeniedAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessdeniedace)

[AddAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addace)

[AddAuditAccessAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addauditaccessace)

[GetAclInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getaclinformation)

[InitializeAcl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-initializeacl)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)