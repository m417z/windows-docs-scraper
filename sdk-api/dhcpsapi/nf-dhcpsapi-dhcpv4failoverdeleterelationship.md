# DhcpV4FailoverDeleteRelationship function

## Description

The **DhcpV4FailoverDeleteRelationship** function deletes a DHCPv4 failover relationship between two servers.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `pRelationshipName` [in]

Pointer to null-terminated Unicode string that represents the name of the relationship to delete.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |
| **ERROR_DHCP_FO_RELATIONSHIP_DOES_NOT_EXIST** | The failover relationship doesn't exist. |

## See also

[DhcpV4FailoverCreateRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failovercreaterelationship)

[DhcpV4FailoverEnumRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failoverenumrelationship)

[DhcpV4FailoverGetRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failovergetrelationship)

[DhcpV4FailoverSetRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failoversetrelationship)