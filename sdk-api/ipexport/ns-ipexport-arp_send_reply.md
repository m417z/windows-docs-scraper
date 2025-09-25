# ARP_SEND_REPLY structure

## Description

The **ARP_SEND_REPLY** structure stores information about an Address Resolution Protocol (ARP) reply messages.

## Members

### `DestAddress`

 The destination IPv4 address to which the ARP message is sent, in the form of an [IPAddr](https://learn.microsoft.com/windows/desktop/api/inaddr/ns-inaddr-in_addr) structure.

### `SrcAddress`

The source IPv4 address from which the ARP message is being transmitted, in the form of an [IPAddr](https://learn.microsoft.com/windows/desktop/api/inaddr/ns-inaddr-in_addr) structure.

## See also

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IP Helper Structures](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-structures)

[IPAddr](https://learn.microsoft.com/windows/desktop/api/inaddr/ns-inaddr-in_addr)