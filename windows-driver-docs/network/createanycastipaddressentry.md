# CreateAnycastIpAddressEntry function

The **CreateAnycastIpAddressEntry** function adds a new anycast IP address entry on a local computer.

## Parameters

- *Row* \[in\]
A pointer to a [**MIB\_ANYCASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-anycastipaddress-row) structure entry for an anycast IP address entry.

## Return value

**CreateAnycastIpAddressEntry** returns STATUS\_SUCCESS if the function succeeds.

If the function fails, **CreateAnycastIpAddressEntry** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Row* parameter, the **Address** member of the [**MIB_ANYCASTIPADDRESS_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-anycastipaddress-row) structure that the *Row* parameter points to was not set to a valid unicast IPv4 or IPv6 address, or both **InterfaceLuid** and **InterfaceIndex** members of the MIB_ANYCASTIPADDRESS_ROW structure were unspecified. |
| **STATUS_NOT_FOUND** | The specified interface could not be found. This error is returned if the function cannot find the network interface that is specified by the **InterfaceLuid** or **InterfaceIndex** member of the MIB_UNICASTIPADDRESS_ROW structure that the *Row* parameter points to. |
| **STATUS_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is located on the local computer and an IPv4 address was specified in the **Address** member of the MIB_ANYCASTIPADDRESS_ROW structure that the *Row* parameter points to, or if no IPv6 stack is located on the local computer and an IPv6 address was specified in the **Address** member. |
| **ERROR_OBJECT_ALREADY_EXISTS** | The object already exists. This error is returned if the **Address** member of the MIB_ANYCASTIPADDRESS_ROW structure that the *Row* parameter points to is a duplicate of an existing anycast IP address on the interface that is specified by the **InterfaceLuid** or **InterfaceIndex** member of the MIB_ANYCASTIPADDRESS_ROW structure. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

Your driver must initialize the following members of the [**MIB\_ANYCASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-anycastipaddress-row) structure that the *Row* parameter points to.

- **Address**
Set to a valid unicast IPv4 or IPv6 address and family.

- **InterfaceLuid** or **InterfaceIndex**
These members are used in the order that is listed earlier. So if **InterfaceLuid** is specified, this member is used to determine the interface to add the unicast IP address to. If no value was set for the **InterfaceLuid** member (the value of this member was set to zero), the **InterfaceIndex** member is next used to determine the interface.

The **ScopeId** member of the MIB\_ANYCASTIPADDRESS\_ROW structure that the *Row* parameter points to is ignored when the **CreateAnycastIpAddressEntry** function is called. The **ScopeId** member is automatically determined by the interface that the address is added on.

The **CreateAnycastIpAddressEntry** function fails if the anycast IP address that is passed in the **Address** member of the MIB\_ANYCASTIPADDRESS\_ROW structure that the *Row* parameter points to is a duplicate of an existing anycast IP address on the interface.

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://learn.microsoft.com/windows-hardware/drivers/develop/target-platforms) |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |
| Library | Netio.lib |
| IRQL | < DISPATCH_LEVEL |

## See also

[**DeleteAnycastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/deleteanycastipaddressentry)

[**GetAnycastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/getanycastipaddressentry)

[**GetAnycastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getanycastipaddresstable)

[**MIB\_ANYCASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-anycastipaddress-row)

[**MIB\_ANYCASTIPADDRESS\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-anycastipaddress-table)