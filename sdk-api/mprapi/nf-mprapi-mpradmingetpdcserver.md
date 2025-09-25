# MprAdminGetPDCServer function

## Description

The
**MprAdminGetPDCServer** function retrieves the name of the server with the master User Accounts Subsystem (UAS) from either a domain name or a server name. Either the domain name parameter or the server name parameter may be **NULL**, but not both.

## Parameters

### `lpszDomain` [in]

Pointer to a null-terminated Unicode string that specifies the name of the domain to which the RAS server belongs. This parameter can be **NULL** if you are running your RAS administration application on a Windows NT/Windows 2000 server that is not participating in a domain. If this parameter is **NULL**, the *lpwsServerName* parameter must not be **NULL**.

### `lpszServer` [in]

Pointer to a null-terminated Unicode string that specifies the name of the Windows NT/Windows 2000 RAS server. Specify the name with leading "\\" characters, in the form: **\\servername**. This parameter can be **NULL** if the *lpwsDomain* parameter is not **NULL**.

### `lpszPDCServer` [out]

Pointer to a buffer that receives a null-terminated Unicode string that contains the name of a domain controller that has the user account database. The buffer should be big enough to hold the server name (UNCLEN +1). The function prefixes the returned server name with leading "\\" characters, in the form: **\\servername**.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails the return value is one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_NO_SUCH_DOMAIN** | The domain specified is not valid. |
| **NERR_InvalidComputer** | The *lpwsDomainName* parameter is **NULL**, and *lpwsServerName* parameter is not valid. |

## Remarks

The
**MprAdminGetPDCServer** function can obtain the name of the server with the user accounts database given the name of the RAS server, or the name of the domain in which the RAS server resides. To get the server name, call the
[GetComputerName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcomputernamea) function

If the server name specified by *lpszServer* is part of a domain, The server returned by
**MprAdminGetPDCServer** will be either the primary domain controller or a backup domain controller.

If the server name specified by *lpszServer* is a stand-alone Windows NT/Windows 2000 server (that is, the server or workstation does not participate in a domain), then the server name itself is returned in the *lpszUserAccountServer* buffer.

You can then use the name of the user account server in a call to the
[NetQueryDisplayInformation](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netquerydisplayinformation) function to enumerate the users in the user account database. You can also use the server name in calls to the
[MprAdminUserGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminusergetinfo) and
[MprAdminUserSetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminusersetinfo) functions to get and set RAS privileges for a specified user account.

## See also

[GetComputerName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcomputernamea)

[MprAdminUserGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminusergetinfo)

[MprAdminUserSetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminusersetinfo)

[NetQueryDisplayInformation](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netquerydisplayinformation)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)