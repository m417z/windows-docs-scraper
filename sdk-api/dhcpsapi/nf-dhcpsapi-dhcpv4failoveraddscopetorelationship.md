# DhcpV4FailoverAddScopeToRelationship function

## Description

The **DhcpV4FailoverAddScopeToRelationship** function adds a DHCPv4 scope to the specified failover relationship.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `pRelationship` [in]

Pointer to a [DHCP_FAILOVER_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_failover_relationship) structure that contains both the scope information to add and the failover relationship to modify.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | IPv4 scope doesn't exist on the DHCPv4 server. |
| **ERROR_DHCP_FO_SCOPE_ALREADY_IN_RELATIONSHIP** | IPv4 scope is already part of another failover relationship. |
| **ERROR_DHCP_FO_RELATIONSHIP_DOES_NOT_EXIST** | Failover relationship doesn't exist. |
| **ERROR_DHCP_FO_MAX_ADD_SCOPES** | Number of scopes being added to the failover relationship exceeds the max number of scopes which can be added to a failover relationship at one time. |

## See also

[DhcpV4FailoverDeleteScopeFromRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failoverdeletescopefromrelationship)

[DhcpV4FailoverGetScopeRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failovergetscoperelationship)

[DhcpV4FailoverGetScopeStatistics](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failovergetscopestatistics)