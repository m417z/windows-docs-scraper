# GetIpNetEntry2 function

The **GetIpNetEntry2** function retrieves information for a neighbor IP address entry on the local computer.

## Parameters

- *Row* \[in, out\]
A pointer to a [**MIB\_IPNET\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipnet-row2) structure entry for a neighbor IP address entry. On successful return, this structure is updated with the properties for neighbor IP address.

## Return value

**GetIpNetEntry2** returns STATUS\_SUCCESS if the function succeeds.

If the function fails, **GetIpNetEntry2** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Row* parameter, the **Address** member of the [**MIB_IPNET_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipnet-row2) structure that the *Row* parameter points to was not set to a valid neighbor IPv4 or IPv6 address, or both **InterfaceLuid** and **InterfaceIndex** members of the MIB_IPNET_ROW2 structure were unspecified. |
| **STATUS_NOT_FOUND** | The specified interface could not be found. This error is returned if the function cannot find the network interface that is specified by the **InterfaceLuid** or **InterfaceIndex** member of the MIB_IPNET_ROW2 structure that the *Row* parameter points to. |
| **STATUS_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is located on the local computer and an IPv4 address was specified in the **Address** member of the MIB_IPNET_ROW2 structure that the *Row* parameter points to, or if no IPv6 stack is located on the local computer and an IPv6 address was specified in the **Address** member. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The **GetIpNetEntry2** function is used to retrieve a [**MIB\_IPNET\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipnet-row2) structure entry.

On input, your driver must initialize the following members of the MIB\_IPNET\_ROW2 structure that the *Row* parameter points to.

- **Address**
Set to a valid neighbor IPv4 or IPv6 address and family.

- **InterfaceLuid** or **InterfaceIndex**
These members are used in the order that is listed earlier. So if **InterfaceLuid** is specified, this member is used to determine the interface. If no value was set for the **InterfaceLuid** member (the value of this member was set to zero), the **InterfaceIndex** member is next used to determine the interface.

On output, when the call is successful, **GetIpNetEntry2** retrieves the other properties for the neighbor IP address and fills in the MIB\_IPNET\_ROW2 structure that the *Row* parameter points to.

Your driver can call the [**GetIpNetTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipnettable2) function to enumerate the neighbor IP address entries on a local computer.

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://learn.microsoft.com/windows-hardware/drivers/develop/target-platforms) |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |
| Library | Netio.lib |
| IRQL | < DISPATCH_LEVEL |

## See also

[**GetIpNetTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipnettable2)

[**MIB\_IPNET\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipnet-row2)