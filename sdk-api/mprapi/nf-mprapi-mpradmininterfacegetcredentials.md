# MprAdminInterfaceGetCredentials function

## Description

Use the
**MprAdminInterfaceGetCredentials** function to retrieve the domain, user name, and password for dialing out on the specified demand-dial interface.

## Parameters

### `lpwsServer` [in]

Pointer to a **null**-terminated Unicode string that specifies the name of the router on which to execute this call.

This parameter is optional. If the calling application specifies **NULL** for this parameter, the call is executed on the local machine.

### `lpwsInterfaceName` [in]

Pointer to a **null**-terminated Unicode string that specifies the name of the demand-dial interface. Use
[MprAdminInterfaceGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacegetinfo) to obtain the interface name.

### `lpwsUserName` [out]

Pointer to a Unicode string that receives the name of the user. This string should be UNLEN+1 long.

This parameter is optional. If the calling application specifies **NULL** for this parameter, the function does not return the user name.

### `lpwsPassword` [out]

Pointer to a Unicode string that receives the password. This string should be PWLEN+1 long.

This parameter is optional. If the calling application specifies **NULL** for this parameter, the function does not return the password.

### `lpwsDomainName` [out]

Pointer to a Unicode string that receives the domain name. This string should be DNLEN+1 long.

This parameter is optional. If the calling application specifies **NULL** for this parameter, the function does not return the domain name.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_CANNOT_FIND_PHONEBOOK_ENTRY** | The specified interface does not have any demand-dial parameters associated with it. |
| **ERROR_INVALID_PARAMETER** | The *lpwsInterfaceName* parameter is **NULL**. |
| **NO_ERROR** | The *lpwsUserName*, *lpwsPassword*, and *lpwsDomainName* parameters are all **NULL**. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## Remarks

The *lpwsUserName*, *lpwsPassword*, and *lpwsDomainName* parameters are optional. If the calling application specifies **NULL** for all three parameters,
**MprAdminInterfaceGetCredentials** returns NO_ERROR and the domain, user name, and password are not returned.

The constants UNLEN, PWLEN, and DNLEN are the maximum lengths for the user name, password, and domain name. These constants are defined in lmcons.h.

Note that the order of the parameters in
**MprAdminInterfaceGetCredentials** is different from
[MprAdminInterfaceSetCredentials](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacesetcredentials).

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[MprAdminInterfaceSetCredentials](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacesetcredentials)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)