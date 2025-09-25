## Description

The **PKTMON_PACKET_HEADER_INFORMATION** struct contains the packet header information.

## Members

### `SockAddrLocal`

The local socket address.

### `SockAddrRemote`

The remote socket address.

### `IpProtocol`

The IP protocol.

### `Transport`

A union that defines the transport protocol.

### `Transport.Udp`

The UDP protocol.

### `Transport.Udp.PortLocal`

The local port for the UDP protocol.

### `Transport.Udp.PortRemote`

The remote port for the UDP protocol.

### `Transport.Tcp`

The TCP protocol.

### `Transport.Tcp.PortLocal`

The local port for the TCP protocol.

### `Transport.Tcp.PortRemote`

The remote port for the TCP protocol.

### `Transport.Tcp.Flags`

Flags for the TCP protocol.

### `Transport.Icmp`

The ICMP protocol.

### `Transport.Icmp.Type`

The type for the ICMP protocol.

### `Transport.Icmp.Code`

The code for the ICMP protocol.

## Remarks

## See also

- [PktMonClntNblLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntnbllog)
- [PktMonClntNblDrop](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntnbldrop)
- [PktMonClntHeaderInfoLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntheaderinfolog)
- [PktMonClntHeaderInfoDrop](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntheaderinfodrop)