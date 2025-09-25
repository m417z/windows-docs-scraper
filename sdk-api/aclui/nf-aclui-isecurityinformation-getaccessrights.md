# ISecurityInformation::GetAccessRights

## Description

The **GetAccessRights** method requests information about the access rights that can be controlled for a securable object. The access control editor calls this method to retrieve display strings and other information used to initialize the property pages. For more information, see
[Access Rights and Access Masks](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-rights-and-access-masks).

## Parameters

### `pguidObjectType` [in]

A pointer to a
[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) structure that identifies the type of object for which access rights are being requested. If this parameter is **NULL** or a pointer to GUID_NULL, return the access rights for the object being edited. Otherwise, the GUID identifies a child object type returned by the
[ISecurityInformation::GetInheritTypes](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getinherittypes) method. The GUID corresponds to the **InheritedObjectType** member of an object-specific ACE.

### `dwFlags` [in]

A set of bit flags that indicate the property page being initialized. This value is zero if the basic security page is being initialized. Otherwise, it is a combination of the following values.

| Value | Meaning |
| --- | --- |
| **SI_ADVANCED** | The **Advanced Security** property sheet is being initialized. |
| **SI_EDIT_AUDITS** | The **Advanced Security** property sheet includes the **Audit** property page. |
| **SI_EDIT_PROPERTIES** | The **Advanced Security** property sheet enables editing of ACEs that apply to the properties and property sets of the object. |

### `ppAccess` [out]

A pointer to an array of
[SI_ACCESS](https://learn.microsoft.com/windows/desktop/api/aclui/ns-aclui-si_access) structures. The array must include one entry for each access right. You can specify access rights that apply to the object itself, as well as object-specific access rights that apply only to a property set or property on the object.

### `pcAccesses` [out]

A pointer to **ULONG** that indicates the number of entries in the *ppAccess* array.

### `piDefaultAccess` [out]

A pointer to **ULONG** that indicates the zero-based index of the array entry that contains the default access rights. The access control editor uses this entry as the initial access rights in a new ACE.

## Return value

If the function succeeds, the function returns S_OK.

 If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The **GetAccessRights** method is called each time a property page is initialized.

The access control editor does not free the pointer returned in *ppAccess*.

## See also

[Access Control Editor](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-editor)

[Access Control Editor Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[CreateSecurityPage](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-createsecuritypage)

[EditSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-editsecurity)

[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)

[ISecurityInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation)

[ISecurityInformation::GetInheritTypes](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getinherittypes)

[SI_ACCESS](https://learn.microsoft.com/windows/desktop/api/aclui/ns-aclui-si_access)