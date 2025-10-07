# RAS\_PPP\_IPCP\_RESULT structure

\[The **RAS\_PPP\_IPCP\_RESULT** structure is not supported as of Windows Vista.\]

The **RAS\_PPP\_IPCP\_RESULT** structure is used to report the result of a PPP Internet Protocol (IP) projection operation for a port.

## Members

**dwError**

Indicates the results of the IP projection operation. A value of NO\_ERROR indicates success, in which case, the **wszAddress** member is valid. If the projection operation was not successful, **dwError** is an error code from Winerror.h or Raserror.h.

**wszAddress**

A null-terminated Unicode string that specifies the IP address assigned to the remote client. This string has the form *a***.***b***.***c***.***d*.

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

