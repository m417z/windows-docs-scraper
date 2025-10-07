# RAS\_PORT\_0 structure

\[This version of the **RAS\_PORT\_0** structure is not supported as of Windows Vista. Use the newer [**RAS\_PORT\_0**](https://learn.microsoft.com/windows/desktop/api/Mprapi/ns-mprapi-ras_port_0) defined in mprapi.h instead.\]

The **RAS\_PORT\_0** structure contains information that describes a RAS port.

## Members

**wszPortName**

A null-terminated Unicode string that specifies the name of the port, such as "COM1".

**wszDeviceType**

A null-terminated Unicode string that specifies the type of the device on which the connection was made, such as Modem or ISDN. The list of device types that might be specified in this member includes all the device types installed on the server, including third-party devices.

**wszDeviceName**

A null-terminated Unicode string that specifies the name of the device on which the connection was made, such as "Hayes 9600" or "PCIMACISDN1".

**wszMediaName**

Specifies a null-terminated Unicode string that specifies the name of the media used for the connection, such as *rasser* or *rastapi*.

**reserved**

Reserved.

**Flags**

Specifies a set of bit flags that specify the nature of the connection made on this port. This member can be a combination of the following flags.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GATEWAY\_ACTIVE** | If this flag is set, the NetBIOS gateway is active on the server.<br> |
| **MESSENGER\_PRESENT** | If this flag is set, the messenger service is running on the remote client.<br> |
| **PORT\_MULTILINKED** | If this flag is set, the port is multilinked with other ports. Use this information to display the connection status as a multilinked port. <br> For a multilinked port, the [**RAS\_PORT\_STATISTICS**](https://learn.microsoft.com/windows/win32/rras/ras-port-statistics-str) structure contains two sets of statistics: one for the port alone, and another for the combined ports in the multilink connection.<br> |
| **PPP\_CLIENT** | If this flag is set, the remote client connected using PPP. If this flag is not set, the remote client connected using the AMB protocol.<br> |
| **REMOTE\_LISTEN** | If this flag is set, the RemoteListen parameter of the NetBIOS gateway is set to 1 on the server.<br> |
| **USER\_AUTHENTICATED** | If this flag is set, a remote client is connected to the server and the user has been authenticated. Check this flag to ensure that a client is actually connected to a port.<br> |

If the MESSENGER\_PRESENT, GATEWAY\_ACTIVE, and REMOTE\_LISTEN flags are set, use the messenger service to send an administrative message to the remote client. If MESSENGER\_PRESENT and REMOTE\_LISTEN are set, but GATEWAY\_ACTIVE is not, send messages to the client only from the RAS server to which the client is connected.

**wszUserName**

A null-terminated Unicode string that specifies the name of the remote user connected to this port.

**wszComputer**

A null-terminated Unicode string that specifies the name of the remote client computer.

**dwStartSessionTime**

Specifies the time, in seconds from January 1, 1970, that the client connected to the RAS server on this port. Use the standard time functions to format this value for display.

**wszLogonDomain**

Specifies a null-terminated Unicode string that specifies the name of the domain on which the remote user was authenticated. This string is the domain name only, with no "\\\\" prefix.

**fAdvancedServer**

Specifies a flag that is nonzero if the RAS server associated with this port is an advanced server such as Windows 2000 Advanced Server. Use this information to determine the name of the server that has the user account database. If the RAS server is an advanced server, get the name of the user account server by concatenating the prefix "\\\\" to the name returned in the **wszLogonDomain** member. This is because for an advanced server the local logon domain name is the same as the server name. If the RAS server is a workstation, use the [**RasAdminGetUserAccountServer**](https://learn.microsoft.com/windows/win32/rras/rasadmingetuseraccountserver) function to get the name of the user account server.

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

[**RAS\_PORT\_1**](https://learn.microsoft.com/windows/win32/rras/ras-port-1-str)

[**RAS\_PORT\_STATISTICS**](https://learn.microsoft.com/windows/win32/rras/ras-port-statistics-str)

[**RasAdminGetUserAccountServer**](https://learn.microsoft.com/windows/win32/rras/rasadmingetuseraccountserver)

[**RasAdminPortEnum**](https://learn.microsoft.com/windows/win32/rras/rasadminportenum)

