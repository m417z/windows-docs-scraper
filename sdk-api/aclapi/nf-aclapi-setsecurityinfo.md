# SetSecurityInfo function

## Description

The **SetSecurityInfo** function sets specified security information in the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of a specified object. The caller identifies the object by a handle.

To set the SACL of an object, the caller must have the **SE_SECURITY_NAME** privilege enabled.

## Parameters

### `handle` [in]

A handle to the object for which to set security information.

### `ObjectType` [in]

A member of the
[SE_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-se_object_type) enumeration that indicates the type of object identified by the *handle* parameter.

### `SecurityInfo` [in]

A set of
bit flags that indicate the type of security information to set. This parameter can be a combination of the
[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) bit flags.

### `psidOwner` [in, optional]

A pointer to a SID that identifies the owner of the object. The SID must be one that can be assigned as the owner SID of a security descriptor. The *SecurityInfo* parameter must include the OWNER_SECURITY_INFORMATION flag. This parameter can be **NULL** if you are not setting the owner SID.

### `psidGroup` [in, optional]

A pointer to a SID that identifies the primary group of the object. The *SecurityInfo* parameter must include the GROUP_SECURITY_INFORMATION flag. This parameter can be **NULL** if you are not setting the primary group SID.

### `pDacl` [in, optional]

A pointer to the new DACL for the object. This parameter is ignored unless the value of the *SecurityInfo* parameter includes the **DACL_SECURITY_INFORMATION** flag. If the value of the *SecurityInfo* parameter includes the **DACL_SECURITY_INFORMATION** flag and the value of this parameter is set to **NULL**, full access to the object is granted to everyone. For information about **null** DACLs, see [Creating a DACL](https://learn.microsoft.com/windows/desktop/SecBP/creating-a-dacl).

### `pSacl` [in, optional]

A pointer to the new SACL for the object. The *SecurityInfo* parameter must include any of the following flags: SACL_SECURITY_INFORMATION, LABEL_SECURITY_INFORMATION, ATTRIBUTE_SECURITY_INFORMATION, SCOPE_SECURITY_INFORMATION, or BACKUP_SECURITY_INFORMATION. If setting SACL_SECURITY_INFORMATION or SCOPE_SECURITY_INFORMATION, the caller must have the SE_SECURITY_NAME privilege enabled. This parameter can be **NULL** if you are not setting the SACL.

## Return value

If the function succeeds, the function returns ERROR_SUCCESS.

If the function fails, it returns a nonzero error code defined in WinError.h.

## Remarks

If you are setting the [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) or any elements in the [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) of an object, the system automatically propagates any inheritable [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs) to existing child objects, according to the
[ACE inheritance rules](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace-inheritance-rules).

You can use the **SetSecurityInfo** function with the following types of objects:

* Local or remote files or directories on an NTFS
* Named pipes
* Local or remote printers
* Local or remote Windows services
* Network shares
* Registry keys
* Semaphores, events, mutexes, and waitable timers
* Processes, threads, jobs, and file-mapping objects
* Window stations and desktops
* Directory service objects

The **SetSecurityInfo** function does not reorder access-allowed or access-denied ACEs based on the preferred order. When propagating inheritable ACEs to existing child objects, **SetSecurityInfo** puts inherited ACEs in order after all of the noninherited ACEs in the DACLs of the child objects.

**Note** If share access to the children of the object is not available, this function will not propagate unprotected ACEs to the children. For example, if a directory is opened with exclusive access, the operating system will not propagate unprotected ACEs to the subdirectories or files of that directory when the security on the directory is changed.

**Warning** If the supplied *handle* was opened with an [ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask) value of **MAXIMUM_ALLOWED**, then the **SetSecurityInfo** function will not propagate ACEs to children.

## See also

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[GetNamedSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getnamedsecurityinfoa)

[GetSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getsecurityinfo)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information)

[SE_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-se_object_type)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)

[SetNamedSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setnamedsecurityinfoa)