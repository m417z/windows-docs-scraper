# DeleteUnicastIpAddressEntry function

The **DeleteUnicastIpAddressEntry** function deletes an existing unicast IP address entry on a local computer.

## Parameters

- *Row* \[in\]
A pointer to a [**MIB\_UNICASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-row) structure entry for an existing unicast IP address entry to delete from the local computer.

## Return value

**DeleteUnicastIpAddressEntry** returns STATUS\_SUCCESS if the function succeeds.

If the function fails, **DeleteUnicastIpAddressEntry** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Row* parameter, the **Address** member of the [**MIB_UNICASTIPADDRESS_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-row) structure that the *Row* parameter points to was not set to a valid unicast IPv4 or IPv6 address, or both **InterfaceLuid** and **InterfaceIndex** members of the MIB_UNICASTIPADDRESS_ROW structure were unspecified. |
| **STATUS_NOT_FOUND** | The specified interface could not be found. This error is returned if the function cannot find the network interface that is specified by the **InterfaceLuid** or **InterfaceIndex** member of the MIB_UNICASTIPADDRESS_ROW structure that the *Row* parameter points to. |
| **STATUS_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is located on the local computer and an IPv4 address was specified in the **Address** member of the MIB_UNICASTIPADDRESS_ROW structure that the *Row* parameter points to, or if no IPv6 stack is located on the local computer and an IPv6 address was specified in the **Address** member. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The **DeleteUnicastIpAddressEntry** function is used to delete an existing [**MIB\_UNICASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-row) structure entry on the local computer.

On input, your driver must initialize the following members of the MIB\_UNICASTIPADDRESS\_ROW structure that the *Row* parameter points to.

- **Address**
Set to a valid IPv4 or IPv6 unicast address and family.

- **InterfaceLuid** or **InterfaceIndex**
These members are used in the order that is listed earlier. So if **InterfaceLuid** is specified, this member is used to determine the interface. If no value was set for the **InterfaceLuid** member (the value of this member was set to zero), the **InterfaceIndex** member is next used to determine the interface.

If the function is successful, the existing IP address that the *Row* parameter represents is deleted.

Your driver can call the [**GetUnicastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getunicastipaddresstable) function to enumerate the unicast IP address entries on a local computer. Your driver can call the [**GetUnicastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/getunicastipaddressentry) function to retrieve a specific existing unicast IP address entry.

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

[**GetUnicastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/getunicastipaddressentry)

[**GetUnicastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getunicastipaddresstable)

[**InitializeUnicastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/initializeunicastipaddressentry)

[**MIB\_UNICASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-row)

[**MIB\_UNICASTIPADDRESS\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-table)

[**NotifyUnicastIpAddressChange**](https://learn.microsoft.com/windows-hardware/drivers/network/notifyunicastipaddresschange)

[**SetUnicastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/setunicastipaddressentry)