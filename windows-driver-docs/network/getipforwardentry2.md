# GetIpForwardEntry2 function

The **GetIpForwardEntry2** function retrieves information for an IP route entry on a local computer.

## Parameters

- *Row* \[in, out\]
A pointer to a [**MIB\_IPFORWARD\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2) structure entry for an IP route entry. On successful return, this structure is updated with the properties for the IP route entry.

## Return value

**GetIpForwardEntry2** returns STATUS\_SUCCESS if the function succeeds.

If the function fails, **GetIpForwardEntry2** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if one of the following situations occurs:<br><br>* A **NULL** pointer is passed in the *Row* parameter.<br>* The **DestinationPrefix** member of the [**MIB_IPFORWARD_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2) structure that the *Row* parameter points to was not specified.<br>* The **NextHop** member of the MIB_IPFORWARD_ROW2 structure was not specified.<br>* Both **InterfaceLuid** and **InterfaceIndex** members of the MIB_IPFORWARD_ROW2 structure were unspecified.<br>* The **PreferredLifetime** member of the MIB_IPFORWARD_ROW2 structure is greater than the **ValidLifetime** member.<br>* The **SitePrefixLength** member of the MIB_IPFORWARD_ROW2 structure is greater than the prefix length that is specified by the **DestinationPrefix** member. |
| **STATUS_NOT_FOUND** | The specified interface could not be found. This error is returned if the function cannot find the network interface that is specified by the **InterfaceLuid** or **InterfaceIndex** member of the MIB_IPFORWARD_ROW2 structure that the *Row* parameter points to. |
| **STATUS_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is located on the local computer and AF_INET was specified in the address family in the **DestinationPrefix** member of the MIB_IPFORWARD_ROW2 structure that the *Row* parameter points to, or if no IPv6 stack is located on the local computer and AF_INET6 was specified for the address family in the **DestinationPrefix** member. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The **GetIpForwardEntry2** function is used to retrieve a [**MIB\_IPFORWARD\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2) structure entry.

On input, your driver must initialize the following members of the MIB\_IPFORWARD\_ROW2 structure that the *Row* parameter points to.

- **DestinationPrefix**
Set to a valid IPv4 or IPv6 address prefix and family.

- **NextHop**
Set to a valid IPv4 or IPv6 address and family.

- **InterfaceLuid** or **InterfaceIndex**
These members are used in the order that is listed earlier. So if **InterfaceLuid** is specified, this member is used to determine the interface. If no value was set for the **InterfaceLuid** member (the value of this member was set to zero), the **InterfaceIndex** member is next used to determine the interface.

On output, when the call is successful, **GetIpForwardEntry2** retrieves the other properties for the IP route entry and fills out the MIB\_IPFORWARD\_ROW2 structure that the *Row* parameter points to.

The route metric offset that is specified in the **Metric** member of the MIB\_IPFORWARD\_ROW2 structure that the *Row* parameter points to represents only part of the complete route metric. The complete metric is a combination of this route metric added to the interface metric that is specified in the **Metric** member of the MIB\_IPINTERFACE\_ROW structure of the associated interface. A driver can retrieve the interface metric by calling the [**GetIpInterfaceEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/getipinterfaceentry) function.

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

[**DeleteIpForwardEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/deleteipforwardentry2)

[**GetBestRoute2**](https://learn.microsoft.com/windows-hardware/drivers/network/getbestroute2)

[**GetIpForwardTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipforwardtable2)

[**GetIpInterfaceEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/getipinterfaceentry)

[**InitializeIpForwardEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/initializeipforwardentry)

[**MIB\_IPFORWARD\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2)

[**MIB\_IPFORWARD\_TABLE2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-table2)

[**MIB\_IPINTERFACE\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipinterface-row)

[**NotifyRouteChange2**](https://learn.microsoft.com/windows-hardware/drivers/network/notifyroutechange2)

[**SetIpForwardEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/setipforwardentry2)