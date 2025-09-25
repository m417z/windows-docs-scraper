# DHCP_FILTER_RECORD structure

## Description

The **DHCP_FILTER_RECORD** structure contains information for a specific link-layer filter.

## Members

### `AddrPatt`

[DHCP_ADDR_PATTERN](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_addr_pattern) structure that contains the address/pattern related information of the link-layer filter.

### `Comment`

Pointer to a null-terminated Unicode string which contains the comment associated with the address/pattern.

## See also

[DHCP_ADDR_PATTERN](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_addr_pattern)