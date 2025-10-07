# GetBestRoute2 function

The **GetBestRoute2** function retrieves the IP route entry on a local computer for the best route to the specified destination IP address.

## Parameters

- *InterfaceLuid* \[in, optional\]
The locally unique identifier (LUID) to specify the network interface that is associated with an IP route entry.

- *InterfaceIndex* \[in\]
The local index value to specify the network interface that is associated with an IP route entry. This index value might change when a network adapter is disabled and then enabled, or under other circumstances, so this value does not persistent.

- *SourceAddress* \[in, optional\]
The source IP address. Your driver can omit this parameter and pass a **NULL** pointer.

- *DestinationAddress* \[in\]
The destination IP address.

- *AddressSortOptions* \[in\]
A set of options that affect how IP addresses are sorted. This parameter is currently not used.

- *BestRoute* \[out\]
A pointer to the [**MIB\_IPFORWARD\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2) structure for the best route from the source IP address to the destination IP address.

- *BestSourceAddress* \[out\]
A pointer to the best source IP address.

## Return value

**GetBestRoute2** returns STATUS\_SUCCESS if the function succeeds.

If the function fails, **GetBestRoute2** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *DestinationAddress*, *BestSourceAddress*, or *BestRoute* parameters. This error is also returned if both *InterfaceLuid* and *InterfaceIndex* parameters were unspecified. This error is also returned if the *DestinationAddress* parameter does not specify an IPv4 or IPv6 address and family |
| **STATUS_NOT_FOUND** | The specified interface could not be found. This error is returned if the network interface that the *InterfaceLuid* or *InterfaceIndex* parameter specifies could not be found. |
| **STATUS_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is located on the local computer and an IPv4 address and family was specified in the *DestinationAddress* parameter, or if no IPv6 stack is located on the local computer and an IPv4 address and family was specified in the *DestinationAddress* parameter. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The **GetBestRoute2** function is used to retrieve a [**MIB\_IPFORWARD\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2) structure entry for the best route from a source IP address to a destination IP address.

On input, your driver must initialize the following parameters.

- *DestinationAddress*
Set to a valid IPv4 or IPv6 address and family.

- *InterfaceLuid* or *InterfaceIndex*
These parameters are used in the order that is listed earlier. So if *InterfaceLuid* is specified, this parameter is used to determine the interface. If no value was set for the *InterfaceLuid* member (the value of this parameter was set to zero), the *InterfaceIndex* parameter is next used to determine the interface.

In addition, on input, your driver can initialize the *SourceAddress* parameter to the preferred IPv4 or IPv6 address and family.

On output, when the call is successful, **GetBestRoute2** retrieves an MIB\_IPFORWARD\_ROW2 structure for the best route from the source IP address the destination IP address.

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

[**GetIpForwardEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipforwardentry2)

[**GetIpForwardTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipforwardtable2)

[**InitializeIpForwardEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/initializeipforwardentry)

[**MIB\_IPFORWARD\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2)

[**MIB\_IPFORWARD\_TABLE2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-table2)

[**NotifyRouteChange2**](https://learn.microsoft.com/windows-hardware/drivers/network/notifyroutechange2)

[**SetIpForwardEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/setipforwardentry2)