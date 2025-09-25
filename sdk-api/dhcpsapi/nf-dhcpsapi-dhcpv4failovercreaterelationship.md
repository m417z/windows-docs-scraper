# DhcpV4FailoverCreateRelationship function

## Description

The **DhcpV4FailoverCreateRelationship** function creates a new DHCPv4 failover relationship between two servers.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `pRelationship` [in]

Pointer to a [DHCP_FAILOVER_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_failover_relationship) structure that contains information about the DHCPv4 failover relationship to create.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | IPv4 scope doesn't exist on the DHCPv4 server. |
| **ERROR_DHCP_FO_SCOPE_ALREADY_IN_RELATIONSHIP** | IPv4 is already part of another failover relationship. |
| **ERROR_DHCP_FO_RELATIONSHIP_EXISTS** | A failover relationship with the same name already exists on DHCPv4 server. |
| **ERROR_DHCP_FO_RELATIONSHIP_NAME_TOO_LONG** | The failover relationship name is longer than the expected length. |
| **ERROR_DHCP_FO_MAX_RELATIONSHIPS** | The maximum number of allowed failover relationship configured on the DHCP server has exceeded. |

## See also

[DhcpV4FailoverDeleteRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failoverdeleterelationship)

[DhcpV4FailoverEnumRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failoverenumrelationship)

[DhcpV4FailoverGetRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failovergetrelationship)

[DhcpV4FailoverSetRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failoversetrelationship)