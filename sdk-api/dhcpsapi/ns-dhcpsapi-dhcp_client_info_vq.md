# DHCP_CLIENT_INFO_VQ structure

## Description

The **DHCP_CLIENT_INFO_VQ** structure defines information about the DHCPv4 client.

## Members

### `ClientIpAddress`

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) type value that contains the DHCPv4 client's IPv4 address.

### `SubnetMask`

[DHCP IP_MASK](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) type value that contains the DHCPv4 client's IPv4 subnet mask address.

### `ClientHardwareAddress`

GUID value that contains the hardware address (MAC address) of the DHCPv4 client.

### `ClientName`

Ppointer to a null-terminated Unicode string that represents the DHCPv4 client's machine name.

### `ClientComment`

Pointer to a null-terminated Unicode string that represents the description given to the DHCPv4 client.

### `ClientLeaseExpires`

[DATE_TIME](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-date_time) structure that contains the lease expiry time for the DHCPv4 client. This is UTC time represented in the [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) format.

### `OwnerHost`

[DHCP_HOST_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_host_info) structure that contains information about the host machine (DHCPv4 server machine) that has provided a lease to the DHCPv4 client.

### `bClientType`

Possible types of the DHCPv4 client. The possible values are shown in the following table.

| Value | Meaning |
| --- | --- |
| **CLIENT_TYPE_UNSPECIFIED**<br><br>0x00 | A DHCPv4 client other than ones defined in this table. |
| **CLIENT_TYPE_DHCP**<br><br>0x01 | The DHCPv4 client supports the DHCP protocol. |
| **CLIENT_TYPE_BOOTP**<br><br>0x02 | The DHCPv4 client supports the BOOTP protocol. |
| **CLIENT_TYPE_BOTH**<br><br>0x03 | The DHCPv4 client understands both the DHCPv4 and the BOOTP protocols. |
| **CLIENT_TYPE_RESERVATION_FLAG**<br><br>0x04 | There is an IPv4 reservation created for the DHCPv4 client. |
| **CLIENT_TYPE_NONE**<br><br>0x64 | Backward compatibility for manual addressing. |

### `AddressState`

Possible states of the IPv4 address given to the DHCPv4 client. The following table represents the different values and their meanings.

| Value | Meaning |
| --- | --- |
| **ADDRESS_STATE_OFFERED**<br><br>0x00 | The DHCPv4 client has been offered this IPv4 address. |
| **ADDRESS_STATE_ACTIVE**<br><br>0x01 | The IPv4 address is active and has an active DHCPv4 client lease record. |
| **ADDRESS_STATE_DECLINED**<br><br>0x02 | The IPv4 address request was declined by the DHCPv4 client; hence, it is a bad IPv4 address. |
| **ADDRESS_STATE_DOOM**<br><br>0x03 | The IPv4 address is in DOOMED state and is due to be deleted. |

### `Status`

[QuarantineStatus](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-quarantinestatus) enumeration that specifies possible health status values for the DHCPv4 client, as validated at the NAP server.

### `ProbationEnds`

This is of type [DATE_TIME](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-date_time), containing the end time of the probation if the DHCPv4 client is on probation. For this time period, the DHCPv4 client has full access to the network.

### `QuarantineCapable`

If **TRUE**, the DHCPv4 client is quarantine-enabled; if **FALSE**, it is not.

## Remarks

**DHCP_CLIENT_INFO_VQ** augments the DHCP_CLIENT_INFO_V5 structure by including information relating to the NAP settings of the DHCPv4 client.

## See also

[DHCP Server Management Type Definitions](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions)

[DHCP_HOST_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_host_info)