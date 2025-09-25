# DhcpServerGetConfigVQ function

## Description

The **DhcpServerGetConfigVQ** function retrieves the current DHCP server configuration settings.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `ConfigInfo` [out]

Pointer to the address of a [DHCP_SERVER_CONFIG_INFO_VQ](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_server_config_info_vq) structure that contains the returned DHCP server configuration settings.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |

## Remarks

The caller of this function must free the memory pointed to by *ConfigInfo* by calling [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## See also

[DHCP_SERVER_CONFIG_INFO_VQ](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_server_config_info_vq)

[DhcpServerSetConfigVQ](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpserversetconfigvq)