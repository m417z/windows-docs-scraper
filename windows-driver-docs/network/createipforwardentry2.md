# CreateIpForwardEntry2 function

The **CreateIpForwardEntry2** function creates a new IP route entry on a local computer.

## Parameters

- *Row* \[in\]
A pointer to a [**MIB\_IPFORWARD\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2) structure entry for an IP route entry.

## Return value

**CreateIpForwardEntry2** returns STATUS\_SUCCESS if the function succeeds.

If the function fails, **CreateIpForwardEntry2** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if one of the following situations occurs:<br><br>* A **NULL** pointer is passed in the *Row* parameter.<br>* The **DestinationPrefix** member of the [**MIB_IPFORWARD_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2) structure that the *Row* parameter points to was not specified.<br>* The **NextHop** member of the MIB_IPFORWARD_ROW2 structure was not specified.<br>* Both **InterfaceLuid** and **InterfaceIndex** members of the MIB_IPFORWARD_ROW2 structure were unspecified.<br>* The **PreferredLifetime** member of the MIB_IPFORWARD_ROW2 structure is greater than the **ValidLifetime** member.<br>* The **SitePrefixLength** member of the MIB_IPFORWARD_ROW2 structure is greater than the prefix length that is specified by the **DestinationPrefix** member.<br><br>This error is returned if a **NULL** pointer is passed in the *Row* parameter, the **DestinationPrefix** member of the [**MIB_IPFORWARD_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2) structure that is pointed to by the *Row* parameter was not specified, the **NextHop** member of the MIB_IPFORWARD_ROW2 structure was not specified, or both **InterfaceLuid** and **InterfaceIndex** members of the MIB_IPFORWARD_ROW2 structure were unspecified. This error is also returned if the **PreferredLifetime** member that is specified in the MIB_IPFORWARD_ROW2 structure is greater than the **ValidLifetime** member, or if the **SitePrefixLength** in the MIB_IPFORWARD_ROW2 structure is greater than the prefix length that is specified in the **DestinationPrefix** member. |
| **STATUS_NOT_FOUND** | The specified interface could not be found. This error is returned if the function cannot find the network interface that is specified by the **InterfaceLuid** or **InterfaceIndex** member of the MIB_IPNET_ROW2 structure that the *Row* parameter points to. |
| **STATUS_NOT_SUPPORTED** | The request is not supported. This error is returned if the interface that is specified does not support routes. This error is returned if no IPv4 stack is located on the local computer and AF_INET was specified in the address family in the **DestinationPrefix** member of the MIB_IPFORWARD_ROW2 structure that the *Row* parameter points to, or if no IPv6 stack is located on the local computer and AF_INET6 was specified for the address family in the **DestinationPrefix** member. |
| **ERROR_OBJECT_ALREADY_EXISTS** | The object already exists. This error is returned if the **DestinationPrefix** member of the MIB_IPFORWARD_ROW2 structure that the *Row* parameter points to is a duplicate of an existing IP route entry on the interface that is specified by the **InterfaceLuid** or **InterfaceIndex** member of the MIB_IPFORWARD_ROW2 structure. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The **CreateIpForwardEntry2** function is used to add a new neighbor IP address entry on a local computer. Use the [**InitializeIpForwardEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/initializeipforwardentry) function to initialize the members of a [**MIB\_IPFORWARD\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2) structure entry with default values. A driver can then change the members in the MIB\_IPFORWARD\_ROW2 entry that it wants to modify and then call **CreateIpForwardEntry2**.

Your driver must initialize the following members of the MIB\_IPFORWARD\_ROW2 structure that the *Row* parameter points to:

- Set **DestinationPrefix** to a valid IPv4 or IPv6 address prefix.

- Set **NextHop** to a valid IPv4 or IPv6 address and family.

- Set **InterfaceLuid** or **InterfaceIndex** to the LUID or index value of the interface.

The **InterfaceLuid** and **InterfaceIndex** members are used in the order that is listed earlier. So if the **InterfaceLuid** is specified, this member is used to determine the interface to add the IP route entry on. If no value was set for the **InterfaceLuid** member (the value of this member was set to zero), the **InterfaceIndex** member is next used to determine the interface.

The route metric offset that is specified in the **Metric** member of the MIB\_IPFORWARD\_ROW2 structure that the *Row* parameter points to represents only part of the complete route metric. The complete metric is a combination of this route metric offset added to the interface metric that is specified in the **Metric** member of the [**MIB\_IPINTERFACE\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipinterface-row) structure of the associated interface. A driver can retrieve the interface metric by calling the [**GetIpInterfaceEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/getipinterfaceentry) function.

The **Age** and **Origin** members of the MIB\_IPFORWARD\_ROW2 structure that the *Row* parameter points to are ignored when the **CreateIpForwardEntry2** function is called. These members are set by the network stack and cannot be set by using the **CreateIpForwardEntry2** function.

The **CreateIpForwardEntry2** function fails if the **DestinationPrefix** and **NextHop** members of the MIB\_IPFORWARD\_ROW2 structure that the *Row* parameter points to are a duplicate of an existing IP route entry on the interface that is specified in the **InterfaceLuid** or **InterfaceIndex** members.

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://learn.microsoft.com/windows-hardware/drivers/develop/target-platforms) |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |
| Library | Netio.lib |
| IRQL | < DISPATCH_LEVEL |

## See also

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

[**SetIpForwardEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/setipforwardentry2)