# DhcpSetSuperScopeV4 function

## Description

The **DhcpSetSuperScopeV4** function sets a subnet as the superscope on a DHCP server.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that contains the IP address of the subnet that will be defined as the superscope.

### `SuperScopeName` [in, optional]

Pointer to a Unicode string that specifies the new name of the superscope.

### `ChangeExisting` [in]

Specifies whether or not to change an existing superscope to the supplied subnet. If this parameter is **TRUE** and another subnet is set as the superscope, change the superscope to the supplied subnet; otherwise, if set to **FALSE** and another subnet is defined as the superscope, do not change it.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |
| **ERROR_INVALID_PARAMETER** | One of the parameters provides an invalid value. |

## Remarks

A *superscope* is a subnet that contains the complete scope of all addresses available for lease (or are already leased) across the subnet scopes defined on the DHCP server.

## See also

[DhcpDeleteSuperScopeV4](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpdeletesuperscopev4)