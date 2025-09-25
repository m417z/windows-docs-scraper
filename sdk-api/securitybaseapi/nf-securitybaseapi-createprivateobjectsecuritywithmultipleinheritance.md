# CreatePrivateObjectSecurityWithMultipleInheritance function

## Description

The **CreatePrivateObjectSecurityWithMultipleInheritance** function allocates and initializes a [self-relative security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) for a new private object created by the resource manager calling this function. This function supports private objects (such as Directory Service objects with attached auxiliary classes) composed of multiple object types or classes.

## Parameters

### `ParentDescriptor` [in, optional]

A pointer to the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) for the parent container of the object. If there is no parent container, this parameter is **NULL**.

### `CreatorDescriptor` [in, optional]

A pointer to a security descriptor provided by the creator of the object. If the object's creator does not explicitly pass security information for the new object, this parameter can be **NULL**. Alternatively, this parameter can point to a default security descriptor.

### `NewDescriptor` [out]

A pointer to a variable to receive a pointer to the newly allocated self-relative security descriptor. When you have finished using the security descriptor, free it by calling the
[DestroyPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-destroyprivateobjectsecurity) function.

### `ObjectTypes` [in, optional]

An array of pointers to [GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) structures that identify the object types or classes of the object associated with *NewDescriptor*. For Active Directory objects, this array contains pointers to the class GUIDs of the object's structural class and all attached auxiliary classes. Set *ObjectTypes* to **NULL** if the object does not have a GUID.

### `GuidCount` [in]

The number of GUIDs present in the *ObjectTypes* parameter.

### `IsContainerObject` [in]

Specifies whether the new object can contain other objects. A value of **TRUE** indicates that the new object is a container. A value of **FALSE** indicates that the new object is not a container.

### `AutoInheritFlags` [in]

A set of bit flags that control how [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs) are inherited from *ParentDescriptor*. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **SEF_DACL_AUTO_INHERIT**<br><br>0x01 | The new [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) contains ACEs inherited from the DACL of *ParentDescriptor*, as well as any explicit ACEs specified in the DACL of *CreatorDescriptor*. If this flag is not set, the new DACL does not inherit ACEs. |
| **SEF_SACL_AUTO_INHERIT**<br><br>0x02 | The new [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) contains ACEs inherited from the SACL of *ParentDescriptor*, as well as any explicit ACEs specified in the SACL of *CreatorDescriptor*. If this flag is not set, the new SACL does not inherit ACEs. |
| **SEF_DEFAULT_DESCRIPTOR_FOR_OBJECT**<br><br>0x04 | *CreatorDescriptor* is the default descriptor for the types of objects specified by *ObjectTypes*. As such, *CreatorDescriptor* is ignored if *ParentDescriptor* has any object-specific ACEs for the types of objects specified by the *ObjectTypes* parameter. If no such ACEs are inherited, *CreatorDescriptor* is handled as though this flag were not specified. |
| **SEF_AVOID_PRIVILEGE_CHECK**<br><br>0x08 | The function does not perform privilege checking. If the SEF_AVOID_OWNER_CHECK flag is also set, the *Token* parameter can be **NULL**. This flag is useful while implementing automatic inheritance to avoid checking privileges on each child updated. |
| **SEF_AVOID_OWNER_CHECK**<br><br>0x10 | The function does not check the validity of the owner in the resultant *NewDescriptor* as described in the Remarks section. If the SEF_AVOID_PRIVILEGE_CHECK flag is also set, the *Token* parameter can be **NULL**. |
| **SEF_DEFAULT_OWNER_FROM_PARENT**<br><br>0x20 | The owner of *NewDescriptor* defaults to the owner from *ParentDescriptor*. If not set, the owner of *NewDescriptor* defaults to the owner of the token specified by the *Token* parameter. The owner of the token is specified in the token itself. In either case, if the *CreatorDescriptor* parameter is not **NULL**, the *NewDescriptor* owner is set to the owner from *CreatorDescriptor*. |
| **SEF_DEFAULT_GROUP_FROM_PARENT**<br><br>0x40 | The group of *NewDescriptor* defaults to the group from *ParentDescriptor*. If not set, the group of *NewDescriptor* defaults to the group of the token specified by the *Token* parameter. The group of the token is specified in the token itself. In either case, if the *CreatorDescriptor* parameter is not **NULL**, the *NewDescriptor* group is set to the group from *CreatorDescriptor*. |
| **SEF_MACL_NO_WRITE_UP**<br><br>0x100 | A principal with a mandatory level lower than that of the object cannot write to the object. |
| **SEF_MACL_NO_READ_UP**<br><br>0x200 | A principal with a mandatory level lower than that of the object cannot read the object. |
| **SEF_MACL_NO_EXECUTE_UP**<br><br>0x400 | A principal with a mandatory level lower than that of the object cannot execute the object. |
| **SEF_AVOID_OWNER_RESTRICTION**<br><br>0x1000 | Any restrictions specified by the *ParentDescriptor* parameter that would limit the caller's ability to specify a DACL in the *CreatorDescriptor* are ignored. |

### `Token` [in, optional]

A handle to the [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) for the client [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) on whose behalf the object is being created. If this is an [impersonation token](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly), it must be at SecurityIdentification level or higher. For a full description of the SecurityIdentification impersonation level, see the
[SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-security_impersonation_level) enumerated type.

The client token contains default security information, such as the default owner, primary group, and DACL. This function uses these defaults if the information is not in the input security descriptors. The token must be open for **TOKEN_QUERY** access.

