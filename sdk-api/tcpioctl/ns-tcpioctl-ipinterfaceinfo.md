# IPInterfaceInfo structure

## Description

[This structure may be altered or unavailable in future versions of Windows.]

The **IPInterfaceInfo** structure contains information about a specific IP interface, returned by the [IOCTL_TCP_QUERY_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ni-tcpioctl-ioctl_tcp_query_information_ex) control code.

## Members

### `iii_flags`

The types of communication supported on this interface. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| 1 | Point-to-point. |
| 2 | Point-to-multipoint. |
| 4 | Unidirectional communication. |

### `iii_mtu`

The maximum transmission unit: the size, in bytes, of the largest datagram that can be sent
and/or received on the interface.

### `iii_speed`

An estimate of the interface's current bandwidth in bits per second. For interfaces that
do not vary in bandwidth or for which no accurate estimation can be made, this member contains
the nominal bandwidth.

### `iii_addrlength`

The length, in bytes, of the IP address associated with this interface that is contained in the
**iii_addr** member.

### `iii_addr`

The IP address associated with this interface. In Windows Vista, this is the physical address.

## Remarks

This is a variable-length structure whose size depends on whether the **iii_addr** member contains an IPv4 or IPv6 address. To allocate a buffer large enough to contain it safely, use the size:

`sizeof(IPInterfaceInfo) + MAX_PHYSADDR_SIZE`

## See also

[IOCTL_TCP_QUERY_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ni-tcpioctl-ioctl_tcp_query_information_ex)

[Management Information Base
Reference](https://learn.microsoft.com/previous-versions/windows/desktop/mib/management-information-base-reference)