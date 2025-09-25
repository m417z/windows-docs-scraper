# SetPrivateObjectSecurityEx function

## Description

The **SetPrivateObjectSecurityEx** function modifies the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of a private object maintained by the resource manager calling this function. The **SetPrivateObjectSecurityEx** function has a flags parameter that specifies whether the resource manager supports automatic inheritance of [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs).

## Parameters

### `SecurityInformation` [in]

The parts of the security descriptor to set. This value can be a combination of the
[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) bit flags.

### `ModificationDescriptor` [in]

A pointer to a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure. The parts of this security descriptor indicated by the *SecurityInformation* parameter are applied to the *ObjectsSecurityDescriptor* security descriptor.

### `ObjectsSecurityDescriptor` [in, out]

A pointer to a pointer to a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure. This security descriptor must be in [self-relative](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) form. **The memory for the security descriptor must be allocated from the process heap (GetProcessHeap) with the HeapAlloc function.**

On input, this is the current security descriptor of the private object. The function modifies it to produce the new security descriptor. If necessary, the **SetPrivateObjectSecurityEx** function allocates additional memory to produce a larger security descriptor.

### `AutoInheritFlags` [in]

Specifies automatic inheritance of ACEs. If the protected server does not implement automatic inheritance, it should specify zero; otherwise, it can specify a combination of the following values, defined in Winnt.h.

| Value | Meaning |
| --- | --- |
| **SEF_DACL_AUTO_INHERIT**<br><br>0x01 | The new [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) contains ACEs inherited from the DACL of the object's parent, as well as any explicit ACEs specified in the DACL of *ModificationDescriptor*. If this flag is not set, the new DACL does not inherit ACEs. |
| **SEF_SACL_AUTO_INHERIT**<br><br>0x02 | The new [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) contains ACEs inherited from the SACL of the security descriptor associated with the object's parent, as well as any explicit ACEs specified in the SACL of *ModificationDescriptor*. If this flag is not set, the new SACL does not inherit ACEs. |
| **SEF_AVOID_PRIVILEGE_CHECK**<br><br>0x08 | The function does not perform privilege checking. If the **SEF_AVOID_OWNER_CHECK** flag is also set, the *Token* parameter can be **NULL**. Use this flag when implementing automatic inheritance to avoid checking privileges on each child updated. |
| **SEF_AVOID_OWNER_CHECK**<br><br>0x10 | The function does not check the validity of the owner in the resultant *ObjectsSecurityDescriptor* as described in Remarks. If the **SEF_AVOID_PRIVILEGE_CHECK** flag is also set, the *Token* parameter can be **NULL**. |
| **SEF_DEFAULT_OWNER_FROM_PARENT**<br><br>0x20 | The owner of *ObjectsSecurityDescriptor* defaults to the owner of the object's parent. If this flag is not set, the owner of *ObjectsSecurityDescriptor* defaults to the owner of the token specified by the *Token* parameter. The owner of the token is specified in the token itself. In either case, if the *ModificationDescriptor* parameter is not **NULL**, the *ObjectsSecurityDescriptor* owner is set to the owner from *ModificationDescriptor*. |
| **SEF_DEFAULT_GROUP_FROM_PARENT**<br><br>0x40 | The group of *ObjectsSecurityDescriptor* defaults to the group from the owner of the object's parent. If this flag is not set, the group of *ObjectsSecurityDescriptor* defaults to the group of the token specified by the *Token* parameter. The group of the token is specified in the token itself. In either case, if the *ModificationDescriptor* parameter is not **NULL**, the *ObjectsSecurityDescriptor* group is set to the group from *ModificationDescriptor*. |
| **SEF_MACL_NO_WRITE_UP**<br><br>0x100 | A principal with a mandatory level lower than that of the object cannot write to the object. |
| **SEF_MACL_NO_READ_UP**<br><br>0x200 | A principal with a mandatory level lower than that of the object cannot read the object. |
| **SEF_MACL_NO_EXECUTE_UP**<br><br>0x400 | A principal with a mandatory level lower than that of the object cannot execute the object. |
| **SEF_AVOID_OWNER_RESTRICTION**<br><br>0x1000 | Any restrictions specified by the owner of the object's parent that would limit the caller's ability to specify a DACL in the *ObjectsSecurityDescriptor* are ignored. |

### `GenericMapping` [in]

A pointer to a
[GENERIC_MAPPING](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-generic_mapping) structure that specifies the specific and standard access rights that correspond to each of the generic access rights.

### `Token` [in, optional]

Identifies the [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) for the client on whose behalf the private object's security is being modified. This parameter is required to ensure that the client has provided a legitimate value for a new owner [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID). The token must be open for TOKEN_QUERY access.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the *AutoInheritFlags* parameter is zero, **SetPrivateObjectSecurityEx** is identical to the
[SetPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setprivateobjectsecurity) function.

