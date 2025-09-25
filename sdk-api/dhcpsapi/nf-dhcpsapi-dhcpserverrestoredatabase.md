# DhcpServerRestoreDatabase function

## Description

The **DhcpServerRestoreDatabase** function restores the settings, configuration, and records for a client lease database from a specific backup location (path).

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `Path` [in]

Unicode string that specifies the full absolute path and filename to the backup file from which the registry configuration file and client lease database will be restored. Note that this operation will overwrite any database currently held in memory.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |

## See also

[DhcpScanDatabase](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpscandatabase)

[DhcpServerBackupDatabase](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpserverbackupdatabase)