# DhcpServerGetConfigV4 function

## Description

The **DhcpServerGetConfigV4** function returns the specific configuration settings of a DHCP server. This function extends the functionality of DhcpServerGetConfig by adding configuration parameters for the number of ping retries a server uses to determine connectability, the settings for the boot file table, and the audit log state. Configuration information includes information on the JET database used to store subnet and client lease information, and the supported protocols.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `ConfigInfo` [out]

Pointer to a [DHCP_SERVER_CONFIG_INFO_V4](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_server_config_info_v4) structure that contains the specific configuration information for the DHCP server.

**Note**

The memory for this parameter must be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |
| **ERROR_INVALID_PARAMETER** | One of the parameters provides an invalid value. |

## See also

[DHCP_SERVER_CONFIG_INFO_V4](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_server_config_info_v4)

[DhcpServerSetConfigV4](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpserversetconfigv4)