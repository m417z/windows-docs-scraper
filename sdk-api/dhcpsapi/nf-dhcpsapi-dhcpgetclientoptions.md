# DhcpGetClientOptions function

## Description

The **DhcpGetClientOptions** function returns only ERROR_NOT_IMPLEMENTED, as it is not used or supported.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `ClientIpAddress` [in]

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the IP address or hostname of the DHCP client whose option values will be returned.

### `ClientSubnetMask` [in]

[DHCP_IP_MASK](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the subnet mask of the DHCP client whose option values will be returned.

### `ClientOptions` [out]

Pointer to a [DHCP_OPTION_LIST](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_list) structure that contains the returned option values for the DHCP client.

**Note**

The memory for this parameter must be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_NOT_IMPLEMENTED** | This function is not implemented and is not supported. |

## See also

[DHCP_OPTION_LIST](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_list)