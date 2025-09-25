# GetNamedSecurityInfoA function

## Description

The **GetNamedSecurityInfo** function retrieves a copy of the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) for an object specified by name.

## Parameters

### `pObjectName` [in]

A pointer to a null-terminated string that specifies the name of the object from which to retrieve security information. For descriptions of the string formats for the different object types, see
[SE_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-se_object_type).

### `ObjectType` [in]

Specifies a value from the [SE_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-se_object_type) enumeration that indicates the type of object named by the *pObjectName* parameter.

### `SecurityInfo` [in]

A set of
bit flags that indicate the type of security information to retrieve. This parameter can be a combination of the
[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) bit flags.

### `ppsidOwner` [out, optional]

A pointer to a variable that receives a pointer to the owner SID in the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) returned in *ppSecurityDescriptor* or **NULL** if the security descriptor has no owner SID. The returned pointer is valid only if you set the OWNER_SECURITY_INFORMATION flag. Also, this parameter can be **NULL** if you do not need the owner SID.

### `ppsidGroup` [out, optional]

A pointer to a variable that receives a pointer to the primary group SID in the returned security descriptor or **NULL** if the security descriptor has no group SID. The returned pointer is valid only if you set the GROUP_SECURITY_INFORMATION flag. Also, this parameter can be **NULL** if you do not need the group SID.

### `ppDacl` [out, optional]

A pointer to a variable that receives a pointer to the DACL in the returned security descriptor or **NULL** if the security descriptor has no DACL. The returned pointer is valid only if you set the DACL_SECURITY_INFORMATION flag. Also, this parameter can be **NULL** if you do not need the DACL.

### `ppSacl` [out, optional]

A pointer to a variable that receives a pointer to the SACL in the returned security descriptor or **NULL** if the security descriptor has no SACL. The returned pointer is valid only if you set the SACL_SECURITY_INFORMATION flag. Also, this parameter can be **NULL** if you do not need the SACL.

### `ppSecurityDescriptor` [out, optional]

A pointer to a variable that receives a pointer to the security descriptor of the object. When you have finished using the pointer, free the returned buffer by calling the
[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

This parameter is required if any one of the *ppsidOwner*, *ppsidGroup*, *ppDacl*, or *ppSacl* parameters is not **NULL**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in WinError.h.

## Remarks

If any of the *ppsidOwner*, *ppsidGroup*, *ppDacl*, or *ppSacl* parameters are non-**NULL**, and the *SecurityInfo* parameter specifies that they be retrieved from the object, those parameters will point to the corresponding parameters in the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) returned in *ppSecurityDescriptor*. If the security descriptor does not contain the requested information, the corresponding parameter will be set to **NULL**.

To read the owner, group, or DACL from the object's security descriptor, the object's DACL must grant READ_CONTROL access to the caller, or the caller must be the owner of the object.

To read the system access control list of the object, the SE_SECURITY_NAME privilege must be enabled for the calling process. For information about the security implications of enabling privileges, see [Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

You can use the **GetNamedSecurityInfo** function with the following types of objects:

* Local or remote files or directories on an NTFS file system
* Local or remote printers
* Local or remote Windows services
* Network shares
* Registry keys
* Semaphores, events, mutexes, and waitable timers
* File-mapping objects
* Directory service objects

This function does not handle race conditions. If your thread calls this function at the approximate time that another thread changes the object's security descriptor, then this function could fail.

This function transfers information in plaintext. The information transferred by this function is signed unless signing has been turned off for the system, but no encryption is performed.

For more information about controlling access to objects through user accounts, group accounts, or logon sessions, see [How DACLs Control Access to an Object](https://learn.microsoft.com/windows/desktop/SecAuthZ/how-dacls-control-access-to-an-object).

#### Examples

For an example that uses **GetNamedSecurityInfo**, see [Modifying the ACLs of an Object](https://learn.microsoft.com/windows/desktop/SecAuthZ/modifying-the-acls-of-an-object-in-c--).

> [!NOTE]
> The aclapi.h header defines GetNamedSecurityInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[GetSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getsecurityinfo)

[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree)

[Privilege Constants](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-constants)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information)

[SE_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-se_object_type)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)

[SetNamedSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setnamedsecurityinfoa)

[SetSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setsecurityinfo)