# DhcpV4FailoverDeleteScopeFromRelationship function

## Description

The **DhcpV4FailoverDeleteScopeFromRelationship** function deletes a DHCPv4 scope from the specified failover relationship.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `pRelationship` [in]

Pointer to a [DHCP_FAILOVER_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_failover_relationship) structure that contains the scopes to delete. The scopes are defined in the **pScopes** member of this structure.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | IPv4 scope doesn't exist on the DHCPv4 server. |
| **ERROR_DHCP_FO_RELATIONSHIP_DOES_NOT_EXIST** | Failover relationship doesn't exist. |
| **ERROR_DHCP_FO_SCOPE_NOT_IN_RELATIONSHIP** | IPv4 subnet is not part of the failover relationship. |

## See also

[DhcpV4FailoverAddScopeToRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failoveraddscopetorelationship)

[DhcpV4FailoverGetScopeRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failovergetscoperelationship)

[DhcpV4FailoverGetScopeStatistics](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failovergetscopestatistics)