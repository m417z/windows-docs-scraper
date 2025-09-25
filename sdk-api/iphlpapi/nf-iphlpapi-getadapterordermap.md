# GetAdapterOrderMap function

## Description

The **GetAdapterOrderMap** function obtains an adapter order map that indicates priority for interfaces on the local computer.

## Return value

Returns an [IP_ADAPTER_ORDER_MAP](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_adapter_order_map) structure filled with adapter priority information. See the **IP_ADAPTER_ORDER_MAP** structure for more information.

## Remarks

Interface indices appear in the order specified in the Adapters and Bindings dialog box in the Advanced Settings property sheet. This ordering is used as a tie breaker controlling the sequence in which interfaces are used on multihomed systems for situations including route selection, DNS name resolution, and other network related operations.

This function should not be called directly. Instead, use the [IP_ADAPTER_INFO](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_info) structure returned in a [GetAdaptersInfo](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersinfo) function call.

**Note** The caller is responsible for calling the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function to free the array returned by **GetAdapterOrderMap**.

## See also

[GetAdaptersInfo](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersinfo)

[IP_ADAPTER_INFO](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_info)

[IP_ADAPTER_ORDER_MAP](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_adapter_order_map)

[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree)