# DHCP_CLIENT_INFO_PB structure

## Description

The **DHCP_CLIENT_INFO_PB** structure defines information about a DHCPv4 client, including filter status information and any policies that resulted in the IPv4 address assignment.

## Members

### `ClientIpAddress`

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that contains the DHCPv4 client IPv4 address.

### `SubnetMask`

[DHCP IP_MASK](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that contains the DHCPv4 client IPv4 subnet mask.

### `ClientHardwareAddress`

[DHCP_CLIENT_UID](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_binary_data) structure that contains the hardware address (MAC address) of the DHCPv4 client.

### `ClientName`

Pointer to a null-terminated Unicode string that represents the DHCPv4 client machine name.

### `ClientComment`

Pointer to a null-terminated Unicode string that represents the description of the DHCPv4 client.

### `ClientLeaseExpires`

[DATE_TIME](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-date_time) structure that contains the lease expiry time for the DHCPv4 client. This is UTC time represented in the [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) format.

### `OwnerHost`

[DHCP_HOST_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_host_info) structure that contains information about the host machine (DHCPv4 server machine) that provided a lease to the DHCPv4 client.

### `bClientType`

Value that specifies the DHCPv4 client type. The possible values are below:

| Value | Meaning |
| --- | --- |
| **CLIENT_TYPE_UNSPECIFIED**<br><br>0x00 | The DHCPv4 client is not defined in the server database. |
| **CLIENT_TYPE_DHCP**<br><br>0x01 | The DHCPv4 client supports the DHCP protocol. |
| **CLIENT_TYPE_BOOTP**<br><br>0x02 | The DHCPv4 client supports the BOOTP protocol. |
| **CLIENT_TYPE_BOTH**<br><br>0x03 | The DHCPv4 client supports both the DHCPv4 and the BOOTP protocols |
| **CLIENT_TYPE_RESERVATION_FLAG**<br><br>0x04 | There is an IPv4 reservation created for the DHCPv4 client. |
| **CLIENT_TYPE_NONE**<br><br>0x64 | Backward compatibility for manual addressing. |

### `AddressState`

Value that specifies various states of the IPv4 address. The possible values are below:

| Value | Meaning |
| --- | --- |
| **ADDRESS_STATE_OFFERED**<br><br>0x0 | The DHCPv4 client is offered this IPv4 address. |
| **ADDRESS_STATE_ACTIVE**<br><br>0x1 | The IPv4 address is active and has an active DHCPv4 client lease record. |
| **ADDRESS_STATE_DECLINED**<br><br>0x2 | The IPv4 address request is declined by the DHCPv4 client; hence, it is a bad IPv4 address. |
| **ADDRESS_STATE_DOOM**<br><br>0x3 | The IPv4 address is in *DOOMED* state and is due to be deleted. |

### `Status`

[QuarantineStatus](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-quarantinestatus) enumeration that specifies possible health status values for the DHCPv4 client, as validated at the NAP server.

### `ProbationEnds`

[DATE_TIME](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-date_time) structure that contains the probation end time if the DHCPv4 client is on probation. The DHCPv4 client has full access to the network for this time period. This is UTC time represented in the [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) format.

### `QuarantineCapable`

**TRUE**, if the DHCPv4 client is quarantine-enabled; Otherwise, it is **FALSE**.

### `FilterStatus`

Integer flag value that specifies the status of the link-layer filter.

| Value | Meaning |
| --- | --- |
| **FILTER_STATUS_NONE**<br><br>0x00000001 | The DHCPv4 client MAC address does not match any filter. |
| **FILTER_STATUS_FULL_MATCH_IN_ALLOW_LIST**<br><br>0x00000002 | The DHCv4P client MAC address fully matches an allow list filter. |
| **FILTER_STATUS_FULL_MATCH_IN_DENY_LIST**<br><br>0x00000004 | The DHCPv4 client MAC address fully matches a deny list filter. |
| **FILTER_STATUS_WILDCARD_MATCH_IN_ALLOW_LIST**<br><br>0x00000008 | The DHCPv4 client MAC address has a wild card match in the allow list. |
| **FILTER_STATUS_WILDCARD_MATCH_IN_DENY_LIST**<br><br>0x00000010 | The DHCPv4 client MAC address has a wild card match in the deny list. |

### `PolicyName`

Pointer to a null-terminated Unicode string that represents the DHCP server policy name that resulted in the IPv4 address assignment to the DHCPv4 client in the lease.

## See also

[DHCP_CLIENT_INFO_PB_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_pb_array)

[DhcpV4CreateClientInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4createclientinfo)

[DhcpV4GetClientInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4getclientinfo)