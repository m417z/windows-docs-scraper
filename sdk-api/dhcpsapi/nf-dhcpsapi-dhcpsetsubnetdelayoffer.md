# DhcpSetSubnetDelayOffer function

## Description

The **DhcpSetSubnetDelayOffer** function sets the delay period for DHCP OFFER messages after a DISCOVER message is received, for a specific DHCP scope.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

**DHCP_IP_ADDRESS** value that contains the IP address of the subnet gateway.

### `TimeDelayInMilliseconds` [in]

Unsigned 16-bit integer value that specifies the time to delay an OFFER message after receiving a DISCOVER message, in milliseconds, and set for a particular scope. This value must be between 0 and 1000 (milliseconds). The default value is 0.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified subnet is not defined on the DHCP server. |
| **ERROR_DHCP_INVALID_DELAY** | The time delay was set to a value less than 0 or greater than 1000. |
| **ERROR_INVALID_PARAMETER** | One of the parameters provides an invalid value. |

## See also

[DhcpGetSubnetDelayOffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpgetsubnetdelayoffer)