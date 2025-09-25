# EditSecurity function

## Description

The **EditSecurity** function displays a property sheet that contains a
[basic security property page](https://learn.microsoft.com/windows/desktop/SecAuthZ/basic-security-property-page). This property page enables the user to view and edit the access rights allowed or denied by the ACEs in an object's DACL.

## Parameters

### `hwndOwner` [in]

A handle to the window that owns the property sheet. This parameter can be **NULL**.

### `psi` [in]

A pointer to your implementation of the
[ISecurityInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation) interface. The system calls the interface methods to retrieve information about the object being edited and to return the user's input.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **EditSecurity** function calls the
[CreateSecurityPage](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-createsecuritypage) function to create a basic security property page.

During the property page initialization, the system calls the
[ISecurityInformation::GetSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getsecurity) and
[ISecurityInformation::SetSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-setsecurity) methods to determine whether the user has permission to edit the object's [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). The system displays an error message if the user does not have permission.

The basic security property page can include an **Advanced** button for displaying the
[advanced security property sheet](https://learn.microsoft.com/windows/desktop/SecAuthZ/advanced-security-property-sheet). This advanced security property sheet can contain three additional property pages that enable the user to view and edit the object's DACL, SACL, and owner.

## See also

[Access Control Editor](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-editor)

[Access Control Editor Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[CreateSecurityPage](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-createsecuritypage)

[GetSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getsecurity)

[ISecurityInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation)

[SetSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-setsecurity)