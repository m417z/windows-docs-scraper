# DHCP_SERVER_CONFIG_INFO_V4 structure

## Description

The **DHCP_SERVER_CONFIG_INFO_V4** structure defines the data used to configure the DHCP server.

## Members

### `APIProtocolSupport`

Specifies a set of bit flags that contain the RPC protocols supported by the DHCP server.

| Value | Meaning |
| --- | --- |
| **DHCP_SERVER_USE_RPC_OVER_TCPIP**<br><br>0x00000001 | TCP/IP can be used for DHCP API RPC calls. |
| **DHCP_SERVER_USE_RPC_OVER_NP**<br><br>0x00000002 | Named pipes can be used for DHCP API RPC calls. |
| **DHCP_SERVER_USE_RPC_OVER_LPC**<br><br>0x00000004 | Local Procedure Call (LPC) can be used for local DHCP API RPC calls. |

### `DatabaseName`

Unicode string that specifies the file name of the client lease JET database.

### `DatabasePath`

Unicode string that specifies the absolute path to **DatabaseName**.

### `BackupPath`

Unicode string that specifies the absolute path and file name of the backup client lease JET database.

### `BackupInterval`

Specifies the interval, in minutes, between backups of the client lease database.

### `DatabaseLoggingFlag`

Specifies a bit flag that indicates whether or not database actions should be logged.

| Value | Meaning |
| --- | --- |
| 0x00000001 | All database operations will be logged. |

### `RestoreFlag`

Specifies a bit flag that indicates whether or not a database restore operation should be performed.

| Value | Meaning |
| --- | --- |
| 0x00000001 | The client lease database should be restored from the path and file specified in **BackupPath**. |

### `DatabaseCleanupInterval`

Specifies the interval, in minutes, between cleanup operations performed on the client lease database.

### `DebugFlag`

Reserved. This field should be set to 0x00000000.

### `dwPingRetries`

Specifies a value equal to or greater than 0 or less than 6 that indicates the number of times to ping an unresponsive client before determining unavailability.

### `cbBootTableString`

Specifies the size of **wszBootTableString**, in bytes.

### `wszBootTableString`

Unicode string that contains the boot table string for the DHCP server. ?? More information needed. ??

### `wszBootTableString.size_is`

### `wszBootTableString.size_is.cbBootTableString/2`

### `fAuditLog`

Specifies whether or not to enable audit logging on the DHCP server. A value of **TRUE** indicates that an audit log is generated; **FALSE** indicates that audit logging is not performed.

## See also

[DhcpServerGetConfigV4](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpservergetconfigv4)

[DhcpServerSetConfigV4](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpserversetconfigv4)