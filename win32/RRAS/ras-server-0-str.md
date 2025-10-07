# RAS\_SERVER\_0 structure

\[The **RAS\_SERVER\_0** structure is not supported as of Windows Vista.\]

The **RAS\_SERVER\_0** structure is used by the [**RasAdminServerGetInfo**](https://learn.microsoft.com/windows/win32/rras/rasadminservergetinfo) function to return information about the ports configured on a RAS server.

## Members

**TotalPorts**

Specifies the total number of ports configured on the RAS server that are available for remote clients to connect to. For example, if the total number of ports configured for dialing in to a server is four, but one of the ports is currently in use for dialing out, **TotalPorts** is three.

**PortsInUse**

Specifies the number of ports currently in use by remote clients.

**RasVersion**

Specifies the version of the RAS server. Use this information to take version-specific action. This member is one of the following values.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------|
|

**RASDOWNLEVEL**

| Indicates a LAN Manager version 1.0 RAS server.<br> |
|

**RASADMIN\_35**

| Indicates a Windows NT Server 3.51 and earlier RAS server or client.<br> |
|

**RASADMIN\_CURRENT**

| Indicates a Windows NT 4.0 RAS server or client.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| End of client support<br> | Windows XP<br> |
| End of server support<br> | Windows Server 2003<br> |
| Header<br> | Rassapi.h |

## See also

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/win32/rras/about-remote-access-service)

[RAS Server Administration Structures](https://learn.microsoft.com/windows/win32/rras/ras-server-administration-structures)

[**RasAdminServerGetInfo**](https://learn.microsoft.com/windows/win32/rras/rasadminservergetinfo)

