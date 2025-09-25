# DHCP_SERVER_CONFIG_INFO_VQ structure

## Description

The **DHCP_SERVER_CONFIG_INFO_VQ** structure defines settings for the DHCP server.

## Members

### `APIProtocolSupport`

Integer value that defines the type of RPC protocol used by the DHCP server to register with RPC. Following is the set of supported types, which may be bitwise OR'd to produce valid values.

| Value | Meaning |
| --- | --- |
| **DHCP_SERVER_USE_RPC_OVER_TCPIP**<br><br>0x00000001 | RPC protocol over TCP is used by the DHCP server to register. |
| **DHCP_SERVER_USE_RPC_OVER_NP**<br><br>0x00000002 | RPC protocol over named pipes is used by the DHCP server to register.<8> |
| **DHCP_SERVER_USE_RPC_OVER_LPC**<br><br>0x00000004 | RPC protocol over LPC is used by the DHCP server to register.<9> |
| **DHCP_SERVER_USE_RPC_OVER_ALL**<br><br>0x00000007 | The DHCP server supports all of the preceding protocols. |

### `DatabaseName`

Pointer to a null-terminated Unicode string that represents the DHCP server database name that is used by the DHCP server for persistent storage.

### `DatabasePath`

Pointer to a null-terminated Unicode string that contains the absolute path, where the DHCP server database is stored.

### `BackupPath`

Pointer to a null-terminated Unicode string that contains the absolute path for backup storage that is used by the DHCP server for backup.

### `BackupInterval`

Integer value that specifies the interval in minutes between backups of the DHCP server database.

### `DatabaseLoggingFlag`

Integer value that indicates the transaction logging mode of the DHCP server. The value 1 indicates that the transaction log is enabled for the DHCP server, and 0 indicates that the transaction log is disabled for the DHCP server.

### `RestoreFlag`

Integer value used as a BOOL flag. If this setting is **TRUE** (1), the DHCP service loads the DHCP database from the backup database on DHCP service startup. The default value of this flag is **FALSE** (0).

### `DatabaseCleanupInterval`

Integer value that specifies the maximum time interval that DOOMED IPv4 DHCP client records are allowed to persist within the DHCP server database.

### `DebugFlag`

Integer flag value that specifies the level of logging done by the DHCP server. The following table defines the set values that can be used. Specifying '0xFFFFFFFF' enables all types of logging.

LOW WORD bitmask (0x0000FFFF) for low-frequency debug output.

| Value | Meaning |
| --- | --- |
| **DEBUG_ADDRESS**<br><br>0x00000001 | Enable IP-address-related logging. |
| **DEBUG_CLIENT**<br><br>0x00000002 | Enable DHCP-client-API-related logging. |
| **DEBUG_PARAMETERS**<br><br>0x00000004 | Enable DHCP-server-parameters-related logging. |
| **DEBUG_OPTIONS**<br><br>0x00000008 | Enable DHCP-options-related logging. |
| **DEBUG_ERRORS**<br><br>0x00000010 | Enable DHCP-errors-related logging. |
| **DEBUG_STOC**<br><br>0x00000020 | Enable DHCPv4 and DCHPv6-protocol-errors-related logging. |
| **DEBUG_INIT**<br><br>0x00000040 | Enable DHCP-server-initialization-related logging. |
| **DEBUG_SCAVENGER**<br><br>0x00000080 | Enable scavenger's-error-related logging. |
| **DEBUG_TIMESTAMP**<br><br>0x00000100 | Enable timing-errors-related logging. |
| **DEBUG_APIS**<br><br>0x00000200 | Enable DHCP-APIs-related logging. |
| **DEBUG_REGISTRY**<br><br>0x00000400 | Enable the logging of errors caused by registry setting operations. |
| **DEBUG_JET**<br><br>0x00000800 | Enable the logging of the DHCP server database errors. |
| **DEBUG_THREADPOOL**<br><br>0x00001000 | Enable the logging related to executing thread pool operations. |
| **DEBUG_AUDITLOG**<br><br>0x00002000 | Enable the logging related to errors caused by audit log operations. |
| **DEBUG_QUARANTINE**<br><br>0x00004000 | Enable the logging of errors caused by quarantine errors. |
| **DEBUG_MISC**<br><br>0x00008000 | Enable the logging caused by miscellaneous errors. |

HIGH WORD bitmask (0xFFFF0000) for high-frequency debug output, that is, more verbose.

| Value | Meaning |
| --- | --- |
| **DEBUG_MESSAGE**<br><br>0x00010000 | Enable the logging related to debug messages. |
| **DEBUG_API_VERBOSE**<br><br>0x00020000 | Enable the logging related to DHCP API verbose errors. |
| **DEBUG_DNS**<br><br>0x00040000 | Enable the logging related to DNS messages. |
| **DEBUG_MSTOC**<br><br>0x00080000 | Enable the logging related to multicast protocol layer errors. |
| **DEBUG_TRACK**<br><br>0x00100000 | Enable the logging tracking specific problems. |
| **DEBUG_ROGUE**<br><br>0x00200000 | Enable the logging related to a ROGUE DHCP server. |
| **DEBUG_PNP**<br><br>0x00400000 | Enable the logging related to PNP interface errors. |
| **DEBUG_PERF**<br><br>0x01000000 | Enable the logging of performance-related messages. |
| **DEBUG_ALLOC**<br><br>0x02000000 | Enable the logging of allocation-related and deallocation-related messages. |
| **DEBUG_PING**<br><br>0x04000000 | Enable the logging of synchronous ping–related messages. |
| **DEBUG_THREAD**<br><br>0x08000000 | Enable the logging of thread-related messages. |
| **DEBUG_TRACE**<br><br>0x10000000 | Enable the logging for tracing through code messages. |
| **DEBUG_TRACE_CALLS**<br><br>0x20000000 | Enable the logging for tracing through piles of code. |
| **DEBUG_STARTUP_BRK**<br><br>0x40000000 | Enable the logging related to debugger break during setup messages. |
| **DEBUG_LOG_IN_FILE**<br><br>0x80000000 | Enable the logging of debug output in a file. |

### `dwPingRetries`

Integer value that specifies the number of retries that the DHCP server can make to verify whether a particular address is already in use by any client by issuing a ping before issuing any address to the DHCP client (valid range: 0–5, inclusive).

### `cbBootTableString`

Integer value that contains the size of the BOOT TABLE given to the DHCP client.

### `wszBootTableString`

Pointer to a null-terminated Unicode string that contains the absolute path of the BOOTP TABLE given to the BOOTP client.

### `wszBootTableString.size_is`

### `wszBootTableString.size_is.cbBootTableString/2`

### `fAuditLog`

If **TRUE**, an audit log will be written by the DHCP server; if **FALSE**, it will not.

### `QuarantineOn`

If **TRUE**, Quarantine is turned ON on the DHCP server; if **FALSE**, it is turned OFF.

### `QuarDefFail`

Integer value that determines the default policy for a DHCP NAP server when an NPS server is not reachable. Choices include Quarantine/unrestricted/Drop Request.

### `QuarRuntimeStatus`

If **TRUE**, NAP is enabled on the DHCP server; if **FALSE**, it is not.