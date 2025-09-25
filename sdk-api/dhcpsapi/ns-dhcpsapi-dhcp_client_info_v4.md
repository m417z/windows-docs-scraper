# DHCP_CLIENT_INFO_V4 structure

## Description

The **DHCP_CLIENT_INFO_V4** structure defines a client information record used by the DHCP server, extending the definition provided in [DHCP_CLIENT_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info) by including client type information.

## Members

### `ClientIpAddress`

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that contains the assigned IP address of the DHCP client.

### `SubnetMask`

[DHCP_IP_MASK](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that contains the subnet mask value assigned to the DHCP client.

### `ClientHardwareAddress`

[DHCP_CLIENT_UID](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_binary_data) structure containing the MAC address of the client's network interface device.

### `ClientName`

Unicode string that specifies the network name of the DHCP client. This member is optional.

### `ClientComment`

Unicode string that contains a comment associated with the DHCP client. This member is optional.

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

## See also

[DATE_TIME](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-date_time)

[DHCP_CLIENT_INFO_ARRAY_V4](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_array_v4)

[DHCP_CLIENT_UID](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_binary_data)

[DHCP_HOST_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_host_info)

[DhcpGetClientInfoV4](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpgetclientinfov4)