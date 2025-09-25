# MprAdminGetIpAddressForUser function

## Description

RAS calls
the **MprAdminGetIpAddressForUser** function once for each user that requires an IP address. RAS calls the function with the IP address that RAS selects for the user. The third-party DLL that implements this function can change this address to one of its own choosing.

## Parameters

### `lpwszUserName` [in]

Pointer to a Unicode string that specifies the name of the user that requires an IP address.

### `lpwszPortName` [in]

Pointer to a Unicode string that specifies the name of the port on which the user is attempting to connect.

### `lpdwIpAddress` [in, out]

On input, pointer to a **DWORD** variable that contains zero or the IP address RAS allocated for the user.

On output, if RAS specified zero, the DLL allocates an IP address for the user. In this case, if the DLL does not allocate an IP address, the user is not able to connect. If RAS specified an IP address, the DLL either accepts the address or substitutes a different one.

### `bNotifyRelease` [out]

Pointer to a **BOOL** variable. If the DLL sets this variable to **TRUE**, RAS calls
[MprAdminReleaseIpAddress](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminreleaseipaddress) when the user disconnects. Otherwise, RAS does not notify the DLL when this IP address is released.

## Return value

If function succeeds, the return value should be NO_ERROR.

If the function returns anything other than NO_ERROR, RAS will terminate the connection.

## Remarks

RAS supports multiple Administration DLLs. However, RAS calls
**MprAdminGetIpAddressForUser** only in the first DLL that implements and export it. RAS ignores implementations of these functions in the other DLLs. RAS checks the DLLs for these functions in the order in which they are listed in the
[registry](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-dll-registry-setup).

An administration DLL need not implement the
**MprAdminGetIpAddressForUser** function. However, if the DLL implements
**MprAdminGetIpAddressForUser**, it must also implement
[MprAdminReleaseIpAddress](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminreleaseipaddress).

Do not call any of the
[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions) or
[RAS User Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-user-administration-functions) from inside
**MprAdminGetIpAddressForUser**. Calls to these functions will not return when made from within a callout function.

## See also

[MprAdminReleaseIpAddress](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminreleaseipaddress)

[RAS Administration DLL](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-dll)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)