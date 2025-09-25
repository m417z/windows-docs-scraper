# DHCP_CLASS_INFO_ARRAY_V6 structure

## Description

The **DHCP_CLASS_INFO_ARRAY_V6** structure contains a list of information regarding a user class or a vendor class.

## Members

### `NumElements`

This is of type **DWORD**, specifying the number of classes whose information is contained in the array specified by Classes.

### `Classes`

A pointer to an array of structures [DHCP_CLASS_INFO_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_class_info_v6) (section 2.2.1.2.70) that contains information regarding the various user classes and vendor classes.

### `Classes.size_is`

### `Classes.size_is.NumElements`

## See also

[DHCP_CLASS_INFO_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_class_info_v6)