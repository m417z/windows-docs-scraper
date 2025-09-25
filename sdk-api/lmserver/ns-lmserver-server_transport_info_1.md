# SERVER_TRANSPORT_INFO_1 structure

## Description

The
**SERVER_TRANSPORT_INFO_1** structure contains information about the specified transport protocol, including name and address. This information level is valid only for the
[NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex) function.

## Members

### `svti1_numberofvcs`

Type: **DWORD**

The number of clients connected to the server that are using the transport protocol specified by the **svti1_transportname** member.

### `svti1_transportname`

Type: **LMSTR**

A pointer to a null-terminated character string that contains the name of a transport device; for example,

``` syntax
\Device\NetBT_Tcpip_{2C9725F4-151A-11D3-AEEC-C3B211BD350B}

```

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

### `svti1_transportaddress`

Type: **LPBYTE**

A pointer to a variable that contains the address the server is using on the transport device specified by the **svti1_transportname** member.

This member is usually the NetBIOS name that the server is using. In these instances, the name must be 16 characters long, and the last character must be a blank character (0x20).

### `svti1_transportaddress.size_is`

### `svti1_transportaddress.size_is.svti1_transportaddresslength`

### `svti1_transportaddresslength`

Type: **DWORD**

The length, in bytes, of the **svti1_transportaddress** member. For NetBIOS names, the value of this member is 16 (decimal).

### `svti1_networkaddress`

Type: **LMSTR**

A pointer to a NULL-terminated character string that contains the address the network adapter is using. The string is transport-specific.

You can retrieve this value only with a call to the
[NetServerTransportEnum](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportenum) function. You cannot set this value with a call to the
[NetServerTransportAdd](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportadd) function or the
[NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex) function.)

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

### `svti1_domain`

Type: **LMSTR**

A pointer to a NULL-terminated character string that contains the name of the domain to which the server should announce its presence. (When you call
[NetServerTransportEnum](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportenum), this member is the name of the domain to which the server is announcing its presence.)

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

## Remarks

The
**SERVER_TRANSPORT_INFO_1** structure is used by the [NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex) function to bind the specified server to the transport protocol.

## See also

[NetServerComputerNameAdd](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservercomputernameadd)

[NetServerComputerNameDel](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservercomputernamedel)

[NetServerTransportAdd](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportadd)

[NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex)

[NetServerTransportDel](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportdel)

[NetServerTransportEnum](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportenum)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[SERVER_TRANSPORT_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_0)

[SERVER_TRANSPORT_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_2)

[SERVER_TRANSPORT_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_3)

[Server and Workstation Transport Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-and-workstation-transport-functions)