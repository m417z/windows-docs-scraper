# DhcpAddSubnetElementV6 function

## Description

The **DhcpAddSubnetElementV6** function adds an element describing a feature or aspect of the subnet to the subnet entry in the DHCP database.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

DHCP_IPV6_ADDRESS structure that contains the IP address of the subnet.

### `AddElementInfo` [in]

Pointer to a DHCP_SUBNET_ELEMENT_DATA_V6 structure that contains the element data to add to the subnet. The V5 structure adds support for BOOTP clients.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The parameters were invalid. |
| **ERROR_DUPLICATE_TAG** | The specified scope already exists. |