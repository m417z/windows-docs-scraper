# GetIfStackTable function

## Description

The **GetIfStackTable** function retrieves a table of network interface stack row entries that specify the relationship of the network interfaces on an interface stack.

## Parameters

### `Table` [out]

A pointer to a buffer that receives the table of interface stack row entries in a [MIB_IFSTACK_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ifstack_table) structure.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Table* parameter. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory resources are available to complete the operation. |
| **ERROR_NOT_FOUND** | No interface stack entries were found. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The **GetIfStackTable** function is defined on Windows Vista and later.

The
**GetIfStackTable** function enumerates the physical and logical network interfaces on an interface stack on a local system and returns this information in a [MIB_IFSTACK_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ifstack_table) structure.

Interface stack entries are returned in a [MIB_IFSTACK_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ifstack_table) structure in the buffer pointed to by the *Table* parameter. The **MIB_IFSTACK_TABLE** structure contains an interface stack entry count and an array of [MIB_IFSTACK_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ifstack_row) structures for each interface stack entry.

The relationship between the interfaces in the interface stack is that the interface with index in the **HigherLayerInterfaceIndex** member of the [MIB_IFSTACK_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ifstack_row) structure is immediately above the interface with index in the **LowerLayerInterfaceIndex** member of the **MIB_IFSTACK_ROW** structure.

Memory is allocated by the **GetIfStackTable** function for the [MIB_IFSTACK_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ifstack_table) structure and the [MIB_IFSTACK_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ifstack_row) entries in this structure. When these returned structures are no longer required, free the memory by calling the [FreeMibTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-freemibtable).

Note that the returned [MIB_IFSTACK_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ifstack_table) structure pointed to by the *Table* parameter may contain padding for alignment between the **NumEntries** member and the first [MIB_IFSTACK_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ifstack_row) array entry in the **Table** member of the **MIB_IFSTACK_TABLE** structure. Padding for alignment may also be present between the **MIB_IFSTACK_ROW** array entries. Any access to a **MIB_IFSTACK_ROW** array entry should assume padding may exist.

## See also

[FreeMibTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-freemibtable)

[GetIfEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getifentry2)

[GetIfTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2)

[GetInvertedIfStackTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getinvertedifstacktable)

[GetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfaceentry)

[InitializeIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-initializeipinterfaceentry)

[MIB_IFSTACK_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ifstack_row)

[MIB_IFSTACK_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ifstack_table)

[MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2)

[MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2)

[MIB_INVERTEDIFSTACK_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_invertedifstack_row)

[MIB_INVERTEDIFSTACK_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_invertedifstack_table)

[MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row)

[NotifyIpInterfaceChange](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyipinterfacechange)

[SetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-setipinterfaceentry)