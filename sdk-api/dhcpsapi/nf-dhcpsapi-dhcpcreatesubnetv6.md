# DhcpCreateSubnetV6 function

## Description

The **DhcpCreateSubnetV6** function creates a new subnet on the DHCP server.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

DHCP_IPV6_ADDRESS value that contains the IP address of the subnet's gateway.

### `SubnetInfo` [in]

DHCP_SUBNET_INFO_V6 structure that contains specific settings for the subnet, including the subnet mask and IP address of the subnet gateway.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The parameters were invalid. |
| **ERROR_DUPLICATE_TAG** | The specified scope already exists. |