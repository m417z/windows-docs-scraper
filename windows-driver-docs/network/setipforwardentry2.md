# SetIpForwardEntry2 function

The **SetIpForwardEntry2** function sets the properties of an IP route entry on a local computer.

## Parameters

- *Route* \[in\]
A pointer to a [**MIB\_IPFORWARD\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2) structure entry for an IP route entry. Your driver must set the **DestinationPrefix** member of the MIB\_IPFORWARD\_ROW2 structure to a valid IP destination prefix and family, set the **NextHop** member of MIB\_IPFORWARD\_ROW2 to a valid IP address and family, and specify the **InterfaceLuid** member or the **InterfaceIndex** member of MIB\_IPFORWARD\_ROW2.

## Return value

**SetIpForwardEntry2** returns STATUS\_SUCCESS if the function succeeds.

If the function fails, **SetIpForwardEntry2** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Route* parameter, the **DestinationPrefix** member of the [**MIB_IPFORWARD_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2) structure that the *Route* parameter points to was not specified, the **NextHop** member of the MIB_IPFORWARD_ROW2 structure was not specified, or both **InterfaceLuid** and **InterfaceIndex** members of the MIB_IPFORWARD_ROW2 structure were unspecified. |
| **STATUS_NOT_FOUND** | The specified interface could not be found. This error is returned if the function cannot find the network interface that is specified by the **InterfaceLuid** or **InterfaceIndex** member of the MIB_IPFORWARD_ROW2 structure that the *Route* parameter points to. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The **SetIpForwardEntry2** function is used to set the properties for an existing IP route entry on a local computer.

Your driver must initialize the following members of the [**MIB\_IPFORWARD\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2) structure that the *Row* parameter points to.

- **DestinationPrefix**
Set to a valid IPv4 or IPv6 address prefix and family.

- **NextHop**
Set to a valid IPv4 or IPv6 address and family.

- **InterfaceLuid** or **InterfaceIndex**
These members are used in the order that is listed earlier. So if **InterfaceLuid** is specified, this member is used to determine the interface. If no value was set for the **InterfaceLuid** member (the value of this member was set to zero), the **InterfaceIndex** member is next used to determine the interface.

The route metric offset that is specified in the **Metric** member of the MIB\_IPFORWARD\_ROW2 structure that *Route* parameter points to represents only part of the complete route metric. The complete metric is a combination of this route metric offset added to the interface metric that is specified in the **Metric** member of the [**MIB\_IPINTERFACE\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipinterface-row) structure of the associated interface. A driver can retrieve the interface metric by calling the [**GetIpInterfaceEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/getipinterfaceentry) function.

**SetIpForwardEntry2** ignores the **Age** and **Origin** members of the MIB\_IPFORWARD\_ROW2 structure that the *Row* parameter points to. These members are set by the network stack and cannot be changed by using the **SetIpForwardEntry2** function.

The **SetIpForwardEntry2** function fails if the **DestinationPrefix** and **NextHop** members of the MIB\_IPFORWARD\_ROW2 structure that the *Route* parameter points to do not match an IP route entry on the specified interface.

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

[**DeleteIpForwardEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/deleteipforwardentry2)

[**GetBestRoute2**](https://learn.microsoft.com/windows-hardware/drivers/network/getbestroute2)

[**GetIpForwardEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipforwardentry2)

[**GetIpForwardTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipforwardtable2)

[**GetIpInterfaceEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/getipinterfaceentry)

[**InitializeIpForwardEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/initializeipforwardentry)

[**MIB\_IPFORWARD\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2)

[**MIB\_IPFORWARD\_TABLE2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-table2)

[**MIB\_IPINTERFACE\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipinterface-row)

[**NotifyRouteChange2**](https://learn.microsoft.com/windows-hardware/drivers/network/notifyroutechange2)