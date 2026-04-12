## Description

The **PKTMON_IP_ADDRESS** structure represents an IP address in either IPv4 or IPv6 format for use in packet monitoring operations. This structure provides a union that allows the same memory space to be interpreted as either an IPv4 address or an IPv6 address, enabling efficient storage and flexible access to IP address data when logging or filtering network packets.

## Members

### `IPv4`

Contains the IPv4 address as a single 32-bit value. This field is part of a union and shares memory with **IPv4_bytes**.

### `IPv4_bytes[PKTMON_IPV4_ADDRESS_SIZE]`

Contains the IPv4 address as an array of bytes. This field is part of a union and shares memory with **IPv4**, providing an alternative byte-level view of the same IPv4 address data.

### `IPv6[2]`

Contains the IPv6 address as an array of two 64-bit values. This field is part of a union and shares memory with **IPv6_bytes**.

### `IPv6_bytes[PKTMON_IPV6_ADDRESS_SIZE]`

Contains the IPv6 address as an array of bytes. This field is part of a union and shares memory with **IPv6**, providing an alternative byte-level view of the same IPv6 address data.

## Remarks

This structure is typically used as part of packet header information structures to represent local and remote IP addresses during packet monitoring operations. The union design allows developers to access the IP address data in the most convenient format for their use case—either as integer values or as byte arrays.

## See also

- [PKTMON_PACKET_HEADER_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/ns-pktmonclntk-pktmon_packet_header_information)
- [PKTMON_PACKET_HEADER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_packet_header_info)
- [PktMonClntHeaderInfoLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntheaderinfolog)