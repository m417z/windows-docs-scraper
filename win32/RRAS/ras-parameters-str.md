# RAS\_PARAMETERS structure

\[The **RAS\_PARAMETERS** structure is not supported as of Windows Vista.\]

The **RAS\_PARAMETERS** structure is used by the [**RasAdminPortGetInfo**](https://learn.microsoft.com/windows/win32/rras/rasadminportgetinfo) function to return the name and value of a media-specific parameter associated with a port on a RAS server.

## Members

**P\_Key**

Specifies the name of the key that represents the media-specific parameter, such as MAXCONNECTBPS.

**P\_Type**

Identifies the type of data associated with the parameter. This member can be one of the following values from the [**RAS\_PARAMS\_FORMAT**](https://learn.microsoft.com/windows/win32/rras/ras-params-format-str) enumeration.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------|
|

**ParamNumber**

| Indicates that the data associated with the key is a number.<br> |
|

**ParamString**

| Indicates that the data associated with the key is a string.<br> |

**P\_Attributes**

Reserved.

**P\_Value**

Specifies the value associated with the parameter. This member is a [**RAS\_PARAMS\_VALUE**](https://learn.microsoft.com/windows/win32/rras/ras-params-value-str) union. If the **P\_Type** member is ParamNumber, the **Number** member of the union contains the value. If **P\_Type** is ParamString, the **String** member of the union contains the value.

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

[**RasAdminAcceptNewConnection**](https://learn.microsoft.com/windows/win32/rras/rasadminacceptnewconnection)

[**RasAdminConnectionHangupNotification**](https://learn.microsoft.com/windows/win32/rras/rasadminconnectionhangupnotification)

[**RasAdminPortGetInfo**](https://learn.microsoft.com/windows/win32/rras/rasadminportgetinfo)

