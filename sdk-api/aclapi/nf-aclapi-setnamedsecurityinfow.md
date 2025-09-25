# SetNamedSecurityInfoW function

## Description

The **SetNamedSecurityInfo** function sets specified security information in the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of a specified object. The caller identifies the object by name.

## Parameters

### `pObjectName` [in]

A pointer to a **null**-terminated string that specifies the name of the object for which to set security information. This can be the name of a local or remote file or directory on an NTFS file system, network share, registry key, semaphore, event, mutex, file mapping, or waitable timer.

For descriptions of the string formats for the different object types, see
[SE_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-se_object_type).

### `ObjectType` [in]

A value of the [SE_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-se_object_type) enumeration that indicates the type of object named by the *pObjectName* parameter.

### `SecurityInfo` [in]

A set of
bit flags that indicate the type of security information to set. This parameter can be a combination of the [SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) bit flags.

### `psidOwner` [in, optional]

A pointer to a [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure that identifies the owner of the object. If the caller does not have the **SeRestorePrivilege** constant (see [Privilege Constants](https://learn.microsoft.com/windows/desktop/SecAuthZ/privilege-constants)), this **SID** must be contained in the caller's token, and must have the **SE_GROUP_OWNER** permission enabled. The *SecurityInfo* parameter must include the OWNER_SECURITY_INFORMATION flag. To set the owner, the caller must have WRITE_OWNER access to the object or have the SE_TAKE_OWNERSHIP_NAME privilege enabled. If you are not setting the owner **SID**, this parameter can be **NULL**.

### `psidGroup` [in, optional]

A pointer to a SID that identifies the primary group of the object. The *SecurityInfo* parameter must include the GROUP_SECURITY_INFORMATION flag. If you are not setting the primary group SID, this parameter can be **NULL**.

### `pDacl` [in, optional]

A pointer to the new DACL for the object. The *SecurityInfo* parameter must include the DACL_SECURITY_INFORMATION flag. The caller must have WRITE_DAC access to the object or be the owner of the object. If you are not setting the DACL, this parameter can be **NULL**.

### `pSacl` [in, optional]

A pointer to the new SACL for the object. The *SecurityInfo* parameter must include any of the following flags: SACL_SECURITY_INFORMATION, LABEL_SECURITY_INFORMATION, ATTRIBUTE_SECURITY_INFORMATION, SCOPE_SECURITY_INFORMATION, or BACKUP_SECURITY_INFORMATION.

If setting SACL_SECURITY_INFORMATION or SCOPE_SECURITY_INFORMATION, the caller must have the SE_SECURITY_NAME privilege enabled. If you are not setting the SACL, this parameter can be **NULL**.

## Return value

If the function succeeds, the function returns ERROR_SUCCESS.

If the function fails, it returns a nonzero error code defined in WinError.h.

## Remarks

 If you are setting the [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) or any elements in the [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) of an object, the system automatically propagates any inheritable [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs) to existing child objects, according to the
[rules of inheritance](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace-inheritance-rules).

You can use the **SetNamedSecurityInfo** function with the following types of objects:

* Local or remote files or directories on an NTFS
* Local or remote printers
* Local or remote Windows services
* Network shares
* Registry keys
* Semaphores, events, mutexes, and waitable timers
* File-mapping objects
* Directory service objects

The **SetNamedSecurityInfo** function does not reorder access-allowed or access-denied ACEs based on the preferred order. When propagating inheritable ACEs to existing child objects, **SetNamedSecurityInfo** puts inherited ACEs in order after all of the noninherited ACEs in the DACLs of the child objects.

This function transfers information in [plaintext](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). The information transferred by this function is signed unless signing has been turned off for the system, but no encryption is performed.

When you update access rights of a folder indicated by an UNC path, for example \\Test\TestFolder, the original inherited ACE is removed and the full volume path is not included.

#### Examples

For an example that uses this function, see [Modifying the ACLs of an Object](https://learn.microsoft.com/windows/desktop/SecAuthZ/modifying-the-acls-of-an-object-in-c--) or [Taking Object Ownership](https://learn.microsoft.com/windows/desktop/SecAuthZ/taking-object-ownership-in-c--).

> [!NOTE]
> The aclapi.h header defines SetNamedSecurityInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

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

[SetSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setsecurityinfo)