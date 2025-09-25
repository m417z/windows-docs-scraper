# GetMulticastIpAddressEntry function

## Description

The
**GetMulticastIpAddressEntry** function retrieves information for an existing multicast IP address entry on the local computer.

## Parameters

### `Row` [in, out]

A pointer to a
[MIB_MULTICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_multicastipaddress_row) structure entry for a multicast IP address entry. On successful return, this structure will be updated with the properties for an existing multicast IP address.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_FILE_NOT_FOUND** | The system cannot find the file specified. This error is returned if the network interface LUID or interface index specified by the **InterfaceLuid** or **InterfaceIndex** member of the [MIB_MULTICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_multicastipaddress_row) pointed to by the *Row* parameter is not a value on the local machine. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if a **NULL** pointer is passed in the *Row* parameter, the **Address** member of the [MIB_MULTICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_multicastipaddress_row) pointed to by the *Row* parameter is not set to a valid multicast IPv4 or IPv6 address, or both the **InterfaceLuid** or **InterfaceIndex** members of the **MIB_MULTICASTIPADDRESS_ROW** pointed to by the *Row* parameter are unspecified. |
| **ERROR_NOT_FOUND** | Element not found. This error is returned if the network interface specified by the **InterfaceLuid** or **InterfaceIndex** member of the [MIB_MULTICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_multicastipaddress_row) structure pointed to by the *Row* parameter does not match the IP address and address family specified in the **Address** member in the **MIB_MULTICASTIPADDRESS_ROW** structure. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is on the local computer and an IPv4 address is specified in the **Address** member [MIB_MULTICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_multicastipaddress_row) pointed to by the *Row* parameter. This error is also returned if no IPv6 stack is on the local computer and an IPv6 address is specified in the **Address** member. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **GetMulticastIpAddressEntry** function is defined on Windows Vista and later.

The **GetMulticastIpAddressEntry** function is used to retrieve an existing [MIB_MULTICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_multicastipaddress_row) structure entry.

On input, the **Address** member in the [MIB_MULTICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_multicastipaddress_row) structure pointed to by the *Row* parameter must be initialized to a valid multicast IPv4 or IPv6 address and family. In addition, at least one of the following members in the **MIB_MULTICASTIPADDRESS_ROW** structure pointed to the *Row* parameter must be initialized: the **InterfaceLuid** or **InterfaceIndex**.

The fields are used in the order listed above. So if the **InterfaceLuid** is specified, then this member is used to determine the interface. If no value is set for the **InterfaceLuid** member (the value of this member is set to zero), then the **InterfaceIndex** member is next used to determine the interface.

On output when the call is successful, **GetMulticastIpAddressEntry** retrieves the other properties for the multicast IP address and fills out the [MIB_MULTICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_multicastipaddress_row) structure pointed to by the *Row* parameter.

The [GetMulticastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getmulticastipaddresstable) function can be called to enumerate the multicast IP address entries on a local computer.

## See also

[GetMulticastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getmulticastipaddresstable)

[MIB_MULTICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_multicastipaddress_row)

[MIB_MULTICASTIPADDRESS_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_multicastipaddress_table)