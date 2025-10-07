# RAS\_PPP\_ATCP\_RESULT structure

\[The **RAS\_PPP\_ATCP\_RESULT** structure is not supported as of Windows Vista.\]

The **RAS\_PPP\_ATCP\_RESULT** structure is used to report the result of an AppleTalk protocol projection operation for a port.

## Members

**dwError**

Specifies a value that indicates the results of the AppleTalk projection operation. A value of NO\_ERROR indicates success, in which case, the **wszAddress** member is valid. If the projection operation is not successful, **dwError** is an error code from Winerror.h or Raserror.h.

**wszAddress**

Specifies a null-terminated Unicode string that specifies the IP address assigned to the remote client.

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

[**RAS\_PPP\_PROJECTION\_RESULT**](https://learn.microsoft.com/windows/win32/rras/ras-ppp-projection-result-str)

