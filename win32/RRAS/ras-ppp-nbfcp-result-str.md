# RAS\_PPP\_NBFCP\_RESULT structure

\[The **RAS\_PPP\_NBFCP\_RESULT** structure is not supported as of Windows Vista.\]

The **RAS\_PPP\_NBFCP\_RESULT** structure is used to report the result of a PPP NetBEUI Framer (NBF) projection operation for a port.

## Members

**dwError**

Indicates the results of the NBF projection operation. A value of NO\_ERROR indicates success, in which case, the **wszWksta** member contains the name of the remote computer. If the projection operation was not successful, **dwError** is an error code from Winerror.h or Raserror.h.

**dwNetBiosError**

Ignore this member on the server; it is relevant only on the client.

**szName**

Ignore this member on the server; it is relevant only on the client.

**wszWksta**

A null-terminated Unicode string that specifies the NetBIOS name of the RAS client workstation.

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

[**RAS\_PPP\_PROJECTION\_RESULT**](https://learn.microsoft.com/windows/win32/rras/ras-ppp-projection-result-str)

[**RasAdminPortGetInfo**](https://learn.microsoft.com/windows/win32/rras/rasadminportgetinfo)

