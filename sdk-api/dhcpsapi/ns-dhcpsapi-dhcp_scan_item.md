# DHCP_SCAN_ITEM structure

## Description

The **DHCP_SCAN_ITEM** structure defines a desynchronized client lease address stored on a DHCPv4 server, and the location in which it should be fixed (in-memory cache or database).

## Members

### `IpAddress`

DHCP_IP_ADDRESS value that specifies the address whose lease status was changed during a scan operation.

### `ScanFlag`

[DHCP_SCAN_FLAG](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_scan_flag) enumeration value that indicates whether the supplied client lease IP address will be fixed in the DHCPv4 server's in-memory client lease cache or the client lease database proper.

## See also

[DHCP_SCAN_FLAG](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_scan_flag)

[DHCP_SCAN_LIST](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_scan_list)

[DhcpScanDatabase](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpscandatabase)