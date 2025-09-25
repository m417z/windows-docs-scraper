# DhcpServerSetConfigV6 function

## Description

The **DhcpServerSetConfigV6** function sets the DHCPv6 server configuration data at the scope or server level.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `ScopeInfo` [in]

Pointer to a [DHCP_OPTION_SCOPE_INFO6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_scope_info6) structure that contains the configuration information at the scope or server level.

### `FieldsToSet` [in]

Specifies the set of value that indicate the type of configuration information provided in *ConfigInfo*. Only one of these values may be set per call.

| Value | Meaning |
| --- | --- |
| **Set_UnicastFlag**<br><br>0x00000001 | Not used. |
| **Set_RapidCommitFlag**<br><br>0x00000002 | Not used. |
| **Set_PreferredLifetime**<br><br>0x00000004 | Sets the preferred lifetime value for a non-temporary IPv6 address. |
| **Set_ValidLifetime**<br><br>0x00000008 | Sets the valid lifetime value for a non-temporary IPv6 address. |
| **Set_T1**<br><br>0x00000010 | Sets the T1 time value. |
| **Set_T2**<br><br>0x00000020 | Sets the T2 time value. |
| **Set_PreferredLifetimeIATA**<br><br>0x00000040 | Not used. |
| **Set_ValidLifetimeIATA**<br><br>0x00000080 | Not used. |
| **Set_AuditLogState**<br><br>0x00000800 | Sets the audit log state in the registry. |

### `ConfigInfo` [in]

Pointer to a [DHCP_SERVER_CONFIG_INFO_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_server_config_info_v6) structure that contains configuration information of the type indicated by the value supplied in *FieldsToSet*.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |

## See also

[DHCP_SERVER_CONFIG_INFO_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_server_config_info_v6)