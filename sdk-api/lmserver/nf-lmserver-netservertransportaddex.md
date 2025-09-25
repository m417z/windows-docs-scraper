# NetServerTransportAddEx function

## Description

The
**NetServerTransportAddEx** function binds the specified server to the transport protocol. This extended function allows the calling application to specify the
[SERVER_TRANSPORT_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_0), [SERVER_TRANSPORT_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_1),
[SERVER_TRANSPORT_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_2), or
[SERVER_TRANSPORT_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_3) information levels.

## Parameters

### `servername` [in]

A pointer to a string that specifies the name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `level` [in]

Specifies a value that indicates the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Specifies information about the transport protocol, including name, address, and location on the network. The *bufptr* parameter points to a [SERVER_TRANSPORT_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_0) structure. |
| **1** | Specifies information about the transport protocol, including name, address, network location, and domain. The *bufptr* parameter points to a [SERVER_TRANSPORT_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_1) structure. |
| **2** | Specifies the same information as level 1, with the addition of an **svti2_flags** member. The *bufptr* parameter points to a [SERVER_TRANSPORT_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_2) structure. |
| **3** | Specifies the same information as level 2, with the addition of credential information. The *bufptr* parameter points to a [SERVER_TRANSPORT_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_3) structure. |

### `bufptr` [in]

A pointer to the buffer that contains the data. The format of this data depends on the value of the *level* parameter.

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
| **ERROR_INVALID_PARAMETER** | A parameter is invalid. <br><br>This error is returned if the transport name or transport address member in the [SERVER_TRANSPORT_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_0), [SERVER_TRANSPORT_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_1), [SERVER_TRANSPORT_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_2), or [SERVER_TRANSPORT_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_3) structure pointed to by the *bufptr* parameter is **NULL**. This error is also returned if the transport address length member in the **SERVER_TRANSPORT_INFO_0**, **SERVER_TRANSPORT_INFO_1**, **SERVER_TRANSPORT_INFO_2**, or **SERVER_TRANSPORT_INFO_3** structure pointed to by the *bufptr* parameter is zero or larger than MAX_PATH (defined in the *Windef.h* header file). This error is also returned if the flags member of the **SERVER_TRANSPORT_INFO_2**, or **SERVER_TRANSPORT_INFO_3** structure pointed to by the *bufptr* parameter contains an illegal value.<br><br>This error is also returned for other invalid parameters. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory is available. |

## Remarks

Only members of the Administrators or Server Operators local group can successfully execute the
**NetServerTransportAddEx** function.

If you add a transport protocol to a server using a call to the
**NetServerTransportAddEx** function, the connection will not remain after the server reboots or restarts.

The
[NetServerComputerNameAdd](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservercomputernameadd) function is a utility function. It combines the features of the
[NetServerTransportEnum](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportenum) function and the
**NetServerTransportAddEx** function, allowing you to specify an emulated server name.

On Windows Server 2008 and Windows Vista with Service Pack 1 (SP1), every name registered with the Windows remote file server (SRV) is designated as either a scoped name or a non-scoped name. Every share that is added to the system will then either be attached to all of the non-scoped names, or to a single scoped name. Applications that wish to use the scoping features are responsible for both registering the new name as a scoped endpoint and then creating the shares with an appropriate scope. In this way, legacy uses of the Network Management and Network Share Management functions are not affected in any way since they continue to register shares and names as non-scoped names.

A scoped endpoint is created by calling the **NetServerTransportAddEx** function with the *level* parameter set to 2 and the *bufptr* parameter pointed to a [SERVER_TRANSPORT_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_2) structure with the **SVTI2_SCOPED_NAME** bit value set in **svti2_flags** member. A scoped endpoint is also created by calling the **NetServerTransportAddEx** function with the *level* parameter set to 3 and the *bufptr* parameter pointed to a [SERVER_TRANSPORT_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_3) structure with the **SVTI2_SCOPED_NAME** bit value set in **svti3_flags** member.

When the **SVTI2_SCOPED_NAME** bit value is set for a transport, then shares can be added with a corresponding server name (the **shi503_servername** member of the [SHARE_INFO_503](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_503) structure) in a scoped fashion using the [NetShareAdd](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netshareadd) function. If there is no transport registered with the **SVTI2_SCOPED_NAME** bit value and the name provided in **shi503_servername** member, then the share add in a scoped fashion will not succeed.

The [NetShareAdd](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netshareadd) function is used to add a scoped share on a remote server specified in the *servername* parameter. The remote server specified in the **shi503_servername** member of the [SHARE_INFO_503](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_503) passed in the *bufptr* parameter must have been bound to a transport protocol using the **NetServerTransportAddEx** function as a scoped endpoint. The **SVTI2_SCOPED_NAME** flag must have been specified in the **shi503_servername** member of the [SERVER_TRANSPORT_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_2) or [SERVER_TRANSPORT_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_3) structure for the transport protocol. The [NetShareDelEx](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharedelex) function is used to delete a scoped share. The [NetShareGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharegetinfo) and [NetShareSetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharesetinfo) functions are to used to get and set information on a scoped share.

Scoped endpoints are generally used by the cluster namespace.

## See also

[NetServerComputerNameAdd](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservercomputernameadd)

[NetServerComputerNameDel](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservercomputernamedel)

[NetServerTransportAdd](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportadd)

[NetServerTransportDel](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportdel)

[NetServerTransportEnum](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportenum)

[NetShareAdd](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netshareadd)

[NetShareDelEx](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharedelex)

[NetShareGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharegetinfo)

[NetShareSetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharesetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[SERVER_TRANSPORT_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_0)

[SERVER_TRANSPORT_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_1)

[SERVER_TRANSPORT_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_2)

[SERVER_TRANSPORT_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_3)

[SHARE_INFO_503](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_503)

[Server and Workstation Transport Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-and-workstation-transport-functions)