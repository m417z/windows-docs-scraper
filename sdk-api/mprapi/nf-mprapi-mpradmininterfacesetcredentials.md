# MprAdminInterfaceSetCredentials function

## Description

Use
**MprAdminInterfaceSetCredentials** function to set the domain, user name, and password that will be used for dialing out on the specified demand-dial interface.

## Parameters

### `lpwsServer` [in]

Pointer to a **null**-terminated Unicode string that specifies the name of the router on which to execute this call.

This parameter is optional. If the calling application specifies **NULL** for this parameter, the call is executed on the local machine.

### `lpwsInterfaceName` [in]

Pointer to a **null**-terminated Unicode string that specifies the name of the demand-dial interface. Use
[MprAdminInterfaceGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacegetinfo) to obtain the interface name.

### `lpwsUserName` [in]

Pointer to a **null**-terminated Unicode string that specifies the user name.

This parameter is optional. If the calling application specifies **NULL** for this parameter, the function does not change the user name associated with this interface.

### `lpwsDomainName` [in]

Pointer to a **null**-terminated Unicode string that specifies the domain name.

This parameter is optional. If the calling application specifies **NULL** for this parameter, the function does not change the domain name associated with this interface.

### `lpwsPassword` [in]

Pointer to a **null**-terminated Unicode string that specifies the password.

This parameter is optional. If the calling application specifies **NULL** for this parameter, the function does not change the password associated with this interface.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | At least one of the following is true: <br><br>* The *lpwsInterfaceName* parameter is **NULL**, or it is longer than MAX_INTERFACE_NAME_LEN.<br>* At least one of the *lpwsUserName*, *lpwsPassword*, and *lpwsDomainName* parameters is too long, and therefore invalid. See the Remarks section for more information. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory to create a new data structure to contain the credentials. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## Remarks

The *lpwsUserName*, *lpwsPassword*, and *lpwsDomainName* parameters are optional. If the calling application specifies **NULL** for all three parameters,
**MprAdminInterfaceSetCredentials** removes all credential information for this interface.

The constants UNLEN, PWLEN, and DNLEN are the maximum lengths for the user name, password, and domain name. These constants are defined in Lmcons.h.

Note that the order of the parameters in
**MprAdminInterfaceSetCredentials** is different from
[MprAdminInterfaceGetCredentials](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacegetcredentials).

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[MprAdminInterfaceGetCredentials](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacegetcredentials)

[MprAdminInterfaceGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacegetinfo)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)