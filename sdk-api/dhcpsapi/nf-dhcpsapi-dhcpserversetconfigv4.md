# DhcpServerSetConfigV4 function

## Description

The **DhcpServerSetConfigV4** function configures a DHCP server with specific settings, including information on the JET database used to store subnet and client lease information, and the supported protocols.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `FieldsToSet` [in]

Specifies a set of bit flags that indicate which fields in *ConfigInfo* are set. If a flag is present, the corresponding field must also be populated in the [DHCP_SERVER_CONFIG_INFO_V4](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_server_config_info_v4) structure referenced by *ConfigInfo*, and will be used to set the same value on the DHCP server,

| Value | Meaning |
| --- | --- |
| **Set_APIProtocolSupport**<br><br>0x00000001 | The **APIProtocolSupport** field is populated. |
| **Set_DatabaseName**<br><br>0x00000002 | The **DatabaseName** field is populated. |
| **Set_DatabasePath**<br><br>0x00000004 | The **DatabasePath** field is populated. |
| **Set_BackupPath**<br><br>0x00000008 | The **BackupPath** field is populated. |
| **Set_BackupInterval**<br><br>0x00000010 | The **BackupInterval** field is populated. |
| **Set_DatabaseLoggingFlag**<br><br>0x00000020 | The **DatabaseLoggingFlag** field is populated. |
| **Set_RestoreFlag**<br><br>0x00000040 | The **RestoreFlag** field is populated. |
| **Set_DatabaseCleanupInterval**<br><br>0x00000080 | The **DatabaseCleanupInterval** field is populated. |
| **Set_DebugFlag**<br><br>0x00000100 | The **DebugFlag** field is populated. |
| **Set_PingRetries**<br><br>0x00000200 | The **PingRetries** field is populated. |
| **Set_BootFileTable**<br><br>0x00000400 | The **BootFileTable** field is populated. |
| **Set_AuditLogState**<br><br>0x00000800 | The **AuditLogState** field is populated. |

### `ConfigInfo` [in]

[DHCP_SERVER_CONFIG_INFO_V4](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_server_config_info_v4) structure that contains the specific DHCP server configuration settings as indicated by the bit flags set in *FieldsToSet*.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |
| **ERROR_INVALID_PARAMETER** | One of the parameters provides an invalid value. |

## See also

[DHCP_SERVER_CONFIG_INFO_V4](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_server_config_info_v4)

[DhcpServerGetConfigV4](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpservergetconfigv4)