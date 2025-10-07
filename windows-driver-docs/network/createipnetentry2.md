# CreateIpNetEntry2 function

The **CreateIpNetEntry2** function creates a new neighbor IP address entry on the local computer.

## Parameters

- *Row* \[in\]
A pointer to a [**MIB\_IPNET\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipnet-row2) structure entry for an IP route entry.

## Return value

**CreateIpNetEntry2** returns STATUS\_SUCCESS if the function succeeds.

If the function fails, **CreateIpNetEntry2** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if one of the following items occurs:<br><br>* A **NULL** pointer is passed in the *Row* parameter.<br>* The **Address** member of the [**MIB_IPNET_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipnet-row2) structure that the *Row* parameter points to was not set to a valid unicast, anycast, or multicast IPv4 or IPv6 address.<br>* The **PhysicalAddress** and **PhysicalAddressLength** members of the MIB_IPNET_ROW2 structure were not set to a valid physical address.<br>* Both **InterfaceLuid** and **InterfaceIndex** members of the MIB_IPNET_ROW2 structure were unspecified.<br>* A loopback address was passed in the **Address** member. |
| **STATUS_NOT_FOUND** | The specified interface could not be found. This error is returned if the function cannot find the network interface that is specified by the **InterfaceLuid** or **InterfaceIndex** member of the MIB_IPNET_ROW2 structure that the *Row* parameter points to. |
| **STATUS_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is located on the local computer and an IPv4 address was specified in the **Address** member of the MIB_IPNET_ROW2 structure that the *Row* parameter points, or if no IPv6 stack is located on the local computer and an IPv6 address was specified in the **Address** member. |
| **ERROR_OBJECT_ALREADY_EXISTS** | The object already exists. This error is returned if the **Address** member of the MIB_IPNET_ROW2 structure that the *Row* parameter points to is a duplicate of an existing neighbor IP address on the interface that is specified by the **InterfaceLuid** or **InterfaceIndex** member of the MIB_IPNET_ROW2 structure. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

Your driver must initialize the following members of the [**MIB\_IPNET\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipnet-row2) structure that the *Row* parameter points to:

- Set the **Address** member to a valid unicast, anycast, or multicast IPv4 or IPv6 address and family.

- Set the **PhysicalAddress** and **PhysicalAddressLength** members in the MIB\_IPNET\_ROW2 structure to a valid physical address.

- Set **InterfaceLuid** or **InterfaceIndex** to the LUID or index value of the interface.

The **InterfaceLuid** and **InterfaceIndex** members are used in the order that is listed earlier. So if the **InterfaceLuid** is specified, this member is used to determine the interface to add the unicast IP address on. If no value was set for the **InterfaceLuid** member (the value of this member was set to zero), the **InterfaceIndex** member is next used to determine the interface.

The **CreateIpNetEntry2** function fails if the IP address that is passed in the **Address** member of the MIB\_IPNET\_ROW2 structure that the *Row* parameter points to is a duplicate of an existing neighbor IP address on the interface.

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://learn.microsoft.com/windows-hardware/drivers/develop/target-platforms) |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |
| Library | Netio.lib |
| IRQL | < DISPATCH_LEVEL |

## See also

[**DeleteIpNetEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/deleteipnetentry2)

[**FlushIpNetTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/flushipnettable2)

[**GetIpNetEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipnetentry2)

[**GetIpNetTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipnettable2)

[**MIB\_IPNET\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipnet-row2)

[**MIB\_IPNET\_TABLE2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipnet-table2)

[**ResolveIpNetEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/resolveipnetentry2)

[**SetIpNetEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/setipnetentry2)