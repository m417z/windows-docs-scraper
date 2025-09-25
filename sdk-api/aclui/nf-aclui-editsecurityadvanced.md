# EditSecurityAdvanced function

## Description

The **EditSecurityAdvanced** function extends the [EditSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-editsecurity) function to include the security page type when displaying the property sheet that contains a
[basic security property page](https://learn.microsoft.com/windows/desktop/SecAuthZ/basic-security-property-page). This property page enables the user to view and edit the access rights allowed or denied by the [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs) in an object's [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL).

## Parameters

### `hwndOwner` [in]

A handle to the window that owns the property sheet. This parameter can be **NULL**.

### `psi` [in]

A pointer to your implementation of the
[ISecurityInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation) interface. The system calls the interface methods to retrieve information about the object being edited and to return the user's input.

### `uSIPage` [in]

A value of the
[SI_PAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/aclui/ne-aclui-si_page_type) enumeration that indicates the page type on which to display the elevated access control editor.

## Return value

If the function succeeds, the return value is S_OK.

If the function fails, any other **HRESULT** value indicates an error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[Access Control Editor](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-editor)

[Access Control Editor Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[CreateSecurityPage](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-createsecuritypage)

[EditSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-editsecurity)

[GetSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getsecurity)

[ISecurityInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation)

[SetSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-setsecurity)