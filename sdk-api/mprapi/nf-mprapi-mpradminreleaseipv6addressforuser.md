# MprAdminReleaseIpv6AddressForUser function

## Description

The
*MprAdminReleaseIpv6AddressForUser* function is called once for each user that needs to release an IPv6 address.

## Parameters

### `lpszUserName` [in]

Pointer to a Unicode string that specifies the name of the user that disconnected.

### `lpszPortName` [in]

Pointer to a Unicode string that specifies the name of the port on which the user disconnected.

### `lpdwIpv6Address` [in]

Pointer to an [IN6_ADDR](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms738560(v=vs.85)) structure. This variable specifies the IPv6 address to be released.

## Return value

If function succeeds, the return value should be NO_ERROR.

If the function returns anything other than NO_ERROR, RAS will terminate the connection.

## Remarks

An administration DLL need not implement the
*MprAdminReleaseIpv6AddressForUser* function. However, if the DLL implements
*MprAdminReleaseIpv6AddressForUser*, it must also implement
[MprAdminGetIpv6AddressForUser](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmingetipv6addressforuser).

## See also

[MprAdminConnectionHangupNotification](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionhangupnotification)

[MprAdminGetIpv6AddressForUser](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmingetipv6addressforuser)

[RAS Administration DLL](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-dll)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)