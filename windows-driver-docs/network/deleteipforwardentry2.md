# DeleteIpForwardEntry2 function

The **DeleteIpForwardEntry2** function deletes an IP route entry on a local computer.

## Parameters

- *Row* \[in\]
A pointer to a [**MIB\_IPFORWARD\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2) structure entry for an IP route entry. On successful return, this entry is deleted.

## Return value

**DeleteIpForwardEntry2** returns STATUS\_SUCCESS if the function succeeds.

If the function fails, **DeleteIpForwardEntry2** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Row* parameter, the **DestinationPrefix** member of the [**MIB_IPFORWARD_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2) structure that the *Row* parameter points to was not specified, the **NextHop** member of the MIB_IPFORWARD_ROW2 structure was not specified, or both **InterfaceLuid** and **InterfaceIndex** members of the MIB_IPFORWARD_ROW2 structure were unspecified. |
| **STATUS_NOT_FOUND** | The specified interface could not be found. This error is returned if the function cannot find the network interface that is specified by the **InterfaceLuid** or **InterfaceIndex** member of the MIB_IPFORWARD_ROW2 structure that the *Row* parameter points to. |
| **STATUS_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is located on the local computer and an IPv4 address was specified in the **Address** member of the MIB_IPFORWARD_ROW2 structure that the *Row* parameter points to, or if no IPv6 stack is located on the local computer and an IPv6 address was specified in the **Address** member. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The **DeleteIpForwardEntry2** function is used to delete a [**MIB\_IPFORWARD\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2) structure entry.

On input, your driver must initialize the following members of the MIB\_IPFORWARD\_ROW2 structure that the *Row* parameter points to.

- **DestinationPrefix**
Set to a valid IPv4 or IPv6 address prefix and family.

- **NextHop**
Set to a valid IPv4 or IPv6 address and family.

- **InterfaceLuid** or **InterfaceIndex**
These members are used in the order that is listed earlier. So if **InterfaceLuid** is specified, this member is used to determine the interface. If no value was set for the **InterfaceLuid** member (the value of this member was set to zero), the **InterfaceIndex** member is next used to determine the interface.

On output, when the call is successful, **DeleteIpForwardEntry2** deletes the IP route entry.

The **DeleteIpForwardEntry2** function fails if the **DestinationPrefix** and **NextHop** members of the MIB\_IPFORWARD\_ROW2 structure that the *Row* parameter points to do not match an existing IP route entry on the interface that is specified in the **InterfaceLuid** or **InterfaceIndex** members.

Your driver can call the [**GetIpForwardTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipforwardtable2) function to enumerate the IP route entries on a local computer.

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://learn.microsoft.com/windows-hardware/drivers/develop/target-platforms) |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |
| Library | Netio.lib |
| IRQL | < DISPATCH_LEVEL |

## See also

[**CreateIpForwardEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/createipforwardentry2)

[**GetBestRoute2**](https://learn.microsoft.com/windows-hardware/drivers/network/getbestroute2)

[**GetIpForwardEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipforwardentry2)

[**GetIpForwardTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipforwardtable2)

[**InitializeIpForwardEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/initializeipforwardentry)

[**MIB\_IPFORWARD\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2)

[**MIB\_IPFORWARD\_TABLE2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-table2)

[**NotifyRouteChange2**](https://learn.microsoft.com/windows-hardware/drivers/network/notifyroutechange2)

[**SetIpForwardEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/setipforwardentry2)