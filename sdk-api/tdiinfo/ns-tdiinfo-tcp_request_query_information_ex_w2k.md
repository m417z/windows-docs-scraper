# TCP_REQUEST_QUERY_INFORMATION_EX_W2K structure

## Description

[This structure may be altered or unavailable in future versions of Windows.]

Contains the input for the [IOCTL_TCP_QUERY_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ni-tcpioctl-ioctl_tcp_query_information_ex) control code.

## Members

### `ID`

The [TDIObjectID](https://learn.microsoft.com/windows/desktop/api/tdiinfo/ns-tdiinfo-tdiobjectid) structure that defines the type of information being requested from the TCP driver by [IOCTL_TCP_QUERY_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ni-tcpioctl-ioctl_tcp_query_information_ex).

### `Context`

The IPv4 or IPv6 address to be used when [IPInterfaceInfo](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ns-tcpioctl-ipinterfaceinfo) data is requested for a particular IP address.

## See also

[IOCTL_TCP_QUERY_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ni-tcpioctl-ioctl_tcp_query_information_ex)

[IPInterfaceInfo](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ns-tcpioctl-ipinterfaceinfo)

[TDIObjectID](https://learn.microsoft.com/windows/desktop/api/tdiinfo/ns-tdiinfo-tdiobjectid)