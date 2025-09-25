# DhcpGetMibInfoV5 function

## Description

The **DhcpGetMibInfoV5** function obtains a MIB data structure that contains current statistics about the specified DHCP server.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a zero-delimited string that contains the IPv4 address of the DHCP server for which statistical information is to be retrieved. This value is specified in the format "*.*.*.*".

If this parameter is **NULL**, then the local DHCP server process is queried.

### `MibInfo` [out]

Pointer to the address of a [DHCP_MIB_INFO_V5](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_mib_info_v5) structure that contains statistical information about the DHCP server specified in the *ServerIpAddress* parameter.

**Note**

The memory for this parameter must be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |
| **ERROR_INVALID_PARAMETER** | One of the parameters provides an invalid value. |

## See also

[DHCP_MIB_INFO_V5](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_mib_info_v5)