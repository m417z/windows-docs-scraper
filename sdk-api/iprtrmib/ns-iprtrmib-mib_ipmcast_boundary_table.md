# MIB_IPMCAST_BOUNDARY_TABLE structure

## Description

The **MIB_IPMCAST_BOUNDARY_TABLE** structure contains a list of a router's scoped IPv4 multicast address boundaries.

## Members

### `dwNumEntries`

The number of [MIB_IPMCAST_BOUNDARY](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ns-iprtrmib-mib_ipmcast_boundary) structures listed in **table[]**.

### `table`

An array of [MIB_IPMCAST_BOUNDARY](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ns-iprtrmib-mib_ipmcast_boundary) structures which collectively define the set of scoped IPv4 multicast address boundaries on a router.

## Remarks

This structure does not have a fixed size. Use the **SIZEOF_BOUNDARY_TABLE(X)** macro to determine the size of this structure. This macro is defined in the *Iprtrmib.h* header file.

Note that the *Iprtrmib.h* header file is automatically included in the *Iphlpapi.h* header file. The *Iprtrmib.h* header file should never be used directly.

## See also

[MIB_IPMCAST_BOUNDARY](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ns-iprtrmib-mib_ipmcast_boundary)