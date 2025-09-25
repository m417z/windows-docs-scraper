# GetIpPathEntry function

## Description

The
**GetIpPathEntry** function retrieves information for a IP path entry on the local computer.

## Parameters

### `Row` [in, out]

A pointer to a
[MIB_IPPATH_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ippath_row) structure entry for a IP path entry. On successful return, this structure will be updated with the properties for IP path entry.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_FILE_NOT_FOUND** | The system cannot find the file specified. This error is returned if the network interface LUID or interface index specified by the **InterfaceLuid** or **InterfaceIndex** member of the [MIB_IPPATH_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ippath_row) pointed to by the *Row* parameter is not a value on the local machine. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if a **NULL** pointer is passed in the *Row* parameter, the **si_family** member in the **Destination** member of the [MIB_IPPATH_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ippath_row) pointed to by the *Row* parameter is not set to **AF_INET** or **AF_INET6**, or both the **InterfaceLuid** or **InterfaceIndex** members of the **MIB_IPPATH_ROW** pointed to by the *Row* parameter are unspecified. This error is also returned if the **si_family** member in the **Source** member of the **MIB_IPPATH_ROW** pointed to by the *Row* parameter did not match the destination IP address family and the **si_family** for the source IP address is not specified as **AF_UNSPEC**. |
| **ERROR_NOT_FOUND** | Element not found. This error is returned if the network interface specified by the **InterfaceLuid** or **InterfaceIndex** member of the [MIB_IPPATH_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ippath_row) structure pointed to by the *Row* parameter does not match the IP address and address family specified in the **Destination** member in the **MIB_IPPATH_ROW** structure. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is on the local computer and an IPv4 address is specified in the **Source** and **Destination** members of the [MIB_IPPATH_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ippath_row) pointed to by the *Row* parameter. This error is also returned if no IPv6 stack is on the local computer and an IPv6 address is specified in the **Source** and **Destination** members. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **GetIpPathEntry** function is defined on Windows Vista and later.

The **GetIpPathEntry** function is used to retrieve a [MIB_IPPATH_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ippath_row) structure entry.

On input, the **Destination** member in the [MIB_IPPATH_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ippath_row) structure pointed to by the *Row* parameter must be initialized to a valid IPv4 or IPv6 address and family. The address family specified in **Source** member in the **MIB_IPPATH_ROW** structure must also either match the destination IP address family specified in the **Destination** member or the address family in the **Source** member must be specified as **AF_UNSPEC**. In addition , at least one of the following members in the **MIB_IPPATH_ROW** structure pointed to the *Row* parameter must be initialized: the **InterfaceLuid** or **InterfaceIndex**.

The fields are used in the order listed above. So if the **InterfaceLuid** is specified, then this member is used to determine the interface. If no value is set for the **InterfaceLuid** member (the values of this member is set to zero), then the **InterfaceIndex** member is next used to determine the interface.

On output when the call is successful, **GetIpPathEntry** retrieves the other properties for the IP path entry and fills out the [MIB_IPPATH_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ippath_row) structure pointed to by the *Row* parameter.

The [GetIpPathTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getippathtable) function can be called to enumerate the IP path entries on a local computer.

## See also

[FlushIpPathTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-flushippathtable)

[GetIpPathTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getippathtable)

[MIB_IPPATH_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ippath_row)

[MIB_IPPATH_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ippath_table)