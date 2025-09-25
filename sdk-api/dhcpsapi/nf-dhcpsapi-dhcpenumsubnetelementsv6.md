# DhcpEnumSubnetElementsV6 function

## Description

The **DhcpEnumSubnetElementsV6** function returns an enumerated list of elements for a specific DHCP subnet.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

DHCP_IPV6_ADDRESS value that specifies the subnet whose elements will be enumerated.

### `EnumElementType` [in]

DHCP_SUBNET_ELEMENT_TYPE_V6 enumeration value that indicates the type of subnet element to enumerate.

### `ResumeHandle` [in, out]

Pointer to a [DHCP_RESUME_HANDLE](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that identifies the enumeration operation. Initially, this value should be zero, with a successful call returning the handle value used for subsequent enumeration requests. For example, if *PreferredMaximum* is set to 1000 bytes, and 2000 bytes worth of subnet elements are stored on the server, the resume handle can be used after the first 1000 bytes are retrieved to obtain the next 1000 on a subsequent call, and so forth.

### `PreferredMaximum` [in]

Specifies the preferred maximum number of bytes of subnet elements to return. If the number of remaining unenumerated options (in bytes) is less than this value, then that amount will be returned.

### `EnumElementInfo` [out]

Pointer to a DHCP_SUBNET_ELEMENT_INFO_ARRAY_V6 structure containing an enumerated list of all elements available for the specified subnet. If no elements are available for enumeration, this value will be null.

### `ElementsRead` [out]

Pointer to a DWORD value that specifies the number of subnet elements returned in *EnumElementInfo*.

### `ElementsTotal` [out]

Pointer to a DWORD value that specifies the total number of elements for the specified subnet.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The parameters were invalid. |
| **ERROR_NO_MORE_ITEMS** | No more items to enumerate. |
| **ERROR_NOT_ENOUGH_MEMORY** | Memory failure. |
| **ERROR_MORE_DATA** | More data is available to enumerate. |