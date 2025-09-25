# DhcpV4FailoverSetRelationship function

## Description

The **DhcpV4FailoverSetRelationship** function sets or modifies the parameters of a DHCPv4 server failover relationship.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `Flags` [in]

A bitmask that specifies the fields to update in *pRelationship*. Each value specifies a member of the [DHCP_FAILOVER_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_failover_relationship) structure to be modified.

| Flag | Meaning |
| --- | --- |
| **MCLT**<br><br>0x00000001 | The **mclt** member in *pRelationship* parameter structure is populated. |
| **SAFEPERIOD**<br><br>0x00000002 | The **safePeriod** member in *pRelationship* parameter structure is populated. |
| **CHANGESTATE**<br><br>0x00000004 | The **state** member in *pRelationship* parameter structure is populated. |
| **PERCENTAGE**<br><br>0x00000008 | The **percentage** member in *pRelationship* parameter structure is populated. |
| **MODE**<br><br>0x00000010 | The **mode** member in *pRelationship* parameter structure is populated. |
| **PREVSTATE**<br><br>0x00000020 | The **prevState** member in *pRelationship* parameter structure is populated. |

### `pRelationship` [in]

Pointer to a [DHCP_FAILOVER_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_failover_relationship) structure that contains update information about the fields in the DHCPv4 failover relationship.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |
| **ERROR_DHCP_FO_RELATIONSHIP_DOES_NOT_EXIST** | The failover relationship doesn’t exist. |

## See also

[DhcpV4FailoverCreateRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failovercreaterelationship)

[DhcpV4FailoverDeleteRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failoverdeleterelationship)

[DhcpV4FailoverEnumRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failoverenumrelationship)

[DhcpV4FailoverGetRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failovergetrelationship)