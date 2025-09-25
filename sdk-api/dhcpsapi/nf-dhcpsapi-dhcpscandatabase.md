# DhcpScanDatabase function

## Description

The **DhcpScanDatabase** function enumerates the leased DHCPv4 client IPv4 addresses that are not synchronized between the in-memory cache and the server database.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the subnet whose leases will be scanned for desynchronized client lease IP addresses.

### `FixFlag` [in]

Specifies a set of bit flags that indicate whether the in-memory cache or the client lease database should be the definitive source for fixes when synchronizing the two on the DHCPv4 server. These flags are enumerated in [DHCP_SCAN_FLAG](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_scan_flag).

### `ScanList` [out]

[DHCP_SCAN_LIST](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_scan_list) structure that contains the returned list of leased client IP addresses that are not in sync.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCPv4 server's database. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified subnet is not defined on the DHCPv4 server. |

## Remarks

Each leased DHCPv4 client IPv4 address defined on a DHCPv4 server has an entry in both an in-memory store, which serves as a cache for speeding up lease retrieval, and in the client lease database proper. **DhcpScanDatabase** enumerates either the DHCPv4 client IPv4 addresses that are present in the in-memory store and are not present in the database, or those that are present in database but not present in the in-memory store.

This process is necessary as the DHCPv4 server maintains an in-memory cache of frequently-accessed client leases used to improve performance, but it can become desynchronized relative to the server's persistent client lease database. Therefore, it is necessary to reconcile the two stores, and update either the in-memory version of a client lease IP address, or the client lease IP address stored in the database. The [DHCP_SCAN_LIST](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_scan_list) structure returned by this operation contains the "definitive" client leases as specified by the preferred location set in the *FixFlag* parameter.

## See also

[DHCP_SCAN_LIST](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_scan_list)