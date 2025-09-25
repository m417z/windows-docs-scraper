# GetAnycastIpAddressEntry function

## Description

The
**GetAnycastIpAddressEntry** function retrieves information for an existing anycast IP address entry on the local computer.

## Parameters

### `Row` [in, out]

A pointer to a
[MIB_ANYCASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_anycastipaddress_row) structure entry for an anycast IP address entry. On successful return, this structure will be updated with the properties for an existing anycast IP address.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_FILE_NOT_FOUND** | The system cannot find the file specified. This error is returned if the network interface LUID or interface index specified by the **InterfaceLuid** or **InterfaceIndex** member of the [MIB_ANYCASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_anycastipaddress_row) pointed to by the *Row* parameter is not a value on the local machine. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if a **NULL** pointer is passed in the *Row* parameter, the **Address** member of the [MIB_ANYCASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_anycastipaddress_row) pointed to by the *Row* parameter is not set to a valid anycast IPv4 or IPv6 address, or both the **InterfaceLuid** or **InterfaceIndex** members of the **MIB_ANYCASTIPADDRESS_ROW** pointed to by the *Row* parameter were unspecified. |
| **ERROR_NOT_FOUND** | Element not found. This error is returned if the network interface specified by the **InterfaceLuid** or **InterfaceIndex** member of the [MIB_ANYCASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_anycastipaddress_row) structure pointed to by the *Row* parameter does not match the IP address and address family specified in the **Address** member in the **MIB_ANYCASTIPADDRESS_ROW** structure. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is on the local computer and an IPv4 address is specified in the **Address** member of the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure pointed to by the *Row* parameter. This error is returned if no IPv6 stack is on the local computer and an IPv6 address is specified in the **Address** member. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **GetAnycastIpAddressEntry** function is defined on Windows Vista and later.

The **GetAnycastIpAddressEntry** function is used to retrieve an existing [MIB_ANYCASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_anycastipaddress_row) structure entry.

On input, the **Address** member in the [MIB_ANYCASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_anycastipaddress_row) structure pointed to by the *Row* parameter must be initialized to a valid anycast IPv4 or IPv6 address and family. In addition, at least one of the following members in the **MIB_ANYCASTIPADDRESS_ROW** structure pointed to the *Row* parameter must be initialized: the **InterfaceLuid** or **InterfaceIndex**.

The fields are used in the order listed above. So if the **InterfaceLuid** is specified, then this member is used to determine the interface. If no value is set for the **InterfaceLuid** member (the value of this member is set to zero), then the **InterfaceIndex** member is next used to determine the interface.

On output when the call is successful, **GetAnycastIpAddressEntry** retrieves the other properties for the anycast IP address and fills out the [MIB_ANYCASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_anycastipaddress_row) structure pointed to by the *Row* parameter.

The [GetAnycastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getanycastipaddresstable) function can be called to enumerate the anycast IP address entries on a local computer.

## See also

[CreateAnycastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createanycastipaddressentry)

[DeleteAnycastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-deleteanycastipaddressentry)

[GetAnycastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getanycastipaddresstable)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[MIB_ANYCASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_anycastipaddress_row)

[MIB_ANYCASTIPADDRESS_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_anycastipaddress_table)