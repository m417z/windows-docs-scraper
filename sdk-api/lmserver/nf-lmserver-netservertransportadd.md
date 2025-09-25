# NetServerTransportAdd function

## Description

The
**NetServerTransportAdd** function binds the server to the transport protocol.

The extended function
[NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex) allows the calling application to specify the
[SERVER_TRANSPORT_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_1),
[SERVER_TRANSPORT_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_2), and
[SERVER_TRANSPORT_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_3) information levels.

## Parameters

### `servername` [in]

A pointer to a string that specifies the name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `level` [in]

Specifies the information level of the data. This parameter can be the following value.

| Value | Meaning |
| --- | --- |
| **0** | Specifies information about the transport protocol, including name, address, and location on the network. The *bufptr* parameter points to a [SERVER_TRANSPORT_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_0) structure. |

### `bufptr` [in]

A pointer to the buffer that contains the data.

For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers).

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_DUP_NAME** | A duplicate name exists on the network. |
| **ERROR_INVALID_DOMAINNAME** | The domain name could not be found on the network. |
| **ERROR_INVALID_LEVEL** | The value specified for the *level* parameter is invalid. |
| **ERROR_INVALID_PARAMETER** | A parameter is invalid. <br><br>This error is returned if the **svti0_transportname** or **svti0_transportaddress** member in the [SERVER_TRANSPORT_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_0) structure pointed to by the *bufptr* parameter is **NULL**. This error is also returned if the **svti0_transportaddresslength** member in the **SERVER_TRANSPORT_INFO_0** structure pointed to by the *bufptr* parameter is zero or larger than MAX_PATH (defined in the Windef.h header file). <br><br>This error is also returned for other invalid parameters. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory is available. |

## Remarks

Only members of the Administrators or Server Operators local group can successfully execute the
**NetServerTransportAdd** function.

If you add a transport protocol to a server using a call to the
**NetServerTransportAdd** function, the connection will not remain after the server reboots or restarts.

## See also

[NetServerComputerNameAdd](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservercomputernameadd)

[NetServerComputerNameDel](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservercomputernamedel)

[NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex)

[NetServerTransportDel](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportdel)

[NetServerTransportEnum](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportenum)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[SERVER_TRANSPORT_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_0)

[SERVER_TRANSPORT_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_1)

[SERVER_TRANSPORT_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_2)

[SERVER_TRANSPORT_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_3)

[Server and Workstation Transport Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-and-workstation-transport-functions)