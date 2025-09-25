# DHCP_FILTER_ADD_INFO structure

## Description

The **DHCP_FILTER_ADD_INFO** structure contains information regarding the link-layer filter to be added to the allow and deny filter list.

## Members

### `AddrPatt`

[DHCP_ADDR_PATTERN](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_addr_pattern) structure that contains the address/pattern-related information of the link-layer filter.

### `Comment`

Pointer to a Unicode string that contains a text comment for the filter.

### `ListType`

[DHCP_FILTER_LIST_TYPE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_filter_list_type) enumeration value that specifies the list type to which the filter is to be added.

## See also

[DHCP_ADDR_PATTERN](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_addr_pattern)

[DHCP_FILTER_LIST_TYPE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_filter_list_type)