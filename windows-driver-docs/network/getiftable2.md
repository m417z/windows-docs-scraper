# GetIfTable2 function

The **GetIfTable2** function retrieves the MIB-II interface table.

## Parameters

- *Table* \[out\]
A pointer to a buffer that receives the table of interfaces in a [**MIB\_IF\_TABLE2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-if-table2) structure.

## Return value

**GetIfTable2** returns STATUS\_SUCCESS if the function succeeds.

If the function fails, **GetIfTable2** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_NOT_ENOUGH_MEMORY** | Insufficient memory resources are available to complete the operation. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The **GetIfTable2** function enumerates the logical and physical interfaces on a local computer and returns this information in a [**MIB\_IF\_TABLE2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-if-table2) structure.

Your driver can use a similar function, [**GetIfTable2Ex**](https://learn.microsoft.com/windows-hardware/drivers/network/getiftable2ex), to specify the level of interfaces to return. A call to the **GetIfTable2Ex** function with the *Level* parameter set to **MibIfTableNormal** retrieves the same results as calling the **GetIfTable2** function.

**GetIfTable2** returns interfaces in a MIB\_IF\_TABLE2 structure in the buffer that the *Table* parameter points to. The MIB\_IF\_TABLE2 structure contains an interface count and an array of [**MIB\_IF\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-if-row2) structures for each interface. **GetIfTable2** allocates memory for the MIB\_IF\_TABLE2 structure and the MIB\_IF\_ROW2 entries in this structure. When these returned structures are no longer required, your driver should free the memory by calling [**FreeMibTable**](https://learn.microsoft.com/windows-hardware/drivers/network/freemibtable).

Note that the returned MIB\_IF\_TABLE2 structure that the *Table* parameter points to might contain padding for alignment between the **NumEntries** member and the first MIB\_IF\_ROW2 array entry in the **Table** member of the MIB\_IF\_TABLE2 structure. Padding for alignment might also be present between the MIB\_IF\_ROW2 array entries. Any access to a MIB\_IF\_ROW2 array entry should assume padding may exist.

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

[**GetIfTable2Ex**](https://learn.microsoft.com/windows-hardware/drivers/network/getiftable2ex)

[**MIB\_IF\_TABLE2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-if-table2)

[**MIB\_IF\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-if-row2)