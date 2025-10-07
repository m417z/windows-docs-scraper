# GetIfTable2Ex function

The **GetIfTable2Ex** function retrieves the MIB-II interface table, given a level of interface information to retrieve.

## Parameters

- *Level* \[in\]
The level of interface information to retrieve. This parameter can be one of the values from the [**MIB\_IF\_TABLE\_LEVEL**](https://learn.microsoft.com/windows/win32/api/netioapi/ne-netioapi-mib_if_table_level) enumeration.

- *Table* \[out\]
A pointer to a buffer that receives the table of interfaces in a [**MIB\_IF\_TABLE2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-if-table2) structure.

## Return value

**GetIfTable2Ex** returns STATUS\_SUCCESS if the function succeeds.

If the function fails, **GetIfTable2Ex** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if an illegal value was passed in the *Level* parameter. |
| **STATUS_NOT_ENOUGH_MEMORY** | Insufficient memory resources are available to complete the operation. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The **GetIfTable2Ex** function enumerates the logical and physical interfaces on a local computer and returns this information in a [**MIB\_IF\_TABLE2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-if-table2) structure.

Your driver can use a similar function, [**GetIfTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getiftable2), to retrieve interfaces, but **GetIfTable2** does not enable your driver tospecify the level of interfaces to return. A call to the **GetIfTable2Ex** function with the *Level* parameter set to **MibIfTableNormal** retrieves the same results as calling the **GetIfTable2** function.

**GetIfTable2Ex** returns interfaces in a MIB\_IF\_TABLE2 structure in the buffer that the *Table* parameter points to. The MIB\_IF\_TABLE2 structure contains an interface count and an array of [**MIB\_IF\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-if-row2) structures for each interface. **GetIfTable2** allocates mmory for the MIB\_IF\_TABLE2 structure and the MIB\_IF\_ROW2 entries in this structure. When these returned structures are no longer required, your driver should free the memory by calling [**FreeMibTable**](https://learn.microsoft.com/windows-hardware/drivers/network/freemibtable).

All interfaces, including NDIS intermediate driver interfaces and NDIS filter driver interfaces, are returned for either of the possible values for the *Level* parameter. The setting for the *Level* parameter affects how statistics and state members of the MIB\_IF\_ROW2 structure in the MIB\_IF\_TABLE2 structure that is pointed to by the *Table* parameter for the interface are returned. For example, a network interface card (NIC) has an NDIS miniport driver. An NDIS intermediate driver can be installed to interface between upper-level protocol drivers and NDIS miniport drivers. An [NDIS filter driver](https://learn.microsoft.com/windows-hardware/drivers/network/introduction-to-ndis-filter-drivers) can be attached on top of the NDIS intermediate driver. Assume that the NIC reports the **MediaConnectState** member of the MIB\_IF\_ROW2 structure as **MediaConnectStateConnected**, but the NDIS filter driver modifies the state and reports the state as **MediaConnectStateDisconnected**. When the interface information is queried with *Level* parameter set to **MibIfTableNormal**, the state at the top of the filter stack (**MediaConnectStateDisconnected**) is reported. When the interface is queried with the *Level* parameter set to **MibIfTableRaw**, the state at the interface level directly (**MediaConnectStateConnected**) is returned.

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

[**GetIfTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getiftable2)

[**MIB\_IF\_TABLE\_LEVEL**](https://learn.microsoft.com/windows/win32/api/netioapi/ne-netioapi-mib_if_table_level)

[**MIB\_IF\_TABLE2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-if-table2)

[**MIB\_IF\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-if-row2)