# DrtCreateIpv6UdpTransport function

## Description

The **DrtCreateIpv6UdpTransport** function creates a transport based on the IPv6 UDP protocol.

## Parameters

### `scope`

The **DRT_SCOPE** enumeration that specifies the IPv6 scope in which the DRT is to operate.

### `dwScopeId`

The identifier that uniquely specifies the interface the scope is associated with.

For the Global scope this parameter is always the "GLOBAL_" ID and is optional when using only the global scope.
For the link local scope, this parameter represents the interface associated with the Network Interface Card on which the link local scope exists.

### `dwLocalityThreshold`

The identifier that specifies how Locality information based on IpV6 addresses is used when caching neighbors. By default, the DRT gives preference to neighbors that have an IPv6 address with a prefix in common with the local machine.

### `pwPort` [in, out]

Pointer to the port utilized by the local DRT instance.

### `phTransport` [out]

Pointer to a DRT transport handle specified in the [DRT_SETTINGS](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_settings) structure.

## Return value

This function returns S_OK on success. Other possible values include:

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | The system cannot allocate memory for the provider. |
| **DRT_E_INVALID_PORT** | *pwPort* is **NULL**. |
| **DRT_E_INVALID_TRANSPORT_PROVIDER** | *hTransport* is **NULL**. |
| **DRT_E_INVALID_SCOPE** | The specified scope is not DRT_GLOBAL_SCOPE, DRT_SITE_LOCAL_SCOPE or DRT_LINK_LOCAL_SCOPE. |
| **DRT_E_TRANSPORT_UNEXPECTED** | An unexpected error has occurred. See TraceError for reason. |

**Note** This function may also return errors from underlying calls to [NotifyUnicastIpAddressChange](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyunicastipaddresschange),[WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup), [GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses), [setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt), [WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa), [Bind](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff566268(v=vs.85)), [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl), [CreateThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolio), [CreateThreadpoolCleanupGroup](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolcleanupgroup) and [CreateTimerQueue](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-createtimerqueue).

## Remarks

The default IPv6 UDP Transport created by this function is specific to the DRT it is created for. As a result it cannot be re-used across multiple DRTs.

When using the Distributed Routing Table API in Windows XP with Service Pack 2 (SP2), support of the IPv6 protocol must be enabled for the creation of a transport using **DrtCreateIpv6UdpTransport** to be successful.

## See also

[DRT_SETTINGS](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_settings)

[DrtDeleteIpv6UdpTransport](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtdeleteipv6udptransport)