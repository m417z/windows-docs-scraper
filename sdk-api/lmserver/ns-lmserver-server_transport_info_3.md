# SERVER_TRANSPORT_INFO_3 structure

## Description

The
**SERVER_TRANSPORT_INFO_3** structure contains information about the specified transport protocol, including name, address and password (credentials). This information level is valid only for the
[NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex) function.

## Members

### `svti3_numberofvcs`

Type: **DWORD**

The number of clients connected to the server that are using the transport protocol specified by the **svti3_transportname** member.

### `svti3_transportname`

Type: **LMSTR**

A pointer to a NULL-terminated character string that contains the name of a transport device; for example,

``` syntax
\Device\NetBT_Tcpip_{2C9725F4-151A-11D3-AEEC-C3B211BD350B}

```

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

### `svti3_transportaddress`

Type: **LPBYTE**

A pointer to a variable that contains the address the server is using on the transport device specified by the **svti3_transportname** member.

This member is usually the NetBIOS name that the server is using. In these instances, the name must be 16 characters long, and the last character must be a blank character (0x20).

### `svti3_transportaddress.size_is`

### `svti3_transportaddress.size_is.svti3_transportaddresslength`

### `svti3_transportaddresslength`

Type: **DWORD**

The length, in bytes, of the **svti3_transportaddress** member. For NetBIOS names, the value of this member is 16 (decimal).

### `svti3_networkaddress`

Type: **LMSTR**

A pointer to a NULL-terminated character string that contains the address the network adapter is using. The string is transport-specific.

You can retrieve this value only with a call to the
[NetServerTransportEnum](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportenum) function. You cannot set this value with a call to the
[NetServerTransportAdd](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportadd) function or the
[NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex) function.)

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

### `svti3_domain`

Type: **LMSTR**

A pointer to a NULL-terminated character string that contains the name of the domain to which the server should announce its presence. (When you call
[NetServerTransportEnum](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportenum), this member is the name of the domain to which the server is announcing its presence.)

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

### `svti3_flags`

Type: **ULONG**

This member can be a combination of the following bit values defined in the *Lmserver.h* header file.

| Value | Meaning |
| --- | --- |
| **SVTI2_REMAP_PIPE_NAMES** | If this value is set for an endpoint, client requests arriving over the transport to open a named pipe are rerouted (remapped) to the following local pipe name:<br><br>**$$\ServerName\PipeName**<br><br>For more information on the use of this value, see the Remarks section. |
| **SVTI2_SCOPED_NAME** | If this value is set for an endpoint and there is an attempt to create a second transport with the same network address but a different transport name and conflicting settings for the SCOPED flag, this transport creation will fail. Thus, every registered transport for a given network address must have the same scoped setting.<br><br>For more information on the use of this value, see the Remarks section.<br><br>This value is defined on Windows Server 2008 and Windows Vista with SP1. |

### `svti3_passwordlength`

Type: **DWORD**

The number of valid bytes in the **svti3_password** member.

### `svti3_password`

Type: **BYTE[256]**

The credentials to use for the new transport address. If the **svti3_passwordlength** member is zero, the credentials for the server are used.

## Remarks

The
**SERVER_TRANSPORT_INFO_3** structure is used by the [NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex) function to bind the specified server to the transport protocol.

An example of the use of the SVTI2_REMAP_PIPE_NAMES value follows. Call the
[NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex) function to add a transport to the server, specifying the address of "MyServer" in the **svti3_transportaddress** member, and **SVTI2_REMAP_PIPE_NAMES** in the **svti3_flags** member. When a client attempts to open "Pipe" on "\\MyServer" the client will actually open $$MyServer\Pipe instead.

The **svti3_passwordlength** and **svti3_password** members are necessary for a client and server to perform mutual authentication.

On Windows Server 2008 and Windows Vista with SP1, every name registered with the Windows remote file server (SRV) is designated as either a scoped name or a non-scoped name. Every share that is added to the system will then either be attached to all of the non-scoped names, or to a single scoped name. Applications that wish to use the scoping features are responsible for both registering the new name as a scoped endpoint and then creating the shares with an appropriate scope. In this way, legacy uses of the Network Management and Network Share Management functions are not affected in any way since they continue to register shares and names as non-scoped names.

A scoped endpoint is created by calling the [NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex) function with the *level* parameter set to 2 and the *bufptr* parameter pointed to a [SERVER_TRANSPORT_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_2) structure with the **SVTI2_SCOPED_NAME** bit value set in **svti2_flags** member. A scoped endpoint is also created by calling the **NetServerTransportAddEx** function with the *level* parameter set to 3 and the *bufptr* parameter pointed to a **SERVER_TRANSPORT_INFO_3** structure with the **SVTI2_SCOPED_NAME** bit value set in **svti3_flags** member.

When the **SVTI2_SCOPED_NAME** bit value is set for a transport, then shares can be added with a corresponding server name (the **shi503_servername** member of the [SHARE_INFO_503](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_503) structure) in a scoped fashion using the [NetShareAdd](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netshareadd) function. If there is no transport registered with the **SVTI2_SCOPED_NAME** bit value and the name provided in **shi503_servername** member, then the share add in a scoped fashion will not succeed.

The [NetShareAdd](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netshareadd) function is used to add a scoped share on a remote server specified in the *servername* parameter. The remote server specified in the **shi503_servername** member of the [SHARE_INFO_503](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_503) passed in the *bufptr* parameter must have been bound to a transport protocol using the [NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex) function as a scoped endpoint. The **SVTI2_SCOPED_NAME** flag must have been specified in the **shi503_servername** member of the [SERVER_TRANSPORT_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_2) or **SERVER_TRANSPORT_INFO_3** structure for the transport protocol. The [NetShareDelEx](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharedelex) function is used to delete a scoped share. The [NetShareGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharegetinfo) and [NetShareSetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharesetinfo) functions are to used to get and set information on a scoped share.

Scoped endpoints are generally used by the cluster namespace.

## See also

[NetServerTransportAdd](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportadd)

[NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex)

[NetServerTransportDel](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportdel)

[NetServerTransportEnum](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportenum)

[NetShareAdd](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netshareadd)

[NetShareDelEx](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharedelex)

[NetShareGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharegetinfo)

[NetShareSetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharesetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[SERVER_TRANSPORT_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_0)

[SERVER_TRANSPORT_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_1)

[SERVER_TRANSPORT_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_2)

[SHARE_INFO_503](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_503)

[Server and Workstation Transport Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-and-workstation-transport-functions)