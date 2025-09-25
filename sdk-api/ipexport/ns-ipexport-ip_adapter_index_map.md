# IP_ADAPTER_INDEX_MAP structure

## Description

The
**IP_ADAPTER_INDEX_MAP** structure stores the interface index associated with a network adapter with IPv4 enabled together with the name of the network adapter.

## Members

### `Index`

The interface index associated with the network adapter.

### `Name`

A pointer to a Unicode string that contains the name of the adapter.

## Remarks

The
**IP_ADAPTER_INDEX_MAP** structure is specific to network adapters with IPv4 enabled.

An adapter index may change when the adapter is disabled and then enabled, or under other circumstances, and should not be considered persistent.

On Windows Vista and later, the **Name** member of the **IP_ADAPTER_INDEX_MAP** structure may be a Unicode string of the GUID for the network interface (the string begins with the '{' character).

This structure is defined in the *Ipexport.h* header file which is automatically included in the *Iphlpapi.h* header file. The *Ipexport.h* header file should never be used directly.

## See also

[IP Helper
Structures](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-structures)

[IP Helper Start
Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IP_INTERFACE_INFO](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_interface_info)

[IpReleaseAddress](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-ipreleaseaddress)

[IpRenewAddress](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-iprenewaddress)