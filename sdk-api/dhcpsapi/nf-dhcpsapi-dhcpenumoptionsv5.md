# DhcpEnumOptionsV5 function

## Description

The **DhcpEnumOptionsV5** function returns an enumerated list of DHCP options for a given user or vendor class.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `Flags` [in]

A set of flags that indicate the option definition for enumeration.

| Value | Meaning |
| --- | --- |
| 0x00000000 | The option definitions are enumerated for a default vendor class. |
| **DHCP_FLAGS_OPTION_IS_VENDOR**<br><br>0x00000003 | The option definitions are enumerated for a specific vendor class. |

### `ClassName` [in]

Pointer to a Unicode string that contains the name of the class whose options will be enumerated. This parameter is optional.

### `VendorName` [in]

Pointer to a Unicode string that contains the name of the vendor for the class. This parameter is optional. If a vendor class name is not provided, the default vendor class name is used.

### `ResumeHandle` [in, out]

Pointer to a [DHCP_RESUME_HANDLE](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that identifies the enumeration operation. Initially, this value should be zero, with a successful call returning the handle value used for subsequent enumeration requests. For example, if *PreferredMaximum* is set to 1000 bytes, and 2000 bytes of option definitions are stored on the server, the resume handle can be used after the first 1000 bytes are retrieved to obtain the next 1000 on a subsequent call, and so forth.

### `PreferredMaximum` [in]

Specifies the preferred maximum number of bytes of options to return. If the number of remaining unenumerated option definitions (in bytes) is less than this value, all option definitions are returned.

### `Options` [out]

Pointer to a [DHCP_OPTION_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_array) structure containing the returned option definitions. If there are no option definitions available on the DHCP server, this parameter will return null.

### `OptionsRead` [out]

Pointer to a DWORD value that specifies the number of option definitions returned in *Options*.

### `OptionsTotal` [out]

Pointer to a DWORD value that specifies the total number of unenumerated option definitions on the DHCP server.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_CLASS_NOT_FOUND** | The supplied user or vendor class name is either incorrect or unknown. |

## See also

[DHCP_OPTION_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_array)

[DhcpCreateOptionV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpcreateoptionv5)

[DhcpRemoveOptionV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpremoveoptionv5)