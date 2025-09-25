## Description

The **DHCP_ALL_OPTIONS** structure defines the set of all options available on a DHCP server.

## Members

### `Flags`

Reserved. This value should be set to 0.

### `NonVendorOptions`

[DHCP_OPTION_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_array) structure that contains the set of non-vendor options.

### `NumVendorOptions`

Specifies the number of vendor options listed in **VendorOptions**.

### `Option`

[DHCP_OPTION](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option) structure that contains specific information describing the option.

### `VendorName`

Unicode string that contains the name of the vendor for the option.

### `ClassName`

Unicode string that contains the name of the DHCP class for the option.

### `VendorOptions`

Pointer to a list of structures that contain the following fields.