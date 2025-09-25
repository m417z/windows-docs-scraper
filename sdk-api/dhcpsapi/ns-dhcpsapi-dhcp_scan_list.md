# DHCP_SCAN_LIST structure

## Description

The **DHCP_SCAN_LIST** structure defines a list of all desynchronized client lease IP address on a DHCPv4 server that must be fixed.

## Members

### `NumScanItems`

Specifies the number of [DHCP_SCAN_ITEM](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_scan_item) structures listed in *ScanItems*.

### `ScanItems`

Pointer to a list of [DHCP_SCAN_ITEM](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_scan_item) structures that contain the specific client IP addresses whose leases differed between the in-memory cache of client leases and the subnet client lease database during a [DhcpScanDatabase](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpscandatabase) operation.

### `ScanItems.size_is`

### `ScanItems.size_is.NumScanItems`

## See also

[DHCP_SCAN_ITEM](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_scan_item)

[DhcpScanDatabase](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpscandatabase)