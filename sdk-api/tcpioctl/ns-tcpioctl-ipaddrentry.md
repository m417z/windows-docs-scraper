# IPAddrEntry structure

## Description

[This structure may be altered or unavailable in future versions of Windows.]

Implements part of the Management Information Base (MIB-II)
information group for the Internet Protocol (IP) as specified in the
Internet Engineering Task Force (IETF) Request for Comments [(RFC) 2011](https://www.ietf.org/rfc/rfc2011.txt).

## Members

### `iae_addr`

An IPv4 IP address to which this structure pertains.

### `iae_index`

The index value that uniquely identifies the interface associated with this
IP address.

### `iae_mask`

The subnet mask associated with this IP address. The value of the mask is an
IPv4 address with all the network bits set to 1 and all the hosts bits set to 0.

### `iae_bcastaddr`

The value of the least-significant bit in the IP broadcast address used for
sending datagrams on the logical interface associated with this IP address.
For example, when the Internet standard all-ones broadcast address
is used, the value is 1. This value applies to both the subnet and network
broadcast addresses used by the entity on this logical interface.

### `iae_reasmsize`

The size of the largest IP datagram that this entity can reassemble from
incoming IP fragmented datagrams received on this interface.

### `iae_context`

A context value for this IP address.

### `iae_pad`

A pad value.

## See also

[IOCTL_TCP_QUERY_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ni-tcpioctl-ioctl_tcp_query_information_ex)

[Management Information Base
Reference](https://learn.microsoft.com/previous-versions/windows/desktop/mib/management-information-base-reference)