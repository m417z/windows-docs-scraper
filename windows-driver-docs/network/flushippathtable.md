# FlushIpPathTable function

The **FlushIpPathTable** function flushes the IP path table on a local computer.

## Parameters

- *Family* \[in\]
The address family to flush.

 Possible values for the address family are listed in the Winsock2.h header file. Note that the values for the AF\_ address family and PF\_ protocol family constants are identical (for example, AF\_INET and PF\_INET), so you can use either constant.

 On Windows Vista and later versions of the Windows operating systems, possible values for the *Family* parameter are defined in the Ws2def.h header file. Note that the Ws2def.h header file is automatically included in Netioapi.h and you should never use Ws2def.h directly.

 The following values are currently supported for the address family:

   - AF\_INET
The IPv4 address family. When this value is specified, this function flushes the IP path table that contains only IPv4 entries.

   - AF\_INET6
The IPv6 address family. When this value is specified, this function flushes the IP path table that contains only IPv6 entries.

   - AF\_UNSPEC
The address family is unspecified. When this value is specified, this function flushes the neighbor IP address table that contains both IPv4 and IPv6 entries.

## Return value

**FlushIpPathTable** returns STATUS\_SUCCESS if the function succeeds.

If the function fails, **FlushIpPathTable** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if the *Family* parameter was not specified as AF_INET, AF_INET6, or AF_UNSPEC. |
| **STATUS_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is located on the local computer and AF_INET was specified in the *Family* parameter, or if no IPv6 stack is located on the local computer and AF_INET6 was specified in the *Family* parameter. This error is also returned on versions of Windows where this function is not supported. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The **FlushIpPathTable** function flushes or deletes the IP path entries on a local computer. Your driver can use the *Family* parameter to limit the IP path entries to delete to a particular IP address family. If IP path entries for both IPv4 and IPv6 should be deleted, your driver should set the *Family* parameter to AF\_UNSPEC.

Your driver must initialize the *Family* parameter to either AF\_INET, AF\_INET6, or AF\_UNSPEC.

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://learn.microsoft.com/windows-hardware/drivers/develop/target-platforms) |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |
| Library | Netio.lib |
| IRQL | < DISPATCH_LEVEL |

## See also

[**GetIpPathEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/getippathentry)

[**GetIpPathTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getippathtable)

[**MIB\_IPPATH\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ippath-row)

[**MIB\_IPPATH\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ippath-table)