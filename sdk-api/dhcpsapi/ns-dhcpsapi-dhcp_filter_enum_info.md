# DHCP_FILTER_ENUM_INFO structure

## Description

The **DHCP_FILTER_ENUM_INFO** structure contains information regarding the number of link-layer filter records.

## Members

### `NumElements`

Integer value that specifies the number of link-layer filter records contained in the array specified by pEnumRecords.

### `pEnumRecords`

Pointer to an array of [DHCP_FILTER_RECORD](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_filter_record) structures that contain link-layer filter records.

### `pEnumRecords.size_is`

### `pEnumRecords.size_is.NumElements`

## See also

[DHCP_FILTER_RECORD](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_filter_record)