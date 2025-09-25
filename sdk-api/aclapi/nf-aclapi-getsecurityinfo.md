# GetSecurityInfo function

## Description

The **GetSecurityInfo** function retrieves a copy of the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) for an object specified by a handle.

## Parameters

### `handle` [in]

A handle to the object from which to retrieve security information.

### `ObjectType` [in]

[SE_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-se_object_type) enumeration value that indicates the type of object.

### `SecurityInfo` [in]

A set of
bit flags that indicate the type of security information to retrieve. This parameter can be a combination of the
[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) bit flags.

### `ppsidOwner` [out, optional]

A pointer to a variable that receives a pointer to the owner SID in the security descriptor returned in *ppSecurityDescriptor*. The returned pointer is valid only if you set the OWNER_SECURITY_INFORMATION flag. This parameter can be **NULL** if you do not need the owner SID.

### `ppsidGroup` [out, optional]

A pointer to a variable that receives a pointer to the primary group SID in the returned [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). The returned pointer is valid only if you set the GROUP_SECURITY_INFORMATION flag. This parameter can be **NULL** if you do not need the group SID.

### `ppDacl` [out, optional]

A pointer to a variable that receives a pointer to the DACL in the returned security descriptor. The returned pointer is valid only if you set the DACL_SECURITY_INFORMATION flag. This parameter can be **NULL** if you do not need the DACL.

### `ppSacl` [out, optional]

A pointer to a variable that receives a pointer to the SACL in the returned security descriptor. The returned pointer is valid only if you set the SACL_SECURITY_INFORMATION flag. This parameter can be **NULL** if you do not need the SACL.

### `ppSecurityDescriptor` [out, optional]

A pointer to a variable that receives a pointer to the security descriptor of the object. When you have finished using the pointer, free the returned buffer by calling the
[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

This parameter is required if any one of the *ppsidOwner*, *ppsidGroup*, *ppDacl*, or *ppSacl* parameters is not **NULL**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in WinError.h.

## Remarks

If the *ppsidOwner*, *ppsidGroup*, *ppDacl*, and *ppSacl* parameters are non-**NULL**, and the *SecurityInfo* parameter specifies that they be retrieved from the object, those parameters will point to the corresponding parameters in the security descriptor returned in *ppSecurityDescriptor*.

To read the owner, group, or DACL from the object's security descriptor, the calling process must have been granted READ_CONTROL access when the handle was opened. To get READ_CONTROL access, the caller must be the owner of the object or the object's DACL must grant the access.

To read the SACL from the security descriptor, the calling process must have been granted ACCESS_SYSTEM_SECURITY access when the handle was opened. The proper way to get this access is to enable the SE_SECURITY_NAME privilege in the caller's current token, open the handle for ACCESS_SYSTEM_SECURITY access, and then disable the privilege. For information about the security implications of enabling privileges, see [Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

You can use the **GetSecurityInfo** function with the following types of objects:

* Local or remote files or directories on an NTFS file system
* Named pipes
* Local or remote printers
* Local or remote Windows services
* Network shares
* Registry keys
* Semaphores, events, mutexes, and waitable timers
* Processes, threads, jobs, and file-mapping objects
* Interactive service window stations and desktops
* Directory service objects

This function does not handle race conditions. If your thread calls this function at the approximate time that another thread changes the object's security descriptor, then this function could fail.

#### Examples

For an example that uses this function, see
[Finding the Owner of a File Object](https://learn.microsoft.com/windows/desktop/SecAuthZ/finding-the-owner-of-a-file-object-in-c--).

## See also

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[GetNamedSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getnamedsecurityinfoa)

[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree)

[Privilege Constants](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-constants)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information)

[SE_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-se_object_type)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)

[SetNamedSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setnamedsecurityinfoa)

[SetSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setsecurityinfo)