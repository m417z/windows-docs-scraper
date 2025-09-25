# GetIfTable2 function

## Description

The **GetIfTable2** function retrieves the MIB-II interface table.

## Parameters

### `Table` [out]

A pointer to a buffer that receives the table of interfaces in a [MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2) structure.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory resources are available to complete the operation. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The
**GetIfTable2** function enumerates the logical and physical interfaces on a local system and returns this information in a [MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2) structure. **GetIfTable2** is an enhanced version of the **GetIfTable** function.

A similar [GetIfTable2Ex](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2ex) function can be used to specify the level of interfaces to return. Calling the **GetIfTable2Ex** function with the *Level* parameter set to **MibIfTableNormal** retrieves the same results as calling the **GetIfTable2** function.

Interfaces are returned in a [MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2) structure in the buffer pointed to by the *Table* parameter. The **MIB_IF_TABLE2** structure contains an interface count and an array of [MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2) structures for each interface. Memory is allocated by the **GetIfTable2** function for the **MIB_IF_TABLE2** structure and the **MIB_IF_ROW2** entries in this structure. When these returned structures are no longer required, free the memory by calling the [FreeMibTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-freemibtable).

Note that the returned [MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2) structure pointed to by the *Table* parameter may contain padding for alignment between the **NumEntries** member and the first [MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2) array entry in the **Table** member of the **MIB_IF_TABLE2** structure. Padding for alignment may also be present between the **MIB_IF_ROW2** array entries. Any access to a **MIB_IF_ROW2** array entry should assume padding may exist.

## See also

[FreeMibTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-freemibtable)

[GetIfTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getiftable)

[GetIfTable2Ex](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2ex)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2)

[MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2)