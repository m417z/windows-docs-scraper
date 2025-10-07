# RAS\_PORT\_1 structure

\[This version of the **RAS\_PORT\_1** structure is not supported as of Windows Vista. Use the newer [**RAS\_PORT\_1**](https://learn.microsoft.com/windows/desktop/api/Mprapi/ns-mprapi-ras_port_1) defined in mprapi.h instead.\]

The **RAS\_PORT\_1** structure contains information about a RAS port.

## Members

**rasport0**

Specifies a [**RAS\_PORT\_0**](https://learn.microsoft.com/windows/win32/rras/ras-port-0-str) structure that contains information about the port, such as the name of the port, the name of the remote user connected to the port, and so on.

**LineCondition**

Specifies the state of the port. This member can be one of the following values.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**RAS\_PORT\_NON\_OPERATIONAL**

| The port is not operational. Check the event log for errors reported by the server.<br> |
|

**RAS\_PORT\_DISCONNECTED**

| The port is currently disconnected.<br> |
|

**RAS\_PORT\_CALLING\_BACK**

| The RAS server is calling back the RAS client.<br> |
|

**RAS\_PORT\_LISTENING**

| The port is waiting for a client to call in.<br> |
|

**RAS\_PORT\_AUTHENTICATING**

| The server is in the process of authenticating the remote client.<br> |
|

**RAS\_PORT\_AUTHENTICATED**

| The remote client is now authenticated.<br> |
|

**RAS\_PORT\_INITIALIZING**

| The device attached to the port is being initialized. The state of the port will change to RAS\_PORT\_LISTENING when the initialization has been completed.<br> |

**HardwareCondition**

Specifies one of the following values to indicate the state of the device attached to the port.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------|
|

**RAS\_MODEM\_OPERATIONAL**

| The modem attached to this port is operational and is ready to receive client calls.<br> |
|

**RAS\_MODEM\_HARDWARE\_FAILURE**

| The modem attached to this port has a hardware problem.<br> |

**LineSpeed**

Specifies the speed, in bits per second, with which the computer can communicate with the port.

**NumStatistics**

This member is not used. The RAS administration functions, such as the [**RasAdminPortGetInfo**](https://learn.microsoft.com/windows/win32/rras/rasadminportgetinfo) function, use the [**RAS\_PORT\_STATISTICS**](https://learn.microsoft.com/windows/win32/rras/ras-port-statistics-str) structure to return port statistics.

**NumMediaParms**

Specifies the number of media-specific parameters for this port. For serial media this is typically the number of values that appear in the SERIAL.INI file.

**SizeMediaParms**

Specifies the size, in bytes, of the buffer required for all media-specific parameters. The [**RasAdminPortGetInfo**](https://learn.microsoft.com/windows/win32/rras/rasadminportgetinfo) function returns a buffer that contains an array of [**RAS\_PARAMETERS**](https://learn.microsoft.com/windows/win32/rras/ras-parameters-str) structures with the media parameters and values for the port.

**ProjResult**

A [**RAS\_PPP\_PROJECTION\_RESULT**](https://learn.microsoft.com/windows/win32/rras/ras-ppp-projection-result-str) structure that specifies the PPP projection information for this port. This structure provides information for each protocol that is negotiated when a RAS client connects to a server.

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

[**RAS\_PARAMETERS**](https://learn.microsoft.com/windows/win32/rras/ras-parameters-str)

[**RAS\_PORT\_0**](https://learn.microsoft.com/windows/win32/rras/ras-port-0-str)

[**RAS\_PORT\_STATISTICS**](https://learn.microsoft.com/windows/win32/rras/ras-port-statistics-str)

[**RAS\_PPP\_PROJECTION\_RESULT**](https://learn.microsoft.com/windows/win32/rras/ras-ppp-projection-result-str)

[**RasAdminAcceptNewConnection**](https://learn.microsoft.com/windows/win32/rras/rasadminacceptnewconnection)

[**RasAdminConnectionHangupNotification**](https://learn.microsoft.com/windows/win32/rras/rasadminconnectionhangupnotification)

[**RasAdminPortGetInfo**](https://learn.microsoft.com/windows/win32/rras/rasadminportgetinfo)

