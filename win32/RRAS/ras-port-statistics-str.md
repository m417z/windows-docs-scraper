# RAS\_PORT\_STATISTICS structure

\[The **RAS\_PORT\_STATISTICS** structure is not supported as of Windows Vista.\]

The **RAS\_PORT\_STATISTICS** structure reports the statistics that a RAS server collects for a connected port. The RAS server resets the various statistic counters each time the port is connected. Call the [**RasAdminPortClearStatistics**](https://learn.microsoft.com/windows/win32/rras/rasadminportclearstatistics) function to force the RAS server to reset the statistic counters.

For a port that is part of a multilink connection, this structure provides two sets of statistics. The first set contains the cumulative statistics for all ports in the connection. These statistics are the same for all ports in the connection. The second set contains the statistics for just this port. If the port is not part of a multilink connection, both sets of statistics have the same information. To determine whether a port is part of a multilink connection, check the PORT\_MULTILINKED bit in the **Flags** member of the port's [**RAS\_PORT\_0**](https://learn.microsoft.com/windows/win32/rras/ras-port-0-str) structure.

## Members

**dwBytesXmited**

Specifies the total number of bytes transmitted by the connection.

**dwBytesRcved**

Specifies the total number of bytes received by the connection.

**dwFramesXmited**

Specifies the total number of frames transmitted by the connection.

**dwFramesRcved**

Specifies the total number of frames received by the connection.

**dwCrcErr**

Specifies the total number of CRC errors on the connection. CRC errors are caused by the failure of a cyclic redundancy check. A CRC error indicates that one or more characters in the data packet received were found garbled on arrival.

**dwTimeoutErr**

Specifies the total number of time-out errors on the connection. Time-out errors occur when an expected character is not received in time. When this occurs, the software assumes that the data has been lost and requests that it be resent.

**dwAlignmentErr**

Specifies the total number of alignment errors on the connection. Alignment errors occur when a character received is not the one expected. This usually happens when a character is lost or when a time-out error occurs.

**dwHardwareOverrunErr**

Specifies the total number of hardware overrun errors on the connection. These errors indicate the number of times the sending computer has transmitted characters faster than the receiving computer hardware can process them. If this problem persists, reduce the BPS connection rate on the client.

**dwFramingErr**

Specifies the total number of framing errors on the connection. A framing error occurs when an asynchronous character is received with an invalid start or stop bit.

**dwBufferOverrunErr**

Specifies the total number of buffer overrun errors on the connection. A buffer overrun error occurs when the sending computer is transmitting characters faster than the receiving computer can accommodate them. If this problem persists, reduce the BPS connection rate on the client.

**dwBytesXmitedUncompressed**

Specifies the total number of bytes transmitted uncompressed by the connection.

**dwBytesRcvedUncompressed**

Specifies the total number of bytes received uncompressed by the connection.

**dwBytesXmitedCompressed**

Specifies the total number of bytes transmitted compressed by the connection.

**dwBytesRcvedCompressed**

Specifies the total number of bytes received compressed by the connection.

**dwPortBytesXmited**

Specifies the total number of bytes transmitted by the port.

**dwPortBytesRcved**

Specifies the total number of bytes received by the port.

**dwPortFramesXmited**

Specifies the total number of frames transmitted by the port.

**dwPortFramesRcved**

Specifies the total number of frames received by the port.

**dwPortCrcErr**

Specifies the total number of CRC errors on the port. CRC errors are caused by the failure of a cyclic redundancy check. A CRC error indicates that one or more characters in the data packet received were found garbled on arrival.

**dwPortTimeoutErr**

Specifies the total number of time-out errors on the port. Time-out errors occur when an expected character is not received in time. When this occurs, the software assumes that the data has been lost and requests that it be resent.

**dwPortAlignmentErr**

Specifies the total number of alignment errors on the port. Alignment errors occur when a character received is not the one expected. This usually happens when a character is lost or when a time-out error occurs.

**dwPortHardwareOverrunErr**

Specifies the total number of hardware overrun errors on the port. These errors indicate the number of times the sending computer has transmitted characters faster than the receiving computer hardware can process them. If this problem persists, reduce the BPS connection rate on the client.

**dwPortFramingErr**

Specifies the total number of framing errors on the port. A framing error occurs when an asynchronous character is received with an invalid start or stop bit.

**dwPortBufferOverrunErr**

Specifies the total number of buffer overrun errors on the port. A buffer overrun error occurs when the sending computer is transmitting characters faster than the receiving computer can accommodate them. If this problem persists, reduce the BPS connection rate on the client.

**dwPortBytesXmitedUncompressed**

Specifies the total number of bytes transmitted uncompressed by the port. If the port is part of a multilink connection, this member is not valid. Use the compression statistics for the connection instead.

**dwPortBytesRcvedUncompressed**

Specifies the total number of bytes received uncompressed by the port. If the port is part of a multilink connection, this member is not valid. Use the compression statistics for the connection instead.

**dwPortBytesXmitedCompressed**

Specifies the total number of bytes transmitted compressed by the port. If the port is part of a multilink connection, this member is not valid. Use the compression statistics for the connection instead.

**dwPortBytesRcvedCompressed**

Specifies the total number of bytes received compressed by the port. If the port is part of a multilink connection, this member is not valid. Use the compression statistics for the connection instead.

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

[**RAS\_PORT\_0**](https://learn.microsoft.com/windows/win32/rras/ras-port-0-str)

[**RasAdminAcceptNewConnection**](https://learn.microsoft.com/windows/win32/rras/rasadminacceptnewconnection)

[**RasAdminConnectionHangupNotification**](https://learn.microsoft.com/windows/win32/rras/rasadminconnectionhangupnotification)

[**RasAdminPortClearStatistics**](https://learn.microsoft.com/windows/win32/rras/rasadminportclearstatistics)

[**RasAdminPortGetInfo**](https://learn.microsoft.com/windows/win32/rras/rasadminportgetinfo)

