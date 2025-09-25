# CreateSecurityPage function

## Description

The **CreateSecurityPage** function creates a
[basic security property page](https://learn.microsoft.com/windows/desktop/SecAuthZ/basic-security-property-page) that enables the user to view and edit the access rights allowed or denied by the [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs) in an object's [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL). Use the
[PropertySheet](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propertysheeta) function or the
[PSM_ADDPAGE](https://learn.microsoft.com/windows/desktop/Controls/psm-addpage) message to add this page to a property sheet.

## Parameters

### `psi` [in]

A pointer to your implementation of the
[ISecurityInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation) interface. The system calls the interface methods to retrieve information about the object being edited and to return the user's input.

## Return value

If the function succeeds, the function returns a handle to a basic security property page.

If the function fails, it returns **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

During the property page initialization, the system calls the
[ISecurityInformation::GetSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getsecurity) and
[ISecurityInformation::SetSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-setsecurity) methods to determine whether the user has permission to edit the object's [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). The system displays an error message if the user does not have permission.

The basic security property page can include an **Advanced** button for displaying the
[advanced security property sheet](https://learn.microsoft.com/windows/desktop/SecAuthZ/advanced-security-property-sheet). This advanced security property sheet can contain three additional property pages that enable the user to view and edit the object's DACL, [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL), and owner.

## See also

[Access Control Editor](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-editor)

[Access Control Editor Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[EditSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-editsecurity)

[GetSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getsecurity)

[ISecurityInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation)

[PSM_ADDPAGE](https://learn.microsoft.com/windows/desktop/Controls/psm-addpage)

[PropertySheet](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propertysheeta)

[SetSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-setsecurity)