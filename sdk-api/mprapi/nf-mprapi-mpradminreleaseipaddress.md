# MprAdminReleaseIpAddress function

## Description

The
**MprAdminReleaseIpAddress** function is called when a user disconnects and the user's IP address is about to be released.

## Parameters

### `lpszUserName` [in]

Pointer to a Unicode string that specifies the name of the user that requires an IP address.

### `lpszPortName` [in]

Pointer to a Unicode string that specifies the name of the port on which the user is attempting to connect.

### `lpdwIpAddress` [in]

Pointer to a **DWORD** variable. This variable specifies the IP address to be released.

## Remarks

An administration DLL need not implement the
**MprAdminReleaseIpAddress** function. However, if the DLL implements
**MprAdminReleaseIpAddress**, it must also implement
[MprAdminGetIpAddressForUser](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmingetipaddressforuser).

RAS supports multiple Administration DLLs. However, RAS calls
**MprAdminReleaseIpAddress** only in the first DLL that implements and export it. RAS ignores implementations of these functions in the other DLLs. RAS checks the DLLs for these functions in the order in which they are listed in the
[registry](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-dll-registry-setup).

**Windows 2000 Server or earlier:** If RAS does not accept the new link, RAS does not call the
[MprAdminLinkHangupNotification](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminlinkhangupnotification) function.

Do not call any of the
[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions) or
[RAS User Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-user-administration-functions) from inside
**MprAdminReleaseIpAddress**. Calls to these functions do not return when made from within a callout function.

## See also

[MprAdminConnectionHangupNotification](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionhangupnotification)

[MprAdminGetIpAddressForUser](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmingetipaddressforuser)

[RAS Administration DLL](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-dll)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)