# DhcpServerSetConfig function

## Description

The **DhcpServerSetConfig** function configures a DHCPv4 server with specific settings, including information on the JET database used to store subnet and client lease information, and the supported protocols.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `FieldsToSet` [in]

Specifies a set of bit flags that indicate which fields in *ConfigInfo* are set. If a flag is present, the corresponding field must also be populated in the [DHCP_SERVER_CONFIG_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_server_config_info) structure referenced by *ConfigInfo*, and will be used to set the same value on the DHCP server,

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
| **Set_Set_DebugFlag**<br><br>0x00000100 | The **DebugFlag** field is populated. |

### `ConfigInfo` [in]

[DHCP_SERVER_CONFIG_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_server_config_info) structure that contains the specific configuration information to set on the DHCP server, as indicated by the flags specified in *FieldsToSet*.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

## Remarks

The DHCPv4 server must be restarted for the following settings to be effective:

* Set_APIProtocolSupport
* Set_DatabaseName
* Set_DatabasePath
* Set_DatabaseLoggingFlag
* Set_RestoreFlag

## See also

[DHCP_SERVER_CONFIG_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_server_config_info)

[DhcpServerGetConfig](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpservergetconfig)

[DhcpServerSetConfigV4](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpserversetconfigv4)