# NetServerComputerNameAdd function

## Description

The
**NetServerComputerNameAdd** function enumerates the transports on which the specified server is active, and binds the emulated server name to each of the transports.

**NetServerComputerNameAdd** is a utility function that combines the functionality of the
[NetServerTransportEnum](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportenum) function and the
[NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex) function.

## Parameters

### `ServerName` [in]

Pointer to a string that specifies the name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `EmulatedDomainName` [in]

Pointer to a string that contains the domain name the specified server should use when announcing its presence using the *EmulatedServerName*. This parameter is optional.

### `EmulatedServerName` [in]

Pointer to a null-terminated character string that contains the emulated name the server should begin supporting in addition to the name specified by the *ServerName* parameter.

## Return value

If the function succeeds, the return value is NERR_Success. Note that
**NetServerComputerNameAdd** succeeds if the emulated server name specified is added to at least one transport.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_DUP_NAME** | A duplicate name exists on the network. |
| **ERROR_INVALID_DOMAINNAME** | The domain name could not be found on the network. |
| **ERROR_INVALID_PARAMETER** | The specified parameter is invalid. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory is available. |

## Remarks

Only members of the Administrators or Server Operators local group can successfully execute the
**NetServerComputerNameAdd** function.

The server specified by the *ServerName* parameter continues to support all names it was supporting, and additionally begins to support new names supplied by successful calls to the
**NetServerComputerNameAdd** function.

Name emulation that results from a call to
**NetServerComputerNameAdd** ceases when the server reboots or restarts. To discontinue name emulation set by a previous call to
**NetServerComputerNameAdd** without restarting or rebooting, you can call the
[NetServerComputerNameDel](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservercomputernamedel) function.

The
**NetServerComputerNameAdd** function is typically used when a system administrator replaces a server, but wants to keep the conversion transparent to users.

#### Examples

Following is an example of a call to the **NetServerComputerNameAdd** function requesting that \\Server1 also respond to requests for \\Server2.

```cpp
NetServerComputerNameAdd (Server1, NULL, Server2);

```

## See also

[NetServerComputerNameDel](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservercomputernamedel)

[NetServerTransportAdd](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportadd)

[NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex)

[NetServerTransportEnum](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportenum)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Server
Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-functions)