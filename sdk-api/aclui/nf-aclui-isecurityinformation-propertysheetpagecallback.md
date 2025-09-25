# ISecurityInformation::PropertySheetPageCallback

## Description

The **PropertySheetPageCallback** method notifies an
[EditSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-editsecurity) or
[CreateSecurityPage](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-createsecuritypage) caller that an access control editor property page is being created or destroyed.

## Parameters

### `hwnd` [in]

If *uMsg* is PSPCB_SI_INITDIALOG, *hwnd* is a handle to the property page dialog box. Otherwise, *hwnd* is **NULL**.

### `uMsg` [in]

Identifies the message being received. This parameter is one of the following values.

| Value | Meaning |
| --- | --- |
| **PSPCB_CREATE** | Indicates that a property page is being created. |
| **PSPCB_RELEASE** | Indicates that a property page is being destroyed. |
| **PSPCB_SI_INITDIALOG** | Indicates that a property page is being initialized. |

### `uPage` [in]

A value from the
[SI_PAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/aclui/ne-aclui-si_page_type) enumeration type that indicates the type of access control editor property page being created or destroyed.

## Return value

Returns S_OK if successful.

Returns a nonzero error code if an error occurs.

## See also

[Access Control Editor](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-editor)

[Access Control Editor Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[CreateSecurityPage](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-createsecuritypage)

[EditSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-editsecurity)

[ISecurityInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation)

[SI_PAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/aclui/ne-aclui-si_page_type)