If all of the following conditions are true, then the handle must be opened for **TOKEN_DUPLICATE** access in addition to **TOKEN_QUERY** access.

* The token handle refers to a primary token.
* The security descriptor of the token contains one or more ACEs with the **OwnerRights** SID.
* A security descriptor is specified for the *CreatorDescriptor* parameter.
* The caller of this function does not set the **SEF_AVOID_OWNER_RESTRICTION** flag in the *AutoInheritFlags* parameter.

### `GenericMapping` [in]

A pointer to a
[GENERIC_MAPPING](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-generic_mapping) structure that specifies the mapping from each generic right to specific rights for the object.

## Return value

If the function succeeds, the function returns a nonzero value.

If the function fails, it returns zero. Call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) for extended error information. Some extended error codes and their meanings are listed in the following table.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PRIMARY_GROUP** | The function cannot retrieve a primary group for the new security descriptor. |
| **ERROR_INVALID_OWNER** | The function cannot retrieve an owner for the new security descriptor or the [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) cannot be assigned as an owner. This occurs when validating the owner SID against the passed-in token. |
| **ERROR_NO_TOKEN** | The function received **NULL** instead of a token for owner validation or [privilege](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) checking. |
| **ERROR_PRIVILEGE_NOT_HELD** | A SACL is being set, SEF_AVOID_PRIVILEGE_CHECK was not passed in, and the token passed in did not have SE_SECURITY_NAME enabled. |

## Remarks

The
[CreatePrivateObjectSecurityEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createprivateobjectsecurityex) function is identical to calling the
**CreatePrivateObjectSecurityWithMultipleInheritance** function with a single GUID in *ObjectTypes*.

The *AutoInheritFlags* are distinct from the similarly named bits in the **Control** member of the
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure. For an explanation of the control bits, see
[SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-control).

If *AutoInheritFlags* specifies the SEF_DACL_AUTO_INHERIT bit, the function applies the following rules to the DACL in the new security descriptor:

* The SE_DACL_AUTO_INHERITED flag is set in the **Control** member of the new security descriptor.
* The DACL of the new security descriptor inherits ACEs from *ParentDescriptor* regardless of whether *CreatorDescriptor* is the default security descriptor or was explicitly specified by the creator. The new DACL is a combination of the parent and creator DACLs as defined by the rules of inheritance. Specifically, any ACEs in *ParentDescriptor* that are inheritable either to all child objects or to any object class listed in *ObjectTypes* will be applied to the new DACL.
* Inherited ACEs are marked as INHERITED_ACE.

If *AutoInheritFlags* specifies the SEF_SACL_AUTO_INHERIT bit, the function applies similar rules to the new SACL.

For both DACLs and SACLs, certain types of ACEs in *ParentDescriptor* and *CreatorDescriptor* will be manipulated and possibly replaced by two ACEs in *NewDescriptor*. Specifically, an inheritable ACE that contains at least one of the following mappable elements may result in two ACEs in the output security descriptor. Mappable elements include:

* Generic access rights in the ACCESS_MASK
* Creator Owner SID or Creator Group SID as the ACE subject identifier

ACEs with any of these mappable elements will result in the following two ACEs in *NewDescriptor*:

* An ACE that is a copy of the original, but with the INHERIT_ONLY flag set. However, this ACE will not be created if either of the following two conditions exist:

  + The *IsContainerObject* parameter is **FALSE**. Inheritable ACEs are meaningless on noncontainer objects.
  + The original ACE contains the NO_PROPAGATE_INHERIT flag. The original ACE is intended to be inherited as an effective ACE on children, but not inheritable below those children.
* An effective ACE in which the INHERITED_ACE bit is turned on and the generic elements are mapped to specific elements:

  + Generic access rights are replaced by the corresponding standard and specific access rights indicated in the input *GenericMapping*.
  + Creator Owner SID is replaced with the Owner in the resultant *NewDescriptor*
  + Creator Group SID is replaced with the Group in the resultant *NewDescriptor*

If *AutoInheritFlags* does not specify the SEF_AVOID_OWNER_CHECK bit, owner validity checking is performed according to the following rules. The Owner in the resultant *NewDescriptor* must be a legally formed SID, and either must match the TokenUser in *Token* or must match a group in the TokenGroups in *Token*. The attributes on the group:

* Must include SE_GROUP_OWNER
* Must not include SE_GROUP_USE_FOR_DENY_ONLY

Callers that do not have access to the token of the client that will ultimately be setting the owner may choose to skip owner validation checking.

To create a security descriptor for a new object, call **CreatePrivateObjectSecurityWithMultipleInheritance** with *ParentDescriptor* set to the security descriptor of the parent container and *CreatorDescriptor* set to the security descriptor proposed by the creator of the object.

To verify the current security descriptor on an object, call **CreatePrivateObjectSecurityWithMultipleInheritance** with *ParentDescriptor* set to the security descriptor of the parent container and *CreatorDescriptor* set to the current security descriptor of the object. This call ensures that the ACEs are appropriately inherited from parent to child security descriptors.

If the *CreatorDescriptor* security descriptor contains a SACL, *Token* must have the SE_SECURITY_NAME privilege enabled or the caller must specify the SEF_AVOID_PRIVILEGE_CHECK flag in *AutoInheritFlags*.

## See also

[CreatePrivateObjectSecurityEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createprivateobjectsecurityex)

[DestroyPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-destroyprivateobjectsecurity)

[GENERIC_MAPPING](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-generic_mapping)

[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-control)

[SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-security_impersonation_level)