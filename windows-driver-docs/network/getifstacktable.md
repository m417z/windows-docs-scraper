# GetIfStackTable function

The **GetIfStackTable** function retrieves a table of network interface stack row entries that specify the relationship of the network interfaces on an interface stack.

## Parameters

- *Table* \[out\]
A pointer to a buffer that receives the table of interface stack row entries in a [**MIB\_IFSTACK\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ifstack-table) structure.

## Return value

**GetIfStackTable** returns STATUS\_SUCCESS if the function succeeds.

If the function fails, **GetIfStackTable** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Table* parameter. |
| **STATUS_NOT_ENOUGH_MEMORY** | Insufficient memory resources are available to complete the operation. |
| **STATUS_NOT_FOUND** | No interface stack entries were found. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The **GetIfStackTable** function enumerates the physical and logical network interfaces on an interface stack on a local computer and returns this information in a [**MIB\_IFSTACK\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ifstack-table) structure.

Interface stack entries are returned in a MIB\_IFSTACK\_TABLE structure in the buffer that the *Table* parameter points to. The MIB\_IFSTACK\_TABLE structure contains an interface stack entry count and an array of [**MIB\_IFSTACK\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ifstack-row) structures for each interface stack entry.

The relationship between the interfaces in the interface stack is that the interface with index in the **HigherLayerInterfaceIndex** member of the MIB\_IFSTACK\_ROW structure is immediately above the interface with index in the **LowerLayerInterfaceIndex** member of the MIB\_IFSTACK\_ROW structure.

Memory is allocated by the **GetIfStackTable** function for the MIB\_IFSTACK\_TABLE structure and the MIB\_IFSTACK\_ROW entries in this structure. When these returned structures are no longer required, your driver should free the memory by calling [**FreeMibTable**](https://learn.microsoft.com/windows-hardware/drivers/network/freemibtable).

Note that the returned MIB\_IFSTACK\_TABLE structure that the *Table* parameter points to might contain padding for alignment between the **NumEntries** member and the first MIB\_IFSTACK\_ROW array entry in the **Table** member of the MIB\_IFSTACK\_TABLE structure. Padding for alignment might also be present between the MIB\_IFSTACK\_ROW array entries. Any access to a MIB\_IFSTACK\_ROW array entry should assume padding may exist.

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

[**GetIfEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/getifentry2)

[**GetIfTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getiftable2)

[**GetInvertedIfStackTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getinvertedifstacktable)

[**GetIpInterfaceEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/getipinterfaceentry)

[**InitializeIpInterfaceEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/initializeipinterfaceentry)

[**MIB\_IF\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-if-row2)

[**MIB\_IF\_TABLE2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-if-table2)

[**MIB\_IFSTACK\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ifstack-row)

[**MIB\_IFSTACK\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ifstack-table)

[**MIB\_INVERTEDIFSTACK\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-invertedifstack-row)

[**MIB\_INVERTEDIFSTACK\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-invertedifstack-table)

[**MIB\_IPINTERFACE\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipinterface-row)

[**NotifyIpInterfaceChange**](https://learn.microsoft.com/windows-hardware/drivers/network/notifyipinterfacechange)

[**SetIpInterfaceEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/setipinterfaceentry)