# DhcpV4FailoverEnumRelationship function

## Description

The **DhcpV4FailoverEnumRelationship** function enumerates all failover relationships present on the server.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `ResumeHandle` [in, out]

Pointer to a [DHCP_RESUME_HANDLE](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that identifies this enumeration for use in subsequent calls to this function.

Initially, this value should be zero on input. If successful, the returned value should be used for subsequent enumeration requests. For example, if *PreferredMaximum* is set to 100, and 200 reservation elements are configured on the server, the resume handle can be used after the first 100 policies are retrieved to obtain the next 100 on a subsequent call.

### `PreferredMaximum` [in]

The maximum number of failover relationship elements to return in *pRelationship*. If *PreferredMaximum* is greater than the number of remaining non-enumerated policies on the server, the remaining number of non-enumerated policies is returned.

### `pRelationship` [out]

Pointer to a [DHCP_FAILOVER_RELATIONSHIP_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_failover_relationship_array) structure that contains an array of the failover relationships available on the DHCP server. If no relationships are configured, this value is **NULL**.

### `RelationshipRead` [out]

Pointer to a **DWORD** that specifies the number of failover relationship elements returned in *pRelationship*.

### `RelationshipTotal` [out]

Pointer to a **DWORD** that specifies the number of failover relationships configured on the DHCP server that have not yet been enumerated.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following. or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes)

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |
| **ERROR_MORE_DATA** | There are more elements available to enumerate. |
| **ERROR_NO_MORE_ITEMS** | There are no more elements left to enumerate. |

## See also

[DhcpV4FailoverCreateRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failovercreaterelationship)

[DhcpV4FailoverDeleteRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failoverdeleterelationship)

[DhcpV4FailoverGetRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failovergetrelationship)

[DhcpV4FailoverSetRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failoversetrelationship)