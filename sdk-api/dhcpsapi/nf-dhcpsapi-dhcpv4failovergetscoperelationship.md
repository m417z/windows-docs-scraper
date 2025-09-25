# DhcpV4FailoverGetScopeRelationship function

## Description

The **DhcpV4FailoverGetScopeRelationship** function retrieves the failover relationship that is configured on a specified DHCPv4 scope.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `ScopeId` [in]

A **DHCP_IP_ADDRESS** field that contains the IPv4 scope address for which the relationship details are to be retrieved.

### `pRelationship` [out]

Pointer to a [DHCP_FAILOVER_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_failover_relationship) structure that contains information about the retrieved failover relationship which contains **scopeId** field in its **pScopes** member.

**Note**

The memory for this parameter must be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |
| **ERROR_DHCP_FO_SCOPE_NOT_IN_RELATIONSHIP** | IPv4 subnet is not part of the failover relationship. |

## See also

[DhcpV4FailoverAddScopeToRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failoveraddscopetorelationship)

[DhcpV4FailoverDeleteScopeFromRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failoverdeletescopefromrelationship)

[DhcpV4FailoverGetScopeStatistics](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failovergetscopestatistics)