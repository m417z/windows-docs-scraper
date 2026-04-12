## Description

The **PKTMON_PACKET_HEADER_INFO** structure contains parsed packet header information for network and transport layer protocols. This structure provides detailed information about IP addresses, protocols, and transport-specific details (TCP, UDP, or ICMP).

## Members

### `AddrFamily`

The address family of the packet, indicating whether it uses IPv4 or IPv6.

### `IpAddrLocal`

A **[PKTMON_IP_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmondefk/ns-pktmondefk-pktmon_ip_address)** structure containing the local IP address.

### `IpAddrRemote`

A **[PKTMON_IP_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmondefk/ns-pktmondefk-pktmon_ip_address)** structure containing the remote IP address.

### `IpProtocol`

The IP protocol number (e.g., 6 for TCP, 17 for UDP, 1 for ICMP).

### `Transport`

A union containing transport-layer specific information.

### `Transport.Udp`

A structure containing UDP-specific fields.

### `Transport.Udp.PortLocal`

The local UDP port number.

### `Transport.Udp.PortRemote`

The remote UDP port number.

### `Transport.Tcp`

A structure containing TCP-specific fields.

### `Transport.Tcp.PortLocal`

The local TCP port number.

### `Transport.Tcp.PortRemote`

The remote TCP port number.

### `Transport.Tcp.Flags`

TCP flags (e.g., SYN, ACK, FIN).

### `Transport.Icmp`

A structure containing ICMP-specific fields.

### `Transport.Icmp.Type`

The ICMP message type.

### `Transport.Icmp.Code`

The ICMP message code.

### `_PKTMON_TRANSPORT`

The name of the transport union type.

## Remarks

This structure is used within **[PKTMON_PACKET_LOG_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_packet_log_in)** to provide parsed header information when logging packets.

## See also

- [PKTMON_PACKET_LOG_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_packet_log_in)
- [PKTMON_IP_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmondefk/ns-pktmondefk-pktmon_ip_address)
- [PktMonClntHeaderInfoLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntheaderinfolog)