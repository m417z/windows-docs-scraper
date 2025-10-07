# ResolveIpNetEntry2 function

The **ResolveIpNetEntry2** function resolves the physical address for a neighbor IP address entry on a local computer.

## Parameters

- *Row* \[in, out\]
A pointer to a [**MIB\_IPNET\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipnet-row2) structure entry for a neighbor IP address entry. On successful return, this structure is updated with the properties for neighbor IP address.

- *SourceAddress* \[in, optional\]
A pointer to an optional source IP address that is used to select the interface to send the requests on for the neighbor IP address entry.

## Return value

**ResolveIpNetEntry2** returns STATUS\_SUCCESS if the function succeeds.

If the function fails, **ResolveIpNetEntry2** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_BAD_NETWORK_NAME** | The network name cannot be found. This error is returned if the network with the neighbor IP address is unreachable. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Row* parameter, the **Address** member of the [**MIB_IPNET_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipnet-row2) structure that the *Row* parameter points to was not set to a valid IPv4 or IPv6 address, or both **InterfaceLuid** and **InterfaceIndex** members of the MIB_IPNET_ROW2 structure were unspecified. This error is also returned if a loopback address was passed in the **Address** member. |
| **STATUS_NOT_FOUND** | The specified interface could not be found. This error is returned if the function cannot find the network interface that is specified by the **InterfaceLuid** or **InterfaceIndex** member of the MIB_IPNET_ROW2 structure that the *Row* parameter points to. |
| **STATUS_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is located on the local computer and an IPv4 address was specified in the **Address** member of the MIB_IPNET_ROW2 structure that the *Row* parameter points to, or if no IPv6 stack is located on the local computer and an IPv6 address was specified in the **Address** member. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The **ResolveIpNetEntry2** function is used to resolve the physical address for a neighbor IP address entry on a local computer. This function flushes any existing neighbor entry that matches the IP address on the interface and then resolves the physical address (MAC) address by sending ARP requests for an IPv4 address or Neighbor Solicitation (NS) requests for an IPv6 address. If the *SourceAddress* parameter is specified, **ResolveIpNetEntry2** selects the interface with this source IP address to send the requests on. If the *SourceAddress* parameter is not specified (**NULL** was passed in this parameter), **ResolveIpNetEntry2** automatically selects the best interface to send the requests on.

Your driver must initialize the following members of the [**MIB\_IPNET\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipnet-row2) structure that the *Row* parameter points to.

- **Address**
Set to a valid IPv4 or IPv6 address and family.

- **InterfaceLuid** or **InterfaceIndex**
These members are used in the order that is listed earlier. So if **InterfaceLuid** is specified, this member is used to determine the interface. If no value was set for the **InterfaceLuid** member (the value of this member was set to zero), the **InterfaceIndex** member is next used to determine the interface.

If the IP address that is passed in the **Address** member of the MIB\_IPNET\_ROW2 structure that the *Row* parameter points to is a duplicate of an existing neighbor IP address on the interface, the **ResolveIpNetEntry2** function flushes the existing entry before resolving the IP address.

On output, when the call is successful, **ResolveIpNetEntry2** retrieves the other properties for the neighbor IP address and fills in the MIB\_IPNET\_ROW2 structure that the *Row* parameter points to. The **PhysicalAddress** and **PhysicalAddressLength** members in the MIB\_IPNET\_ROW2 structure are initialized to a valid physical address.

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://learn.microsoft.com/windows-hardware/drivers/develop/target-platforms) |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |
| Library | Netio.lib |
| IRQL | < DISPATCH_LEVEL |

## See also

[**CreateIpNetEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/createipnetentry2)

[**DeleteIpNetEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/deleteipnetentry2)

[**FlushIpNetTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/flushipnettable2)

[**GetIpNetEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipnetentry2)

[**GetIpNetTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipnettable2)

[**MIB\_IPNET\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipnet-row2)

[**MIB\_IPNET\_TABLE2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipnet-table2)

[**SetIpNetEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/setipnetentry2)