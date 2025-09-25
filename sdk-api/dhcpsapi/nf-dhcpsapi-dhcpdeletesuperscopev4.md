# DhcpDeleteSuperScopeV4 function

## Description

The **DhcpDeleteSuperScopeV4** function deletes a superscope from the DHCP server.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `SuperScopeName` [in]

Unicode string that specifies the name of the superscope to delete.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified IPv4 subnet does not exist on the DHCP server. |

## Remarks

Deleting a superscope does not delete the subnets present in the superscope; it simply removes the table that groups the subnets into a superscope. Individual subnets should be deleted using [DhcpDeleteSubnet](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpdeletesubnet).

## See also

[DhcpGetSuperScopeInfoV4](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpgetsuperscopeinfov4)

[DhcpSetSuperScopeV4](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpsetsuperscopev4)