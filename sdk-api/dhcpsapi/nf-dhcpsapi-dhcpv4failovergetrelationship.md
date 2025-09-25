# DhcpV4FailoverGetRelationship function

## Description

The **DhcpV4FailoverGetRelationship** function retrieves relationship details for a specific relationship name.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `pRelationshipName` [in]

Pointer to a null-terminated Unicode string which represents the name of the relationship to retrieve.

### `pRelationship` [out]

Pointer to a [DHCP_FAILOVER_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_failover_relationship) structure that contains information about the retrieved failover relationship.

**Note**

The memory for this parameter must be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |
| **ERROR_DHCP_FO_RELATIONSHIP_DOES_NOT_EXIST** | The failover relationship does not exist. |

## See also

[DhcpV4FailoverCreateRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failovercreaterelationship)

[DhcpV4FailoverDeleteRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failoverdeleterelationship)

[DhcpV4FailoverEnumRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failoverenumrelationship)

[DhcpV4FailoverSetRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failoversetrelationship)