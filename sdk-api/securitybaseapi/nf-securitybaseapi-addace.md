# AddAce function

## Description

The **AddAce** function adds one or more [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs) to a specified [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL).

## Parameters

### `pAcl` [in, out]

A pointer to an
ACL. This function adds an ACE to this ACL.

### `dwAceRevision` [in]

Specifies the revision level of the ACL being modified.

This value can be ACL_REVISION or ACL_REVISION_DS. Use ACL_REVISION_DS if the ACL contains object-specific ACEs. This value must be compatible with the **AceType** field of all ACEs in *pAceList*.
Otherwise, the function will fail and set the last error to ERROR_INVALID_PARAMETER.

### `dwStartingAceIndex` [in]

Specifies the position in the ACL's list of ACEs at which to add new ACEs. A value of zero inserts the ACEs at the beginning of the list. A value of MAXDWORD appends the ACEs to the end of the list.

### `pAceList` [in]

A pointer to a list of one or more ACEs to be added to the specified ACL. The ACEs in the list must be stored contiguously.

### `nAceListLength` [in]

Specifies the size, in bytes, of the input buffer pointed to by the *pAceList* parameter.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following are possible error values.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The new ACE does not fit into the ACL. A larger ACL buffer is required. |
| **ERROR_INVALID_PARAMETER** | The specified ACL is not properly formed. |
| **ERROR_SUCCESS** | The ACE was successfully added. |

## Remarks

Applications frequently use the
[FindFirstFreeAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-findfirstfreeace) and
[GetAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getace) functions when using the **AddAce** function to manipulate an ACL. In addition, the
[ACL_SIZE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl_size_information) structure retrieved by the
[GetAclInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getaclinformation) function contains the size of the ACL and the number of ACEs it contains.

#### Examples

For an example that uses this function, see [Starting an Interactive Client Process](https://learn.microsoft.com/previous-versions/aa379608(v=vs.85)).

## See also

[ACL_SIZE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl_size_information)

[AddAccessAllowedAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessallowedace)

[AddAccessDeniedAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessdeniedace)

[AddAuditAccessAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addauditaccessace)

[DeleteAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-deleteace)

[FindFirstFreeAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-findfirstfreeace)

[GetAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getace)

[GetAclInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getaclinformation)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)