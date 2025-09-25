# ISecurityInformation2::IsDaclCanonical

## Description

The **IsDaclCanonical** method determines whether the ACEs contained in the specified DACL structure are ordered according to the definition of DACL ordering implemented by the client.

## Parameters

### `pDacl` [in]

A pointer to a discretionary
[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) structure initialized by
[InitializeAcl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-initializeacl).

## Return value

Returns **TRUE** if the ACEs contained in the specified DACL structure are ordered according to the definition of DACL ordering implemented by the client.

Returns **FALSE** if the ACEs are not ordered correctly.

## Remarks

If the return value of this method is **FALSE**, the access control editor displays a message box stating that the DACL is incorrectly ordered. If this method is not provided and the editor requires this information, the editor will check the canonical ordering defined in
[Order of ACEs in a DACL](https://learn.microsoft.com/windows/desktop/SecAuthZ/order-of-aces-in-a-dacl).

## See also

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[Access Control Editor](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-editor)

[Access Control Editor Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[ISecurityInformation2](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation2)

[InitializeAcl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-initializeacl)