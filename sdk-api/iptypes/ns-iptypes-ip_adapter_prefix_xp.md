# IP_ADAPTER_PREFIX_XP structure

## Description

The **IP_ADAPTER_PREFIX** structure stores an IP address prefix.

## Members

### `Alignment`

Reserved. Used by the compiler to align the structure.

### `Length`

The length, in bytes, of this structure.

### `Flags`

This member is reserved and should be set to zero.

### `Next`

A pointer to the next adapter prefix structure in the list.

### `Address`

The address prefix, in the form of a [SOCKET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-socket_address) structure.

### `PrefixLength`

The length of the prefix, in bits.

## Remarks

The [IP_ADAPTER_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_addresses_lh) structure is retrieved by the [GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses) function. On Windows XP with Service Pack 1 (SP1) and later, the **FirstPrefix** member of the **IP_ADAPTER_ADDRESSES** structure is a pointer to a linked list of **IP_ADAPTER_PREFIX** structures.

The [SOCKET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-socket_address) structure is used in the **IP_ADAPTER_PREFIX** structure. On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **SOCKET_ADDRESS** structure is defined in the *Ws2def.h* header file which is automatically included by the *Winsock2.h* header file. On the Platform Software Development Kit (SDK) released for Windows Server 2003 and Windows XP, the **SOCKET_ADDRESS** structure is declared in the *Winsock2.h* header file. In order to use the **IP_ADAPTER_PREFIX** structure, the *Winsock2.h* header file must be included before the *Iphlpapi.h* header file.

## See also

[GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses)

[IP Helper
Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IP Helper
Structures](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-structures)

[IP_ADAPTER_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_addresses_lh)

[SOCKET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-socket_address)