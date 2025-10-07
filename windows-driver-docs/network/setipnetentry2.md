# SetIpNetEntry2 function

The **SetIpNetEntry2** function sets the physical address of an existing neighbor IP address entry on a local computer.

## Parameters

- *Row* \[in\]
A pointer to a [**MIB\_IPNET\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipnet-row2) structure entry for a neighbor IP address entry.

## Return value

**SetIpNetEntry2** return STATUS\_SUCCESS if the function succeeds.

If the function fails, **SetIpNetEntry2** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned in the following situations.<br><br>* A **NULL** pointer was passed in the *Row* parameter.<br>* The **Address** member of the [**MIB_IPNET_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipnet-row2) structure that the *Row* parameter points to was not set to a valid unicast, anycast, or multicast IPv4 or IPv6 address.<br>* The **PhysicalAddress** and **PhysicalAddressLength** members of the MIB_IPNET_ROW2 structure were not set to a valid physical address.<br>* Both **InterfaceLuid** and **InterfaceIndex** members of the MIB_IPNET_ROW2 structure were unspecified.<br>* A loopback address was passed in the **Address** member. |
| **STATUS_NOT_FOUND** | The specified interface could not be found. This error is returned if the function cannot find the network interface that is specified by the **InterfaceLuid** or **InterfaceIndex** member of the MIB_IPNET_ROW2 structure that the *Row* parameter points to. |
| **STATUS_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is located on the local computer and an IPv4 address was specified in the **Address** member of the MIB_IPNET_ROW2 structure that the *Row* parameter points to, or if no IPv6 stack is located on the local computer and an IPv6 address was specified in the **Address** member. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

Your driver must initialize the following members of the [**MIB\_IPNET\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipnet-row2) structure that the *Row* parameter points to.

- **Address**
Set to a valid unicast, anycast, or multicast IPv4 or IPv6 address and family.

- **PhysicalAddress** and **PhysicalAddressLength**
Set to a valid physical address.

- **InterfaceLuid** or **InterfaceIndex**
These members are used in the order that is listed earlier. So if **InterfaceLuid** is specified, this member is used to determine the interface. If no value was set for the **InterfaceLuid** member (the value of this member was set to zero), the **InterfaceIndex** member is next used to determine the interface.

The **SetIpNetEntry2** function fails if the IP address that is passed in the **Address** member of the MIB\_IPNET\_ROW2 structure that the *Row* parameter points to is not an existing neighbor IP address on the interface that is specified.

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

[**ResolveIpNetEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/resolveipnetentry2)