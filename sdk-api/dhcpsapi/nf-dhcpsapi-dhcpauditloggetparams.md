# DhcpAuditLogGetParams function

## Description

The **DhcpAuditLogGetParams** function returns the audit log configuration settings from the DHCP server.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `Flags` [in]

Specifies a set of bit flags for filtering the audit log. Currently, this parameter is reserved and should be set to 0.

### `AuditLogDir` [out]

Unicode string that contains the directory where the audit log is stored as an absolute path within the file system.

### `DiskCheckInterval` [out]

Specifies the disk check interval for attempting to write the audit log to the specified file as the number of logged DHCP server events that should occur between checks. The default is 50 DHCP server events between checks.

### `MaxLogFilesSize` [out]

Specifies the maximum log file size, in bytes.

### `MinSpaceOnDisk` [out]

Specifies the minimum required disk space, in bytes, for audit log storage.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |

## See also

[DhcpAuditLogSetParams](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpauditlogsetparams)