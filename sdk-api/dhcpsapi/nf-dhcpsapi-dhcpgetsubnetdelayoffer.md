# DhcpGetSubnetDelayOffer function

## Description

The **DhcpGetSubnetDelayOffer** function obtains the delay period for DHCP OFFER messages after a DISCOVER message is received.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that contains the IP address of the subnet gateway.

### `TimeDelayInMilliseconds` [out]

Unsigned 16-bit integer value that receive the time to delay an OFFER message after receiving a DISCOVER message as configured on the DHCP server, in milliseconds.

**Note**

The memory for this parameter must be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified subnet is not defined on the DHCP server. |
| **ERROR_INVALID_PARAMETER** | One of the parameters provides an invalid value. |

## See also

[DhcpSetSubnetDelayOffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpsetsubnetdelayoffer)