# IP_ADAPTER_UNICAST_ADDRESS_LH structure

## Description

The
**IP_ADAPTER_UNICAST_ADDRESS** structure stores a single unicast IP address in a linked list of IP addresses for a particular adapter.

## Members

### `Alignment`

### `Length`

Type: **ULONG**

The length, in bytes, of this structure.

### `Flags`

Type: **DWORD**

A set of flags for this IP address.

The following table shows possible values. These constants are defined in the *Iptypes.h* header file.

| Value | Meaning |
| --- | --- |
| **IP_ADAPTER_ADDRESS_DNS_ELIGIBLE** | The IP address is legal to appear in DNS. |
| **IP_ADAPTER_ADDRESS_TRANSIENT** | The IP address is a cluster address and should not be used by most applications. |

### `Next`

Type: **struct _IP_ADAPTER_UNICAST_ADDRESS***

A pointer to the next IP adapter address structure in the list.

### `Address`

Type: **[SOCKET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-socket_address)**

The IP address for this unicast IP address entry. This member can be an IPv6 address or an IPv4 address.

### `PrefixOrigin`

Type: **IP_PREFIX_ORIGIN**

The prefix or network part of IP the address. This member can be one of the values from the [IP_PREFIX_ORIGIN](https://learn.microsoft.com/windows/desktop/api/nldef/ne-nldef-nl_prefix_origin) enumeration type defined in the *Iptypes.h* header file.

### `SuffixOrigin`

Type: **IP_SUFFIX_ORIGIN**

The suffix or host part of the IP address. This member can be one of the values from the [IP_SUFFIX_ORIGIN](https://learn.microsoft.com/windows/desktop/api/nldef/ne-nldef-nl_suffix_origin) enumeration type defined in the *Iptypes.h* header file.

### `DadState`

Type: **IP_DAD_STATE**

The duplicate address detection (DAD) state. This member can be one of the values from the [IP_DAD_STATE](https://learn.microsoft.com/windows/desktop/api/nldef/ne-nldef-nl_dad_state) enumeration type defined in the *Iptypes.h* header file.
Duplicate address detection is available for both IPv4 and IPv6 addresses.

### `ValidLifetime`

Type: **ULONG**

The maximum lifetime, in seconds, that the IP address is valid. A value of 0xffffffff is considered to be infinite.

### `PreferredLifetime`

Type: **ULONG**

The preferred lifetime, in seconds, that the IP address is valid. A value of 0xffffffff is considered to be infinite.

### `LeaseLifetime`

Type: **ULONG**

The lease lifetime, in seconds, that the IP address is valid.

### `OnLinkPrefixLength`

Type: **UINT8**

The length, in bits, of the prefix or network part of the IP address. For a unicast IPv4 address, any value greater than 32 is an illegal value. For a unicast IPv6 address, any value greater than 128 is an illegal value.
A value of 255 is commonly used to represent an illegal value.

**Note** This structure member is only available on Windows Vista and later.

## Remarks

The [IP_ADAPTER_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_addresses_lh) structure is retrieved by the [GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses) function. The **FirstUnicastAddress** member of the **IP_ADAPTER_ADDRESSES** structure is a pointer to a linked list of **IP_ADAPTER_UNICAST_ADDRESS** structures.

The size of the **IP_ADAPTER_UNICAST_ADDRESS** structure changed on Windows Vista and later. The **Length** member should be used to determine which version of the **IP_ADAPTER_UNICAST_ADDRESS** structure is being used.

The version of the **IP_ADAPTER_UNICAST_ADDRESS** structure on Windows Vista and later has the following new member added: **OnLinkPrefixLength**.

When this structure is used with the [GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses) function and similar management functions, all configured addresses are shown, including duplicate addresses. Such duplicate address entries can occur when addresses are configured statically. Such reporting facilitates administrator troubleshooting. The **DadState** member is effective in identifying and troubleshooting such situations.

In the Windows SDK, the version of the structure for use on Windows Vista and later is defined as **IP_ADAPTER_UNICAST_ADDRESS_LH**. In the Windows SDK, the version of this structure to be used on earlier systems including Windows XP with Service Pack 1 (SP1) and later is defined as **IP_ADAPTER_UNICAST_ADDRESS_XP**. When compiling an application if the target platform is Windows Vista and later (`NTDDI_VERSION >= NTDDI_VISTA`, `_WIN32_WINNT >= 0x0600`, or `WINVER >= 0x0600`), the **IP_ADAPTER_UNICAST_ADDRESS_LH** structure is typedefed to the **IP_ADAPTER_UNICAST_ADDRESS** structure. When compiling an application if the target platform is not Windows Vista and later, the **IP_ADAPTER_UNICAST_ADDRESS_XP** structure is typedefed to the **IP_ADAPTER_UNICAST_ADDRESS** structure.

The [SOCKET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-socket_address) structure is used in the **IP_ADAPTER_UNICAST_ADDRESS** structure. On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **SOCKET_ADDRESS** structure is defined in the *Ws2def.h* header file which is automatically included by the *Winsock2.h* header file. On the Platform Software Development Kit (SDK) released for Windows Server 2003 and Windows XP, the **SOCKET_ADDRESS** structure is declared in the *Winsock2.h* header file. In order to use the **IP_ADAPTER_UNICAST_ADDRESS** structure, the *Winsock2.h* header file must be included before the *Iphlpapi.h* header file.

## See also

[GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses)

[IP Helper
Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IP Helper
Structures](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-structures)

[IP_ADAPTER_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_addresses_lh)

[IP_DAD_STATE](https://learn.microsoft.com/windows/desktop/api/nldef/ne-nldef-nl_dad_state)

[IP_PREFIX_ORIGIN](https://learn.microsoft.com/windows/desktop/api/nldef/ne-nldef-nl_prefix_origin)

[IP_SUFFIX_ORIGIN](https://learn.microsoft.com/windows/desktop/api/nldef/ne-nldef-nl_suffix_origin)

[SOCKET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-socket_address)