# DHCP_OPTION_DATA_ELEMENT structure

## Description

The **DHCP_OPTION_DATA_ELEMENT** structure defines a data element present (either singly or as a member of an array) within a [DHCP_OPTION_DATA](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_data) structure.

## Members

### `OptionType`

A [DHCP_OPTION_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_option_data_type) enumeration value that indicates the type of data that is present in the subsequent field, **Element**.

### `Element.ByteOption.case`

### `Element.ByteOption.case.DhcpByteOption`

### `Element.WordOption.case`

### `Element.WordOption.case.DhcpWordOption`

### `Element.DWordOption.case`

### `Element.DWordOption.case.DhcpDWordOption`

### `Element.DWordDWordOption.case`

### `Element.DWordDWordOption.case.DhcpDWordDWordOption`

### `Element.IpAddressOption.case`

### `Element.IpAddressOption.case.DhcpIpAddressOption`

### `Element.StringDataOption.case`

### `Element.StringDataOption.case.DhcpStringDataOption`

### `Element.BinaryDataOption.case`

### `Element.BinaryDataOption.case.DhcpBinaryDataOption`

### `Element.EncapsulatedDataOption.case`

### `Element.EncapsulatedDataOption.case.DhcpEncapsulatedDataOption`

### `Element.Ipv6AddressDataOption.case`

### `Element.Ipv6AddressDataOption.case.DhcpIpv6AddressOption`

### `Element`

### `Element.ByteOption`

Specifies the data as a BYTE value. This field will be present if the **OptionType** is **DhcpByteOption**.

### `Element.WordOption`

Specifies the data as a WORD value. This field will be present if the **OptionType** is **DhcpWordOption**.

### `Element.DWordOption`

Specifies the data as a DWORD value. This field will be present if the **OptionType** is **DhcpDWordOption**.

### `Element.DWordDWordOption`

Specifies the data as a [DWORD_DWORD](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dword_dword) value. This field will be present if the **OptionType** is **DhcpDWordDWordOption**.

### `Element.IpAddressOption`

Specifies the data as a [DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) (DWORD) value. This field will be present if the **OptionType** is **IpAddressOption**.

### `Element.StringDataOption`

Specifies the data as a Unicode string value. This field will be present if the **OptionType** is **DhcpStringDataOption**.

### `Element.BinaryDataOption`

Specifies the data as a [DHCP_BINARY_DATA](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_binary_data) structure. This field will be present if the **OptionType** is **DhcpBinaryDataOption**.

### `Element.EncapsulatedDataOption`

Specifies the data as encapsulated within a [DHCP_BINARY_DATA](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_binary_data) structure. The application must know the format of the opaque data capsule in order to read it from the **Data** field of **DHCP_BINARY_DATA**. This field will be present if the **OptionType** is **DhcpEncapsulatedDataOption**.

### `Element.Ipv6AddressDataOption`

Specifies the data as a Unicode string value. This field will be present if the **OptionType** is **DhcpIpv6AddressOption**.

### `_DHCP_OPTION_ELEMENT_UNION`

## See also

[DHCP_BINARY_DATA](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_binary_data)

[DHCP_OPTION_DATA](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_data)

[DHCP_OPTION_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_option_data_type)

[DWORD_DWORD](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dword_dword)