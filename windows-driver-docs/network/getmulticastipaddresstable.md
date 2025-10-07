# GetMulticastIpAddressTable function

The **GetMulticastIpAddressTable** function retrieves the multicast IP address table on a local computer.

## Parameters

- *Family* \[in\]
The address family to retrieve.

 Possible values for the address family are listed in the Winsock2.h header file. Note that the values for the AF\_ address family and PF\_ protocol family constants are identical (for example, AF\_INET and PF\_INET), so you can use either constant.

 On Windows Vista and later versions of the Windows operating systems, possible values for the *Family* parameter are defined in the Ws2def.h header file. Note that the Ws2def.h header file is automatically included in Netioapi.h and you should never use Ws2def.h directly.

 The following values are currently supported for the address family:

   - AF\_INET
The IPv4 address family. When this value is specified, this function returns the multicast IP address table that contains only IPv4 entries.

   - AF\_INET6
The IPv6 address family. When this value is specified, this function returns the multicast IP address table that contains only IPv6 entries.

   - AF\_UNSPEC
The address family is unspecified. When this value is specified, this function returns the multicast IP address table that contains both IPv4 and IPv6 entries.

- *Table* \[out\]
A pointer to a [**MIB\_MULTICASTIPADDRESS\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-multicastipaddress-table) structure that contains a table of anycast IP address entries on the local computer.

## Return value

**GetMulticastIpAddressTable** returns STATUS\_SUCCESS if the function succeeds.

If the function fails, **GetMulticastIpAddressTable** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Table* parameter or the *Family* parameter was not specified as AF_INET, AF_INET6, or AF_UNSPEC. |
| **STATUS_NOT_ENOUGH_MEMORY** | Insufficient memory resources are available to complete the operation. |
| **STATUS_NOT_FOUND** | No anycast IP address entries, as specified in the *Family* parameter, were found. |
| **STATUS_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is located on the local computer and AF_INET was specified in the *Family* parameter, or if no IPv6 stack is located on the local computer and AF_INET6 was specified in the *Family* parameter. This error is also returned on versions of Windows where this function is not supported. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The **GetMulticastIpAddressTable** function enumerates the multicast IP addresses on a local computer and returns this information in a [**MIB\_MULTICASTIPADDRESS\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-multicastipaddress-table) structure.

**GetMulticastIpAddressTable** returns the multicast IP address entries in a MIB\_MULTICASTIPADDRESS\_TABLE structure in the buffer that the *Table* parameter points to. The MIB\_MULTICASTIPADDRESS\_TABLE structure contains a multicast IP address entry count and an array of [**MIB\_MULTICASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-multicastipaddress-row) structures for each multicast IP address entry. When these returned structures are no longer required, your driver should free the memory by calling [**FreeMibTable**](https://learn.microsoft.com/windows-hardware/drivers/network/freemibtable).

Your driver must initialize the *Family* parameter to either AF\_INET, AF\_INET6, or AF\_UNSPEC.

Note that the returned MIB\_MULTICASTIPADDRESS\_TABLE structure that the *Table* parameter points to might contain padding for alignment between the **NumEntries** member and the first MIB\_MULTICASTIPADDRESS\_ROW array entry in the **Table** member of the MIB\_MULTICASTIPADDRESS\_TABLE structure. Padding for alignment might also be present between the MIB\_MULTICASTIPADDRESS\_ROW array entries. Any access to a MIB\_MULTICASTIPADDRESS\_ROW array entry should assume padding might exist.

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://learn.microsoft.com/windows-hardware/drivers/develop/target-platforms) |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |
| Library | Netio.lib |
| IRQL | < DISPATCH_LEVEL |

## See also

[**GetMulticastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/getmulticastipaddressentry)

[**MIB\_MULTICASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-multicastipaddress-row)

[**MIB\_MULTICASTIPADDRESS\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-multicastipaddress-table)