This function is intended for use by resource managers only. To implement the standard Windows access control semantics for updating security descriptors, a resource manager should verify that the following conditions are met before calling **SetPrivateObjectSecurityEx**:

* If the object's owner is being set, the calling [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) must have either WRITE_OWNER permission or be the object's owner.
* If the object's DACL is being set, the calling process must have either WRITE_DAC permission or be the object's owner.
* If the object's SACL is being set, the SE_SECURITY_NAME privilege must be enabled for the calling process.

If the preceding conditions are not met, a call to this function does not fail, however, standard Windows access policy is not enforced.

The process calling this function should not be impersonating a client because clients do not typically have appropriate privileges required for underlying token operations.

If *AutoInheritFlags* specifies the SEF_DACL_AUTO_INHERIT bit, the function applies the following rules to the DACL to create the new security descriptor from the current descriptor:

* If the SE_DACL_PROTECTED flag is not set in the control bits of either the current security descriptor or the *ModificationDescriptor*, the function constructs the output security descriptor from the inherited ACEs of the current security descriptor and noninherited ACEs of *ModificationDescriptor*. That is, it is impossible to change an inherited ACE by changing the [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL) on an object. This behavior preserves the inherited ACEs as they were inherited from the parent container.

  An ACL editor should make inherited ACEs unavailable to prevent them from being modified.
* If SE_DACL_PROTECTED is set in
  *ModificationDescriptor*, the current security descriptor is ignored. The output security descriptor is built as a copy of
  *ModificationDescriptor* with any INHERITED_ACE bits turned off.

  Ideally an ACL editor should turn off the INHERITED_ACE bits that indicate to its caller that the ACEs inherited from the object's parent are now being explicitly set on the object.
* If SE_DACL_PROTECTED is set in the current security descriptor and not in
  *ModificationDescriptor*, the current security descriptor is ignored. The output security descriptor is built as a copy of
  *ModificationDescriptor*. It is the caller's responsibility to ensure that the correct ACEs have the INHERITED_ACE bit turned on.

If *AutoInheritFlags* specifies the SEF_SACL_AUTO_INHERIT bit, the function applies similar rules to the new SACL.

For both DACLs and SACLs, certain types of ACEs in the input *ObjectsSecurityDescriptor* and in *ModificationDescriptor* will be replaced by two ACEs in the output *ObjectsSecurityDescriptor*. Specifically, an inheritable ACE that contains at least one of the following mappable elements will result in two ACEs in the output *ObjectsSecurityDescriptor*. Mappable elements include:

* Generic access rights in the [ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask) structure
* Creator Owner SID or Creator Group SID as the ACE subject identifier

ACEs with any of these mappable elements will result in the following two ACEs in the output *ObjectsSecurityDescriptor*:

* An ACE that is a copy of the original, but with the INHERIT_ONLY flag set
* An ACE in which the INHERITED_ACE bit is turned on and the generic elements are mapped to specific elements:

  + Generic access rights are replaced by the corresponding standard and specific access rights indicated in the input *GenericMapping*.
  + Creator Owner SID is replaced with the Owner in the output *SecurityDescriptor*
  + Creator Group SID is replaced with the Group in the output *SecurityDescriptor*

If *AutoInheritFlags* does not specify the SEF_AVOID_PRIVILEGE_CHECK bit, owner validity checking is performed according to the following rules. The Owner in *ModificationDescriptor*:

* Must be a legally formed SID
* Must match the TokenUser in *Token*

Or

* Must match a group in the TokenGroups in *Token* where the attributes on the group:

  + Include SE_GROUP_OWNER
  + Include SE_GROUP_USE_FOR_DENY_ONLY

A resource manager that is setting the Owner on a subtree of objects can avoid the overhead of redundant owner validity checking. If the Owner in *ModificationDescriptor* and *Token* remain the same for iterative calls to this function, the SEF_AVOID_PRIVILEGE_CHECK bit may be set in *AutoInheritFlags* for calls subsequent to an initial call in which owner validity checking is performed. Callers that do not have access to the token of the client that will ultimately be setting the owner should also choose to skip owner validation checking.

**Note** The SEF_AVOID_PRIVILEGE_CHECK bit as used in the
**SetPrivateObjectSecurityEx** function is equivalent to the SEF_AVOID_OWNER_CHECK bit used in the
[CreatePrivateObjectSecurityEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createprivateobjectsecurityex) function.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask)

[Client/Server Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[Client/Server Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)

[CreatePrivateObjectSecurityEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createprivateobjectsecurityex)

[DestroyPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-destroyprivateobjectsecurity)

[GENERIC_MAPPING](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-generic_mapping)

[GetPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getprivateobjectsecurity)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information)

[SetFileSecurity](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setfilesecuritya)

[SetKernelObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setkernelobjectsecurity)

[SetPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setprivateobjectsecurity)

[SetUserObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setuserobjectsecurity)