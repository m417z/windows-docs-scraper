# MIB_IPFORWARD_TABLE2 structure

## Description

The
**MIB_IPFORWARD_TABLE2** structure contains a table of IP route entries.

## Members

### `NumEntries`

A value that specifies the number of IP route entries in the array.

### `Table`

An array of
[MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) structures containing IP route entries.

## Remarks

The **MIB_IPFORWARD_TABLE2** structure is defined on Windows Vista and later.

The **GetIpForwardTable2** function enumerates the IP route entries on a local system and returns this information in a **MIB_IPFORWARD_TABLE2** structure.

The **GetIpForwardEntry2** function retrieves a single IP route entry and returns this information in a [MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) structure.

The **MIB_IPFORWARD_TABLE2** structure may contain padding for alignment between the **NumEntries** member and the first [MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) array entry in the **Table** member. Padding for alignment may also be present between the **MIB_IPFORWARD_ROW2** array entries in the **Table** member. Any access to a **MIB_IPFORWARD_ROW2** array entry should assume padding may exist.

Note that the *Netioapi.h* header file is automatically included in the *Iphlpapi.h* header file. The *Netioapi.h* header file should never be used directly.

## See also

**GetIpForwardEntry2**

**GetIpForwardTable2**

[MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2)