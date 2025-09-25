# GetIpNetEntry2 function

## Description

The
**GetIpNetEntry2** function retrieves information for a neighbor IP address entry on the local computer.

## Parameters

### `Row` [in, out]

A pointer to a
[MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2) structure entry for a neighbor IP address entry. On successful return, this structure will be updated with the properties for neighbor IP address.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_FILE_NOT_FOUND** | The system cannot find the file specified. This error is returned if the network interface LUID or interface index specified by the **InterfaceLuid** or **InterfaceIndex** member of the [MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2) pointed to by the *Row* parameter was not a value on the local machine. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Row* parameter, the **Address** member of the [MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2) pointed to by the *Row* parameter was not set to a valid neighbor IPv4 or IPv6 address, or both the **InterfaceLuid** or **InterfaceIndex** members of the **MIB_IPNET_ROW2** pointed to by the *Row* parameter were unspecified. |
| **ERROR_NOT_FOUND** | Element not found. This error is returned if the network interface specified by the **InterfaceLuid** or **InterfaceIndex** member of the [MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2) structure pointed to by the *Row* parameter does not match the neighbor IP address and address family specified in the **Address** member in the **MIB_IPNET_ROW2** structure. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is on the local computer and an IPv4 address was specified in the **Address** member of the [MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2) structure pointed to by the *Row* parameter. This error is also returned if no IPv6 stack is on the local computer and an IPv6 address was specified in the **Address** member of the **MIB_IPNET_ROW2** structure. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **GetIpNetEntry2** function is defined on Windows Vista and later.

The **GetIpNetEntry2** function is used to retrieve a [MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2) structure entry.

On input, the **Address** member in the [MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2) structure pointed to by the *Row* parameter must be initialized to a valid neighbor IPv4 or IPv6 address and family. In addition, at least one of the following members in the **MIB_IPNET_ROW2** structure pointed to the *Row* parameter must be initialized:
the **InterfaceLuid** or **InterfaceIndex**.

The fields are used in the order listed above. So if the **InterfaceLuid** is specified, then this member is used to determine the interface. If no value was set for the **InterfaceLuid** member (the values of this member was set to zero), then the **InterfaceIndex** member is next used to determine the interface.

On output when the call is successful, **GetIpNetEntry2** retrieves the other properties for the neighbor IP address and fills out the [MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2) structure pointed to by the *Row* parameter.

The [GetIpNetTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipnettable2) function can be called to enumerate the neighbor IP address entries on a local computer.

## See also

[CreateIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createipnetentry2)

[DeleteIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-deleteipnetentry2)

[FlushIpNetTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-flushipnettable2)

[GetIpNetTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipnettable2)

[MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2)

[MIB_IPNET_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_table2)

[ResolveIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-resolveipnetentry2)

[SetIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-setipnetentry2)