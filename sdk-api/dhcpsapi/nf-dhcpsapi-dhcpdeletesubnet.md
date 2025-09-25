# DhcpDeleteSubnet function

## Description

The **DhcpDeleteSubnet** function deletes a subnet from the DHCP server.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address of the subnet to delete.

### `SubnetAddress` [in]

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that contains the IP address of the subnet gateway used to identify the subnet.

### `ForceFlag` [in]

[DHCP_FORCE_FLAG](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_force_flag) enumeration value that indicates the type of delete operation to perform (full force, failover force, or no force).

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

## Remarks

Usually, you will use either **DhcpFullForce** or **DhcpNoForce** as the value for *ForceFlag*. The **DhcpFailoverForce** value is intended for use when cleaning up a broken or improperly configured DHCP failover configuration. In that case, use of **DhcpFailoverForce** ensures that the entire DNS configuration isn't improperly deleted while cleaning up the DHCP failover configuration. Note that the minimum server OS requirement for **DhcpFailoverForce** is Windows Server 2012 R2 with KB 3100473 installed.

## See also

 [DHCP_FORCE_FLAG](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_force_flag)

[DhcpCreateSubnet](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpcreatesubnet)

[DhcpEnumSubnets](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpenumsubnets)