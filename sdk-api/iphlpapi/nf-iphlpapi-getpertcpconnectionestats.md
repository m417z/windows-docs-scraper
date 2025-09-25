# GetPerTcpConnectionEStats function

## Description

The
**GetPerTcpConnectionEStats** function retrieves extended statistics for an IPv4 TCP connection.

## Parameters

### `Row`

A pointer to a [MIB_TCPROW](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow_lh) structure for an IPv4 TCP connection.

### `EstatsType`

The type of extended statistics for TCP requested. This parameter determines the data and format of information that is returned in the *Rw*, *Rod*, and *Ros* parameters if the call is successful.

This parameter can be one of the values from the [TCP_ESTATS_TYPE](https://learn.microsoft.com/windows/desktop/api/tcpestats/ne-tcpestats-tcp_estats_type) enumeration type defined in the *Tcpestats.h* header file.

| Value | Meaning |
| --- | --- |
| **TcpConnectionEstatsSynOpts** | This value requests SYN exchange information for a TCP connection.<br><br>Only read-only static information is available for this enumeration value.<br><br>If the *Ros* parameter was not **NULL** and the function succeeds, the buffer pointed to by the *Ros* parameter should contain a [TCP_ESTATS_SYN_OPTS_ROS_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_syn_opts_ros_v0) structure. |
| **TcpConnectionEstatsData** | This value requests extended data transfer information for a TCP connection. <br><br>Only read-only dynamic information and read/write information are available for this enumeration value.<br><br>If the *Rw* parameter was not **NULL** and the function succeeds, the buffer pointed to by the *Rw* parameter should contain a [TCP_ESTATS_DATA_RW_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_data_rw_v0) structure. <br><br>If extended data transfer information was enabled for this TCP connection, the *Rod* parameter was not **NULL**, and the function succeeds, the buffer pointed to by the *Rod* parameter should contain a [TCP_ESTATS_DATA_ROD_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_data_rod_v0) structure. |
| **TcpConnectionEstatsSndCong** | This value requests sender congestion for a TCP connection. <br><br>All three types of information (read-only static, read-only dynamic, and read/write information) are available for this enumeration value.<br><br>If the *Rw* parameter was not **NULL** and the function succeeds, the buffer pointed to by the *Rw* parameter should contain a [TCP_ESTATS_SND_CONG_RW_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_snd_cong_rw_v0) structure. <br><br>If the *Ros* parameter was not **NULL** and the function succeeds, the buffer pointed to by the *Ros* parameter should contain a [TCP_ESTATS_SND_CONG_ROS_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_snd_cong_ros_v0) structure.<br><br>If sender congestion information was enabled for this TCP connection, the *Rod* parameter was not **NULL**, and the function succeeds, the buffer pointed to by the *Rod* parameter should contain a [TCP_ESTATS_SND_CONG_ROD_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_snd_cong_rod_v0) structure. |
| **TcpConnectionEstatsPath** | This value requests extended path measurement information for a TCP connection.<br><br>Only read-only dynamic information and read/write information are available for this enumeration value.<br><br>If the *Rw* parameter was not **NULL** and the function succeeds, the buffer pointed to by the *Rw* parameter should contain a [TCP_ESTATS_PATH_RW_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_path_rw_v0) structure. <br><br>If extended path measurement information was enabled for this TCP connection, the *Rod* parameter was not **NULL**, and the function succeeds, the buffer pointed to by the *Rod* parameter should contain a [TCP_ESTATS_PATH_ROD_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_path_rod_v0) structure. |
| **TcpConnectionEstatsSendBuff** | This value requests extended output-queuing information for a TCP connection.<br><br>Only read-only dynamic information and read/write information are available for this enumeration value.<br><br>If the *Rw* parameter was not **NULL** and the function succeeds, the buffer pointed to by the *Rw* parameter should contain a [TCP_ESTATS_SEND_BUFF_RW_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_send_buff_rw_v0) structure. <br><br>If extended output-queuing information was enabled for this TCP connection, the *Rod* parameter was not **NULL**, and the function succeeds, the buffer pointed to by the *Rod* parameter should contain a [TCP_ESTATS_SEND_BUFF_ROD_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_send_buff_rod_v0) structure. |
| **TcpConnectionEstatsRec** | This value requests extended local-receiver information for a TCP connection.<br><br>Only read-only dynamic information and read/write information are available for this enumeration value.<br><br>If the *Rw* parameter was not **NULL** and the function succeeds, the buffer pointed to by the *Rw* parameter should contain a [TCP_ESTATS_REC_RW_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_rec_rw_v0) structure. <br><br>If extended local-receiver information was enabled for this TCP connection, the *Rod* parameter was not **NULL**, and the function succeeds, the buffer pointed to by the *Rod* parameter should contain a [TCP_ESTATS_REC_ROD_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_rec_rod_v0) structure. |
| **TcpConnectionEstatsObsRec** | This value requests extended remote-receiver information for a TCP connection.<br><br>Only read-only dynamic information and read/write information are available for this enumeration value.<br><br>If the *Rw* parameter was not **NULL** and the function succeeds, the buffer pointed to by the *Rw* parameter should contain a [TCP_ESTATS_OBS_REC_RW_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_obs_rec_rw_v0) structure. <br><br>If extended remote-receiver information was enabled for this TCP connection, the *Rod* parameter was not **NULL**, and the function succeeds, the buffer pointed to by the *Rod* parameter should contain a [TCP_ESTATS_OBS_REC_ROD_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_obs_rec_rod_v0) structure. |
| **TcpConnectionEstatsBandwidth** | This value requests bandwidth estimation statistics for a TCP connection on bandwidth.<br><br>Only read-only dynamic information and read/write information are available for this enumeration value.<br><br>If the *Rw* parameter was not **NULL** and the function succeeds, the buffer pointed to by the *Rw* parameter should contain a [TCP_ESTATS_BANDWIDTH_RW_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_bandwidth_rw_v0) structure. <br><br>If bandwidth estimation statistics was enabled for this TCP connection, the *Rod* parameter was not **NULL**, and the function succeeds, the buffer pointed to by the *Rod* parameter should contain a [TCP_ESTATS_BANDWIDTH_ROD_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_bandwidth_rod_v0) structure. |
| **TcpConnectionEstatsFineRtt** | This value requests fine-grained round-trip time (RTT) estimation statistics for a TCP connection.<br><br>Only read-only dynamic information and read/write information are available for this enumeration value.<br><br>If the *Rw* parameter was not **NULL** and the function succeeds, the buffer pointed to by the *Rw* parameter should contain a [TCP_ESTATS_FINE_RTT_RW_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_fine_rtt_rw_v0) structure. <br><br>If fine-grained RTT estimation statistics was enabled for this TCP connection, the *Rod* parameter was not **NULL**, and the function succeeds, the buffer pointed to by the *Rod* parameter should contain a [TCP_ESTATS_FINE_RTT_ROD_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_fine_rtt_rod_v0) structure. |

### `Rw` [out]

A pointer to a buffer to receive the read/write information. This parameter may be a **NULL** pointer if an application does not want to retrieve read/write information for the TCP connection.

### `RwVersion`

The version of the read/write information requested. The current supported value is a version of zero.

### `RwSize`

The size, in bytes, of the buffer pointed to by *Rw* parameter.

### `Ros` [out]

A pointer to a buffer to receive read-only static information. This parameter may be a **NULL** pointer if an application does not want to retrieve read-only static information for the TCP connection.

### `RosVersion`

The version of the read-only static information requested. The current supported value is a version of zero.

### `RosSize`

The size, in bytes, of the buffer pointed to by the *Ros* parameter.

### `Rod` [out]

A pointer to a buffer to receive read-only dynamic information. This parameter may be a **NULL** pointer if an application does not want to retrieve read-only dynamic information for the TCP connection.

### `RodVersion`

The version of the read-only dynamic information requested. The current supported value is a version of zero.

### `RodSize`

The size, in bytes, of the buffer pointed to by the *Rod* parameter.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | A buffer passed to a function is too small. This error is returned if the buffer pointed to by the *Rw*, *Ros*, or *Rod* parameters is not large enough to receive the data. This error also returned if one of the given buffers pointed to by the *Rw*, *Ros*, or *Rod* parameters is **NULL**, but a length was specified in the associated *RwSize*, *RosSize*, or *RodSize*.<br><br>This error value is returned on Windows Vista and Windows Server 2008. |
| **ERROR_INVALID_PARAMETER** | The parameter is incorrect. This error is returned if the *Row* parameter is a **NULL** pointer. |
| **ERROR_INVALID_USER_BUFFER** | The supplied user buffer is not valid for the requested operation. This error is returned if one of the given buffers pointed to by the *Rw*, *Ros*, or *Rod* parameters is **NULL**, but a length was specified in the associated *RwSize*, *RosSize*, or *RodSize*. As a result, this error is returned if any of the following conditions are met:<br><br>* The *Row* parameter is a **NULL** pointer and the *RwSize* parameter is nonzero.<br>* The *Ros* parameter is a **NULL** pointer and the *RosSize* parameter is nonzero.<br>* The *Rod* parameter is a **NULL** pointer and the *RodSize* parameter is nonzero.<br><br>This error value is returned on Windows 7 and Windows Server 2008 R2. |
| **ERROR_NOT_FOUND** | This requested entry was not found. This error is returned if the TCP connection specified in the *Row* parameter could not be found. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if the *RwVersion*, *RosVersion*, or *RodVersion* parameter is not set to zero. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **GetPerTcpConnectionEStats** function is defined on Windows Vista and later.

The **GetPerTcpConnectionEStats** function is designed to use TCP to diagnose performance
problems in both the network and the application. If a network based
application is performing poorly, TCP can determine if the bottleneck
is in the sender, the receiver or the network itself. If the
bottleneck is in the network, TCP can provide specific information
about its nature.

The **GetPerTcpConnectionEStats** function retrieves extended statistics for the IPv4 TCP connection passed in the *Row* parameter. The type of extended statistics that is retrieved is specified in the *EstatsType* parameter. Extended statistics on this TCP connection must have previously been enabled by calls to the [SetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setpertcpconnectionestats) function for all [TCP_ESTATS_TYPE](https://learn.microsoft.com/windows/desktop/api/tcpestats/ne-tcpestats-tcp_estats_type) values except when **TcpConnectionEstatsSynOpts** is passed in the *EstatsType* parameter.

The [GetTcpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcptable) function is used to retrieve the IPv4 TCP connection table on the local computer. This function returns a [MIB_TCPTABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable) structure that contain an array of [MIB_TCPROW](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow_lh) entries. The *Row* parameter passed to the **GetPerTcpConnectionEStats** function must be an entry for an existing IPv4 TCP connection.

The only version of TCP connection statistics currently supported is version zero. So the *RwVersion*, *RosVersion*, and *RodVersion* parameters passed to **GetPerTcpConnectionEStats** should be set to 0.

For information on extended TCP statistics on an IPv6 connection, see the [GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats) and [SetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setpertcp6connectionestats) functions.

The [SetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setpertcpconnectionestats) function can only be called by a user logged on as a member of the Administrators group. If **SetPerTcpConnectionEStats** is called by a user that is not a member of the Administrators group, the function call will fail and **ERROR_ACCESS_DENIED** is returned. This function can also fail because of user account control (UAC) on Windows Vista and later. If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to requireAdministrator. If the application lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (RunAs administrator) for this function to succeed.

The caller of **GetPerTcpConnectionEStats** should check the *EnableCollection* field in the returned *Rw* struct, and if it is not `TRUE`, then the caller should ignore the data in the *Ros* and *Rod* structs. If *EnableCollection* is set to `FALSE`, then the data returned in *Ros* and *Rod* are undefined. For example, one condition under which this can happen is when you're using **GetPerTcpConnectionEStats** to retrieve extended statistics for an IPv4 TCP connection, and you've previously called [SetPerTcpConnectionEStats](https://learn.microsoft.com/windows/win32/api/iphlpapi/nf-iphlpapi-setpertcpconnectionestats) to enable extended statistics. If the **SetPerTcpConnectionEStats** call fails then subsequent calls to **GetPerTcpConnectionEStats** will return meaningless random data, and not extended TCP statistics. You can observe that example by running the example below as both an administrator, and as a normal user.

## Examples

For a code example, see the **Examples** section in the [GetPerTcp6ConnectionEStats function](https://learn.microsoft.com/windows/win32/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats) topic.

## See also

[GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats)

[GetTcpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcptable)

[MIB_TCPROW](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow_lh)

[MIB_TCPTABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable)

[SetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setpertcp6connectionestats)

[SetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setpertcpconnectionestats)

[TCP_ESTATS_BANDWIDTH_ROD_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_bandwidth_rod_v0)

[TCP_ESTATS_BANDWIDTH_RW_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_bandwidth_rw_v0)

[TCP_ESTATS_DATA_ROD_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_data_rod_v0)

[TCP_ESTATS_DATA_RW_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_data_rw_v0)

[TCP_ESTATS_FINE_RTT_ROD_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_fine_rtt_rod_v0)

[TCP_ESTATS_FINE_RTT_RW_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_fine_rtt_rw_v0)

[TCP_ESTATS_OBS_REC_ROD_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_obs_rec_rod_v0)

[TCP_ESTATS_OBS_REC_RW_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_obs_rec_rw_v0)

[TCP_ESTATS_PATH_ROD_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_path_rod_v0)

[TCP_ESTATS_PATH_RW_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_path_rw_v0)

[TCP_ESTATS_REC_ROD_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_rec_rod_v0)

[TCP_ESTATS_REC_RW_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_rec_rw_v0)

[TCP_ESTATS_SEND_BUFF_ROD_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_send_buff_rod_v0)

[TCP_ESTATS_SEND_BUFF_RW_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_send_buff_rw_v0)

[TCP_ESTATS_SND_CONG_ROD_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_snd_cong_rod_v0)

[TCP_ESTATS_SND_CONG_ROS_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_snd_cong_ros_v0)

[TCP_ESTATS_SND_CONG_RW_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_snd_cong_rw_v0)

[TCP_ESTATS_SYN_OPTS_ROS_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_syn_opts_ros_v0)

[TCP_ESTATS_TYPE](https://learn.microsoft.com/windows/desktop/api/tcpestats/ne-tcpestats-tcp_estats_type)

[TCP_SOFT_ERROR](https://learn.microsoft.com/windows/desktop/api/tcpestats/ne-tcpestats-tcp_soft_error)