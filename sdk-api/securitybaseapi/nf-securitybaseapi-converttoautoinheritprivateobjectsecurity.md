# ConvertToAutoInheritPrivateObjectSecurity function

## Description

The **ConvertToAutoInheritPrivateObjectSecurity** function converts a [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) and its [access control lists](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACLs) to a format that supports automatic propagation of inheritable [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs).

## Parameters

### `ParentDescriptor` [in, optional]

A pointer to the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) for the parent container of the object. If there is no parent container, this parameter is **NULL**.

### `CurrentSecurityDescriptor` [in]

A pointer to the current security descriptor of the object.

### `NewSecurityDescriptor` [out]

A pointer to a variable that receives a pointer to the newly allocated [self-relative security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). It is the caller's responsibility to call the
[DestroyPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-destroyprivateobjectsecurity) function to free this security descriptor.

### `ObjectType` [in, optional]

A pointer to a
[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) structure that identifies the type of object associated with the *CurrentSecurityDescriptor* parameter. If the object does not have a GUID, this parameter must be **NULL**.

### `IsDirectoryObject` [in]

If **TRUE**, the new object is a container and can contain other objects. If **FALSE**, the new object is not a container.

### `GenericMapping` [in]

A pointer to a
[GENERIC_MAPPING](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-generic_mapping) structure that specifies the mapping from each generic right to specific rights for the object.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **ConvertToAutoInheritPrivateObjectSecurity** function attempts to determine whether the ACEs in the [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) and [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) of the current security descriptor were inherited from the parent security descriptor. The function passes the *ParentDescriptor* parameter to the
[CreatePrivateObjectSecurityEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createprivateobjectsecurityex) function to get ACLs that contain only inherited ACEs. Then it compares these ACEs to the ACEs in the original security descriptor to determine which of the original ACEs were inherited. The ACEs do not need to match one-to-one. For instance, an ACE that allows read and write access to a trustee can be equivalent to two ACEs: an ACE that allows read access and an ACE that allows write access.

Any ACEs in the original security descriptor that are equivalent to the ACEs inherited from the parent security descriptor are marked with the INHERITED_ACE flag and added to the new security descriptor. All other ACEs in the original security descriptor are added to the new security descriptor as noninherited ACEs.

If the original DACL does not have any inherited ACEs, the function sets the SE_DACL_PROTECTED flag in the control bits of the new security descriptor. Similarly, the SE_SACL_PROTECTED flag is set if none of the ACEs in the SACL is inherited.

For DACLs that have inherited ACEs, the function reorders the ACEs into two groups. The first group has ACEs that were directly applied to the object. The second group has inherited ACEs. This ordering ensures that noninherited ACEs have precedence over inherited ACEs. For more information, see
[Order of ACEs in a DACL](https://learn.microsoft.com/windows/desktop/SecAuthZ/order-of-aces-in-a-dacl).

The function sets the SE_DACL_AUTO_INHERITED and SE_SACL_AUTO_INHERITED flags in the control bits of the new security descriptor.

The function does not change the ordering of access-allowed ACEs in relation to access-denied ACEs in the DACL because to do so would change the semantics of the resulting security descriptor. If the function cannot convert the DACL without changing the semantics, it leaves the DACL unchanged and sets the SE_DACL_PROTECTED flag.

The new security descriptor has the same owner and primary group as the original security descriptor.

The new security descriptor is equivalent to the original security descriptor, so the caller needs no access rights or [privileges](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) to update the security descriptor to the new format.

This function works with ACL_REVISION and ACL_REVISION_DS ACLs.

## See also

[Client/Server Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)

[Client/Server Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[CreatePrivateObjectSecurityEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createprivateobjectsecurityex)

[DestroyPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-destroyprivateobjectsecurity)

[GENERIC_MAPPING](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-generic_mapping)

[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)