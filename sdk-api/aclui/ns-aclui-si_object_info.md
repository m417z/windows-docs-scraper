# SI_OBJECT_INFO structure

## Description

The **SI_OBJECT_INFO** structure is used by the
[ISecurityInformation::GetObjectInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getobjectinformation) method to specify information used to initialize the access control editor.

## Members

### `dwFlags`

A set of bit flags that determine the editing options available to the user. This member can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **SI_ADVANCED**<br><br>0x00000010L | If this flag is set, the **Advanced** button is displayed on the basic security property page. If the user clicks this button, the system displays an [advanced security property sheet](https://learn.microsoft.com/windows/desktop/SecAuthZ/advanced-security-property-sheet) that enables advanced editing of the [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) of the object. <br><br>Combine this flag with the SI_EDIT_AUDITS, SI_EDIT_OWNER, and SI_EDIT_PROPERTIES flags to enable editing of the object's SACL, owner, and object-specific [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs). |
| **SI_AUDITS_ELEVATION_REQUIRED**<br><br>0x02000000L | If this flag is set, a shield is displayed on the **Edit** button of the advanced **Auditing** pages. For NTFS objects, this flag is requested when the user does not have **READ_CONTROL** or **ACCESS_SYSTEM_SECURITY** access.<br><br>**Windows Server 2003 and Windows XP:** This flag is not supported. |
| **SI_CONTAINER**<br><br>0x00000004L | Indicates that the object is a container. If this flag is set, the access control editor enables the controls relevant to the inheritance of permissions onto child objects. |
| **SI_DISABLE_DENY_ACE**<br><br>0x80000000L | If this flag is set, the system disables denying an ACE. Clients of the access control editor must implement the [ISecurityInformation4](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation4) interface to set this flag.<br><br>**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported. |
| **SI_EDIT_ALL** | Combines the SI_EDIT_PERMS, SI_EDIT_OWNER, and SI_EDIT_AUDITS flags. |
| **SI_EDIT_AUDITS**<br><br>0x00000002L | If this flag is set and the user clicks the **Advanced** button, the system displays an advanced security property sheet that includes an [Auditing property page](https://learn.microsoft.com/windows/desktop/SecAuthZ/auditing-property-page) for editing the object's SACL. To display the **Advanced** button, set the SI_ADVANCED flag. |
| **SI_EDIT_EFFECTIVE**<br><br>0x00020000L | If this flag is set, the **Effective Permissions** page is displayed. This flag is ignored if the [ISecurityInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation) object that initialized the access control editor does not implement the [IEffectivePermission](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-ieffectivepermission) interface. |
| **SI_EDIT_OWNER**<br><br>0x00000001L | If this flag is set and the user clicks the **Advanced** button, the system displays an advanced security property sheet that includes an [Owner property page](https://learn.microsoft.com/windows/desktop/SecAuthZ/owner-property-page) for changing the object's owner. To display the **Advanced** button, set the SI_ADVANCED flag. |
| **SI_EDIT_PERMS**<br><br>0x00000000L | This is the default value. The basic security property page always displays the controls for basic editing of the object's DACL. To disable these controls, set the SI_READONLY flag. |
| **SI_EDIT_PROPERTIES**<br><br>0x00000080L | If this flag is set, the system enables controls for editing ACEs that apply to the object's property sets and properties. These controls are available only on the property sheet displayed when the user clicks the **Advanced** button. |
| **SI_ENABLE_CENTRAL_POLICY**<br><br>0x40000000L | If this flag is set, the system enables editing attributes. Clients of the access control editor must implement the [ISecurityInformation4](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation4) interface to set this flag.<br><br>**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported. |
| **SI_ENABLE_EDIT_ATTRIBUTE_CONDITION**<br><br>0x20000000L | If this flag is set, the system enables editing attributes. Clients of the access control editor must implement the [ISecurityInformation4](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation4) interface to set this flag.<br><br>**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported. |
| **SI_MAY_WRITE**<br><br>0x10000000L | Indicates that the access control editor cannot read the DACL but might be able to write to the DACL. If a call to the [ISecurityInformation::GetSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getsecurity) method returns **AccessDenied**, the user can try to add a new ACE, and a more appropriate warning is displayed. |
| **SI_NO_ACL_PROTECT**<br><br>0x00000200L | If this flag is set, the access control editor hides the check box that allows inheritable ACEs to propagate from the parent object to this object. If this flag is not set, the check box is visible. <br><br>The check box is clear if the SE_DACL_PROTECTED flag is set in the object's security descriptor. In this case, the object's DACL is protected from being modified by inheritable ACEs.<br><br>If the user clears the check box, any inherited ACEs in the security descriptor are deleted or converted to noninherited ACEs. Before proceeding with this conversion, the system displays a warning message box to confirm the change. |
| **SI_NO_ADDITIONAL_PERMISSION**<br><br>0x00200000L | If this flag is set, the access control editor hides the **Special Permissions** tab on the **Advanced Security Settings** page. |
| **SI_NO_TREE_APPLY**<br><br>0x00000400L | If this flag is set, the access control editor hides the check box that controls the NO_PROPAGATE_INHERIT_ACE flag. This flag is relevant only when the SI_ADVANCED flag is also set. |
| **SI_OBJECT_GUID**<br><br>0x00010000L | When set, indicates that the **guidObjectType** member of the **SI_OBJECT_INFO** structure is valid. This is set in comparisons with object-specific ACEs in determining whether the ACE applies to the current object. |
| **SI_OWNER_ELEVATION_REQUIRED**<br><br>0x04000000L | If this flag is set, a shield is displayed on the **Edit** button of the advanced **Owner** page. For NTFS objects, this flag is requested when the user does not have **WRITE_OWNER** access. This flag is valid only if the owner page is requested.<br><br>**Windows Server 2003 and Windows XP:** This flag is not supported. |
| **SI_OWNER_READONLY**<br><br>0x00000040L | If this flag is set, the user cannot change the owner of the object. Set this flag if SI_EDIT_OWNER is set but the user does not have permission to change the owner. |
| **SI_OWNER_RECURSE**<br><br>0x00000100L | Combine this flag with SI_CONTAINER to display a check box on the owner page that indicates whether the user intends the new owner to be applied to all child objects as well as the current object. The access control editor does not perform the recursion; the recursion should be performed by the application in [ISecurityInformation::SetSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-setsecurity). |
| **SI_PAGE_TITLE**<br><br>0x00000800L | If this flag is set, the **pszPageTitle** member is used as the title of the basic security property page. Otherwise, a default title is used. |
| **SI_PERMS_ELEVATION_REQUIRED**<br><br>0x01000000L | If this flag is set, an image of a shield is displayed on the **Edit** button of the simple and advanced **Permissions** pages. For NTFS objects, this flag is requested when the user does not have **READ_CONTROL** or **WRITE_DAC** access.<br><br>**Windows Server 2003 and Windows XP:** This flag is not supported. |
| **SI_READONLY**<br><br>0x00000008L | If this flag is set, the editor displays the object's security information, but the controls for editing the information are disabled.<br><br>This flag cannot be combined with the **SI_VIEW_ONLY** flag. |
| **SI_RESET**<br><br>0x00000020L | If this flag is set, the **Default** button is displayed. If the user clicks this button, the access control editor calls the [ISecurityInformation::GetSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getsecurity) method to retrieve an application-defined default security descriptor. The access control editor uses this security descriptor to reinitialize the property sheet, and the user is allowed to apply the change or cancel. |
| **SI_RESET_DACL**<br><br>0x00040000L | When set, this flag displays the **Reset Defaults** button on the **Permissions** page. |
| **SI_RESET_DACL_TREE**<br><br>0x00004000L | When set, this flag displays the Reset permissions on all child objects and enable propagation of inheritable permissions check box in the Permissions page of the Access Control Settings window. If this check box is selected when the user clicks the **Apply** button, a bitwise-**OR** operation is performed on the *SecurityInformation* parameter of [ISecurityInformation::SetSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-setsecurity) with SI_RESET_DACL_TREE. This function does not reset the permissions and enable propagation of inheritable permissions; the implementation of [ISecurityInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation) must do this. |
| **SI_RESET_OWNER**<br><br>0x00100000L | When set, this flag displays the **Reset Defaults** button on the **Owner** page. |
| **SI_RESET_SACL**<br><br>0x00080000L | When set, this flag displays the **Reset Defaults** button on the **Auditing** page. |
| **SI_RESET_SACL_TREE**<br><br>0x00008000L | When set, this flag displays the Reset auditing entries on all child objects and enables propagation of the inheritable auditing entries check box in the Auditing page of the Access Control Settings window. If this check box is selected when the user clicks the **Apply** button, a bitwise-**OR** operation is performed on the *SecurityInformation* parameter of [ISecurityInformation::SetSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-setsecurity) with SI_RESET_SACL_TREE. This function does not reset the permissions and enable propagation of inheritable permissions; the implementation of [ISecurityInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation) must do this. |
| **SI_SCOPE_ELEVATION_REQUIRED**<br><br>0x08000000L | If this flag is set, an image of a shield is displayed on the **Change** button of the Scope attribute. For NTFS objects, this flag is requested when the user does not have READ_CONTROL or WRITE_DAC access. Clients of the access control editor must implement the [ISecurityInformation4](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation4) interface to set this flag.<br><br>**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported. |
| **SI_SERVER_IS_DC**<br><br>0x00001000L | Set this flag if the **pszServerName** computer is known to be a domain controller. If this flag is set, the domain name is included in the scope list of the **Add Users and Groups** dialog box. Otherwise, the **pszServerName** computer is used to determine the scope list of the dialog box. |
| **SI_VIEW_ONLY**<br><br>0x00400000L | This flag is set by the access control editor client to display read-only versions of the access control editor dialog boxes. These versions of the dialog boxes do not allow editing of the associated object's permissions. Clients of the access control editor must implement the [ISecurityInformation3](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation3) interface to set this flag.<br><br>This flag cannot be combined with the **SI_READONLY** flag.<br><br>**Windows Server 2003 and Windows XP:** This flag is not supported. |

### `hInstance`

Identifies a module that contains string resources to be used in the property sheet. The
[ISecurityInformation::GetAccessRights](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getaccessrights) and
[ISecurityInformation::GetInheritTypes](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getinherittypes) methods can specify string resource identifiers for display names.

### `pszServerName`

A pointer to a **null**-terminated, [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) string that names the computer on which to look up account names and SIDs. This value can be **NULL** to specify the local computer. The access control editor does not free this pointer.

### `pszObjectName`

A pointer to a **null**-terminated, Unicode string that names the object being edited. This name appears in the title of the advanced security property sheet and any error message boxes displayed by the access control editor. The access control editor does not free this pointer.

### `pszPageTitle`

A pointer to a **null**-terminated, Unicode string used as the title of the basic security property page. This member is ignored unless the SI_PAGE_TITLE flag is set in **dwFlags**. If the page title is not provided, a default title is used. The access control editor does not free this pointer.

### `guidObjectType`

A
GUID for the object. This member is ignored unless the SI_OBJECT_GUID flag is set in **dwFlags**.

## See also

[ISecurityInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation)

[ISecurityInformation::GetAccessRights](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getaccessrights)

[ISecurityInformation::GetInheritTypes](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getinherittypes)

[ISecurityInformation::GetObjectInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getobjectinformation)

[ISecurityInformation::GetSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getsecurity)

[ISecurityInformation::SetSecurity](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-setsecurity)