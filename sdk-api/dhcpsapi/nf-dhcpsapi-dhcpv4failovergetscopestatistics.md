# DhcpV4FailoverGetScopeStatistics function

## Description

The **DhcpV4FailoverGetScopeStatistics** function retrieves the address usage statistics of a specific scope that is part of a failover relationship.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `ScopeId` [in]

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that contains the IPv4 scope address of the address usage statistics to retrieve.

### `pStats` [out]

Pointer to a [DHCP_FAILOVER_STATISTICS](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_failover_statistics) structure that contains the address usage information for *scopeId*.

**Note**

The memory for this parameter must be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |

## See also

[DhcpV4FailoverAddScopeToRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failoveraddscopetorelationship)

[DhcpV4FailoverDeleteScopeFromRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failoverdeletescopefromrelationship)

[DhcpV4FailoverGetScopeRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failovergetscoperelationship)