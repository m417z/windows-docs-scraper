# DHCP_SCAN_FLAG enumeration

## Description

The **DHCP_SCAN_FLAG** enumeration defines the set of possible targets of synchronization during a database scan operation.

## Constants

### `DhcpRegistryFix`

Indicates that the in-memory client lease cache on the DHCPv4 server does not contain the client lease IP address, but the DHCPv4 client lease database does contain it. (Note that this enumeration does not inform [DhcpScanDatabase](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpscandatabase) to perform a registry operation despite the name.) Any reconciliation process should update the in-memory cache.

### `DhcpDatabaseFix`

Indicates that the client lease database on the DHCPv4 server does not contain the client lease IP address, but the in-memory cache of client leases does contain it. Any reconciliation process should update the database.

## See also

[DHCP_SCAN_ITEM](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_scan_item)

[DhcpScanDatabase](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpscandatabase)