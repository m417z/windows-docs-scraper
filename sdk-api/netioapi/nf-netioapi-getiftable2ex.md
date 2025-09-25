# GetIfTable2Ex function

## Description

The **GetIfTable2Ex** function retrieves the MIB-II interface table.

## Parameters

### `Level` [in]

The level of interface information to retrieve. This parameter can be one of the values from the **MIB_IF_TABLE_LEVEL** enumeration type defined in the *Netioapi.h* header file.

| Value | Meaning |
| --- | --- |
| **MibIfTableNormal** | The values of statistics and state returned in members of the [MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2) structure in the [MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2) structure pointed to by the *Table* parameter are returned from the top of the filter stack when this parameter is specified. |
| **MibIfTableRaw** | The values of statistics and state returned in members of the [MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2) structure in the [MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2) structure pointed to by the *Table* parameter are returned directly for the interface being queried. |

### `Table` [out]

A pointer to a buffer that receives the table of interfaces in a [MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2) structure.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if an illegal value was passed in the *Level* parameter. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory resources are available to complete the operation. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The
**GetIfTable2Ex** function enumerates the logical and physical interfaces on a local system and returns this information in a [MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2) structure. **GetIfTable2Ex** is an enhanced version of the **GetIfTable** function that allows selecting the level of interface information to retrieve.

A similar [GetIfTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2) function can also be used to retrieve interfaces. but does not allow specifying the level of interfaces to return. Calling the **GetIfTable2Ex** function with the *Level* parameter set to **MibIfTableNormal** retrieves the same results as calling the **GetIfTable2** function.

Interfaces are returned in a [MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2) structure in the buffer pointed to by the *Table* parameter. The **MIB_IF_TABLE2** structure contains an interface count and an array of [MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2) structures for each interface. Memory is allocated by the [GetIfTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2) function for the **MIB_IF_TABLE2** structure and the **MIB_IF_ROW2** entries in this structure. When these returned structures are no longer required, free the memory by calling the [FreeMibTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-freemibtable).

All interfaces including NDIS intermediate driver interfaces and NDIS filter driver interfaces are returned for either of the possible values for the *Level* parameter. The setting for the *Level* parameter affects how statistics and state members of the [MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2) structure in the [MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2) structure pointed to by the *Table* parameter for the interface are returned. For example, a network interface card (NIC) will have a NDIS miniport driver. An NDIS intermediate driver can be installed to interface between upper-level protocol drivers and NDIS miniport drivers. An NDIS filter driver (LWF) can be attached on top of the NDIS intermediate driver. Assume that the NIC reports the MediaConnectState member of the **MIB_IF_ROW2** structure as **MediaConnectStateConnected** but NDIS filter driver modifies the state and reports the state as **MediaConnectStateDisconnected**.
When the interface information is queried with *Level* parameter set to **MibIfTableNormal**, the state at the top of the filter stack, that is **MediaConnectStateDisconnected** is reported. When the interface is queried with the *Level* parameter set to **MibIfTableRaw**, the state at the interface level directly, that is **MediaConnectStateConnected** is returned.

Note that the returned [MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2) structure pointed to by the *Table* parameter may contain padding for alignment between the **NumEntries** member and the first [MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2) array entry in the **Table** member of the **MIB_IF_TABLE2** structure. Padding for alignment may also be present between the **MIB_IF_ROW2** array entries. Any access to a **MIB_IF_ROW2** array entry should assume padding may exist.

## See also

[FreeMibTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-freemibtable)

[GetIfTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getiftable)

[GetIfTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2)

[MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2)