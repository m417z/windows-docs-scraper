# DHCP_CLASS_INFO structure

## Description

The **DHCP_CLASS_INFO** structure defines a DHCP option class.

## Members

### `ClassName`

Unicode string that contains the name of the class.

### `ClassComment`

Unicode string that contains a comment associated with the class.

### `ClassDataLength`

Specifies the size of **ClassData**, in bytes. When passing this structure into [DhcpGetClassInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpgetclassinfo), this value should be set to the size of the initialized buffer.

### `IsVendor`

Specifies whether or not this option class is a vendor-defined option class. If **TRUE**, it is a vendor class; if not, it is not a vendor class. Vendor-defined option classes can be used by DHCP clients that are configured to optionally identify themselves by their vendor type to the DHCP server when obtaining a lease.

### `Flags`

Specifies a bit flag that indicates whether or not the options are vendor-specific. If it is not, this parameter should be 0.

| Value | Meaning |
| --- | --- |
| **DHCP_FLAGS_OPTION_IS_VENDOR** | This flag should be set if the option is provided by a vendor. |

### `ClassData`

Pointer to a byte buffer that contains specific data for the class. When passing this structure into [DhcpGetClassInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpgetclassinfo), this buffer should be initialized to the anticipated size of the data to be returned.

### `ClassData.size_is`

### `ClassData.size_is.ClassDataLength`

## See also

[DHCP_CLASS_INFO_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_class_info_array)

[DhcpCreateClass](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpcreateclass)

[DhcpGetClassInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpgetclassinfo)

[DhcpModifyClass](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpmodifyclass)