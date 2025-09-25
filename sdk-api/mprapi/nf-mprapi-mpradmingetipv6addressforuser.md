# MprAdminGetIpv6AddressForUser function

## Description

RAS calls
the *MprAdminGetIpv6AddressForUser* function once for each user that requires an IPv6 address. RAS calls the function with the IPv6 address that RAS selects for the user. The third-party DLL that implements this function can change this address to one of its own choosing.

## Parameters

### `lpwszUserName` [in]

Pointer to a Unicode string that specifies the name of the user that requires an IP address.

### `lpwszPortName` [in]

Pointer to a Unicode string that specifies the name of the port on which the user is attempting to connect.

### `lpdwIpv6Address` [in, out]

Pointer to an [in6_addr](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms738560(v=vs.85)) structure that contains zero or the IPv6 address RAS allocated for the user.

Currently, only 64 bit identifiers are supported.

On output, if RAS specified zero, the DLL allocates an IPv6 address for the user. In this case, if the DLL does not allocate an IPv6 address, the user is not able to connect. If RAS specified an IPv6 address, the DLL either accepts the address or substitutes a different one.

### `bNotifyRelease` [out]

Pointer to a **BOOL** variable. If the DLL sets this variable to **TRUE**, RAS calls
[MprAdminReleaseIpv6AddressForUser](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminreleaseipv6addressforuser) when the user disconnects. Otherwise, RAS does not notify the DLL when this IP address is released.

## Return value

If function succeeds, the return value should be NO_ERROR.

If the function returns anything other than NO_ERROR, RAS will terminate the connection.

## Remarks

An administration DLL need not implement the
*MprAdminGetIpv6AddressForUser* function. However, if the DLL implements
*MprAdminGetIpv6AddressForUser*, it must also implement
[MprAdminReleaseIpv6AddressForUser](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminreleaseipv6addressforuser).

## See also

[MprAdminReleaseIpv6AddressForUser](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminreleaseipv6addressforuser)

[RAS Administration DLL](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-dll)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)