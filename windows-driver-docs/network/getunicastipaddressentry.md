# GetUnicastIpAddressEntry function

The **GetUnicastIpAddressEntry** function retrieves information for an existing unicast IP address entry on a local computer.

## Parameters

- *Row* \[in, out\]
A pointer to a [**MIB\_UNICASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-row) structure entry for a unicast IP address entry. On successful return, this structure is updated with the properties for an existing unicast IP address.

## Return value

**GetUnicastIpAddressEntry** returns **STATUS\_SUCCESS** if the function succeeds.

If the function fails, **GetUnicastIpAddressEntry** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Row* parameter, the **Address** member of the [**MIB_UNICASTIPADDRESS_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-row) structure that the *Row* parameter points to was not set to a valid unicast IPv4 or IPv6 address, or both **InterfaceLuid** and **InterfaceIndex** members of the **MIB_UNICASTIPADDRESS_ROW** structure were unspecified. |
| **STATUS_NOT_FOUND** | The specified interface could not be found. This error is returned if the function cannot find the network interface that is specified by the **InterfaceLuid** or **InterfaceIndex** member of the [**MIB_UNICASTIPADDRESS_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-row) structure that the *Row* parameter points to. |
| **STATUS_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is located on the local computer and an IPv4 address was specified in the **Address** member of the [**MIB_UNICASTIPADDRESS_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-row) structure that the *Row* parameter points to, or if no IPv6 stack is located on the local computer and an IPv6 address was specified in the **Address** member. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The **GetUnicastIpAddressEntry** function is typically used to retrieve an existing [**MIB\_UNICASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-row) structure entry to be modified. A driver can then change the members in the **MIB\_UNICASTIPADDRESS\_ROW** entry that it wants to modify, and then call the [**SetUnicastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/setunicastipaddressentry) function.

On input, your driver must initialize the following members of the [**MIB\_UNICASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-row) structure that the *Row* parameter points to.

- **Address**
Set to a valid unicast IPv4 or IPv6 address and family.

- **InterfaceLuid** or **InterfaceIndex**
These members are used in the order that is listed earlier. So if **InterfaceLuid** is specified, this member is used to determine the interface. If no value was set for the **InterfaceLuid** member (the value of this member was set to zero), the **InterfaceIndex** member is next used to determine the interface.

On output, when the call is successful, **GetUnicastIpAddressEntry** retrieves the other properties for the unicast IP address and fills in the [**MIB\_UNICASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-row) structure that the *Row* parameter points to.

Your driver can call the [**GetUnicastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getunicastipaddresstable) function to enumerate the unicast IP address entries on a local computer.

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://learn.microsoft.com/windows-hardware/drivers/develop/target-platforms) |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |
| Library | Netio.lib |
| IRQL | < DISPATCH_LEVEL |

## See also

[**CreateUnicastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/createunicastipaddressentry)

[**DeleteUnicastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/deleteunicastipaddressentry)

[**GetUnicastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getunicastipaddresstable)

[**InitializeUnicastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/initializeunicastipaddressentry)

[**MIB\_UNICASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-row)

[**MIB\_UNICASTIPADDRESS\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-table)

[**NotifyUnicastIpAddressChange**](https://learn.microsoft.com/windows-hardware/drivers/network/notifyunicastipaddresschange)

[**SetUnicastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/setunicastipaddressentry)