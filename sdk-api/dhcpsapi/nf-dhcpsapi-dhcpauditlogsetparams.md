# DhcpAuditLogSetParams function

## Description

The **DhcpAuditLogSetParams** function sets the parameters for audit log generation on a DHCP server.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `Flags` [in]

Specifies a set of bit flags for filtering the audit log. Currently, this parameter is reserved and should be set to 0.

### `AuditLogDir` [in]

Unicode string that contains the specific directory and file name where the audit log will be stored. This string should contain the absolute path within the file system; for example, "C:\logs\dhcp\20031020.log".

### `DiskCheckInterval` [in]

Specifies the disk check interval for attempting to write the audit log to the specified file as the number of logged DHCP server events that should occur between checks. The default is 50 DHCP server events between checks.

### `MaxLogFilesSize` [in]

Specifies the maximum log file size, in bytes.

### `MinSpaceOnDisk` [in]

Specifies the minimum required disk space, in bytes, for audit log storage.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |

## See also

[DhcpAuditLogGetParams](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpauditloggetparams)