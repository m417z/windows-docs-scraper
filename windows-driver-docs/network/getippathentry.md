# GetIpPathEntry function

The **GetIpPathEntry** function retrieves information for an IP path entry on a local computer.

## Parameters

- *Row* \[in, out\]
A pointer to a [**MIB\_IPPATH\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ippath-row) structure entry for an IP path entry. On successful return, this structure is updated with the properties for IP path entry.

## Return value

**GetIpPathEntry** returns STATUS\_SUCCESS if the function succeeds.

If the function fails, **GetIpPathEntry** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Row* parameter, the **si_family** member in the **Destination** member of the [**MIB_IPPATH_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ippath-row) structure that the *Row* parameter points to was not set to AF_INET or AF_INET6, or both **InterfaceLuid** and **InterfaceIndex** members of the MIB_IPPATH_ROW structure were unspecified. This error is also returned if the **si_family** member in the **Source** member of the MIB_IPPATH_ROW structure did not match the destination IP address family and the **si_family** for the source IP address was not specified as AF_UNSPEC. |
| **STATUS_NOT_FOUND** | The specified interface could not be found. This error is returned if the function cannot find the network interface that is specified by the **InterfaceLuid** or **InterfaceIndex** member of the MIB_IPPATH_ROW structure that the *Row* parameter points to. |
| **STATUS_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is located on the local computer and an IPv4 address was specified in the **Source** and **Destination** members of the MIB_IPPATH_ROW structure that the *Row* parameter points to, or if no IPv6 stack is located on the local computer and an IPv6 address was specified in the **Source** and **Destination** members. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The **GetIpPathEntry** function is used to retrieve a [**MIB\_IPPATH\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ippath-row) structure entry.

On input, your driver must initialize the following members of the MIB\_IPPATH\_ROW structure that the *Row* parameter points to.

- **Destination**
Set to a valid IPv4 or IPv6 address and family.

- **Source**
Set the address family that is specified in the **Source** member to the destination IP address family that is specified in the **Destination** member, or to AF\_UNSPEC.

- **InterfaceLuid** or **InterfaceIndex**
These members are used in the order that is listed earlier. So if **InterfaceLuid** is specified, this member is used to determine the interface. If no value was set for the **InterfaceLuid** member (the value of this member was set to zero), the **InterfaceIndex** member is next used to determine the interface.

On output, when the call is successful, **GetIpPathEntry** retrieves the other properties for the IP path entry and fills in the MIB\_IPPATH\_ROW structure that the *Row* parameter points to.

Your driver can call the [**GetIpPathTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getippathtable) function to enumerate the IP path entries on a local computer.

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://learn.microsoft.com/windows-hardware/drivers/develop/target-platforms) |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |
| Library | Netio.lib |
| IRQL | < DISPATCH_LEVEL |

## See also

[**FlushIpPathTable**](https://learn.microsoft.com/windows-hardware/drivers/network/flushippathtable)

[**GetIpPathTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getippathtable)

[**MIB\_IPPATH\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ippath-row)

[**MIB\_IPPATH\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ippath-table)