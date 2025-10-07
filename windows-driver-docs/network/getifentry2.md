# GetIfEntry2 function

The **GetIfEntry2** function retrieves information for the specified interface on a local computer.

> [!IMPORTANT]
> For driver developers, it is recommended to use [GetIfEntry2Ex](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2ex) with MibIfEntryNormalWithoutStatistics when possible, in order to avoid a deadlock when servicing NDIS OIDs.

## Parameters

- *Row* \[in, out\]
A pointer to a [**MIB\_IF\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-if-row2) structure that, on successful return, receives information for an interface on the local computer. On input, your driver must set the **InterfaceLuid** member or the **InterfaceIndex** member of the MIB\_IF\_ROW2 structure to the interface to retrieve information for.

## Return value

**GetIfEntry2** returns STATUS\_SUCCESS if the function succeeds.

If the function fails, **GetIfEntry2** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Row* parameter. |
| **STATUS_NOT_FOUND** | The specified interface could not be found. This error is returned if the function cannot find the network interface that is specified by the **InterfaceLuid** or **InterfaceIndex** member of the [**MIB_IF_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-if-row2) structure that the *Row* parameter points to. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

On input, your driver must initialize at least the **InterfaceLuid** or **InterfaceIndex** member in the [**MIB\_IF\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-if-row2) structure that is passed in the *Row* parameter. The members are used in the order that is listed earlier. So if **InterfaceLuid** is specified, this member is used to determine the interface. If no value was set for the **InterfaceLuid** member (the value of this member was set to zero), the **InterfaceIndex** member is next used to determine the interface.

On output, the remaining fields of the MIB\_IF\_ROW2 structure that the *Row* parameter points to are filled in.

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://learn.microsoft.com/windows-hardware/drivers/develop/target-platforms) |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |
| Library | Netio.lib |
| IRQL | < DISPATCH_LEVEL |

## See also

[**GetIfTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getiftable2)

[**GetIfTable2Ex**](https://learn.microsoft.com/windows-hardware/drivers/network/getiftable2ex)

[**MIB\_IF\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-if-row2)

[**MIB\_IF\_TABLE2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-if-table2)