# PFAXACCESSCHECK callback function

## Description

A fax client application calls the **FaxAccessCheck** function to query the fax access privileges of a user.

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies a fax server handle returned by a call to the [FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera) function.

### `AccessMask` [in]

Type: **DWORD**

Specifies a **DWORD** variable that contains a set of bit flags defining a user's fax access permissions. This parameter can be one or more of the following generic access permissions: FAX_READ, FAX_WRITE, and FAX_ALL_ACCESS. It can also be one or more of the following specific access permissions:

* FAX_JOB_SUBMIT
* FAX_JOB_QUERY
* FAX_CONFIG_QUERY
* FAX_CONFIG_SET
* FAX_PORT_QUERY
* FAX_PORT_SET
* FAX_JOB_MANAGE

For a detailed description of these values, see [Generic Fax Access Rights](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-generic-fax-access-rights) and [Specific Fax Access Rights](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-specific-fax-access-rights).

## Return value

Type: **BOOL**

If the user has the required permission, the return value is nonzero.

If the user does not have the required permission, the return value is zero, and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_SUCCESS.

If the function fails, the return value is also zero, but [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns an error code other than ERROR_SUCCESS.

## Remarks

The fax service is a secure service. Users must have certain access privileges to successfully call fax service functions. Call the **FaxAccessCheck** function to programmatically check a user's fax access permissions. For more information, see [Checking the Access Rights of Users](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-checking-the-access-rights-of-users) and [Fax Client User Access Rights](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-client-user-access-rights).

The fax service administration application, a Microsoft Management Console (MMC) snap-in component, is also available for users to query and modify job access, port access, and global configuration data access privileges.

## See also

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera)