# DeleteAce function

## Description

The **DeleteAce** function deletes an [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE) from an [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL).

## Parameters

### `pAcl` [in, out]

A pointer to an
ACL. The ACE specified by the *dwAceIndex* parameter is removed from this ACL.

### `dwAceIndex` [in]

The ACE to delete. A value of zero corresponds to the first ACE in the ACL, a value of one to the second ACE, and so on.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

An application can use the
[ACL_SIZE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl_size_information) structure retrieved by the
[GetAclInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getaclinformation) function to discover the size of the ACL and the number of ACEs it contains. The
[GetAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getace) function retrieves information about an individual ACE.

## See also

[ACL_SIZE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl_size_information)

[AddAccessAllowedAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessallowedace)

[AddAccessDeniedAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessdeniedace)

[AddAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addace)

[AddAuditAccessAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addauditaccessace)

[GetAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getace)

[GetAclInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getaclinformation)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)