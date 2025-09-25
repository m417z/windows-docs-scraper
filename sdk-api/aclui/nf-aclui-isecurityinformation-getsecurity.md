# ISecurityInformation::GetSecurity

## Description

The **GetSecurity** method requests a [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) for the securable object whose security descriptor is being edited. The access control editor calls this method to retrieve the object's current or default security descriptor.

## Parameters

### `RequestedInformation` [in]

A set of
[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) bit flags that indicate the parts of the security descriptor being requested. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **OWNER_SECURITY_INFORMATION** | The security descriptor must include the SID of the object's owner. |
| **GROUP_SECURITY_INFORMATION** | The security descriptor must include the SID of the object's primary group. |
| **DACL_SECURITY_INFORMATION** | The security descriptor must include the object's DACL. |
| **SACL_SECURITY_INFORMATION** | The security descriptor must include the object's SACL. |

### `ppSecurityDescriptor` [out]

A pointer to a variable that your implementation must set to a pointer to the object's security descriptor. The security descriptor must include the components requested by the *RequestedInformation* parameter.

The system calls the
[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function to free the returned pointer.

### `fDefault` [in]

If this parameter is **TRUE**, *ppSecurityDescriptor* should return an application-defined default security descriptor for the object. The access control editor uses this default security descriptor to reinitialize the property page.

The access control editor sets this parameter to **TRUE** only if the user clicks the **Default** button. The **Default** button is displayed only if you set the SI_RESET flag in the
[ISecurityInformation::GetObjectInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getobjectinformation) method. If no default security descriptor is available, do not set the SI_RESET flag.

If this flag is **FALSE**, *ppSecurityDescriptor* should return the object's current security descriptor.

## Return value

Returns S_OK if successful.

Returns a nonzero error code if an error occurs. Returns E_ACCESSDENIED if the user does not have permission to read the requested security information.

## See also

[Access Control Editor](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-editor)

[Access Control Editor Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[ISecurityInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation)

[ISecurityInformation::GetObjectInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getobjectinformation)

[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree)

[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information)