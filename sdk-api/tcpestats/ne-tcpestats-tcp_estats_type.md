# TCP_ESTATS_TYPE enumeration

## Description

The **TCP_ESTATS_TYPE** enumeration defines the type of extended statistics for a TCP connection that is requested or being set.

## Constants

### `TcpConnectionEstatsSynOpts`

This value specifies SYN exchange information for a TCP connection.

Only read-only static information is available for this enumeration value.

### `TcpConnectionEstatsData`

This value specifies extended data transfer information for a TCP connection.

Only read-only dynamic information and read/write information are available for this enumeration value.

### `TcpConnectionEstatsSndCong`

This value specifies sender congestion for a TCP connection.

All three types of information (read-only static, read-only dynamic, and read/write information) are available for this enumeration value.

### `TcpConnectionEstatsPath`

This value specifies extended path measurement information for a TCP connection. This information is used to infer segment
reordering on the path from the local sender to the remote
receiver.

Only read-only dynamic information and read/write information are available for this enumeration value.

### `TcpConnectionEstatsSendBuff`

This value specifies extended output-queuing information for a TCP connection.

Only read-only dynamic information and read/write information are available for this enumeration value.

### `TcpConnectionEstatsRec`

This value specifies extended local-receiver information for a TCP connection.

Only read-only dynamic information and read/write information are available for this enumeration value.

### `TcpConnectionEstatsObsRec`

This value specifies extended remote-receiver information for a TCP connection.

Only read-only dynamic information and read/write information are available for this enumeration value.

### `TcpConnectionEstatsBandwidth`

This value specifies bandwidth estimation statistics for a TCP connection on bandwidth.

Only read-only dynamic information and read/write information are available for this enumeration value.

### `TcpConnectionEstatsFineRtt`

This value specifies fine-grained round-trip time (RTT) estimation statistics for a TCP connection.

Only read-only dynamic information and read/write information are available for this enumeration value.

### `TcpConnectionEstatsMaximum`

The maximum possible value for the [TCP_ESTATS_TYPE](https://learn.microsoft.com/windows/desktop/api/tcpestats/ne-tcpestats-tcp_estats_type)_STATE enumeration type. This is not a legal value for the possible type of extended statistics for a TCP connection.

## Remarks

The **TCP_ESTATS_TYPE** enumeration is defined on Windows Vista and later.

The [GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats) and **GetPerTcp6ConnectionEStats** functions are designed to use TCP to diagnose performance
problems in both the network and the application. If a network based
application is performing poorly, TCP can determine if the bottleneck
is in the sender, the receiver or the network itself. If the
bottleneck is in the network, TCP can provide specific information
about its nature.

The [GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats) and **GetPerTcp6ConnectionEStats** functions are used to retrieve extended statistics for a TCP connection based on the type of extended statistics specified using one of values from the **TCP_ESTATS_TYPE** enumeration type. The collection of extended statistics on a TCP connection are enabled and disabled using calls to the [SetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setpertcp6connectionestats) and [SetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setpertcpconnectionestats) functions where the type of extended statistics specified is one of values from the **TCP_ESTATS_TYPE** enumeration type.

## See also

[GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats)

[GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats)

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