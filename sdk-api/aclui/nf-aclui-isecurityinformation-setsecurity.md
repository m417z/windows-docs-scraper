# ISecurityInformation::SetSecurity

## Description

The **SetSecurity** method provides a [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) containing the security information the user wants to apply to the securable object. The access control editor calls this method when the user clicks **Okay** or **Apply**.

## Parameters

### `SecurityInformation` [in]

A set of
[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) bit flags that indicate the parts of the security descriptor to set. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **OWNER_SECURITY_INFORMATION** | The security descriptor contains the SID of the object's owner. |
| **GROUP_SECURITY_INFORMATION** | The security descriptor contains the SID of the object's primary group. |
| **DACL_SECURITY_INFORMATION** | The security descriptor contains the object's DACL. |
| **SACL_SECURITY_INFORMATION** | The security descriptor contains the object's SACL. |

### `pSecurityDescriptor` [in]

A pointer to a security descriptor containing the new security information. Do not assume the security descriptor is in [self-relative](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) form; it can be either
[absolute or self-relative](https://learn.microsoft.com/windows/desktop/SecAuthZ/absolute-and-self-relative-security-descriptors).

## Return value

Returns S_OK if successful.

Returns a nonzero error code if an error occurs.

## Remarks

To build a complete security descriptor for the object, the application must merge the new security descriptor parts, as defined by the *SecurityInformation* parameter, into the object's existing security descriptor.

## See also

[Access Control Editor](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-editor)

[Access Control Editor Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[ISecurityInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation)

[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information)