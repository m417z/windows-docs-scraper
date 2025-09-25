# DHCP_CLIENT_INFO_V5 structure

## Description

The **DHCP_CLIENT_INFO_V5** structure defines a client information record used by the DHCP server, extending the definition provided in [DHCP_CLIENT_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info) by including client type and address state information.

**Note** This structure is used by the following operating system versions: Windows 2000 and later.

## Members

### `ClientIpAddress`

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that contains the assigned IP address of the DHCP client.

### `SubnetMask`

[DHCP_IP_MASK](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that contains the subnet mask value assigned to the DHCP client.

### `ClientHardwareAddress`

[DHCP_CLIENT_UID](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_binary_data) structure containing the MAC address of the client's network interface device.

### `ClientName`

Pointer to a Unicode string that specifies the network name of the DHCP client. This member is optional.

### `ClientComment`

Pointer to a Unicode string that contains a comment associated with the DHCP client. This member is optional.

### `ClientLeaseExpires`

[DATE_TIME](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-date_time) structure that contains the date and time the DHCP client lease will expire, in UTC time.

### `OwnerHost`

[DHCP_HOST_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_host_info) structure that contains information on the DHCP server that assigned the IP address to the client.

### `bClientType`

Specifies the types of dynamic IP address service used by the client.

| Value | Meaning |
| --- | --- |
| **CLIENT_TYPE_UNSPECIFIED** | The client's dynamic IP address protocol is unknown. |
| **CLIENT_TYPE_DHCP** | The client uses DHCP for dynamic IP address service. |
| **CLIENT_TYPE_BOOTP** | The client uses BOOTP for dynamic IP address service. |
| **CLIENT_TYPE_BOTH** | The client can use either DHCP or BOOTP for dynamic IP address service. |
| **CLIENT_TYPE_NONE** | The client does not use a supported dynamic IP address service. |

### `AddressState`

Specifies the current state of the client IP address.

| Value | Meaning |
| --- | --- |
| **V5_ADDRESS_STATE_OFFERED** | The IP address is currently offered to the client; it has not yet become active. |
| **V5_ADDRESS_STATE_ACTIVE** | The IP address is currently in use by the client. |
| **V5_ADDRESS_STATE_DECLINED** | The IP address has been declined by the client and has not been released back into the pool. |
| **V5_ADDRESS_STATE_DOOM** | The IP address is "doomed", indicating that it is no longer available and will be removed from the pool. |

## Remarks

The **DHCP_CLIENT_INFO_V5** structure is returned by the [DhcpEnumSubnetClientsV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpenumsubnetclientsv5) function.

## See also

[DATE_TIME](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-date_time)

[DHCP_CLIENT_INFO_ARRAY_V5](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_array_v5)

[DHCP_CLIENT_UID](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_binary_data)

[DHCP_HOST_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_host_info)

[DhcpEnumSubnetClientsV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpenumsubnetclientsv5)