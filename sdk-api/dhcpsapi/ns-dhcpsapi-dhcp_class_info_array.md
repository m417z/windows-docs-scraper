# DHCP_CLASS_INFO_ARRAY structure

## Description

The **DHCP_CLASS_INFO_ARRAY** structure defines an array of elements that contain DHCP class information.

## Members

### `NumElements`

Specifies the number of elements in **Classes**.

### `Classes`

Pointer to an array of [DHCP_CLASS_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_class_info) structures that contain DHCP class information.

### `Classes.size_is`

### `Classes.size_is.NumElements`

## See also

[DHCP_CLASS_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_class_info)

[DhcpEnumClasses](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpenumclasses)