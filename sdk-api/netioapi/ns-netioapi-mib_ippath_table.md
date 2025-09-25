# MIB_IPPATH_TABLE structure

## Description

The
**MIB_IPPATH_TABLE** structure contains a table of IP path entries.

## Members

### `NumEntries`

A value that specifies the number of IP path entries in the array.

### `Table`

An array of
[MIB_IPPATH_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ippath_row) structures containing IP path entries.

## Remarks

The **MIB_IPPATH_TABLE** structure is defined on Windows Vista and later.

The [GetIpPathTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getippathtable) function enumerates the IP path entries on a local system and returns this information in a **MIB_IPPATH_TABLE** structure.

The [FlushIpPathTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-flushippathtable) function flushes the IP path table entries on a local system.

The [GetIpPathEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getippathentry) function retrieves a single IP path entry and returns this information in a [MIB_IPPATH_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ippath_row) structure.

The **MIB_IPPATH_TABLE** structure may contain padding for alignment between the **NumEntries** member and the first [MIB_IPPATH_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ippath_row) array entry in the **Table** member. Padding for alignment may also be present between the **MIB_IPPATH_ROW** array entries in the **Table** member. Any access to a **MIB_IPPATH_ROW** array entry should assume padding may exist.

## See also

[FlushIpPathTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-flushippathtable)

[GetIpPathEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getippathentry)

[GetIpPathTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getippathtable)

[MIB_IPPATH_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ippath_row)