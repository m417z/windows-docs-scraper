# PXE_ADDRESS structure

## Description

Specifies the network address for a packet.

## Members

### `uFlags`

Indicates how the structure should be interpreted and which of the members of the structure are
valid.

| Value | Meaning |
| --- | --- |
| **PXE_ADDR_BROADCAST**<br><br>0x0001 | For transmitted packets, this flag specifies that this packet should be broadcast on the network. If the **PXE_ADDR_USE_PORT** flag is set, then the **uPort** member specifies the port number to use; otherwise the source port number of the received packet is used as the destination port number. This flag cannot be combined with **PXE_ADDR_USE_ADDR**.<br><br>For received packets, this flag indicates that the packet was set to the server using a broadcast address. The **uPort** member indicates the port on which the packet was received, in host byte order. The **bAddress** and **uAddrLen** members are filled with the broadcast address used. |
| **PXE_ADDR_USE_PORT**<br><br>0x0002 | For transmitted packets, this flag specifies that the **uPort** member is valid and should be used as the destination port when the packet is sent. The **uPort** member must be in host byte order.<br><br>For received packets, this flag indicates that the packet was not received as a broadcast. |
| **PXE_ADDR_USE_ADDR**<br><br>0x0004 | For transmitted packets, this flag specifies that the **bAddress** and **uAddrLen** members are valid and should be used as the destination address of the packet.<br><br>For received packets, this flag is always set. |
| **PXE_ADDR_USE_DHCP_RULES**<br><br>0x0008 | For transmitted packets, this flag specifies that the received packet is a valid DHCP packet, and that the DHCP rules for relay agent should be used to determine the destination address and port. If this flag is specified then **bAddress**, **uIpAddress**, **uAddrLen**, and **uPort** are ignored.<br><br>For received packets, this flag is not used. |

### `bAddress`

Specifies the address of the packet. For more information, see the description for the
**uFlags** member.

### `uIpAddress`

Specifies the IPv4 address. For more information, see the description for the
**uFlags** member.

### `uAddrLen`

Length of the address (**bAddress** or **uIpAddress**). For
more information, see the description for the **uFlags** member.

### `uPort`

Port number for the packet. For more information, see the description for the
**uFlags** member.

## See also

[PxeSendReply](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxesendreply)

[Windows Deployment Services Structures](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-structures)