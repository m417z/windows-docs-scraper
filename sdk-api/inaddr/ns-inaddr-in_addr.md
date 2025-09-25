# IN_ADDR structure

## Description

The **in_addr** structure represents an IPv4 address.

**Note** The **IPaddr** type definition in IP Helper also represents an IPv4 address and can be cast to an interchangeable [in_addr](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr) structure when needed. The **in_addr** structure in IP Helper has the same syntax and usage as the Windows Sockets **in_addr** structure, and is interchangeable with **in_addr** structure used in Windows sockets. Windows sockets also defines an **IN_ADDR** typedef for the **in_addr** structure.

## Members

### `S_un`

### `S_un.S_un_b`

The IPv4 address of the host formatted as four **u_char**s.

### `S_un.S_un_b.s_b1`

### `S_un.S_un_b.s_b2`

### `S_un.S_un_b.s_b3`

### `S_un.S_un_b.s_b4`

### `S_un.S_un_w`

The IPv4 address of the host formatted as two **u_short**s.

### `S_un.S_un_w.s_w1`

### `S_un.S_un_w.s_w2`

### `S_un.S_addr`

Address of the host formatted as a **u_long**.

## Remarks

The **IPaddr** type definition also represents an IPv4 address and can be cast to an **in_addr** structure when needed.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **in_addr** structure is defined in the *Inaddr.h* header file which is automatically included by the *Ipexport.h* header file. On the Platform Software Development Kit (SDK) released for Windows Server 2003 and Windows XP, the **in_addr** structure is declared in the *Ipexport.h* header file.

## See also

[ARP_SEND_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-arp_send_reply)

[AddIPAddress](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-addipaddress)

[GetBestInterface](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getbestinterface)

[GetRTTAndHopCount](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getrttandhopcount)

[ICMP_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmp_echo_reply)

[IP_UNIDIRECTIONAL_ADAPTER_ADDRESS](https://learn.microsoft.com/windows/win32/api/ipexport/ns-ipexport-ip_unidirectional_adapter_address)

[IcmpSendEcho](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho)

[IcmpSendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2)

[SendARP](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-sendarp)

[in_addr(Winsock)](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr)