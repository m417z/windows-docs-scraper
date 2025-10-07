# RAS\_PPP\_PROJECTION\_RESULT structure

\[The **RAS\_PPP\_PROJECTION\_RESULT** structure is not supported as of Windows Vista.\]

The **RAS\_PPP\_PROJECTION\_RESULT** structure is used to report the results of the various PPP projection operations for a port.

## Members

**nbf**

A [**RAS\_PPP\_NBFCP\_RESULT**](https://learn.microsoft.com/windows/win32/rras/ras-ppp-nbfcp-result-str) structure that reports the result of a PPP NetBEUI Framer (NBF) projection operation.

**ip**

A [**RAS\_PPP\_IPCP\_RESULT**](https://learn.microsoft.com/windows/win32/rras/ras-ppp-ipcp-result-str) structure that reports the result of a PPP Internet Protocol (IP) projection operation.

**ipx**

A [**RAS\_PPP\_IPXCP\_RESULT**](https://learn.microsoft.com/windows/win32/rras/ras-ppp-ipxcp-result-str) structure that reports the result of a PPP Internetwork Packet Exchange (IPX) projection operation.

**at**

A [**RAS\_PPP\_ATCP\_RESULT**](https://learn.microsoft.com/windows/win32/rras/ras-ppp-atcp-result-str) structure.

## Remarks

This structure reports the projection results for NetBEUI, TCP/IP, and IPX protocols. Each PPP structure has a **dwError** member that indicates whether the other information in the structure is valid. If **dwError** is NO\_ERROR, the other information is valid. If **dwError** is one of the error codes in Winerror.h or Raserror.h, the other information is not valid.

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

[**RAS\_PPP\_ATCP\_RESULT**](https://learn.microsoft.com/windows/win32/rras/ras-ppp-atcp-result-str)

[**RAS\_PPP\_IPCP\_RESULT**](https://learn.microsoft.com/windows/win32/rras/ras-ppp-ipcp-result-str)

[**RAS\_PPP\_IPXCP\_RESULT**](https://learn.microsoft.com/windows/win32/rras/ras-ppp-ipxcp-result-str)

[**RAS\_PPP\_NBFCP\_RESULT**](https://learn.microsoft.com/windows/win32/rras/ras-ppp-nbfcp-result-str)

[**RasAdminPortGetInfo**](https://learn.microsoft.com/windows/win32/rras/rasadminportgetinfo)

