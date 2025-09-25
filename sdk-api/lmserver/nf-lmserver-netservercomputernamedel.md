# NetServerComputerNameDel function

## Description

The
**NetServerComputerNameDel** function causes the specified server to cease supporting the emulated server name set by a previous call to the
[NetServerComputerNameAdd](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservercomputernameadd) function. The function does this by unbinding network transports from the emulated name.

## Parameters

### `ServerName` [in]

Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `EmulatedServerName` [in]

Pointer to a null-terminated character string that contains the emulated name the server should stop supporting. The server continues to support all other server names it was supporting.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_INVALID_PARAMETER** | The specified parameter is invalid. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory is available. |
| **NERR_NetNameNotFound** | The share name does not exist. |

## Remarks

Only members of the Administrators or Server Operators local group can successfully execute the
**NetServerComputerNameDel** function.

## See also

[NetServerComputerNameAdd](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservercomputernameadd)

[NetServerTransportAdd](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportadd)

[NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex)

[NetServerTransportEnum](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportenum)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Server
Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-functions)