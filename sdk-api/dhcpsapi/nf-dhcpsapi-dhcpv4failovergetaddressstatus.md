# DhcpV4FailoverGetAddressStatus function

## Description

The **DhcpV4FailoverGetAddressStatus** function returns the status of a IPv4 address.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that contains the IPv4 address whose status is being requested.

### `pStatus` [in, out]

Pointer to a DWORD that returns the status of the IPv4 address as specified in the table below:

| Value | Meaning |
| --- | --- |
| 0 | The IPv4 address will be leased by a primary server. |
| 1 | The IPv4 address will be leased by a secondary server. |
| 2 | The IPv4 address is part of an exclusion range. |
| 3 | The IPv4 address is a reservation. |

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).