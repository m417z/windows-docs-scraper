# GetIpInterfaceTable function

The **GetIpInterfaceTable** function retrieves the IP interface entries on a local computer.

## Parameters

- *Family* \[in\]
The address family of IP interfaces to retrieve.

 Possible values for the address family are listed in the Winsock2.h header file. Note that the values for the AF\_ address family and PF\_ protocol family constants are identical (for example, AF\_INET and PF\_INET), so you can use either constant.

 On Windows Vista and later versions of the Windows operating systems, possible values for the *Family* parameter are defined in the Ws2def.h header file. Note that the Ws2def.h header file is automatically included in Netioapi.h and you should never use Ws2def.h directly.

 The following values are currently supported for the address family:

   - AF\_INET
The IPv4 address family.

   - AF\_INET6
The IPv6 address family.

   - AF\_UNSPEC
The address family is unspecified. When this value is specified, the **GetIpInterfaceTable** function returns the IP interface table that contains both IPv4 and IPv6 entries.

- *Table* \[out\]
A pointer to a buffer that receives the table of IP interface entries in a [**MIB\_IPINTERFACE\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipinterface-table) structure.

## Return value

**GetIpInterfaceTable** returns STATUS\_SUCCESS if the function succeeds.

If the function fails, **GetIpInterfaceTable** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Table* parameter or the *Family* parameter was not specified as AF_INET, AF_INET6, or AF_UNSPEC. |
| **STATUS_NOT_ENOUGH_MEMORY** | Insufficient memory resources are available to complete the operation. |
| **STATUS_NOT_FOUND** | No IP interface entries, as specified in the *Family* parameter, were found. |
| **STATUS_NOT_SUPPORTED** | The function is not supported. This error is returned when the IP transport that is specified in the *Address* parameter is not configured on the local computer. This error is also returned on versions of Windows where this function is not supported. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The **GetIpInterfaceTable** function enumerates the IP interfaces on a local computer and returns this information in an [**MIB\_IPINTERFACE\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipinterface-table) structure.

**GetIpInterfaceTable** returns IP interface entries in a MIB\_IPINTERFACE\_TABLE structure in the buffer that the *Table* parameter points to. The MIB\_IPINTERFACE\_TABLE structure contains an IP interface entry count and an array of [**MIB\_IPINTERFACE\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipinterface-row) structures for each IP interface entry. When these returned structures are no longer required, your driver should free the memory by calling the [**FreeMibTable**](https://learn.microsoft.com/windows-hardware/drivers/network/freemibtable) function.

Your driver must initialize the *Family* parameter to either AF\_INET or AF\_INET6.

Note that the returned MIB\_IPINTERFACE\_TABLE structure that the *Table* parameter points to might contain padding for alignment between the **NumEntries** member and the first [**MIB\_IPINTERFACE\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipinterface-row) array entry in the **Table** member of the MIB\_IPINTERFACE\_TABLE structure. Padding for alignment might also be present between the MIB\_IPINTERFACE\_ROW array entries. Any access to a MIB\_IPINTERFACE\_ROW array entry should assume padding might exist.

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://learn.microsoft.com/windows-hardware/drivers/develop/target-platforms) |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |
| Library | Netio.lib |
| IRQL | < DISPATCH_LEVEL |

## See also

[**FreeMibTable**](https://learn.microsoft.com/windows-hardware/drivers/network/freemibtable)

[**MIB\_IPINTERFACE\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipinterface-row)

[**MIB\_IPINTERFACE\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipinterface-table)

[**MIB\_IPNET\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipnet-row2)

[**MIB\_IPNET\_TABLE2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipnet-table2)