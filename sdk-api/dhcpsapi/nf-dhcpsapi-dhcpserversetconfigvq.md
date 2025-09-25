# DhcpServerSetConfigVQ function

## Description

The **DhcpServerSetConfigVQ** function sets or updates DHCP server settings.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `FieldsToSet` [in]

Specifies a bitmask of the fields to set in the [DHCP_SERVER_CONFIG_INFO_VQ](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_server_config_info_vq) structure passed to *ConfigInfo*.

### `ConfigInfo` [in]

Pointer to a [DHCP_SERVER_CONFIG_INFO_VQ](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_server_config_info_vq) structure that contains the new or updated settings for the DHCP server.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |

## Remarks

Most settings are effective immediately and do not require a restart.

The following DHCP server settings require a restart of the DHCP service:

* Set_APIProtocolSupport
* Set_DatabaseName
* Set_DatabasePath
* Set_DatabaseLoggingPath
* Set_RestoreFlag

## See also

[DHCP_SERVER_CONFIG_INFO_VQ](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_server_config_info_vq)