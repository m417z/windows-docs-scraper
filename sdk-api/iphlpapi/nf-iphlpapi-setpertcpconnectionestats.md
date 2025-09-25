## Description

The **SetPerTcpConnectionEStats** function sets a value in the read/write information for an IPv4 TCP connection. This function is used to enable or disable extended statistics for an IPv4 TCP connection.

## Parameters

### `Row`

A pointer to a [MIB_TCPROW](https://learn.microsoft.com/windows/win32/api/tcpmib/ns-tcpmib-mib_tcprow_lh) structure for an IPv4 TCP connection.

### `EstatsType`

The type of extended statistics for TCP to set. This parameter determines the data and format of information that is expected in the *Rw* parameter.

This parameter can be one of the values from the [TCP_ESTATS_TYPE](https://learn.microsoft.com/windows/win32/api/tcpestats/ne-tcpestats-tcp_estats_type) enumeration type defined in the *Tcpestats.h* header file.

### `Rw`

A pointer to a buffer that contains the read/write information to set. The buffer should contain a value from the [TCP_BOOLEAN_OPTIONAL](https://learn.microsoft.com/windows/win32/api/tcpestats/ne-tcpestats-tcp_boolean_optional) enumeration for each structure member that specifies how each member should be updated.

### `RwVersion`

The version of the read/write information to be set. This parameter should be set to zero for Windows Vista, Windows Server 2008, and Windows 7.

### `RwSize`

The size, in bytes, of the buffer pointed to by the *Rw* parameter.

### `Offset`

The offset, in bytes, to the member in the structure pointed to by the *Rw* parameter to be set. This parameter is currently unused and must be set to zero.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned under several conditions that include the following: the user lacks the required administrative privileges on the local computer or the application is not running in an enhanced shell as the built-in Administrator (RunAs administrator). |
| **ERROR_INVALID_USER_BUFFER** | The supplied user buffer is not valid for the requested operation. This error is returned if the *Row* parameter is a **NULL** pointer and the *RwSize* parameter is nonzero. |
| **ERROR_INVALID_PARAMETER** | The parameter is incorrect. This error is returned if the *Row* parameter is a **NULL** pointer. |
| **ERROR_NOT_FOUND** | This requested entry was not found. This error is returned if the TCP connection specified in the *Row* parameter could not be found. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if the *RwVersion* or the *Offset* parameter is not set to 0. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **SetPerTcpConnectionEStats** function is defined on Windows Vista and later.

The **SetPerTcpConnectionEStats** function is used to enable or disable extended statistics on an IPv4 TCP connection passed in the *Row* parameter. Extended statistics on a TCP connection are disabled by default. The **SetPerTcpConnectionEStats** function is used to set the value of a member in the read/write information for extended statistics for an IPv4 TCP connection. The type and format of the structure to be set is specified by the *EstatsType* parameter. The *Rw* parameter contains a pointer to the structure being passed. All members in the structure pointed to by *Rw* parameter must be specified.

The only version of TCP connection statistics currently supported is version zero. So the *RwVersion* parameter passed to **SetPerTcpConnectionEStats** should be set to 0.

The structure pointed to by the *Rw* parameter passed this function depends on the enumeration value passed in the *EstatsType* parameter. The following table below indicates the structure type that should be passed in the *Rw* parameter for each possible *EstatsType* parameter type.

| *EstatsType* | Structure pointed to by *Rw* |
| --- | --- |
| **TcpConnectionEstatsData** | [TCP_ESTATS_DATA_RW_v0](https://learn.microsoft.com/windows/win32/api/tcpestats/ns-tcpestats-tcp_estats_data_rw_v0) |
| **TcpConnectionEstatsSndCong** | [TCP_ESTATS_SND_CONG_RW_v0](https://learn.microsoft.com/windows/win32/api/tcpestats/ns-tcpestats-tcp_estats_snd_cong_rw_v0) |
| **TcpConnectionEstatsPath** | [TCP_ESTATS_PATH_RW_v0](https://learn.microsoft.com/windows/win32/api/tcpestats/ns-tcpestats-tcp_estats_path_rw_v0) |
| **TcpConnectionEstatsSendBuff** | [TCP_ESTATS_SEND_BUFF_RW_v0](https://learn.microsoft.com/windows/win32/api/tcpestats/ns-tcpestats-tcp_estats_send_buff_rw_v0) |
| **TcpConnectionEstatsRec** | [TCP_ESTATS_REC_RW_v0](https://learn.microsoft.com/windows/win32/api/tcpestats/ns-tcpestats-tcp_estats_rec_rw_v0) |
| **TcpConnectionEstatsObsRec** | [TCP_ESTATS_OBS_REC_RW_v0](https://learn.microsoft.com/windows/win32/api/tcpestats/ns-tcpestats-tcp_estats_obs_rec_rw_v0) |
| **TcpConnectionEstatsBandwidth** | [TCP_ESTATS_BANDWIDTH_RW_v0](https://learn.microsoft.com/windows/win32/api/tcpestats/ns-tcpestats-tcp_estats_bandwidth_rw_v0) |
| **TcpConnectionEstatsFineRtt** | [TCP_ESTATS_FINE_RTT_RW_v0](https://learn.microsoft.com/windows/win32/api/tcpestats/ns-tcpestats-tcp_estats_fine_rtt_rw_v0) |

The *Offset* parameter is currently unused and must be set to 0. The possible structures pointed to by the *Rw* parameter all have a single member except for the [TCP_ESTATS_BANDWIDTH_RW_v0](https://learn.microsoft.com/windows/win32/api/tcpestats/ns-tcpestats-tcp_estats_bandwidth_rw_v0) structure. When the *EstatsType* parameter is set to **TcpConnectionEstatsBandwidth**, the **TCP_ESTATS_BANDWIDTH_RW_v0** structure pointed to by the *Rw* parameter must have both structure members set to the preferred values in a single call to the **SetPerTcpConnectionEStats** function.

If the *RwSize* parameter is set to 0, the **SetPerTcpConnectionEStats** function returns NO_ERROR and makes no changes to the extended statistics status.

The [GetTcpTable](https://learn.microsoft.com/windows/win32/api/iphlpapi/nf-iphlpapi-gettcptable) function is used to retrieve the IPv4 TCP connection table on the local computer. This function returns a [MIB_TCPTABLE](https://learn.microsoft.com/windows/win32/api/tcpmib/ns-tcpmib-mib_tcptable) structure that contain an array of [MIB_TCPROW](https://learn.microsoft.com/windows/win32/api/tcpmib/ns-tcpmib-mib_tcprow_lh) entries. The *Row* parameter passed to the **SetPerTcpConnectionEStats** function must be an entry for an existing IPv4 TCP connection.

Once extended statistics are enabled on a TCP connection for IPv4, applications call the [GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/win32/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats) function to retrieve extended statistics on the TCP connection.

The [GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/win32/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats) function is designed to use TCP to diagnose performance
problems in both the network and the application. If a network based
application is performing poorly, TCP can determine if the bottleneck
is in the sender, the receiver or the network itself. If the
bottleneck is in the network, TCP can provide specific information
about its nature.

For information on extended TCP statistics on an IPv6 connection, see the [GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/win32/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats) and [SetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/win32/api/iphlpapi/nf-iphlpapi-setpertcp6connectionestats) functions.

The **SetPerTcpConnectionEStats** function can only be called by a user logged on as a member of the Administrators group. If **SetPerTcpConnectionEStats** is called by a user that is not a member of the Administrators group, the function call will fail and **ERROR_ACCESS_DENIED** is returned. This function can also fail because of user account control (UAC) on Windows Vista and Windows Server 2008. If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to requireAdministrator. If the application on Windows Vista or Windows Server 2008 lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (RunAs administrator) for this function to succeed.

In Windows versions prior to Windows 10, version 1709 (Fall Creators Update), you can use **SetPerTcpConnectionEStats** to disable and reenable statistics on a connection, causing any statistics counters to be reset to zero. As of Windows 10, version 1709 (Fall Creators Update), some statistics counters don't reset when statistics are disabled and reenabled. Also, if two applications are monitoring statistics for the same connection, then one application can confuse the other by disabling statistics. For these reasons, we recommend that your application refrains from disabling statistics on connections. To detect changes over time, you should save the counter values read by a previous call to [GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/win32/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats), and subtract them from those read by a subsequent call.

## See also

[GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/win32/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats)

[GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/win32/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats)

[GetTcpTable](https://learn.microsoft.com/windows/win32/api/iphlpapi/nf-iphlpapi-gettcptable)

[MIB_TCPROW](https://learn.microsoft.com/windows/win32/api/tcpmib/ns-tcpmib-mib_tcprow_lh)

[SetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/win32/api/iphlpapi/nf-iphlpapi-setpertcp6connectionestats)

[TCP_BOOLEAN_OPTIONAL](https://learn.microsoft.com/windows/win32/api/tcpestats/ne-tcpestats-tcp_boolean_optional)

[TCP_ESTATS_BANDWIDTH_RW_v0](https://learn.microsoft.com/windows/win32/api/tcpestats/ns-tcpestats-tcp_estats_bandwidth_rw_v0)

[TCP_ESTATS_DATA_RW_v0](https://learn.microsoft.com/windows/win32/api/tcpestats/ns-tcpestats-tcp_estats_data_rw_v0)

[TCP_ESTATS_FINE_RTT_RW_v0](https://learn.microsoft.com/windows/win32/api/tcpestats/ns-tcpestats-tcp_estats_fine_rtt_rw_v0)

[TCP_ESTATS_OBS_REC_RW_v0](https://learn.microsoft.com/windows/win32/api/tcpestats/ns-tcpestats-tcp_estats_obs_rec_rw_v0)

[TCP_ESTATS_PATH_RW_v0](https://learn.microsoft.com/windows/win32/api/tcpestats/ns-tcpestats-tcp_estats_path_rw_v0)

[TCP_ESTATS_REC_RW_v0](https://learn.microsoft.com/windows/win32/api/tcpestats/ns-tcpestats-tcp_estats_rec_rw_v0)

[TCP_ESTATS_SEND_BUFF_RW_v0](https://learn.microsoft.com/windows/win32/api/tcpestats/ns-tcpestats-tcp_estats_send_buff_rw_v0)

[TCP_ESTATS_SND_CONG_RW_v0](https://learn.microsoft.com/windows/win32/api/tcpestats/ns-tcpestats-tcp_estats_snd_cong_rw_v0)

[TCP_ESTATS_TYPE](https://learn.microsoft.com/windows/win32/api/tcpestats/ne-tcpestats-tcp_estats_type)