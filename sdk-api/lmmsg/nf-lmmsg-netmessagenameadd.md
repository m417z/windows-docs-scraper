# NetMessageNameAdd function

## Description

[This function is not supported as of Windows Vista because the messenger service is not supported.]

The
**NetMessageNameAdd** function registers a message alias in the message name table. The function requires that the messenger service be started.

## Parameters

### `servername` [in]

Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `msgname` [in]

Pointer to a constant string that specifies the message alias to add. The string cannot be more than 15 characters long.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have the appropriate access to complete the operation. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. |
| **ERROR_NOT_SUPPORTED** | This request is not supported. This error is returned on Windows Vista and later. |
| **NERR_AlreadyExists** | The message alias already exists on this computer. For more information, see the following Remarks section. |
| **NERR_DuplicateName** | The name specified is already in use as a message alias on the network. |
| **NERR_NetworkError** | A general failure occurred in the network hardware. |
| **NERR_TooManyNames** | The maximum number of message aliases has been exceeded. |

## Remarks

Only members of the Administrators local group can successfully execute the
**NetMessageNameAdd** function on a remote server.

The forward action flag is no longer a parameter to the LAN Manager 2.*x***NetMessageNameAdd** function because message forwarding is no longer supported. If the
**NetMessageNameAdd** function detects that a forwarded version of *msgname* exists on the network, the function will fail with error NERR_Already_Exists.

## See also

[Message
Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/message-functions)

[NetMessageNameDel](https://learn.microsoft.com/windows/desktop/api/lmmsg/nf-lmmsg-netmessagenamedel)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)