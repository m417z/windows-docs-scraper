# DhcpV4CreateClientInfo function

## Description

The **DhcpV4CreateClientInfo** function creates a DHCPv4 client lease record in the DHCP server database.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `ClientInfo` [in]

Pointer to a [DHCP_CLIENT_INFO_PB](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info) structure that contains the DHCP client lease record information. The **ClientIpAddress** and **ClientHardwareAddress** fields of this structure are required, all others are optional.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the *DHCP Administrators* security group. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The **ClientIpAddress** passed within *ClientInfo* does not match any DHCPv4 scope configured on the DHCP server. |
| **ERROR_DHCP_CLIENT_EXISTS** | The provided DHCP client record already exists in the DHCP server database. |

## Remarks

This function does not allow creation of leases if there is no scope corresponding to the *ClientIpAddress* configured on the server and instead returns **ERROR_DHCP_SUBNET_NOT_PRESENT**. It marks the specified client IP address as unavailable (or distributed) to avoid IP collisions. The addresses thus marked are also reflected in the scope’s address statistics.

Unlike [DhcpCreateClientInfoVQ](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpcreateclientinfovq), this function uses the **bClientType**, **AddressState**, **Status**, **ProbationEnds** and **QuarantineCapable** fields passed within the [DHCP_CLIENT_INFO_PB](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info) structure to *ClientInfo* when creating the lease record. It also adds the new field **PolicyName** if passed within *ClientInfo* in the new lease record. There is no validation of whether the **PolicyName** corresponds to a valid policy configured on the DHCP server or corresponding scope.

## See also

[DhcpV4GetClientInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4getclientinfo)

[DhcpV6CreateClientInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv6createclientinfo)