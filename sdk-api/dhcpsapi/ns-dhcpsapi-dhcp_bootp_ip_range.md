# DHCP_BOOTP_IP_RANGE structure

## Description

The **DHCP_BOOTP_IP_RANGE** structure defines a suite of IPs for lease to BOOTP-specific clients.

## Members

### `StartAddress`

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the start of the IP range used for BOOTP service.

### `EndAddress`

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the end of the IP range used for BOOTP service.

### `BootpAllocated`

Specifies the number of BOOTP clients with addresses served from this range.

### `MaxBootpAllowed`

Specifies the maximum number of BOOTP clients this range is allowed to serve.