## Description

The **DHCPV4_FAILOVER_CLIENT_INFO** structure defines DHCP server scope statistics that are part of a failover relationship.

## Members

### `ClientIpAddress`

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that contains the DHCPv4 client IPv4 address.

### `SubnetMask`

[DHCP_IP_MASK](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that contains the DHCPv4 client IPv4 subnet mask.

### `ClientHardwareAddress`

[DHCP_CLIENT_UID](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_binary_data) structure that contains the hardware address (MAC address) of the DHCPv4 client.

### `ClientName`

Pointer to a null-terminated Unicode string that represents the DHCPv4 client machine name.

### `ClientComment`

Pointer to a null-terminated Unicode string that represents the description of the DHCPv4 client.

### `ClientLeaseExpires`

[DATE_TIME](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-date_time) structure that contains the lease expiry time for the DHCPv4 client. This is UTC time represented in the [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) format.

### `OwnerHost`

[DHCP_HOST_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_host_info) structure that contains information about the host machine (DHCPv4 server) that provided a lease to the DHCPv4 client.

### `bClientType`

Value that specifies the DHCPv4 client type. The possible values are below.

| Value | Meaning |
| --- | --- |
| **CLIENT_TYPE_UNSPECIFIED**<br><br>0x00 | The DHCPv4 client is not defined in the server database. |
| **CLIENT_TYPE_DHCP**<br><br>0x01 | The DHCPv4 client supports the DHCP protocol. |
| **CLIENT_TYPE_BOOTP**<br><br>0x02 | The DHCPv4 client supports the BOOTP protocol. |
| **CLIENT_TYPE_BOTH**<br><br>0x03 | The DHCPv4 client supports both the DHCPv4 and the BOOTP protocols |
| **CLIENT_TYPE_RESERVATION_FLAG**<br><br>0x04 | There is an IPv4 reservation created for the DHCPv4 client. |
| **CLIENT_TYPE_NONE**<br><br>0x64 | Backward compatibility for manual addressing. |

### `AddressState`

Value that specifies various states of the IPv4 address. The LSB is bit 0 and the MSB is bit 7. The possible values are below.

BIT 0 and BIT 1 signify the DHCPv4 client IPv4 address state, as shown in the following table.

| Value | Meaning |
| --- | --- |
| **ADDRESS_STATE_OFFERED**<br><br>0x0 | The DHCPv4 client is offered this IPv4 address. |
| **ADDRESS_STATE_ACTIVE**<br><br>0x1 | The IPv4 address is active and has an active DHCPv4 client lease record. |
| **ADDRESS_STATE_DECLINED**<br><br>0x2 | The IPv4 address request is declined by the DHCPv4 client; hence, it is a bad IPv4 address. |
| **ADDRESS_STATE_DOOM**<br><br>0x3 | The IPv4 address is in *DOOMED* state and is due to be deleted. |

BIT 2 and BIT 3 signify information related to Name Protection for the leased IPv4 address, as shown in the following table.

| Value | Meaning |
| --- | --- |
| **ADDRESS_BIT_NO_DHCID**<br><br>0x0 | The address is leased to the DHCPv4 client without *DHCID* as defined in sections 3 and 3.5 of [RFC4701](http://www.faqs.org/rfcs/rfc4701.html). |
| **ADDRESS_BIT_DHCID_NO_CLIENTIDOPTION**<br><br>0x1 | The address is leased to the DHCPv4 client with *DHCID* but without the client ID option as defined in sections 3 and 3.5 of [RFC4701](http://www.faqs.org/rfcs/rfc4701.html). |
| **ADDRESS_BIT_DHCID_WITH_CLIENTIDOPTION**<br><br>0x2 | The address is leased to the DHCPv4 client with *DHCID* and the client ID option as defined in sections 3 and 3.5 of [RFC4701](http://www.faqs.org/rfcs/rfc4701.html). |
| **ADDRESS_BIT_DHCID_WITH_DUID**<br><br>0x3 | The address is leased to the DHCPv4 client with *DHCID* and the client DUID and as defined in sections 3 and 3.5 of [RFC4701](http://www.faqs.org/rfcs/rfc4701.html). |

BIT 4, BIT 5, BIT 6, and BIT 7 specify information related to DNS, as shown in the following table.

| Value | Meaning |
| --- | --- |
| **ADDRESS_BIT_CLEANUP**<br><br>0x1 | The DNS update for the DHCPv4 client lease record needs to be deleted from the DNS server when the lease is deleted. |
| **ADDRESS_BIT_BOTH_REC**<br><br>0x2 | The DNS update needs to be sent for both [DNS_A_DATA](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsquery_a) and [DNS_PTR_DATA](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsquery_w) type resource records. |
| **ADDRESS_BIT_UNREGISTERED**<br><br>0x4 | The DNS update is not complete for the lease record. |
| **ADDRESS_BIT_DELETED**<br><br>0x8 | The address lease is expired, but the DNS updates for the lease record have not been deleted from the DNS server. |

### `Status`

[QuarantineStatus](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-quarantinestatus) enumeration that specifies possible health status values for the DHCPv4 client as validated at the NAP server.

### `ProbationEnds`

[DATE_TIME](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-date_time) structure that contains the probation end time if the DHCPv4 client is on probation. The DHCPv4 client has full access to the network for this time period. This is UTC time represented in the [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) format.

### `QuarantineCapable`

**TRUE**, if the DHCPv4 client is quarantine-enabled; Otherwise, it is **FALSE**.

### `SentPotExpTime`

Time, in seconds, of potential-expiration-time sent to the partner server.

### `AckPotExpTime`

Time, in seconds, of potential-expiration-time acknowledged by the partner server.

### `RecvPotExpTime`

Time, in seconds, of potential-expiration-time received from the partner server.

### `StartTime`

Time, in seconds, since the client lease first entered into its current state.

### `CltLastTransTime`

Time, in seconds, since the client-last-transaction-time.

### `LastBndUpdTime`

Time, in seconds, since the partner server last updated the DHCPv4 client lease.

### `BndMsgStatus`

Reserved. Do not use.

### `PolicyName`

Pointer to a null-terminated Unicode string that represents the DHCP server policy name that resulted in the IPv4 address assignment to the DHCPv4 client in the lease.

### `Flags`

Reserved. Do not use.

## See also

[DHCPV4_FAILOVER_CLIENT_INFO_ARRAY](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ns-dhcpsapi-dhcpv4_failover_client_info_array)